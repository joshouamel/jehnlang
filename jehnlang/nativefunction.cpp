#include "nativefunction.h"

shared_ptr<Object> nativefunction::inputArgument(std::vector<shared_ptr<Object>>&v)
{
	return calc(v);
}

nativefunction::nativefunction(int i, shared_ptr<Object>(*calc)(std::vector<shared_ptr<Object>> &)) :func(i), calc(calc) {}
shared_ptr<Object> nativeadd_f(std::vector<shared_ptr<Object>> &v) {
	shared_ptr<Object> a1 = v[0];
	shared_ptr<Object> a2 = v[1];
	while(dynamic_cast<noArgumentFunction*>(a1.get())) {
		a1=dynamic_cast<noArgumentFunction*>(a1.get())->calc();
	}
	while (dynamic_cast<noArgumentFunction*>(a2.get())) {
		a1 = dynamic_cast<noArgumentFunction*>(a2.get())->calc();
	}
}
nativefunction nativeadd(2, nativeadd_f);
extern nativefunction nativesubtract;
extern nativefunction nativemultiply;
extern nativefunction nativedivide;