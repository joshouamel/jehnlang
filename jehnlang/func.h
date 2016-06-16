#pragma once
#include "noArgumentFunction.h"
class func :public Object {
protected:
	func(int);
public:
	int argnum;
	virtual Object_ptr inputArgument(std::vector<Object_ptr>&)=0;
};
class argumentfunction :public func {
protected:
public:
	argumentfunction(int);
	std::vector<shared_ptr<stackedreferenceArgumentFunction>> arglst;
	Object_ptr targ;
	Object_ptr inputArgument(std::vector<Object_ptr>&);
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
	Object_ptr inputArgument(std::vector<Object_ptr>&);
};