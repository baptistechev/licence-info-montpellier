#include <iostream>
#include <string>
#include "Assoc.cc"

template class Assoc<string, int>;
template ostream& operator<<(ostream&, const Assoc<string, int>&);