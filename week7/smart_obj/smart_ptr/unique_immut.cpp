//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr
{
unique_immut::unique_immut()
{
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj)
{
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut)
{
    if (immut._mgr)
    {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut()
{
    release();
}

Object *unique_immut::get() const
{
    if (this->_mgr == nullptr)
        return nullptr;
    return this->_mgr->ptr;
}

void unique_immut::release()
{
    if (_mgr != nullptr)
    {
        delete (_mgr->ptr);
        this->_mgr->ptr = nullptr;
    }
}

unique_immut unique_immut::operator+(unique_immut &unique)
{
    int tmp1 = this->_mgr->ptr->get();
    int tmp2 = unique._mgr->ptr->get();
    Object *tmpobj = new Object(tmp1 + tmp2);
    release();
    unique.release();
    return unique_immut(tmpobj);
}
unique_immut unique_immut::operator-(unique_immut &unique)
{
    int tmp1 = this->_mgr->ptr->get();
    int tmp2 = unique._mgr->ptr->get();
    Object *tmpobj = new Object(tmp1 - tmp2);
    release();
    unique.release();
    return unique_immut(tmpobj);
}
unique_immut unique_immut::operator*(unique_immut &unique)
{
    int tmp1 = this->_mgr->ptr->get();
    int tmp2 = unique._mgr->ptr->get();
    Object *tmpobj = new Object(tmp1 * tmp2);
    release();
    unique.release();
    return unique_immut(tmpobj);
}
unique_immut unique_immut::operator/(unique_immut &unique)
{
    int tmp1 = this->_mgr->ptr->get();
    int tmp2 = unique._mgr->ptr->get();
    Object *tmpobj = new Object(tmp1 / tmp2);
    release();
    unique.release();
    return unique_immut(tmpobj);
}

unique_immut &unique_immut::operator=(unique_immut &r)
{
    // if (this->_mgr->ptr == r._mgr->ptr)
    // {
    //     return *this;
    // }
    // else
    // {
    //     release();
    //     _mgr = new mgr(r.get());
    // }
    this->_mgr->ptr = r._mgr->ptr;
}

Object *unique_immut::operator->()
{
    int tmp = this->_mgr->ptr->get();
    Object *tmpobj = new Object(tmp);
    return tmpobj;
}

} // end of namespace ptr
