//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr
{

shared_mut::shared_mut()
{
    _mgr = new mgr();
}

shared_mut::shared_mut(Object *_obj)
{
    _mgr = new mgr(_obj);
}

shared_mut::~shared_mut()
{
    release();
}

Object *shared_mut::get() const
{
    if (this->_mgr == nullptr)
        return nullptr;
    return this->_mgr->ptr;
}

void shared_mut::release()
{
    if (--_mgr->count == 0)
    {
        delete (_mgr->ptr);
        this->_mgr->ptr = nullptr;
    }
}

int shared_mut::count()
{
    return this->_mgr->count;
}

shared_mut shared_mut::operator+(const shared_mut &shared)
{
    int tmp1 = this->_mgr->ptr->get();
    int tmp2 = shared._mgr->ptr->get();
    Object *tmpobj = new Object(tmp1 + tmp2);
    return shared_mut(tmpobj);
}

shared_mut shared_mut::operator-(const shared_mut &shared)
{
    int tmp1 = this->_mgr->ptr->get();
    int tmp2 = shared._mgr->ptr->get();
    Object *tmpobj = new Object(tmp1 - tmp2);
    return shared_mut(tmpobj);
}

shared_mut shared_mut::operator*(const shared_mut &shared)
{
    int tmp1 = this->_mgr->ptr->get();
    int tmp2 = shared._mgr->ptr->get();
    Object *tmpobj = new Object(tmp1 * tmp2);
    return shared_mut(tmpobj);
}

shared_mut shared_mut::operator/(const shared_mut &shared)
{
    int tmp1 = this->_mgr->ptr->get();
    int tmp2 = shared._mgr->ptr->get();
    Object *tmpobj = new Object(tmp1 / tmp2);
    return shared_mut(tmpobj);
}

Object *shared_mut::operator->()
{
    int tmp = this->_mgr->ptr->get();
    Object *tmpobj = new Object(tmp);
    return tmpobj;
    // _mgr->ptr 처럼 3번 가는거 한번에 리턴할 수 있도록.
}

shared_mut &shared_mut::operator=(const shared_mut &r)
{
    release();
    // mgr* tmpmgr = new mgr(r.get());
    _mgr = new mgr(r.get());
    increase();
}

void shared_mut::increase()
{
    this->_mgr->count += 1;
}

} // end of namespace ptr
