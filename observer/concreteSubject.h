#ifndef concreteSubject_h_
#define concreteSubject_h_
#include "subject.h"

class ConcreteSubject:public Subject
{
public:
    ConcreteSubject();
    virtual ~ConcreteSubject();
    virtual void setState(int i);
    virtual int getState();
private:
    int m_state;
};
#endif