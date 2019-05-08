#include "stdafx.h"
#include<thread>
#include<mutex>
#include <atomic>

using namespace std;

/*����ģʽ*/

//Ŀ�ģ���֤ʵ����������ϵͳ��ֻ��һ������

class Singleton{
private://���������������Ϊ˽�еģ���֤����ְ�ܱ��Լ��Ĺ��к������������ܱ��ⲿʵ����
	Singleton();
	Singleton(const Singleton & other);
public:
	static Singleton * getInstance();
	static Singleton * m_instance;
	static  mutex mut;
};

Singleton* Singleton::m_instance = nullptr;



//�̷߳ǰ�ȫ�汾,û�м����߳��������̵߳�ʱ���ǻᴴ������ʵ��������
Singleton* Singleton::getInstance(){
	if (m_instance == nullptr){
		m_instance = new Singleton();
	}
	return m_instance;
}

//�߳�����ȫ�汾���������ش��۱Ƚϸ�,�ȴ�����
Singleton* Singleton::getInstance(){
	mutex  mut;
	mut.lock();
	if (m_instance == nullptr){
		m_instance = new Singleton();
		mut.unlock();
	}
	return m_instance;
}

//˫�������ȫ�汾�����������ڴ��дreorder����ȫ  
//�岥��new���̵�һ�����̣����ȷ����ڴ棬Ȼ�󽫷���Ľ��г�ʼ�������ù����������һ�������ڴ�ĵ�ַ��������CPUָ���˳����ܲ��������ģ������Ƿ������ڴ��ͷ����˵�ַ
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



//C++ 11 �汾֮��Ŀ�ƽ̨��ʵ��    �õ���automicԭ�Ӳ���,��ʵ�������ڴ�reorder�ı��ϣ�˳�򲻻��������

