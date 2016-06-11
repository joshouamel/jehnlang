#include "func.h"

func::func(int argnum):argnum(argnum){}

argumentfunction::argumentfunction(int i):func(i),arglst(i,nullptr)
{
	for (int j = 0; j < i; j++)
		arglst[i] = shared_ptr<stackedreferenceArgumentFunction>(new stackedreferenceArgumentFunction());
}

shared_ptr<stackedreferenceArgumentFunction> argumentfunction::arg(int i)
{
	if (i < argnum)
		return arglst[i];
	else nullptr;
}

shared_ptr<Object> argumentfunction::inputArgument(std::vector<shared_ptr<Object>>& v)
{
	for (int i = 0; i < argnum; i++) {
		arglst[i]->v.push(v[i]);
	}
	shared_ptr<Object> base = targ;
	while (base&&dynamic_cast<noArgumentFunction*>(base.get()))
		base = ((noArgumentFunction*)base.get())->calc();

	return base;
}

shared_ptr<Object> func_ptr::inputArgument(std::vector<shared_ptr<Object>>& v)
{
	if ((*this)->argnum < v.size()) return nullptr;
	if ((*this)->argnum > v.size()) {
		shared_ptr<argumentfunction> f(new argumentfunction(v.size() - (*this)->argnum));
		shared_ptr<unCalcedData> u(new unCalcedData());
		u->basefunction = *this;
		u->lst =v;
		u->lst.reserve(f->argnum);
		u->lst.insert(u->lst.end(), f->arglst.begin(), f->arglst.end());
		f->targ = u;
		return f;
	}
	if ((*this)->argnum == v.size()) {
		return (*this)->inputArgument(v);
	}
}
