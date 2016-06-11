#include "group.h"
#include "collector.h"
shared_ptr<Object> setgroup() {
	shared_ptr<Object> o (new Object(nullptr, nullptr));
	return o->g = o;
}
shared_ptr<Object> group = setgroup();
nativegroup Int(sizeof(int));
nativegroup Float(sizeof(double));