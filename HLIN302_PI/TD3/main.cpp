#include "population-vivante.h"
#include <unistd.h>
#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv){
  size_t nbIt = 0;
  PopulationVivante pop(20);
  pop.init((20*20)*30/100);
  pop.print();
  while(pop.getCelluleVivantes()!=0){
    nbIt++;
    usleep(100000);
    system("clear");
    pop=pop.next();
    pop.print();
    std::cout << "Cycle numero : " << nbIt << std::endl;
  }
}
