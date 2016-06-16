#include <iostream>
#include "c++assist.h"
using namespace std;
void printObject(Object_ptr o) {
	Object_ptr t=getObject(o);
	
}
int fibb_c(int i) {
	if (i-- == 0)
		return 1;
	if (i-- == 0)
		return 1;
	int a=1, b=2,c;
	while (i--) {
		c = b;
		b += a;
		a = c;
	}
	return b;
}
int main() {
	Object_ptr d = toObject(1);
	Object_ptr k(new dList(toObject(1), toObject(5), toObject(9), toObject(3), toObject(7)));
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
	printObject(k(toObject(3)));
}