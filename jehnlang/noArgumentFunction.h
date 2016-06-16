#pragma once
#include "Object.h"
class noArgumentFunction :
	public Object
{
public:
	virtual Object_ptr calc()=0;
};
class unCalcedData :
	public noArgumentFunction
{
protected:
public:
	Object_ptr basefunction;
	std::vector< Object_ptr> lst;
	Object_ptr calc();
};
class nativenoArgumentFunction :public noArgumentFunction {
	Object_ptr(*calct)();
public:
	nativenoArgumentFunction(Object_ptr(*calct)());
	Object_ptr calc();
};
class referenceArgumentFunction :public noArgumentFunction {
	
};
#include <stack>
class stackedreferenceArgumentFunction :public referenceArgumentFunction {
public:
	std::stack<Object_ptr> v;
	Object_ptr calc();
};
inline Object_ptr getObject(Object_ptr o) {
	while (o&&dynamic_cast<noArgumentFunction*>(o.get())) {
		o = dynamic_cast<noArgumentFunction*>(o.get())->calc();
	}
	return o;
}