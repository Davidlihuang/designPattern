#include <iostream>
#include <atomic>
#include <string>
using namespace std;

class Singleton
{
public:
    static Singleton* m_instance;
    static Singleton* getInstance();
private:
    Singleton():name("huangli"),age(24),salary(10000){}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
public:
    string name;
    int age;
    int salary;
};

Singleton* Singleton::m_instance = nullptr;

//非线程安全

Singleton* Singleton::getInstance()
{
    if(nullptr == m_instance)
    {
        m_instance = new Singleton();
    }
    return m_instance;
}

/*
//线程安全
Singleton* Singleton::getInstance()
{
   Lock lock;
   if(nullptr == m_instance)
   {
       m_instance = new Singleton;
   }
   return m_instance;
}
//双检查锁
Singleton* Singleton::getInstance()
{
   if(nullptr == m_instance)
   {
      Lock lock;
      if(nullptr == m_instance)
      {
          m_instance = new Singleton;
      }
   }
   return m_instance;
}
//c++11跨平台
std::atomic<Singleton*> SingleTon::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance()
{
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);// 获取内存fence,防止reorder
    if(tmp == nullptr)
    {
       std::lock_guard<std::mutex> lock(m_mutex);
       tmp = m_instance.load(std::memory_order_relaxed);
       if(tmp == nullptr)
       {
           tmp = new Singleton;
	   std::atomic_thread_fence(std::memory_order_release);//释放内存fence
	   m_instance.store(tmp,std::memory_order_relaxed);
       }
    }
    return tmp;
}
*/
int main()
{
    Singleton* instance0 = Singleton::getInstance();
    Singleton* instance1 = Singleton::getInstance();
    
    cout <<"addr&:"<< instance0 <<"name:" <<instance0->name << "age:"\
	    << instance0->age << "salary:" << instance0->salary; 
    cout <<"\naddr&:"<<instance1 <<"name:" <<instance1->name << "age:"\
	    << instance1->age << "salary:" << instance1->salary; 
    cout << endl;
    return 0;
}
