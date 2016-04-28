#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/***************************************************/
/***************** INSERTAR			   */
/***************************************************/
  TABBPoro a;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");
  TPoro p6(1,2,6,(char *) "rojo");
  TPoro p7(1,2,7,(char *) "rojo");

  a.Insertar(p5);
  a.Insertar(p2);
  a.Insertar(p1);
  a.Insertar(p3);
  a.Insertar(p6);

  if(a.Insertar(p7))
        cout << "Insertado" << endl;
  else
	cout << "No insertado" << endl;

  if(a.Insertar(p7))
        cout << "Insertado" << endl;
  else
	cout << "No insertado" << endl;

  return 1;
}
