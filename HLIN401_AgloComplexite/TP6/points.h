#include <iostream>
#include <fstream>

#pragma once
using namespace std;

struct coord {
  float x;
  float y;
  friend ostream& operator<<(ostream& os, const coord& P);
};

void pointsAleatoires(int, coord*);
void dessinPoints(int, coord*, string = "Points");
void dessinTsp(int, coord*, int*, string = "Circuit");
void affichePoints(int, coord*);

