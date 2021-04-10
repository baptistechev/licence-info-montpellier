#include "tableauOp.h"
#include <iostream>

using namespace std;

//Constructeur

TableauOp::TableauOp():T(),N(0){}

int  TableauOp::getOptionIndex(int id) const{
  bool found = false;
  size_t i = 0;
  while(!found && (i<N)){
    found = (T[i].getId()==id);
    i++;
  }
  return found? i-1 : -1;
}

int  TableauOp::getOptionIndex(const std::string &nom) const{
  bool found = false;
  size_t i = 0;
  while(!found && (i<N)){
    found = (T[i].getNom()==nom);
    i++;
  }
  return found? i-1 : -1;
}


//Methodes

void TableauOp::addOption(const Option& op){
  if(N==NMax){
    cerr << "Nombre d'option max atteint" << endl;
    terminate();
  }
  if(getOptionIndex(op.getId()) != -1 || getOptionIndex(op.getNom()) != -1){
    cerr << "L'option d'id : " << op.getId() << " ou de nom \"" << op.getNom()<< "\" existe deja !" << endl;
  }else{
    T[N]=op;
    N++;
  }
}
void TableauOp::affOptions() const{
  cout << "Liste des options :" << endl;
  for(size_t i = 0; i<N;i++){
    T[i].print();
  }
}
int TableauOp::idOption(const std::string& nom) const{
  int i = getOptionIndex(nom);
  return  (i>=0)? T[i].getId() : -1;
}
Option::argType TableauOp::typeArg(const std::string& nom) const{
  int i = getOptionIndex(nom);
  if(i<0) cerr << "L'option "<< nom << " n'existe pas" << endl;
  return T[i].getType();
}
