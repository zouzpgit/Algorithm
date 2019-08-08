#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>

using namespace std;
/*
* @brief ԭʼ�� 0-1 ��������
* ����һϵ����Ʒ�������ĺͼ�ֵ���ڸ��������ɳ������£�ѡ��ĳЩ��Ʒװ�뱳����ʹ��װ�뱳���ļ�ֵ���
* ÿ����Ʒ��ҪôȡҪô��ȡ
*
* @param weight : ��Ʒ���������飩          
* @param value : ��Ʒ��ֵ�����飩           
* @param vol : �����ɳ�����             
* @return �����ܵļ�ֵ
*/

/**
* DJi�����⣬��Ŀ������Ϸ������ʱ�������֮�£�ѡ��һ����Ϸȥ�棬��ͨ�غ���л���ֵ����ô�������Ƶ�ǰ���£����õ��Ļ�����ࡣ
* ������Ϊ�����Ŀ������ܶ��ģ��ܷ��꣬�������룬��Ϸ��������T����N�ֵ�����Ϸ������ʱ�����ƣ�����������ÿ����Ϸ����Ӧ�Ļ���ֵ��ʱ�仨�ѡ��������£�
* 2(������T)
* 2 2(��N�ֵ�����Ϸ������ʱ������)
* 10 2(��N�ֵĵ�N����Ϸ���ֺ�ʱ�仨��)
* 20 2
* 3 4
* 10 2
* 18 3
* 10 2
* ������ʵ����һ����򵥵�0 1 ����  ��ά�ռ�ⷨ
* -->C[i][0]:��i�ֵ���Ϸ����  ��C[i][1]:��i�ֵ���Ϸ��ʱ������
* -->TG[i][0]:��i�ֵڻ���ֵ������TG[i][1]:��i�ֵ�ʱ�仨�� ���飩�����һλû��Ԥװ0����Ч�����Ǵ�0��ʼ�ģ����TG[i-1+m]Ҫ��i-1��ʼ������0��ʼ��
*/


//�ö�ά�����������������������ۣ�����û��Ҫ
vector<int > bestgame(vector<vector<int > > &TG, vector<vector<int> > &C, int N){
	vector<int > res;
	int k = 0, m = 0;//m ƫ����
	while (k < N){
		int casenum = C[k][0], casetime = C[k][1];//��������Ϸ��������ʱ��
		vector<vector<int >> dp(casenum + 1, vector<int>(casetime + 1, 0));
		for (int i = 1; i <= casenum; ++i){
			for (int j = 1; j <= casetime; ++j){
				if (TG[i - 1 + m][1]>j)// ��ǰ�Ļ���ʱ��(TG[i][1])����ʱ������(j)�󣬿϶���dp[i][j]=dp[i-1][j];
					dp[i][j] = dp[i - 1][j];
				else//����Ƚϲ��źͷŵĽ����ȡ�ϴ�ֵ
					dp[i][j] = dp[i - 1][j] > (dp[i - 1][j - TG[i - 1 + m][1]] + TG[i - 1 + m][0]) ? dp[i - 1][j] : (dp[i - 1][j - TG[i - 1 + m][1]] + TG[i - 1 + m][0]);
			}
		}
		res.push_back(dp[casenum][casetime]);
		m = casenum;
		k++;
	}
	return res;
}


//��һά����洢������������ĺ�ˬ��  ��ά�ռ�ⷨ
/*
* @param gamev :   ��Ϸ����ֵ�����飩�����һλû��Ԥװ0
* @param gamet :   ��Ϸ�ķ�ʱ�䣨���飩�����һλû��Ԥװ0����Ч�����Ǵ�0��ʼ�ģ����gamet[i-1]Ҫ��i-1��ʼ������0��ʼ��
* @param Ttime :	��ʱ������
* @return �����ܵļ�ֵ
*/
int bestgame(vector<int > &gamev, vector<int > gamet, int Ttime){
	int nums = gamev.size();
	vector<vector<int >> dp(nums + 1, vector<int>(Ttime + 1, 0));
	for (int i = 1; i <= nums; ++i){
		for (int j = 1; j <= Ttime; ++j){
			if (gamet[i - 1]>j)//��ǰ��ʱ�仨��(gamet[i-1])�ȵ�ǰ������ʱ�䣨j���󣬿϶���dp[i][j]=dp[i-1][j];
				dp[i][j] = dp[i - 1][j];
			else//����Ƚϲ��źͷŵĽ����ȡ�ϴ�ֵ
				dp[i][j] = dp[i - 1][j]>(dp[i - 1][j - gamet[i - 1]] + gamev[i - 1]) ? dp[i - 1][j] : (dp[i - 1][j - gamet[i - 1]] + gamev[i - 1]);
		}
	}
	return dp[nums][Ttime];
}

//0 1����һά�ռ�ⷨ
int bestgame1(vector<int > &gamev, vector<int > gamet, int Ttime)
{
	int nums = gamev.size();
	// ��ά����� dp[i][j] ֻ�� dp[i - 1][k] �й�, ���� k <= j
	// ��dp[i - 1] ������֮�� ֱ������״̬�ϸ��¼���, ����ÿ�ζ�Ӧ�ô����������������Ϊʲô�أ�
	// ��ΪҪ����dp[j-gamet[i-1]]+gamev[i-1]�����dp[j-gamet[i-1]]��Ҫ����ȡ���ݵģ�����Ҫ��֤���״̬����һ�㱣�������ģ���Ȼ��û������
	vector<int > dp(Ttime + 1, 0); //Ҫ��һ��dp[0]=0��
	for (int i = 1; i <= nums; ++i){ //�˴�i=1��ʼ������gamet[i-1]��Ҫ��i-1��ʼ����Ϊgamet���������Ч�����Ǵ�0��ʼ�ģ����Ҫ��gamet[i]i��ʼ��gametǰ����Ҫ��һ��0
		for (int j = Ttime; j >= 1; --j){
			if (gamet[i - 1] <= j)//�˴�����ѭ����ԭ����Ҫÿ���õ���һ�εĽ������dp[j-gamet[i-1]]������ȡֵ����ô��ֻ�д��ұ������ѭ����
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
	//�ۣ����꣬��ά����ʵ���Ƿ���
	/*vector<vector<int >> cases(nums, vector<int>(2, 0));//��һ����games���������ڶ�����time����
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

	//������һά��������ţ�����������һ�����ݾͼ���һ�֣�����ȫ��������
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
