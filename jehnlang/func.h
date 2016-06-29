#pragma once
#include "noArgumentFunction.h"
class func :public Object {
protected:
	func(int argnum) :argnum(argnum) {}
public:
	int argnum;
	virtual Object_ptr inputArgument(Object_ptr,Object_ptr);
	virtual Object_ptr inputArgument(std::vector<Object_ptr>&,Object_ptr)=0;
};
class postfunction :public func {
protected:
public:
	inline postfunction(int i, Object_ptr basefunction) : func(i), basefunction(basefunction) {}
	Object_ptr basefunction;
	Object_ptr clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&);
	Object_ptr inputArgument(Object_ptr, Object_ptr);
	Object_ptr inputArgument(std::vector<Object_ptr>&, Object_ptr);

};
class poofunction :public postfunction {
protected:
public:
	inline poofunction(int i, Object_ptr basefunction, std::vector<Object_ptr>&lst) :postfunction(i,basefunction), lst(lst) {}
	inline poofunction(int i, Object_ptr basefunction) : postfunction(i,basefunction) {}
	inline poofunction(int i, Object_ptr basefunction, Object_ptr o) : postfunction(i, basefunction) { lst.push_back(o); }
	std::vector< Object_ptr> lst;
	Object_ptr clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&);
	Object_ptr inputArgument(Object_ptr,Object_ptr);
	Object_ptr inputArgument(std::vector<Object_ptr>&,Object_ptr);
};
class forArgument :public Object {
public:
	Object_ptr clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&);
};
class argumentfunction :public func {
protected:
public:
	inline argumentfunction(int i) :func(i)
	{
		for (int j = 0; j < i; j++)
			arglst.push_back(Object_ptr(shared_ptr<forArgument>(new forArgument())));
	}

	Object_ptr clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&);
	std::vector<Object_ptr> arglst;
	inline Object_ptr arg(int i){return Object_ptr(arglst[i]);}
	Object_ptr targ;
	Object_ptr inputArgument(std::vector<Object_ptr>&,Object_ptr);
};/*
class argumentrequiredfunction:public func {
public:
	argumentrequiredfunction(func_ptr basefunction, std::vector<Object_ptr>& v);
	Object_ptr basefunction;
	std::vector< Object_ptr> lst;
	Object_ptr inputArgument(std::vector<Object_ptr>&);
};*/
class func_ptr :public shared_ptr<func> {
public:
	inline func_ptr(shared_ptr<func>&& a) :shared_ptr<func>(a) {}
	inline func_ptr(Object_ptr a) : shared_ptr<func>(std::dynamic_pointer_cast<func>(a)) {}

};
#ifdef OPT
inline Object_ptr inputArgument(func* basefunction, std::vector<Object_ptr>& v) {
	if (basefunction->argnum < v.size()) return nullptr;
	if (basefunction->argnum > v.size())
		return Object_ptr(new poofunction(basefunction->argnum - v.size(), Object_ptr(basefunction), v));
	return basefunction->inputArgument(v, Object_ptr(basefunction));
}
inline Object_ptr inputArgument(func* basefunction, Object_ptr o) {
	if (basefunction->argnum == 0) return nullptr;
	if (basefunction->argnum > 1)
		return Object_ptr(new poofunction(basefunction->argnum - 1, Object_ptr(basefunction), o));
	return basefunction->inputArgument(o, Object_ptr(basefunction));

	}
#endif
inline Object_ptr inputArgument(Object_ptr basefunction, std::vector<Object_ptr>& v) {
	func_ptr p = func_ptr(getObject(basefunction));
	if (p == nullptr)
		return nullptr;
	if (p->argnum < v.size()) return nullptr;
	if (p->argnum > v.size())
		return Object_ptr(new poofunction(p->argnum - v.size(), basefunction, v));
	return p->inputArgument(v, basefunction);
}
inline Object_ptr inputArgument(Object_ptr basefunction, Object_ptr o) {
	func_ptr p = func_ptr(getObject(basefunction));
	if (p == nullptr)
		return nullptr;
	if (p->argnum == 0) return nullptr;
	if (p->argnum > 1)
		return Object_ptr(new poofunction(p->argnum - 1, basefunction, o));
	return p->inputArgument(o, basefunction);

}
