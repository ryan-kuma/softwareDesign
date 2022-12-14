
//Decorator 模式


class Stream{
public:
	virtual char Read(int number) = 0;
	virtual char Seek(int position) = 0;
	virtual char write(char data) = 0;

	virtual ~stream(){}
};

//文件流
class FileStream: public Stream {
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
class CryptoStream:public Stream {
private:
	Stream* stream; //=new filestream
public: 
	CryptoStream(Stream *_stream):stream(_stream){};

	virtual char read(int number) {
		stream->read(number); 
	}
 
	virtual char seek(int position) {
		//额外的加密操作
		stream->seek(position);
		//额外的解密操作
	}

	virtual char write(char data) {
		//额外的加密操作
		stream->write(data);
		//额外的解密操作
	}
};

//缓冲处理
class BufferStream : public Stream{
private:
	Stream* stream; 
public:
	BufferStream(Stream* _stream):stream(_stream){}

	virtual char read(int number) {
		stream->read(number); 
	}
 
	virtual char seek(int position) {
		//额外的缓冲操作
		stream->seek(position);
		//额外的缓冲操作
	}

	virtual char write(char data) {
		//额外的缓冲操作
		stream->write(data);
		//额外的缓冲操作
	}

};

/*
//即加密又缓冲操作
class CryptoBufferedStream:public Stream {
private:
	Stream *stream;
public:
	CryptoBufferedStream(Stream *_stream):stream(_stream){}
	virtual char read(int number) {
		stream->read(number); 
	}
 
	virtual char seek(int position) {
		//额外的加密操作
		//额外的缓冲操作
		stream->seek(position);
		//额外的解密操作
		//额外的缓冲操作
	}

	virtual char write(char data) {
		//额外的加密操作
		//额外的缓冲操作
		stream->write(data);
		//额外的解密操作
		//额外的缓冲操作
	}
 
}
*/

void Process()
{
	//编译时装配
 	CryptoFileStream *fs1 = new CryptoFileStream();
	BufferMemoryStream *bm1 = new BufferMemoryStream();
	CryptoBufferedFileStream *fs3 = new CryptoBufferedFileStream();

	//运行时装配
	FileStream *s1 = new FileStream();
	CryptoStream *cs1 = new CryptoStream(s1); 
	BufferStream *bs1 = new BufferStream(s1);
	BufferStream *bs2 = new BufferStream(cs1);

}
