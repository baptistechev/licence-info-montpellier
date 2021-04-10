#include "JDV.h"
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

JDV::JDV(): pop(20,0.2){

  Option op1(1,'h',"--help",Option::NONE,"Affiche la liste des Options"),
    op2(2,'v',"--version",Option::NONE,"Affiche le numero de version"),
    op3(10,'d',"--dimension",Option::ENTIER,"Permet de choisir la dimension"),
    op4(11,'p',"--probability",Option::FLOAT,"Permet de choisir la probabilite"),
    op5(20,'c',"--config",Option::CHAINE,"Charge fichier de config");
  opts.addOption(op1);
  opts.addOption(op2);
  opts.addOption(op3);
  opts.addOption(op4);
  opts.addOption(op5);
  
}

void JDV::nettoie(std::string &s){
  size_t pos = s.find_first_of("#");
  if(pos!=string::npos){
    s=s.substr(0,pos);
  }
  int deb=0,fin=s.size()-1;
  while(deb<fin+1 && (s[deb]==' ' || s[deb]=='\t')) deb++;
  while(deb-1<fin && (s[fin]==' ' || s[fin]=='\t')) fin--;
  s=s.substr(deb,fin-deb+1);
}

bool JDV::findCleVal(std::string &s,std::string &cle,std::string &value){
  nettoie(s);
  if(s==string("")) return false;
  size_t pos = s.find_first_of(":");
  if(pos==string::npos){
    cerr << "Fichier de config mal ecrit" << endl;
    terminate();
  }
  cle=s.substr(0,pos);
  value=s.substr(pos+1);
  nettoie(cle);
  nettoie(value);
  return true;
}

void JDV::loadConfig(std::string file){
  ifstream ifs(file.c_str());
  string cle,value;
  if(!ifs.is_open()){
    cerr << "Le fichier n'a pas ete ouvert correctement" << endl;
    terminate();
  }
  string s;
  while(!ifs.eof()){
    getline(ifs,s);
    if(findCleVal(s,cle,value)){
      cout << "Traitement de l'option " << cle << ":" << value << endl;
      traiteOption(cle,value);
    }
  }
}

void JDV::traiteOption(std::string cle, std::string value){

  if(cle=="Dimension"){
    pop.setDim(atoi(value.c_str()));
  }
  if(cle=="Probability"){
    pop.setProba(atof(value.c_str()));
  }
  if(cle=="Cell"){
    int x,y;
    size_t pos = value.find_first_of("x ,");
    if(pos==string::npos){
      cerr << "Probleme avec le fichier de config lors de definition cellule(s)" <<endl;
    }else{
      x=atoi(value.substr(0,pos).c_str());
      y=atoi(value.substr(pos+1).c_str());
      pop.birth(x,y);
    }
  }
}

void JDV::parseOption(int argc, char** argv){
  for(int i = 0; i<argc;i++){
    int id = opts.idOption(argv[i]);
    if(id != -1){
      switch(id){
      case (1):
	opts.affOptions();
	std::terminate();
	break;
      case(2):
	std::cout<< "Version : 1.0" << std::endl;
	std::terminate();
	break;
      case(10):
	pop.setDim(atoi(argv[i+1]));
	break;
      case(11):
	pop.setProba(atof(argv[i+1]));
	break;
      case(20):
	loadConfig(argv[i+1]);
	break;

      }   
    }
  }
}

void JDV::run(){

  size_t nbIt = 0;
  pop.print();
  while(pop.getCelluleVivantes()!=0){
    nbIt++;
    usleep(100000);
    system("clear");
    pop=pop.next();
    pop.print();
    std::cout << "Cycle numero : " << nbIt << std::endl;
  }

  
}
