#include <iostream>
#include "monome.h"

using namespace std;

int main(int argc, char **argv) {

  Monome M1("",10,0,NULL);
  Monome M2("y",-2.3,1,&M1);
  Monome M3("y",5,3,&M2);
  Monome M4("x",-2,1,&M3);
  Monome M5("x",3,2,&M4);

  M5.affiche(false);
  
  return 0;
}
