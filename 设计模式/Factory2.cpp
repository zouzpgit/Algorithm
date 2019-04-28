#include "stdafx.h"
#include <iostream>


using namespace std;

class Operation { //���������

public:
	double numberA, numberB;

	virtual double GetResult() = 0;
};

/*****�Ӽ��˳����������*****/
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
		if (numberB == 0.0)
		{
			cout << "����������Ϊ0" << endl;
			return -1;
		}
		else
			return numberA / numberB;

	}
};

class Factory{ // ����������

public:
	virtual Operation* CreateOperation() = 0;

};

class FactoryAdd :public Factory{

public:
	virtual Operation* CreateOperation(){
		return new OperationAdd();
	}
};

class FactorySub :public Factory{

public:
	virtual Operation* CreateOperation(){
		return new OperationSub();
	}
};

class FactoryMul :public Factory{

public:
	virtual Operation* CreateOperation(){
		return new OperationMul();
	}
};

class FactoryDiv :public Factory{

public:
	virtual Operation* CreateOperation(){
		return new OperationDiv();
	}
};

int main()
{
	Factory *  factory = nullptr;
	Operation * operation = nullptr;

	factory = new FactoryDiv();
	operation = factory->CreateOperation();
	operation->numberA = 5.0;
	operation->numberB = 0.0;
	
	double data =operation->GetResult();


	return 0;

}