#include "func.h"

Object_ptr argumentfunction::clone(std::vector<Object_ptr>&v1, std::vector<Object_ptr>&v2, std::vector<Object_ptr>&v3)
{
	Object_ptr t=targ->clone(v1,v2,v3);
	if (t) {
		argumentfunction* a=new argumentfunction(argnum);
		a->targ = t->clone(arglst, a->arglst,v3);
		if (!a->targ)
			a->targ = t;
		return Object_ptr(a);
	}
	return nullptr;
}



Object_ptr argumentfunction::inputArgument(std::vector<Object_ptr>& v,Object_ptr this_ptr)
{
	return targ.clone(arglst, v,std::vector<Object_ptr>(1,this_ptr));
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

Object_ptr forArgument::clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&)
{
	return nullptr;
}
Object_ptr postfunction::clone(std::vector<Object_ptr>&v1, std::vector<Object_ptr>&v2, std::vector<Object_ptr>& v3)
{
	Object_ptr b;
	if ((b = basefunction.clone(v1, v2, v3)) != basefunction)
		return Object_ptr(new postfunction(argnum, b));
	return nullptr;
}

Object_ptr postfunction::inputArgument(Object_ptr o, Object_ptr this_ptr)
{
	if (argnum == 1)
		return ::inputArgument(basefunction, o);
	return Object_ptr(new poofunction(argnum - 1, basefunction, o));
}

Object_ptr postfunction::inputArgument(std::vector<Object_ptr>& v, Object_ptr this_ptr)
{
	if (argnum == v.size())
		return ::inputArgument(basefunction, v);
	return Object_ptr(new poofunction(argnum - 1, basefunction, v));
}

Object_ptr poofunction::clone(std::vector<Object_ptr>&v1, std::vector<Object_ptr>&v2, std::vector<Object_ptr>& v3)
{
	bool check = false;
	std::vector<Object_ptr> v;
	Object_ptr b;
	if ((b = basefunction.clone(v1, v2,v3)) != basefunction)
		check = true;
	poofunction* u = new poofunction(argnum,b );
	for (int i = 0; i < lst.size(); i++) {
		Object_ptr t = lst[i].clone(v1, v2,v3);
		u->lst.push_back(t);
		if (t != lst[i])
			check = true;
	}
	if (check)
		return Object_ptr(u);
	delete u;
	return nullptr;
}

Object_ptr poofunction::inputArgument(Object_ptr o, Object_ptr this_ptr)
{
	if (argnum == 1) {
		std::vector< Object_ptr> a = lst;
		a.push_back(o);
		return Object_ptr(new unCalcedData(basefunction, a));
	}
	poofunction* p=new poofunction(argnum - 1, basefunction, lst);
	p->lst.push_back(o);
	return Object_ptr(p);
}

Object_ptr poofunction::inputArgument(std::vector<Object_ptr>& v,Object_ptr this_ptr)
{
	if (argnum == v.size()) {
		std::vector< Object_ptr> a = lst;
		a.insert(a.end(), v.begin(), v.end());
		return Object_ptr(new unCalcedData(basefunction, a));
	}
	poofunction* p = new poofunction(argnum - 1, basefunction, lst);
	p->lst.insert(p->lst.end(), v.begin(), v.end());
	return Object_ptr(p);
}

Object_ptr func::inputArgument(Object_ptr o, Object_ptr this_ptr)
{
	return inputArgument(std::vector<Object_ptr>(1, o),this_ptr);
}
