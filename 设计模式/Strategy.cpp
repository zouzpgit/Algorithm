#include "stdafx.h"
#include <iostream>

using namespace std;

/*策略模式：定义一系列的算法（子类），将他们一个个封装一起来，并它们可以相互替换*/

//定义抽象类接口纯虚函数
class Strategy{

public:

	virtual void AlgorithmInterface() = 0;

	//此处还需要写一个纯虚析构函数
};

class ConcreteStrategyA :public Strategy{

public:
	virtual void AlgorithmInterface(){
		cout << "算法A的实现" << endl;
	}
};

class ConcreteStrategyB :public Strategy{

public:
	virtual void AlgorithmInterface(){
		cout << "算法B的实现" << endl;
	}
};

class ConcreteStrategyC :public Strategy{

public:
	virtual void AlgorithmInterface(){
		cout << "算法C的实现" << endl;
	}
};



class Context{
private:
	Strategy * _strategy; //抽象类是没法初始化的。定义一个抽象类的指针对象

public:

	Context(Strategy *strategy){
		this->_strategy= strategy;
	}

	void Algorithm(){
	this->_strategy->AlgorithmInterface();

	}
};

//策略模式+简单工厂模式
class StrategyFactory{

public:

	void RunStrategy(char type){
		Strategy * _strategy= NULL;
		switch (type){
		case 'A':
			_strategy = new ConcreteStrategyA;  break;
		case 'B':
			_strategy = new ConcreteStrategyB; break;
		case 'C':
			_strategy = new ConcreteStrategyC; break;
		}
		_strategy->AlgorithmInterface();
	}
	
};

//添加新的算法只需要重新添加一个算法类，以及增加客户端代码

int main()
{
	/*策略模式*/
	/*Context context1(new ConcreteStrategyA);
	context1.Algorithm();

	Context context2(new ConcreteStrategyB);
	context2.Algorithm();

	Context context3(new ConcreteStrategyC);
	context3.Algorithm();*/

	/***策略模式+简单工厂***/  //将算法实例化和运行移植到工厂中 
	StrategyFactory SF1, SF2, SF3;
	SF1.RunStrategy('A');
	SF1.RunStrategy('B');
	SF1.RunStrategy('C');


	return 0;
}