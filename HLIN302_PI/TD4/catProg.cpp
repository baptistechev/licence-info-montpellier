#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
  
  //Verifier la presence d'1 argument
  if(argc<2){return 1;}


  for(int i = 1; i < argc;i++){
  //ouvrir le fichier et verifier qu'il existe  
    ifstream ifs(argv[i]);
    if(!ifs.is_open()){return 2;}

    //afficher le contenu du fichier
    while(!ifs.eof()){
      string s;
      getline(ifs,s);
      cout << s << endl;
    }

    ifs.close();
  }
  return 0;
}
