#include <string>

class Option{

 public:

  enum argType{ENTIER,CHAINE,CHAR,REEL,FLOAT,NONE};

 private:

  //attributs
  
  int id;
  char rac;
  std::string nom;
  argType type;
  std::string description;

 public:
  
  //constructeurs

  Option();
  Option(int id,char rac,const std::string &nom,argType type,const std::string &description);

  //getters

  int getId() const;
  char getRac() const;
  std::string getNom() const;
  argType getType() const;
  std::string getDescription() const;

  //Methodes

  void print() const;
  
};

std::string argType2String(Option::argType t);
