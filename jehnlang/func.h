#pragma once
#include <memory>
#include <vector>
#include "Object.h"
#include "noArgumentFunction.h"
class func :public Object {
protected:
	func(int);
public:
	int argnum;
	virtual shared_ptr<Object> inputArgument(std::vector<shared_ptr<Object>>&)=0;
};
class argumentfunction :public func {
protected:
public:
	argumentfunction(int);
	std::vector<shared_ptr<stackedreferenceArgumentFunction>> arglst;
	shared_ptr<Object> targ;
	shared_ptr<stackedreferenceArgumentFunction> arg(int);
	shared_ptr<Object> inputArgument(std::vector<shared_ptr<Object>>&);
};
class func_ptr :public shared_ptr<func> {
public:
	shared_ptr<Object> inputArgument(std::vector<shared_ptr<Object>>&);
};