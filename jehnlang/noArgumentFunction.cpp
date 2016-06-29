#include "noArgumentFunction.h"
#include "func.h"


Object_ptr unCalcedData::clone(std::vector<Object_ptr>&v1, std::vector<Object_ptr>&v2, std::vector<Object_ptr>&v3)
{
	bool check = false;
	unCalcedData* u= new unCalcedData();
	if((u->basefunction=basefunction.clone(v1,v2,v3))!=basefunction)
		check = true;
	for (int i = 0; i < lst.size(); i++) {
		auto t=lst[i].clone(v1, v2,v3);
		u->lst.push_back(t);
		if (t != lst[i])
			check = true;
	}
	if (check) 
		return Object_ptr(u);
	delete u;
	return nullptr;
}

Object_ptr unCalcedData::calc()
{
	if (get)
		return get;
	return inputArgument(basefunction,lst);
}

Object_ptr stackedreferenceArgumentFunction::calc()
{
	return v.top();
}

Object_ptr nativenoArgumentFunction::clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&)
{
	return nullptr;
}

nativenoArgumentFunction::nativenoArgumentFunction(Object_ptr(*calct)()):calct(calct){}

Object_ptr nativenoArgumentFunction::calc()
{
	return calct();
}

Object_ptr referenceArgumentFunction::clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&)
{
	return nullptr;
}
