#pragma once
#include "func.h"
class nativefunction :public func {
protected:
	shared_ptr<Object>(*calc)(std::vector<shared_ptr<Object>>&);
public:
	shared_ptr<Object> inputArgument(std::vector<shared_ptr<Object>>&);
	nativefunction(int, shared_ptr<Object>(*t)(std::vector<shared_ptr<Object>>&));
};
extern nativefunction nativeadd;
extern nativefunction nativesubtract;
extern nativefunction nativemultiply;
extern nativefunction nativedivide;