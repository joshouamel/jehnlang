#pragma once
#include "func.h"
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
	shared_ptr<Object> l; shared_ptr<argumentfunction> i; shared_ptr<argumentfunction> o;
public:
	Listc( shared_ptr<Object> l, shared_ptr<argumentfunction> i, shared_ptr<argumentfunction> o);
};
class dList :
	public Listc
{
	shared_ptr<Object> len();
	shared_ptr<Object> at(shared_ptr<Object>);
public:
	dList();
	std::vector<shared_ptr<Object>> v;
};
