#include "population.h"
#include <unistd.h>

int main(int argc, char** argv){
  Population JDV;
  JDV.init(80);  
  JDV.print();

  do{
    JDV=JDV.next();
    JDV.print();
    sleep(1);
  }while(JDV.nb_vivants());
  
  return 0;
}
