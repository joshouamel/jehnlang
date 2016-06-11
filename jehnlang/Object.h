#pragma once
#include <memory>
class group;
using std::shared_ptr;
class Object {
public:
	shared_ptr<group> g;
	virtual int a() { return 1; };
};