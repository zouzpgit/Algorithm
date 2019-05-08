#include "stdafx.h"
#include<thread>
#include<mutex>
#include <atomic>

using namespace std;

/*单例模式*/

//目的：保证实例化的类在系统中只有一个存在

class Singleton{
private://将构造给函数设置为私有的，保证该类职能被自己的共有函数创建，不能被外部实例化
	Singleton();
	Singleton(const Singleton & other);
public:
	static Singleton * getInstance();
	static Singleton * m_instance;
	static  mutex mut;
};

Singleton* Singleton::m_instance = nullptr;



//线程非安全版本,没有加上线程锁，多线程的时候还是会创建两个实例出来的
Singleton* Singleton::getInstance(){
	if (m_instance == nullptr){
		m_instance = new Singleton();
	}
	return m_instance;
}

//线程锁安全版本，但是所地代价比较高,等待过久
Singleton* Singleton::getInstance(){
	mutex  mut;
	mut.lock();
	if (m_instance == nullptr){
		m_instance = new Singleton();
		mut.unlock();
	}
	return m_instance;
}

//双检查索安全版本，但是由于内存读写reorder不安全  
//插播：new过程的一般流程，首先分配内存，然后将分配的进行初始话，调用构造器，最后一步返回内存的地址，但是在CPU指令级别，顺序可能不是这样的，可能是分配完内存后就返回了地址
Singleton* Singleton::getInstance(){
	mutex  mut;
	if (m_instance == nullptr){
		mut.lock();
		if (m_instance == nullptr){
			m_instance = new Singleton();
			mut.unlock();
		}
	}
	return m_instance;
}



//C++ 11 版本之后的跨平台的实现    用的是automic原子操作,来实现他的内存reorder的保障，顺序不会出现问题

