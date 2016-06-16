#include "c++assist.h"

List::List():argumentfunction(1)
{
}


List::~List()
{
}

Object_ptr len_sub(std::vector<Object_ptr>&a)
{
	return toObject((int)getnativevalue(a[0],dList*)->v.size());
}

Object_ptr at_sub(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
	return ((nativeclass<dList*>*)a0.get())->value->v[((nativeclass<int>*)a1.get())->value];
}
dList::dList():Listc(
	Object_ptr((Object*)new nativefunction(1,len_sub))(toObject(this)),
	func_ptr(shared_ptr<func>((func*)(new nativefunction(2, at_sub)))).inputArgument(std::vector<Object_ptr>(1,toObject(this)))
	){}

Listc::Listc(Object_ptr l, Object_ptr i):Listc(l,i,nativegt.inputArgument(std::vector<Object_ptr>(1, l))){}

Listc::Listc(Object_ptr l, Object_ptr i, Object_ptr o):l(l),i(i),o(o){
	targ =
		Object_ptr(nativeif)(
			Object_ptr(nativeor)(
				Object_ptr(nativegt)(
					Object_ptr(arglst[0]),
					toObject(0)
					),
				Object_ptr(nativeequal)(
					Object_ptr(arglst[0]),
					toObject(0)
					)
				),
			Object_ptr(nativeif)(
				o(
					Object_ptr(arglst[0])
					),
				i(
					Object_ptr(arglst[0])
					),
				nullptr
				),
			nullptr
			);
}

