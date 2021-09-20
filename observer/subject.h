#ifndef subject_h_
#define subject_h_
#include "observer.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Subject
{
public:
   Subject();
   virtual ~Subject();
   Observer* m_Observer;
   void attach(Observer* pObserver);
   void dettach(Observer* pObserver);
   void notify();

   virtual int getState()=0;
   virtual void setState(int i)=0;

private:
   vector<Observer*> m_vtObj;
};

#endif
