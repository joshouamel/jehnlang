#include "c++assist.h"

Object_ptr List;
Object_ptr Listc;
#ifdef OPT
Object_ptr List_init_sub(std::vector<Object_ptr>& v) {
	Object_ptr p = getObject(v[3]);
	int k = getnativevalue(p, int);
	if (getnativevalue(getObject(inputArgument(v[2],p)),bool)&& k>= 0) {
		return v[1](p);
	}
	return nullptr;
}
void List_init() {
	List= Object_ptr(new poofunction(3,Object_ptr(new nativefunction(4, List_init_sub))));

}
Object_ptr Listc_init_sub(std::vector<Object_ptr>& v) {
	Object_ptr p = getObject(v[2]);
	int k=getnativevalue(p, int);
	if (getnativevalue(getObject(v[0]), bool)>k&& k >= 0) {
		return v[1](p);
	}
	return nullptr;
}
void Listc_init() {
	Listc = Object_ptr(new poofunction(2,new nativefunction(3, Listc_init_sub)));
}
#else
void List_init() {
	argumentfunction* f = new argumentfunction(4);
	f->targ=Object_ptr(nativeif)(
		Object_ptr(nativeand)(
			Object_ptr(f->arglst[2])(
				Object_ptr(f->arglst[3])
				),
			Object_ptr(nativege)(
				Object_ptr(f->arglst[3]),
				toObject(0)
				)
			),
			Object_ptr(f->arglst[1])(
				Object_ptr(f->arglst[3])
				),
			nullptr
			);
	List= Object_ptr(new postfunction (3,Object_ptr(f)));
}
void Listc_init() {
	argumentfunction* f = new argumentfunction(2);
	f->targ = List(f->arglst[0], f->arglst[1], inputArgument(nativegt,f->arglst[0]));
	Listc= Object_ptr(f);
}
#endif
Object_ptr at_sub(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
	return getnativevalue(a0, std::vector<Object_ptr>)[getnativevalue(a1, int)];
}
