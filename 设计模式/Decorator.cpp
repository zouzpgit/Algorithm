/********װ����ģʽ***********/

#include "stdafx.h"
#include <iostream>

using namespace std;

/***********Ӧ�ó�������Ϊ������************/

//�������
class Stream{
public:
	virtual void Read() = 0; 
	virtual void  Seek() = 0;
	virtual void Write() = 0;

	virtual ~Stream(){}

};
	

/********����ҵ�����********/

//������
class FileStream :public Stream{
public:

	virtual virtual void Read(){
		cout << "�ļ��Ѿ�����ȡ" << endl;
	}
	
	virtual void Seek(){
		cout << "�ļ��Ѿ�����λ" << endl;
	}

	virtual void Write(){
		cout << "�ļ��Ѿ���д��" << endl;
	}
};

//������
class NetworkStream :public Stream{
public:
	virtual virtual void Read(){
		cout << "�ļ��Ѿ�����ȡ" << endl;
	}

	virtual void Seek(){
		cout << "�ļ��Ѿ�����λ" << endl;
	}

	virtual void Write(){
		cout << "�ļ��Ѿ���д��" << endl;
	}
};


class MemoryStream :public Stream{
public:
	virtual virtual void Read(){
		cout << "�ļ��Ѿ�����ȡ" << endl;
	}

	virtual void Seek(){
		cout << "�ļ��Ѿ�����λ" << endl;
	}

	virtual void Write(){
		cout << "�ļ��Ѿ���д��" << endl;
	}
};


/*********��չ����************/

class DecoratorStream :public Stream{
protected:
	Stream* stream;  //ǿ��Ķ�ָ̬�룬����ʱװ��,����ʱһ��������ʱ��һ��
	DecoratorStream(Stream* stm) :stream(stm){
	}
};

//���ܲ���
class CryptoStream :public DecoratorStream{  //����Stream��ָ��Ҳ��Stream�Ļ���
	
public:

	CryptoStream(Stream* stm) :DecoratorStream(stm){
	}

	virtual void Read(){
		cout << "�ļ��Ѿ���������" << endl;
		stream->Read();
	}

	virtual void Seek(){
		cout << "�ļ��Ѿ���������" << endl;
		stream->Seek();
	}

	virtual void Write(){
		cout << "�ļ��Ѿ���������" << endl;
		stream->Write();
	}

};

//�������
class BuffertoStream :public DecoratorStream{

public:

	BuffertoStream(Stream* stm) :DecoratorStream(stm){
	}

	virtual void Read(){
		cout << "�ļ��Ѿ���������" << endl;
		stream->Read();
	}

	virtual void Seek(){
		cout << "�ļ��Ѿ���������" << endl;
		stream->Seek();
	}

	virtual void Write(){
		cout << "�ļ��Ѿ���������" << endl;
		stream->Write();
	}

};

int main()
{

	FileStream* s1 = new FileStream();  //����ʱװ�䣬����ʱ�����ڸ��ֲ�ͬ�����Լ���ͬ��������
	s1->Read();

	CryptoStream* s2 = new CryptoStream(s1); //���ļ�������
	s2->Read();

	BuffertoStream* s3 = new  BuffertoStream(s1); //���ļ�������
	s3->Read();

	BuffertoStream* s4 = new  BuffertoStream(s2); //���ļ����Ȼ����ټ���
	s4->Read();

	return 0;
}