#pragma once
#include "Object.h"
template<class T>
class nativeclass:public Object {
public:
	nativeclass(const T& k) :value(k) {}
	nativeclass(const T&&k) :value(k){}
	Object_ptr clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&) {
		return nullptr;
	}
	T value;
};
#define toObject(k) Object_ptr(new nativeclass<std::remove_reference<decltype(k)>::type>(k))
#define getnativevalue(a,b) ((nativeclass<b>*)(a).get())->value
