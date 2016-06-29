#pragma once
#include "nativefunction.h"
extern Object_ptr List;
extern Object_ptr Listc;
extern Object_ptr List_len;
inline Object_ptr len_sub(Object_ptr& a)
{
	return toObject((int)getnativevalue(a, std::vector<Object_ptr>).size());
}
Object_ptr at_sub(std::vector<Object_ptr>&);
#ifdef OPT
inline Object_ptr dList_sub(Object_ptr v1) {
	return Listc(len_sub(v1), inputArgument(new nativefunction(2, at_sub),v1));
}
#else
inline Object_ptr dList_sub(Object_ptr v1) {
	return Listc(len_sub(v1), inputArgument(Object_ptr(new nativefunction(2, at_sub)), v1));
}
#endif
inline Object_ptr dList() {
	return dList_sub(Object_ptr(new nativeclass<std::vector<Object_ptr>>(std::vector<Object_ptr>())));
};
inline Object_ptr dList(std::vector<Object_ptr>& v) {
	return dList_sub(toObject(v));
}
template<class... T>
Object_ptr dList(T... k) {
	nativeclass<std::vector<Object_ptr>>* v(new nativeclass<std::vector<Object_ptr>>(std::vector<Object_ptr>()));
	push_back(v->value, k...);
	return dList_sub(Object_ptr(v));
};
