#pragma once
#include "List.h"
inline Object_ptr operator+(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativeadd)(a, b);
}
inline Object_ptr operator-(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativesubtract)(a, b);
}
inline Object_ptr operator*(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativemultiply)(a, b);
}
inline Object_ptr operator/(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativedivide)(a, b);
}
inline Object_ptr operator>(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativegt)(a, b);
}
inline Object_ptr operator<(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativelt)(a, b);
}
inline Object_ptr operator==(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativeequal)(a, b);
}
inline Object_ptr operator!(Object_ptr a) {
	return ((Object_ptr)nativenot)(a);
}
inline Object_ptr operator!=(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativenotequal)(a, b);
}
inline Object_ptr operator&(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativeand)(a, b);
}
inline Object_ptr operator|(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativeor)(a, b);
}
inline Object_ptr operator^(Object_ptr a, Object_ptr b) {
	return ((Object_ptr)nativexor)(a, b);
}
#include <tuple>
#include <vector>
template<int... S>
struct seq {};
template<int N, int...S>
struct gens :public gens<N - 1, N - 1, S...> {};
template<int... S>
struct gens < 0, S... > { typedef seq < S... > type; };
template<class Fn, class T, int... S>
auto tuplecall(Fn f, T t, seq<S...>)->decltype(f(std::get<S>(t)...)) {
	return f(std::get<S>(t)...);
}
template<class Fn, class... T>
auto tuplecall(Fn f, std::tuple<T...> t)->decltype(tuplecall(f, t, typename gens<sizeof...(T)>::type())) {
	return tuplecall(f, t, typename gens<sizeof...(T)>::type());
}
template<class... T, int... S>
std::tuple<T...> vectortonativetuple(std::vector<Object_ptr>& v, seq<S...>) {
	return std::tie(getnativevalue(getObject(v[S]),T)...);
}
template<class... T>
std::tuple<T...> vectortonativetuple(std::vector<Object_ptr>& v) {
	return
		vectortonativetuple<T...>(v, gens<sizeof...(T)>::type());
}
template<class R, class... T>
class cppfunction :public func {
protected:
	R(*calc)(T...);
public:
	Object_ptr inputArgument(std::vector<Object_ptr>& v) {
		return toObject(tuplecall(calc, vectortonativetuple<T...>(v)));
	}
	cppfunction(R(*calc)(T...)):calc(calc){}
};
