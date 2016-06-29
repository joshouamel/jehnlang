#pragma once
#include "func.h"
#include "nativeclass.h"
class nativefunction :public func {
protected:
	Object_ptr(*calc)(std::vector<Object_ptr>&);
public:
	Object_ptr inputArgument(std::vector<Object_ptr>&,Object_ptr);
	nativefunction(int, Object_ptr(*t)(std::vector<Object_ptr>&));
	Object_ptr clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&);
};
extern Object_ptr nativeadd;
extern Object_ptr nativesubtract;
extern Object_ptr nativemultiply;
extern Object_ptr nativedivide;
extern Object_ptr nativegt;
extern Object_ptr nativelt;
extern Object_ptr nativege;
extern Object_ptr nativele;
extern Object_ptr nativeequal;
extern Object_ptr nativenotequal;
extern Object_ptr nativenot;
extern Object_ptr nativeand;
extern Object_ptr nativeor;
extern Object_ptr nativexor;
extern Object_ptr nativeif;