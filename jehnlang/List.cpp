#include "List.h"



List::List():argumentfunction(1)
{
}


List::~List()
{
}

shared_ptr<Object> dList::len()
{
	return shared_ptr<Object>(new Object(v.size()));
}

dList::dList():Listc(nullptr, shared_ptr<Object>(new nativenoArgumentFunction(this->len)),this->at){
}
