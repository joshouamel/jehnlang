#pragma once
#include "func.h"
#include "nativeclass.h"
class nativefunction :public func {
protected:
	Object_ptr(*calc)(std::vector<Object_ptr>&);
public:
	Object_ptr inputArgument(std::vector<Object_ptr>&);
	nativefunction(int, Object_ptr(*t)(std::vector<Object_ptr>&));
};
extern func_ptr nativeadd;
extern func_ptr nativesubtract;
extern func_ptr nativemultiply;
extern func_ptr nativedivide;
extern func_ptr nativegt;
extern func_ptr nativelt;
extern func_ptr nativeequal;
extern func_ptr nativenotequal;
extern func_ptr nativenot;
extern func_ptr nativeand;
extern func_ptr nativeor;
extern func_ptr nativexor;
extern func_ptr nativeif;