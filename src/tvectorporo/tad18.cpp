#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
	TPoro a(1, 2, 3, (char*)"rojo");
	TVectorPoro v(5);
	v[1]=a;
	v[2]=a;
	v[3]=a;
	v[4]=a;
	v[5]=a;

	v.Redimensionar(3);

	cout<<v[3]<<endl;
	if(v.Longitud()==3) cout<<"Bien"<<endl;
}