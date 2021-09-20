#include "concreteSubject.h"

ConcreteSubject::ConcreteSubject():m_state(0){}
ConcreteSubject::~ConcreteSubject(){}
void ConcreteSubject::setState(int i)
{
     m_state = i;
}
int ConcreteSubject::getState()
{
    return m_state;
}