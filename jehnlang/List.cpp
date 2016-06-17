#include "c++assist.h"

Object_ptr List;
void List_init() {
	argumentfunction* f = new argumentfunction(3);

	argumentfunction* f1 = new argumentfunction(1);

	f1->targ=Object_ptr(nativeif)(
		Object_ptr(nativeand)(
			Object_ptr(f->arglst[2])(
				Object_ptr(f1->arglst[0])
				),
			Object_ptr(nativege)(
				Object_ptr(f1->arglst[0]),
				toObject(0)
				)
			),
			Object_ptr(f->arglst[1])(
				Object_ptr(f1->arglst[0])
				),
			nullptr
			);

	f->targ = Object_ptr(f1);

	List= Object_ptr(f);
}
Object_ptr Listc;
void Listc_init() {
	argumentfunction* f = new argumentfunction(2);
	f->targ = List(Object_ptr(f->arglst[0]), Object_ptr(f->arglst[1]), Object_ptr(nativegt)(Object_ptr(f->arglst[0])));
	Listc= Object_ptr(f);
}

Object_ptr len_sub(std::vector<Object_ptr>&a)
{
	return toObject((int)getnativevalue(getObject(a[0]),std::vector<Object_ptr>).size());
}

Object_ptr at_sub(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
	return getnativevalue(a0, std::vector<Object_ptr>)[getnativevalue(a1, int)];
}
Object_ptr dList() {
	return dList_sub(Object_ptr(new nativeclass<std::vector<Object_ptr>>(std::vector<Object_ptr>())));
};
Object_ptr dList_sub(Object_ptr v1) {
	return Listc(len_sub(std::vector<Object_ptr>(1, v1)), Object_ptr(new nativefunction(2, at_sub))(v1));
}

Object_ptr dList(std::vector<Object_ptr>& v){
	return dList_sub(toObject(v));
}
