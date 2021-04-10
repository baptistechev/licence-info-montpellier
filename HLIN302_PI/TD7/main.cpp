#include "cellule.h"
#include <iostream>
using namespace std;

template<typename T>
T max3(T x,T y, T z){
  if (x>y && x>z) return x;
  if (y>x && y>z) return y;
  return z;
}

template<typename T,typename U,typename V>
T max3(T x,U y, V z){
  cerr << "Type differents !!" << endl;
  terminate();
}

template<>
Cellule max3(Cellule x,Cellule y, Cellule z){
  if (x.estApres(y) && x.estApres(z)) return x;
  if (y.estApres(x) && y.estApres(z)) return y;
  return z;
}

int main(int argc,char** argv){

  int a,b,c;
  float x,y,z;
  Cellule c1(true,0,0),c2(true,1,0),c3(true,2,0);
  a=1;b=2;c=3;
  x=1;y=2;z=3;
  cout << max3(a,b,c) << endl;
  cout << max3(x,y,z) << endl;
  max3(c1,c2,c3).print();
  return 0;
}
