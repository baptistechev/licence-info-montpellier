#include "tableauOp.h"
#include "population-vivante.h"
#include <unistd.h>
#include <iostream>
#include <stdlib.h>


TableauOp opts;

void executerOp(int id){
  switch(id){
  case (1):
    opts.affOptions();
    std::terminate();
    break;
  case(2):
    std::cout<< "Version : 1.0" << std::endl;
    std::terminate();
    break;
  } 
}

void defOption(int argc,char** argv){
  Option op1(1,'h',"--help",Option::NONE,"Affiche la liste des Options"),
    op2(2,'v',"--version",Option::NONE,"Affiche le numero de version");
  opts.addOption(op1);
  opts.addOption(op2);
  for(size_t i = 0; i<argc;i++){
    int id = opts.idOption(argv[i]);
    if(id != -1) executerOp(id);
  }
}

int main(int argc, char** argv){

  defOption(argc,argv);

  size_t nbIt = 0;
  PopulationVivante pop(20,0.2);
  pop.print();
  while(pop.getCelluleVivantes()!=0){
    nbIt++;
    usleep(100000);
    system("clear");
    pop=pop.next();
    pop.print();
    std::cout << "Cycle numero : " << nbIt << std::endl;
  }
  return 0;
}
