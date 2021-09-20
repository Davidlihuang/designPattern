#include "subject.h"
Subject::Subject(){}
Subject::~Subject(){}

void Subject::attach(Observer* pObserver)
{
    m_vtObj.push_back(pObserver);
}

void Subject::dettach(Observer* pObserver)
{
    for(vector<Observer*>::iterator iter = m_vtObj.begin(); iter != m_vtObj.end(); iter++)
    {
        if(*iter == pObserver)
        {
            m_vtObj.erase(iter);
            return;
        }
    }
}

void Subject::notify()
{
    for(vector<Observer*>::iterator iter = m_vtObj.begin(); iter != m_vtObj.end(); iter++)
    {
        (*iter)->update(this);
    }     
}
