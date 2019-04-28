#include "stdafx.h"
#include <iostream>

using namespace std;

/*����ģʽ������һϵ�е��㷨�����ࣩ��������һ������װһ�����������ǿ����໥�滻*/

//���������ӿڴ��麯��
class Strategy{

public:

	virtual void AlgorithmInterface() = 0;

	//�˴�����Ҫдһ��������������
};

class ConcreteStrategyA :public Strategy{

public:
	virtual void AlgorithmInterface(){
		cout << "�㷨A��ʵ��" << endl;
	}
};

class ConcreteStrategyB :public Strategy{

public:
	virtual void AlgorithmInterface(){
		cout << "�㷨B��ʵ��" << endl;
	}
};

class ConcreteStrategyC :public Strategy{

public:
	virtual void AlgorithmInterface(){
		cout << "�㷨C��ʵ��" << endl;
	}
};



class Context{
private:
	Strategy * _strategy; //��������û����ʼ���ġ�����һ���������ָ�����

public:

	Context(Strategy *strategy){
		this->_strategy= strategy;
	}

	void Algorithm(){
	this->_strategy->AlgorithmInterface();

	}
};

//����ģʽ+�򵥹���ģʽ
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

//����µ��㷨ֻ��Ҫ�������һ���㷨�࣬�Լ����ӿͻ��˴���

int main()
{
	/*����ģʽ*/
	/*Context context1(new ConcreteStrategyA);
	context1.Algorithm();

	Context context2(new ConcreteStrategyB);
	context2.Algorithm();

	Context context3(new ConcreteStrategyC);
	context3.Algorithm();*/

	/***����ģʽ+�򵥹���***/  //���㷨ʵ������������ֲ�������� 
	StrategyFactory SF1, SF2, SF3;
	SF1.RunStrategy('A');
	SF1.RunStrategy('B');
	SF1.RunStrategy('C');


	return 0;
}