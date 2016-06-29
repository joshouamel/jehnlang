#include "nativefunction.h"
#include "nativeclass.h"
Object_ptr nativefunction::inputArgument(std::vector<Object_ptr>& v,Object_ptr)
{
	return calc(v);
}

nativefunction::nativefunction(int a, Object_ptr(*t)(std::vector<Object_ptr>&)):func(a),calc(t){}
Object_ptr nativefunction::clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>&)
{
	return nullptr;
}
#define nativetypeis(a,b) (!!(dynamic_cast<nativeclass<b>*>(a.get())))


Object_ptr nativeadd_f(std::vector<Object_ptr>& v) {
	Object_ptr a0=getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) + getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
#undef tmp
	return nullptr;
}
Object_ptr nativeadd(new nativefunction(2, nativeadd_f));


Object_ptr nativesubtract_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) - getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
#undef tmp
	return nullptr;
}
Object_ptr nativesubtract(new nativefunction(2, nativesubtract_f));


Object_ptr nativemultiply_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) * getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
#undef tmp
	return nullptr;
}
Object_ptr nativemultiply(new nativefunction(2, nativemultiply_f));


Object_ptr nativedivide_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) / getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
#undef tmp
	return nullptr;
}
Object_ptr nativedivide((new nativefunction(2, nativedivide_f)));

Object_ptr nativegt_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) > getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
#undef tmp
	return nullptr;
}
Object_ptr nativegt(new nativefunction(2, nativegt_f));


Object_ptr nativege_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) >= getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
#undef tmp
	return nullptr;
}
Object_ptr nativege((new nativefunction(2, nativege_f)));


Object_ptr nativelt_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) < getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
#undef tmp
	return nullptr;
}
Object_ptr nativelt((new nativefunction(2, nativelt_f)));


Object_ptr nativele_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);\
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) <= getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
#undef tmp
	return nullptr;
}
Object_ptr nativele((new nativefunction(2, nativele_f)));


Object_ptr nativeequal_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) == getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
	tmp(bool, bool);
#undef tmp
	return nullptr;
}
Object_ptr nativeequal((new nativefunction(2, nativeequal_f)));


Object_ptr nativenotequal_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(getnativevalue(a0, a) != getnativevalue(a1, b));
	tmp(int, int);
	tmp(double, int);
	tmp(int, double);
	tmp(double, double);
	tmp(bool,bool)
#undef tmp
	return nullptr;
}
Object_ptr nativenotequal((new nativefunction(2, nativenotequal_f)));


Object_ptr nativenot_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
if (nativetypeis(a0, bool))
	return toObject(!getnativevalue(a0, bool) );
#undef tmp
	return nullptr;
}
Object_ptr nativenot((new nativefunction(1, nativenot_f)));


Object_ptr nativeand_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b,c) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(c(getnativevalue(a0, a) & getnativevalue(a1, b)));
	tmp(int, int,int);
	tmp(bool, bool,bool);
#undef tmp
	return nullptr;
}
Object_ptr nativeand((new nativefunction(2, nativeand_f)));


Object_ptr nativeor_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b,c) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(c(getnativevalue(a0, a) | getnativevalue(a1, b)));
	tmp(int, int,int);
	tmp(bool, bool,bool);
#undef tmp
	return nullptr;
}
Object_ptr nativeor((new nativefunction(2, nativeor_f)));


Object_ptr nativexor_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	Object_ptr a1 = getObject(v[1]);
#define tmp(a,b,c) 	if (nativetypeis(a0, a)&nativetypeis(a1, b))\
	return toObject(c(getnativevalue(a0, a) ^ getnativevalue(a1, b)));
	tmp(int, int,int);
	tmp(bool, bool,bool);
#undef tmp
	return nullptr;
}
Object_ptr nativexor((new nativefunction(2, nativexor_f)));

Object_ptr nativeif_f(std::vector<Object_ptr>& v) {
	Object_ptr a0 = getObject(v[0]);
	if (nativetypeis(a0, bool)) {
		if (getnativevalue(a0,bool))
			return v[1];
		return v[2];
	}
	return nullptr;
}

Object_ptr nativeif((new nativefunction(3, nativeif_f)));
