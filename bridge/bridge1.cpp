class Messager{
public:
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(Image image) = 0;

	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~Messager(){}
};

//PC平台设计
class PCMessagerBase : public Messager{
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
class MobileMessagerBase : public Messager{
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
class PCMessagerLite : public PCMessagerBase {
public:
	virtual void Login(string username, string password) {
		PCMessagerBase::Connect();	
	}
	virtual void SendMessage(string message) {
		PCMessagerBase::WriteText();	
	}
	virtual void SendPicture(Image image) {
		PCMessagerBase::DrawShape();
	}
};

//华丽版
class PCMessagerPerfect : public PCMessagerBase {
public:
	virtual void Login(string username, string password) {
		PCMessagerBase::PlaySound();
		PCMessagerBase::Connect();	
	}
	virtual void SendMessage(string message) {
		PCMessagerBase::PlaySound();
		PCMessagerBase::WriteText();	
	}
	virtual void SendPicture(Image image) {
		PCMessagerBase::PlaySound();
		PCMessagerBase::DrawShape();
	}
};

class MobileMessagerLite : public MobileMessagerBase {
public:
	virtual void Login(string username, string password) {
		MobileMessagerBase::Connect();	
	}
	virtual void SendMessage(string message) {
		MobileMessagerBase::WriteText();	
	}
	virtual void SendPicture(Image image) {
		MobileMessagerBase::DrawShape();
	}
};

//华丽版
class MobileMessagerPerfect : public MobileMessagerBase {
public:
	virtual void Login(string username, string password) {
		MobileMessagerBase::PlaySound();
		MobileMessagerBase::Connect();	
	}
	virtual void SendMessage(string message) {
		MobileMessagerBase::PlaySound();
		MobileMessagerBase::WriteText();	
	}
	virtual void SendPicture(Image image) {
		MobileMessagerBase::PlaySound();
		MobileMessagerBase::DrawShape();
	}
};
