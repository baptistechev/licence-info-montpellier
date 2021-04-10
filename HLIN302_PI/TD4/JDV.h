#include "population-vivante.h"
#include "tableauOp.h"

class JDV{

 private:
  PopulationVivante pop;
  TableauOp opts;

 public:
  JDV();

  void nettoie(std::string &s);
  bool findCleVal(std::string &s,std::string &cle,std::string &value);
  void loadConfig(std::string file);
  void traiteOption(std::string cle, std::string value);

  void parseOption(int argc, char** argv);
  void run();
  
};
