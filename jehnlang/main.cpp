#include <iostream>
#include "c++assist.h"
void List_init();
void Listc_init();
using namespace std;
void printObject(Object_ptr o) {
	Object_ptr t=getObject(o);
	
}
int fibb_c(int i) {
	if (i == 0)
		return 1;
	if (i == 1)
		return 1;
	return fibb_c(i - 1) + fibb_c(i - 2);
}
int main() {
	List_init();
	Listc_init();
	Object_ptr d = toObject(1);
	Object_ptr k(dList(toObject(1), toObject(5), toObject(9), toObject(3), toObject(7)));
	printObject(k(toObject(2)));
	getObject(Object_ptr(nativeadd)(toObject(2))(toObject(3)));
	argumentfunction* fibbf = new argumentfunction(1);
	Object_ptr fibb(fibbf);
	fibbf->targ =
		Object_ptr(nativeif)(
			Object_ptr(nativeequal)(
				Object_ptr(fibbf->arglst[0]),
				toObject(0)
				),
			toObject(1),
			Object_ptr(nativeif)(
				Object_ptr(nativeequal)(
					Object_ptr(fibbf->arglst[0]),
					toObject(1)
					),
				toObject(1),
				fibb(Object_ptr(fibbf->arglst[0]) - toObject(2)) + fibb(Object_ptr(fibbf->arglst[0]) - toObject(1))
				)
			);
	for (int i = 0; i < 11; i++) {
		cout<<getnativevalue(getObject(fibb(toObject(i))),int)<<endl;
	}
	for (int i = 0; i < 11; i++) {
		cout << fibb_c(i) << endl;
	}
	printObject(fibb(toObject(10)));

}
