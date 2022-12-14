class Singleton{
private:
	Singleton();
	Singleton(const Singleton& other);
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

//非线程安全
Singleton* Singleton::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new Singleton();
	return m_instance;
}

//线程安全版本，但是锁的代价过高
Singleton* Singleton::getInstance()
{
	Lock lock;
	if (m_instance == nullptr)
		m_instance = new Singleton();
	return m_instance;
}

//双检查锁，单由于读写reorder不安全
Singleton* Singleton::getInstance()
{
	if (m_instance == nullptr) {
		Lock lock; 
		if (m_instance == nullptr)
			m_instance = new Singleton();
	}
	return m_instance;
}

//安全的双检查锁
//c++11安全的跨平台实现
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
	Singleton *tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
	if(tmp == nullptr)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if(tmp == nullptr) {
			tmp = new Singleton;
			std::atomic_thread_fence(std::memory_order_release); //释放内存
			m_instance.store(tmp, std::memory_order_relaxed);
		 
		}
	}
	return tmp;
}

