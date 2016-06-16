#include "func.h"

func::func(int argnum):argnum(argnum){}

argumentfunction::argumentfunction(int i):func(i)
{
	for (int j = 0; j < i; j++)
		arglst.push_back( shared_ptr<stackedreferenceArgumentFunction>(new stackedreferenceArgumentFunction()));
}

Object_ptr argumentfunction::inputArgument(std::vector<Object_ptr>& v)
{
	std::vector<Object_ptr> vt;
	for (int i = 0; i < argnum; i++) {
		vt.push_back(getObject(v[i]));
	}
	for (int i = 0; i < argnum; i++) {
		arglst[i]->v.push(vt[i]);
	}
	Object_ptr base = getObject(targ);
	for (int i = 0; i < argnum; i++) {
		arglst[i]->v.pop();
	}
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