class ISplitter{
public:
	virtual void split() = 0;
	virtual ISplitter *clone() = 0; //通过clone自己创建对象

	virtual ~ISplitter(){}
};

//具体类
class BinarySplitter:public ISplitter{
public:
//通过拷贝构造函数创建对象
	virtual ISplitter* clone(){
		return new BinarySplitter(*this); 
	}
};

class TxtSplitter: public ISplitter{
public:
	virtual ISplitter* clone(){
		return new TxtSplitter(*this); 
	}
};

class PictureSplitter: public ISplitter{
public:
	virtual ISplitter* clone(){
		return new PictureSplitter(*this); 
	}
};

class VideoSplitter: public ISplitter{
public:
	virtual ISplitter* clone(){
		return new VideoSplitter(*this); 
	}
};

//具体工厂
class MainForm:public Form
{
	ISplitter *prototype;
public:
	MainForm(ISplitter* prototype){
	 	this->prototype = prototype;
	}

	void btnClick(){
		//使用clone方法
		ISplitter *splitter = prototype->clone();//多态new
		splitter->splite();
	}
};
