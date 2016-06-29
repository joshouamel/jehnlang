#pragma once
#include <memory>
#include <vector>
#define forUsers 
#define OPT 
class group;
using std::shared_ptr;
class Object_ptr;
template<class S, class... T>
forUsers void push_back(std::vector<Object_ptr>& v, S a, T... b) {
	v.push_back(a);
	push_back(v, b...);
}
template<class S>
forUsers void push_back(std::vector<Object_ptr>& v, S a) {
	v.push_back(a);
}
class Object {
public:
//	shared_ptr<group> g;
	virtual Object_ptr clone(std::vector<Object_ptr>&, std::vector<Object_ptr>&, std::vector<Object_ptr>& o=std::vector<Object_ptr>())=0;
};
class Object_ptr :public shared_ptr<Object> {
public:
	inline Object_ptr(Object* o=nullptr) :shared_ptr<Object>(o) {}
	inline Object_ptr(shared_ptr<Object> o) : shared_ptr<Object>(o) {}
	template<class _Ty2,
	class = typename enable_if<is_convertible<_Ty2 *, Object *>::value,
		void>::type>
		Object_ptr(const shared_ptr<_Ty2>& _Other) : shared_ptr<Object>(_Other) { }
	template<class... T>
	forUsers Object_ptr operator()(T... k) {
		unCalcedData* u(new unCalcedData);
		u->basefunction = *this;
		push_back(u->lst,k...);
		return Object_ptr((Object*)u);
	}
	inline Object_ptr clone(std::vector<Object_ptr>& v1, std::vector<Object_ptr>&v2, std::vector<Object_ptr>& v3) {
		if (!*this)
			return nullptr;
		for (int i=0; i!=v1.size(); i++) {
			if (v1[i] == *this)
				return v2[i];
		}
		for (int i = 0; i != v3.size(); i++) {
			if (v3[i] == *this)
			return *this;
		}
		v3.push_back(*this);
		Object_ptr a = (*this)->clone(v1,v2,v3);
		v3.pop_back();
		if (a)
			return a;
		return *this;
	}
};