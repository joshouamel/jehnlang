#include "func.h"

func::func(int argnum):argnum(argnum){}

argumentfunction::argumentfunction(int i):func(i)
{
	for (int j = 0; j < i; j++)
		arglst.push_back( Object_ptr(shared_ptr<forArgument>(new forArgument())));
}

Object_ptr argumentfunction::clone(std::vector<Object_ptr>&v1, std::vector<Object_ptr>&v2)
{
	if (&v1 == &arglst)
		return nullptr;
	Object_ptr t=targ->clone(v1,v2);
	if (t) {
		argumentfunction* a=new argumentfunction(argnum);
		std::vector<Object_ptr> v3;
		std::vector<Object_ptr> v4;
		for (int i = 0; i < arglst.size();i++)v3.push_back(Object_ptr(arglst[i]));
		for (int i = 0; i < arglst.size(); i++)v4.push_back(Object_ptr(a->arglst[i]));
		a->targ = t->clone(v3, v4);
		if (a->targ)
			return Object_ptr(a);
		a->targ = t;
		return Object_ptr(a);
	}
	return nullptr;
}

Object_ptr argumentfunction::arg(int i)
{
	return Object_ptr(arglst[i]);
}

Object_ptr argumentfunction::inputArgument(std::vector<Object_ptr>& v)
{
	Object_ptr base = getObject(targ.clone(arglst, v));
	return base;
}

Object_ptr func_ptr::inputArgument(std::vector<Object_ptr>& v)
{
	if (!this->get())
		return nullptr;
	if ((*this)->argnum < v.size()) return nullptr;
	if ((*this)->argnum > v.size()) {
		argumentfunction* f(new argumentfunction((*this)->argnum-v.size()));
		shared_ptr<unCalcedData> u(new unCalcedData());
		u->basefunction = Object_ptr(*this);
		u->lst =v;
		u->lst.insert(u->lst.end(), f->arglst.begin(), f->arglst.end());
		f->targ = Object_ptr(u);
		return func_ptr(shared_ptr<func>(f));
	}
	return (*this)->inputArgument(v);

}
/*
argumentrequiredfunction::argumentrequiredfunction(func_ptr basefunction,std::vector<Object_ptr>& v):func(basefunction->arg-v.size()),lst(v),basefunction(basefunction){}

Object_ptr argumentrequiredfunction::inputArgument(std::vector<Object_ptr>&qlst)
{
	std::vector< Object_ptr> dlst = lst;
	dlst.insert(dlst.end(),qlst.begin(), qlst.end());
	Object_ptr base = getObject(basefunction);

	if (!func_ptr(base))
		return nullptr;

	return ((func*)base.get())->inputArgument(dlst);
}
*/

Object_ptr forArgument::clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&)
{
	return nullptr;
}
