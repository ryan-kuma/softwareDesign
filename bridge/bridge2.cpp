class Messager{
private:
	MessagerImp *messagerImp;
public:
	Messager(MessagerImp* msgImp):messagerImp(msgImp){};
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(Image image) = 0;

	virtual ~Messager(){}
};

//平台实现
class MessagerImp{
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~MessagerImp(){}
 
};

//PC平台设计
class PCMessagerBase : public MessagerImp{
public:
	virtual void PlaySound(){
	 
	}
	virtual void DrawShape() {
	 
	}
	virtual void WriteText() {

	}
	virtual void Connect() {

	}
};

//Mobile平台设计
class MobileMessagerBase : public MessagerImp{
public:
	virtual void PlaySound(){
	 
	}
	virtual void DrawShape() {
	 
	}
	virtual void WriteText() {

	}
	virtual void Connect() {

	}
};

//业务抽象
//轻奢版
class MessagerLite : public Messager{
public:
	MessagerLite(MessagerImp* _msg):Messager(_msg){}
	virtual void Login(string username, string password) {
		messagerImp->Connect();	
	}
	virtual void SendMessage(string message) {
		messagerImp->writeText();	
	}
	virtual void SendPicture(Image image) {
		messagerImp->DrawShape();
	}
};

//华丽版
class MessagerPerfect : public Messager{
public:
	MessagerPerfect(MessagerImp* _msg):Messager(_msg){}
	virtual void Login(string username, string password) {
		messagerImp->PlaySound();
		messagerImp->Connect();	
	}
	virtual void SendMessage(string message) {
		messagerImp->PlaySound();
		messagerImp->WriteText();	
	}
	virtual void SendPicture(Image image) {
		messagerImp->PlaySound();
		messagerImp->DrawShape();
	}
};

void Process() {
	//编译时装配
	Messager *m = new MobileMessagerPerfect();
	//运行时装配
	MessagerIp *pcMsg = new PCMessagerBase();
	Messager *m = new MessagerPerfect(pcMsg);
 
}
