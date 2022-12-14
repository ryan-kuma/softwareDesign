class ISplitter{
public:
	virtual void split() = 0;
	virtual ~ISplitter(){}
};

//具体类
class BinarySplitter:public ISplitter{
 
};

class TxtSplitter: public ISplitter{
 
};

class PictureSplitter: public ISplitter{
 
};

class VideoSplitter: public ISplitter{
 
};

//使用虚函数避免依赖关系
class SplitterFactory{
public:
	virtual ISplitter *CreateSplitter() = 0;
	virtual ~SplitterFactory(){}
};

//具体工厂
class BinarySplitterFactory: public SplitterFactory{
public:
	virtual ISplitter* CreateSplitter() {
	 	return new BinarySplitter();
	}
}

class TxtSplitterFactory: public SplitterFactory{
public:
	virtual ISplitter* CreateSplitter() {
	 	return new TxtSplitter();
	}
}


class PictureSplitterFactory: public SplitterFactory{
public:
	virtual ISplitter* CreateSplitter() {
	 	return new PictureSplitter();
	}
}

class VideoSplitterFactory: public SplitterFactory{
public:
	virtual ISplitter* CreateSplitter() {
	 	return new VideoSplitter();
	}
}

class MainForm:public Form
{
	SplitterFactory *factory;
public:
	MainForm(SplitterFactory* factory){
	 	this->factory = factory;
	}

	void btnClick(){
		//使用new构造对象有依赖关系
		ISplitter *splitter = new BinarySplitter();

		//使用工厂方法
		ISplitter *splitter = factory->CreateSplitter();//多态new
		splitter->splite();
	}
};
