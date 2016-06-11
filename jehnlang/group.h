#pragma once
#include<ctype.h>
#include "Object.h"
extern shared_ptr<Object> group;
class group {
public:
	void* operator new(std::size_t count);
};
class nativegroup {
	int len;
public:
	nativegroup(int len);
};
class sumgroup
extern nativegroup Int;
extern nativegroup Float;