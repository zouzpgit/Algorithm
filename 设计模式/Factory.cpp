// Factory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/******简单工厂模式*******/


using namespace std;

class Operation { //抽象类操作
	/*private:
		double _numberA = 0;
		double _numberB = 0;*/ //大话设计模式上用的pivate属性的字段，

	
	public:
		double numberA, numberB;

		virtual double GetResult() = 0;
};


/*****加减乘除具体操作类*****/
class OperationAdd :public  Operation{
	public:
		virtual double GetResult()
		{
			return numberA + numberB;
		}
};

class OperationSub :public  Operation{
	public:
		virtual double GetResult()
		{
			return numberA - numberB;
		}
};

class OperationMul :public  Operation{
	public:
		virtual double GetResult()
		{
			return numberA * numberB;
		}
};

class OperationDiv :public  Operation{
	public:
		virtual double GetResult()
		{
			if (numberB== 0.0)
			{
				cout << "被除数不能为0" << endl;
				return -1;
			}
			else
				return numberA / numberB;
		
		}
};

/****工厂类*****/
class OperationFactory{

	public :
		static Operation* createOperate(char operate) 
		{
			Operation* oper=NULL ;
			switch (operate)
			{
				case '+':
					oper = new OperationAdd(); break;
				case '-':
					oper = new OperationSub(); break;
				case '*':
					oper = new OperationMul(); break;
				case '/':
					oper = new OperationDiv(); break;

			}
			return oper;
		}
};

int main() {

	OperationFactory operate ;
	Operation* oper;
	oper = operate.createOperate('/');
	oper->numberA = 5.0;
	oper->numberB = 0.0;
	double result = oper->GetResult();
	return 0;
}