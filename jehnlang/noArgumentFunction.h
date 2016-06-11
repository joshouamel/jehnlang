#pragma once
#include "Object.h"
#include <vector>
class noArgumentFunction :
	public Object
{
public:
	virtual shared_ptr<Object> calc()=0;
};
class unCalcedData :
	public noArgumentFunction
{
protected:
public:
	shared_ptr<Object> basefunction;
	std::vector< shared_ptr<Object>> lst;
	shared_ptr<Object> calc();
};
class nativenoArgumentFunction :public noArgumentFunction {
	shared_ptr<Object>(*calct)();
public:
	nativenoArgumentFunction(shared_ptr<Object>(*calct)());
	shared_ptr<Object> calc();
};
class referenceArgumentFunction :public noArgumentFunction {
	
};
#include <stack>
class stackedreferenceArgumentFunction :public referenceArgumentFunction {
public:
	std::stack<shared_ptr<Object>> v;
	shared_ptr<Object> calc();
};