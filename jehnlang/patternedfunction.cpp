#include "patternedfunction.h"
#include "c++assist.h"
shared_ptr<std::vector<Object_ptr>> empty_vector(new std::vector<Object_ptr>);
shared_ptr<std::vector<Object_ptr>> castpattern::getpattern(Object_ptr o)
{
	Object* o1;
	while (true) {
		if (!(o1 = dynamic_cast<unCalcedData*>(o.get())))
			return nullptr;
		int sz = ((unCalcedData*)o1)->lst.size();
		if (sz < this->len);
		//맞음 이제 리턴만 하면 됨
		else if (((unCalcedData*)o1)->basefunction == basefunction) {
			if (sz > this->len)
				return nullptr;
			shared_ptr<std::vector<Object_ptr>> res;
			int i;
			for (i = 0; i < sz; i++) {
				Object_ptr ot = ((unCalcedData*)o1)->lst[i];
				if (ot.get()) {
					if(!(res = this->o[i].getpattern(ot)).get())return nullptr;
					if (res == empty_vector)
						continue;
					break;
				}
			}
			for (; ++i < sz; ) {
				shared_ptr<std::vector<Object_ptr>> ot = this->o[i].getpattern(((unCalcedData*)o1)->lst[i]);
				if (!ot.get())
					return nullptr;
				res->insert(res->end(), ot->begin(), ot->end());
			}
			return res;
		}
		o = ((unCalcedData*)o1)->calc();
	}
}
#define nativetypeis(a,b) (!!(dynamic_cast<nativeclass<b>*>(a.get())))

shared_ptr<std::vector<Object_ptr>> boolpattern::getpattern(Object_ptr o)
{
	o = getObject(f(o) == toObject(true));
	if (nativetypeis(o, bool))
		if (getnativevalue(o, bool))
			return shared_ptr<std::vector<Object_ptr>>(new std::vector<Object_ptr>(1, o));
	return nullptr;
}

shared_ptr<std::vector<Object_ptr>> listpattern::getpattern(Object_ptr o)
{
	o = getObject(o);
	Object* o1 =o.get();
	if (!o1)
		return nullptr;
	o1= dynamic_cast<poofunction*>(o1);
	if (!o1)
		return nullptr;
	if (((poofunction*)o1)->basefunction != List)
		return nullptr;
	if (((poofunction*)o1)->lst.size() != 3)
		return nullptr;
	
	shared_ptr<std::vector<Object_ptr>> res = this->o[0].getpattern(o(toObject(0)));
	for (int i = 1; i < len; i++) {
		shared_ptr<std::vector<Object_ptr>> ot = this->o[i].getpattern(o(toObject(i)));
		if (!ot.get())
			return nullptr;
		res->insert(res->end(), ot->begin(), ot->end());
	}
	return res;
}

shared_ptr<std::vector<Object_ptr>> listduppattern::getpattern(Object_ptr o)
{
	o = getObject(o);
	Object* o1 = o.get();
	if (!o1)
		return nullptr;
	o1 = dynamic_cast<poofunction*>(o1);
	if (!o1)
		return nullptr;
	if (((poofunction*)o1)->basefunction != List)
		return nullptr;
	if (((poofunction*)o1)->lst.size() != 3)
		return nullptr;

	shared_ptr<std::vector<Object_ptr>> res = this->o[0].getpattern(o(toObject(0)));
	for (int i = 1; i < len; i++) {
		shared_ptr<std::vector<Object_ptr>> ot = this->o[i].getpattern(o(toObject(i)));
		if (!ot.get())
			return nullptr;
		res->insert(res->end(), ot->begin(), ot->end());
	}
	return res;
}

Object_ptr patternedfunction::inputArgument(Object_ptr o, Object_ptr)
{
	shared_ptr<std::vector<Object_ptr>> t = this->o[0].getpattern(o);
	if (!(t.get()))
		return nullptr;
	return Object_ptr(new unCalcedData(targ, *t));
}

Object_ptr patternedfunction::inputArgument(std::vector<Object_ptr>&o, Object_ptr)
{
	shared_ptr<std::vector<Object_ptr>> t = this->o[0].getpattern(o[0]);
	if (!(t.get()))
		return nullptr;
	for (int i = 1; i < o.size(); i++) {
		shared_ptr<std::vector<Object_ptr>> ot = this->o[i].getpattern(o[0]);
		if (!(ot.get()))
			return nullptr;
		t->insert(t->begin(), ot->begin(), ot->end());
	}
	return Object_ptr(new unCalcedData(targ, *t));
}

shared_ptr<std::vector<Object_ptr>> pattern::getpattern(Object_ptr)
{
	return empty_vector;
}

shared_ptr<std::vector<Object_ptr>> echopattern::getpattern(Object_ptr o)
{
	return shared_ptr<std::vector<Object_ptr>>(new std::vector<Object_ptr>(1,o));
}
