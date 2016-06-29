#pragma once
#include "func.h"
class pattern {
public:
	virtual shared_ptr<std::vector<Object_ptr>> getpattern(Object_ptr);
};
class castpattern :public pattern {
public:
	int len;
	Object_ptr basefunction;
	std::vector<pattern> o;
	inline castpattern(Object_ptr basefunction, int len) :basefunction(basefunction), len(len) {}
	shared_ptr<std::vector<Object_ptr>> getpattern(Object_ptr);
};
class echopattern :public pattern {
public:
	shared_ptr<std::vector<Object_ptr>> getpattern(Object_ptr);
};
class boolpattern :public pattern {
public:
	Object_ptr f;
	inline boolpattern(Object_ptr f):f(f) {}
	shared_ptr<std::vector<Object_ptr>> getpattern(Object_ptr);
};
class listpattern :public pattern {
public:
	int len;
	std::vector<pattern> o;
	inline listpattern(int len) :len(len) {}
	shared_ptr<std::vector<Object_ptr>> getpattern(Object_ptr);
};
class listduppattern :public pattern {
public:
	int lenf;
	int lenl;
	std::vector<pattern> o;
	inline listduppattern(int lenf, int lenl) :lenf(lenf), lenl(lenl) {}
	shared_ptr<std::vector<Object_ptr>> getpattern(Object_ptr);
};
class patternedfunction:public func {
public:
	std::vector<pattern> o;
	Object_ptr targ;
	Object_ptr inputArgument(Object_ptr, Object_ptr);
	Object_ptr inputArgument(std::vector<Object_ptr>&, Object_ptr);
};
