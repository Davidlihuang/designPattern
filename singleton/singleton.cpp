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
