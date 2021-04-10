#include <iostream>
#include <cstdlib>
#include "tableauInt.h"

using namespace std;

int main(int argc, char ** argv){
  if (argc !=2) {cerr<<"Usage: "<<argv[0]<<" [tab dim]"<<endl; return 1;} 
  size_t n = atoi(argv[1]);
  TableauInt T(n);
  for(size_t i=0;i<n;i++){
    T.at(i)=i+1;
  }
  T.pushback(-7);
  write(cout,T);
  return 0;
}
