#include <iostream>
#include <cstdlib>
#include "tableauCell.h"

using namespace std;

int main(int argc, char ** argv){
  if (argc !=2) {cerr<<"Usage: "<<argv[0]<<" [tab dim]"<<endl; return 1;} 
  size_t n = atoi(argv[1]);
  TableauCell T(n);
  T.read(cin);
  T.write(cout);
  return 0;
}
