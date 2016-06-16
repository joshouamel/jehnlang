#pragma once
#include "Object.h"
template<class T>
class nativeclass:public Object {
public:
	nativeclass(const T& k) :value(k) {}
	nativeclass(const T&&k) :value(k){}
	T value;
};
#define toObject(k) Object_ptr(new nativeclass<decltype(k)>(k))
