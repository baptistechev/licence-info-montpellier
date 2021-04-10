#include "JDV.h"

int main(int argc,char** argv){

  JDV jdv;
  jdv.parseOption(argc,argv);
  jdv.run();
  
}
