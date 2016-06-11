#pragma once
#include "Object.h"
template<class T>
class nativeclass {
public:
	T value;
};
class nativeInt :public Object {
public:
	int value;
};
class nativeBool :public Object {
public:
	bool value;
};
class nativeFloat :public Object {
public:
	double value;
};
shared_ptr<Object> toObject(int);
shared_ptr<Object> toObject(bool);
shared_ptr<Object> toObject(double);
