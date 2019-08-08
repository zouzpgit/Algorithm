#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>

using namespace std;
/*
* @brief 原始的 0-1 背包问题
* 给定一系列物品的重量的和价值，在给定背包可承重量下，选择某些物品装入背包，使得装入背包的价值最大
* 每个物品，要么取要么不取
*
* @param weight : 物品重量（数组）          
* @param value : 物品价值（数组）           
* @param vol : 背包可承重量             
* @return 最大可能的价值
*/

/**
* DJi笔试题，题目是玩游戏，在总时间的限制之下，选择一个游戏去玩，玩通关后会有积分值，那么在总限制的前提下，能拿到的积分最多。
* 个人认为这个题目的输入很恶心，很烦躁，首先输入，游戏的总轮数T，第N轮的总游戏数和总时间限制，接下来就是每个游戏所对应的积分值和时间花费。例子如下：
* 2(总轮数T)
* 2 2(第N轮的总游戏数和总时间限制)
* 10 2(第N轮的第N个游戏积分和时间花费)
* 20 2
* 3 4
* 10 2
* 18 3
* 10 2
* 本题其实就是一个最简单的0 1 背包  二维空间解法
* -->C[i][0]:第i轮的游戏总数  ，C[i][1]:第i轮的游戏总时间限制
* -->TG[i][0]:第i轮第积分值（），TG[i][1]:第i轮第时间花费 数组）数组第一位没有预装0，有效数据是从0开始的，因此TG[i-1+m]要从i-1开始（即从0开始）
*/


//用二维数组存放输入数据真是脑阔疼，真是没必要
vector<int > bestgame(vector<vector<int > > &TG, vector<vector<int> > &C, int N){
	vector<int > res;
	int k = 0, m = 0;//m 偏移量
	while (k < N){
		int casenum = C[k][0], casetime = C[k][1];//该轮总游戏局数和总时间
		vector<vector<int >> dp(casenum + 1, vector<int>(casetime + 1, 0));
		for (int i = 1; i <= casenum; ++i){
			for (int j = 1; j <= casetime; ++j){
				if (TG[i - 1 + m][1]>j)// 当前的花费时间(TG[i][1])比总时间限制(j)大，肯定是dp[i][j]=dp[i-1][j];
					dp[i][j] = dp[i - 1][j];
				else//否则比较不放和放的结果，取较大值
					dp[i][j] = dp[i - 1][j] > (dp[i - 1][j - TG[i - 1 + m][1]] + TG[i - 1 + m][0]) ? dp[i - 1][j] : (dp[i - 1][j - TG[i - 1 + m][1]] + TG[i - 1 + m][0]);
			}
		}
		res.push_back(dp[casenum][casetime]);
		m = casenum;
		k++;
	}
	return res;
}


//用一维数组存储输入数据是真的很爽啊  二维空间解法
/*
* @param gamev :   游戏积分值（数组）数组第一位没有预装0
* @param gamet :   游戏耗费时间（数组）数组第一位没有预装0，有效数据是从0开始的，因此gamet[i-1]要从i-1开始（即从0开始）
* @param Ttime :	总时间限制
* @return 最大可能的价值
*/
int bestgame(vector<int > &gamev, vector<int > gamet, int Ttime){
	int nums = gamev.size();
	vector<vector<int >> dp(nums + 1, vector<int>(Ttime + 1, 0));
	for (int i = 1; i <= nums; ++i){
		for (int j = 1; j <= Ttime; ++j){
			if (gamet[i - 1]>j)//当前的时间花费(gamet[i-1])比当前的限制时间（j）大，肯定是dp[i][j]=dp[i-1][j];
				dp[i][j] = dp[i - 1][j];
			else//否则比较不放和放的结果，取较大值
				dp[i][j] = dp[i - 1][j]>(dp[i - 1][j - gamet[i - 1]] + gamev[i - 1]) ? dp[i - 1][j] : (dp[i - 1][j - gamet[i - 1]] + gamev[i - 1]);
		}
	}
	return dp[nums][Ttime];
}

//0 1背包一维空间解法
int bestgame1(vector<int > &gamev, vector<int > gamet, int Ttime)
{
	int nums = gamev.size();
	// 二维情况下 dp[i][j] 只与 dp[i - 1][k] 有关, 其中 k <= j
	// 当dp[i - 1] 计算完之后， 直接在其状态上更新即可, 而且每次都应该从右至左遍历，这是为什么呢？
	// 因为要计算dp[j-gamet[i-1]]+gamev[i-1]，你的dp[j-gamet[i-1]]是要往回取数据的，所以要保证左边状态是上一层保留下来的，不然就没意义了
	vector<int > dp(Ttime + 1, 0); //要加一个dp[0]=0，
	for (int i = 1; i <= nums; ++i){ //此处i=1开始，但是gamet[i-1]需要从i-1开始，因为gamet的数组的有效数据是从0开始的，如果要从gamet[i]i开始则gamet前面需要放一个0
		for (int j = Ttime; j >= 1; --j){
			if (gamet[i - 1] <= j)//此处逆序循环的原因是要每次拿到上一次的结果，且dp[j-gamet[i-1]]是往左取值，那么就只有从右边往左边循环。
				dp[j] = dp[j]>(dp[j - gamet[i - 1]] + gamev[i - 1]) ? dp[j] : (dp[j - gamet[i - 1]] + gamev[i - 1]);
		}
	}
	return dp[Ttime];
}

int main()
{

	int nums, totalgame, totaltime;
	int k = 0;
	cin >> nums;
	//哇，烦躁，二维输入实在是烦躁
	/*vector<vector<int >> cases(nums, vector<int>(2, 0));//第一列是games总轮数，第二列是time总数
	vector<vector<int >> totalgames;
	int k = 0;

	while (k < nums){
	cin >> totalgame >> totaltime;
	cases[k][0] = totalgame;
	cases[k][1] = totaltime;
	vector<vector<int >> games(totalgame);
	for (int i = 0; i < totalgame; ++i){
	int val, time;
	cin >> val >> time;
	games[i].push_back(val);
	games[i].push_back(time);
	}
	totalgames.insert(totalgames.end(), games.begin(), games.end());
	k++;
	}
	vector<int> result=bestgame(totalgames,cases,nums);*/

	//现在用一维数组来存放，并且是输入一轮数据就计算一轮，不等全部输入完
	while (k<nums){
		cin >> totalgame >> totaltime;
		vector<int > gameval(totalgame, 0);
		vector<int > gametime(totalgame, 0);
		for (int i = 0; i<totalgame; ++i){
			int gv, gt;
			cin >> gv >> gt;
			gameval[i] = gv;
			gametime[i] = gt;
		}
		k++;
		//int res = bestgame(gameval,gametime,totaltime);
		int res = bestgame1(gameval, gametime, totaltime);
		cout << res << endl;
	}
	return 0;
}
