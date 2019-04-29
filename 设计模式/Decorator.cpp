/********装饰器模式***********/

#include "stdafx.h"
#include <iostream>

using namespace std;

/***********应用场景假设为流操作************/

//抽象基类
class Stream{
public:
	virtual void Read() = 0; 
	virtual void  Seek() = 0;
	virtual void Write() = 0;

	virtual ~Stream(){}

};
	

/********具体业务操作********/

//主体类
class FileStream :public Stream{
public:

	virtual virtual void Read(){
		cout << "文件已经被读取" << endl;
	}
	
	virtual void Seek(){
		cout << "文件已经被定位" << endl;
	}

	virtual void Write(){
		cout << "文件已经被写入" << endl;
	}
};

//主体类
class NetworkStream :public Stream{
public:
	virtual virtual void Read(){
		cout << "文件已经被读取" << endl;
	}

	virtual void Seek(){
		cout << "文件已经被定位" << endl;
	}

	virtual void Write(){
		cout << "文件已经被写入" << endl;
	}
};


class MemoryStream :public Stream{
public:
	virtual virtual void Read(){
		cout << "文件已经被读取" << endl;
	}

	virtual void Seek(){
		cout << "文件已经被定位" << endl;
	}

	virtual void Write(){
		cout << "文件已经被写入" << endl;
	}
};


/*********扩展操作************/

class DecoratorStream :public Stream{
protected:
	Stream* stream;  //强大的多态指针，运行时装配,编译时一样，运行时不一样
	DecoratorStream(Stream* stm) :stream(stm){
	}
};

//加密操作
class CryptoStream :public DecoratorStream{  //既有Stream的指针也有Stream的基类
	
public:

	CryptoStream(Stream* stm) :DecoratorStream(stm){
	}

	virtual void Read(){
		cout << "文件已经被加密了" << endl;
		stream->Read();
	}

	virtual void Seek(){
		cout << "文件已经被加密了" << endl;
		stream->Seek();
	}

	virtual void Write(){
		cout << "文件已经被加密了" << endl;
		stream->Write();
	}

};

//缓冲操作
class BuffertoStream :public DecoratorStream{

public:

	BuffertoStream(Stream* stm) :DecoratorStream(stm){
	}

	virtual void Read(){
		cout << "文件已经被缓冲了" << endl;
		stream->Read();
	}

	virtual void Seek(){
		cout << "文件已经被缓冲了" << endl;
		stream->Seek();
	}

	virtual void Write(){
		cout << "文件已经被缓冲了" << endl;
		stream->Write();
	}

};

int main()
{

	FileStream* s1 = new FileStream();  //运行时装配，编译时不存在各种不同类型以及不同操作的流
	s1->Read();

	CryptoStream* s2 = new CryptoStream(s1); //将文件流加密
	s2->Read();

	BuffertoStream* s3 = new  BuffertoStream(s1); //将文件流缓冲
	s3->Read();

	BuffertoStream* s4 = new  BuffertoStream(s2); //将文件流先缓冲再加密
	s4->Read();

	return 0;
}