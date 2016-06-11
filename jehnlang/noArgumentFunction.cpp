#include "noArgumentFunction.h"
#include "func.h"


shared_ptr<Object> unCalcedData::calc()
{
	shared_ptr<Object> base = basefunction;
	while (base&&dynamic_cast<noArgumentFunction*>(base.get()))
			base = ((noArgumentFunction*)base.get())->calc();
	
	if (!base||!dynamic_cast<func*>(base.get()))
		return nullptr;

	return ((func*)base.get())->inputArgument(lst);
}

shared_ptr<Object> stackedreferenceArgumentFunction::calc()
{
	return v.top();
}

nativenoArgumentFunction::nativenoArgumentFunction(shared_ptr<Object>(*calct)()):calct(calct){}

shared_ptr<Object> nativenoArgumentFunction::calc()
{
	return calct();
}
