#pragma once
#include <memory>
#include <list>
using std::list;
using std::shared_ptr;
class group;
class object;
class groupcollector {
	list<group*> s;
	list<shared_ptr<group>> h;
public:
	shared_ptr<group> adds(group* g);
	void addh(group* g);
};
class objectcollector {
	list<object*> s;
	list<shared_ptr<object>> h;
public:
	shared_ptr<object> adds(object* g);
	void addh(object* g);
};
extern groupcollector gcollector;
extern objectcollector ocollector;