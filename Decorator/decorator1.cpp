
//Decorator 模式


class Stream{
public:
	virtual char Read(int number) = 0;
	virtual char Seek(int position) = 0;
	virtual char write(char data) = 0;

	virtual ~stream(){}
};

//文件流
class fileStream: public Stream {
public:
	virtual char read(int number) {
	 
	}
 
	virtual char seek(int position) {
	 
	}

	virtual char write(char data) {
	 
	}
};

//网络流
class networkStream: public Stream {
public: 
	virtual char read(int number) {
	 
	}
 
	virtual char seek(int position) {
	 
	}

	virtual char write(char data) {
	 
	}
};

//内存流
class memoryStream: public Stream {
public: 
	virtual char read(int number) {
	 
	}
 
	virtual char seek(int position) {
	 
	}

	virtual char write(char data) {
	 
	}
};

//扩展操作
class CryptoFileStream: public FileStream{
public: 
	virtual char read(int number) {
		FileStream::read(number); 
	}
 
	virtual char seek(int position) {
		//额外的加密操作
		FileStream::seek(position);
		//额外的解密操作
	}

	virtual char write(char data) {
		//额外的加密操作
		FileStream::write(data);
		//额外的解密操作
	}
};

class CryptoNetworkStream: public networkStream{
public: 
	virtual char read(int number) {
		networkStream::read(number);
	}
 
	virtual char seek(int position) {
		//额外的加密操作
		networkStream::seek(position);
		//额外的解密操作
	}

	virtual char write(char data) {
		//额外的加密操作
		networkStream::write(data);
		//额外的解密操作
	}
};


class CryptoMemoryStream: public memoryStream{
public: 
	virtual char read(int number) {
		memoryStream::read(number);
	}
 
	virtual char seek(int position) {
		//额外的加密操作
		memoryStream::seek(position);
		//额外的解密操作
	}

	virtual char write(char data) {
		//额外的加密操作
		memoryStream::write(data);
		//额外的解密操作
	}
};

//缓冲处理
class BufferFileStream: public FileStream{
 
};
class BufferNetworkStream: public networkStream{
 
};
class BufferMemoryStream: public memoryStream{
 
};

//即加密又缓冲操作
class CryptoBufferedFileStream:public FileStream {
public:
	virtual char read(int number) {
		FileStream::read(number); 
	}
 
	virtual char seek(int position) {
		//额外的加密操作
		//额外的缓冲操作
		FileStream::seek(position);
		//额外的解密操作
		//额外的缓冲操作
	}

	virtual char write(char data) {
		//额外的加密操作
		//额外的缓冲操作
		FileStream::write(data);
		//额外的解密操作
		//额外的缓冲操作
	}
 
}

void Process()
{
 	CryptoFileStream *fs1 = new CryptoFileStream();
	BufferMemoryStream *bm1 = new BufferMemoryStream();
	CryptoBufferedFileStream *fs3 = new CryptoBufferedFileStream();

}
