#include <iostream>
#include <string>
#include "subject.h"
#include "concreteSubject.h"
#include "observer.h"
#include "concreteObserver.h"
using namespace std;

int main()
{
    Subject* subject = new ConcreteSubject();
    Observer* objA = new  ConcreteObserver("obsv1");
    Observer* objB = new ConcreteObserver("obsv2");
   
    subject->attach(objA);
    subject->attach(objB);

    subject->setState(1);
    subject->notify();

    cout << "-----------------" << endl;
    subject->dettach(objB);
    subject->setState(2);
    subject->notify();

    delete subject;
    delete objB;
    delete objA;
   
    return 0;
}

