#include "observer.h"
#include "subject.h"
#include "concreteObserver.h"
#include <string>
#include <iostream>
using namespace std;

ConcreteObserver::ConcreteObserver(const string& name): m_objName(name){ }
ConcreteObserver::~ConcreteObserver() {}
void ConcreteObserver::update(Subject* sub)
{
    m_observerState = sub->getState();
    cout << "update obsesrver[" << m_objName << "] state: " << m_observerState << endl;
}

    
    


