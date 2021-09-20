////////////////////////////////////////////////////////////////////////////
// observer.h
// implementation of class obsesrver
// created on 10-5月-2021 22:29
// original author:c1
////////////////////////////////////////////////////////////////////////////

#ifndef observer_h_
#define observer_h_

class Subject;
class Observer
{
public:
    Observer();
    virtual ~Observer();
    virtual void update(Subject* sub)=0;
};

#endif



