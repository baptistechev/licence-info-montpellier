#include "option.h"
#include <iostream>

//Constructeurs

Option::Option():id(-1),rac(),nom(),type(NONE),description(){}
Option::Option(int id,char rac,const std::string &nom,Option::argType type,const std::string &description):
  id(id),rac(rac),nom(nom),type(type),description(description){}

//getters

int Option::getId() const {return id;}
char Option::getRac() const {return rac;}
std::string Option::getNom() const {return nom;}
Option::argType Option::getType() const {return type;}
std::string Option::getDescription() const {return description;}

//Methodes

void Option::print() const{
  std::cout << nom << " (Id : " << id << ") " << rac << " | Type d'argument : " << argType2String(type) << ", Description : " << ((description.size()>0) ? description : "Aucune") << std::endl;
}


std::string argType2String(Option::argType t){
  switch (t){
  case Option::ENTIER:
    return "Entier";
    break;
  case Option::CHAINE:
    return "Chaine";
    break;
  case Option::CHAR:
    return "Char";
    break;
  case Option::REEL:
    return "Reel";
    break;
  case Option::FLOAT:
    return "Float";
    break;
  default:
    return "Aucun";
    break;
  }
}
