#ifndef concreteObserver_h_
#define concreteObserver_h_
#include <string>
#include "observer.h"

class ConcreteObserver: public Observer
{
public:
    ConcreteObserver(const std::string& name);
    virtual ~ConcreteObserver();
    virtual void update(Subject* sub);
private:
    std::string m_objName;
    int m_observerState;
};
#endif
