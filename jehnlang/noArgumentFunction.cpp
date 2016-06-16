#include "noArgumentFunction.h"
#include "func.h"


Object_ptr unCalcedData::calc()
{
	return func_ptr(getObject(basefunction)).inputArgument(lst);
}

Object_ptr stackedreferenceArgumentFunction::calc()
{
	return v.top();
}

nativenoArgumentFunction::nativenoArgumentFunction(Object_ptr(*calct)()):calct(calct){}

Object_ptr nativenoArgumentFunction::calc()
{
	return calct();
}
