#pragma once
#include "nativefunction.h"
class List :
	public argumentfunction
{
public:
	List();
	~List();
};
class Listc :
	public List
{
protected:
public:
	Object_ptr l; Object_ptr i; Object_ptr o;
	Listc(Object_ptr l, Object_ptr i);
	Listc( Object_ptr l, Object_ptr i, Object_ptr o);
};
class dList :
	public Listc
{
	template<class S,class... T>
	void push_back(S a,T... b) {
		v.push_back(a);
		push_back(b...);
	}
	template<class S>
	void push_back(S a) {
		v.push_back(a);
	}
public:
	template<class... T>
		dList(T... k):dList() {
			push_back(k...); };
		dList();
	std::vector<Object_ptr> v;
};
