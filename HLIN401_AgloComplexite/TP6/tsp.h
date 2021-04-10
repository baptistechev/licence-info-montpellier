#include <iostream>
#include <sstream>
#include <math.h>
#include <cfloat>
//#include <algorithm>

#include "ensembles.h"
#include "matrice.h"
#include "points.h"

using namespace std;

float distance(coord&, coord&);
float tsp(int, coord*, float**, int**, int&);
void tsp_rec(int*, int, float**, int**, int);
float tsp_bruteforce(int, coord*);
