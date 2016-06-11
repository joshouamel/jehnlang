#include "nativeclass.h"

shared_ptr<Object> toObject(int a)
{
	shared_ptr<nativeInt> r(new nativeInt);
	r->value = a;
	return r;
}
shared_ptr<Object> toObject(bool a)
{
	shared_ptr<nativeBool> r(new nativeBool);
	r->value = a;
	return r;
}
shared_ptr<Object> toObject(double a)
{
	shared_ptr<nativeFloat> r(new nativeFloat);
	r->value = a;
	return r;
}