#pragma once
#include "nativefunction.h"
extern Object_ptr List;
extern Object_ptr Listc;
Object_ptr dList();
Object_ptr dList(std::vector<Object_ptr>& v);
Object_ptr dList_sub(Object_ptr v);
template<class... T>
Object_ptr dList(T... k) {
	nativeclass<std::vector<Object_ptr>>* v(new nativeclass<std::vector<Object_ptr>>(std::vector<Object_ptr>()));
	push_back(v->value, k...);
	return dList_sub(Object_ptr(v));
};
