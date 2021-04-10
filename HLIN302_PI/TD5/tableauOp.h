#include "option.h"

#define NMax 30
class TableauOp{

 private:

  //Attributs
  
  Option T[NMax];
  size_t N;

  int  getOptionIndex(int id) const;
  int  getOptionIndex(const std::string &nom) const;
  
 public:

  //Constructeur
  
  TableauOp();

  //Methodes

  void addOption(const Option& op);
  void affOptions() const;
  int idOption(const std::string& nom) const;
  Option::argType typeArg(const std::string& nom) const;

};
