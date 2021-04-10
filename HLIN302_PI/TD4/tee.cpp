#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
  
  //Verifier la presence d'1 argument
  if(argc<2){return 1;}

  //creer le fichier et verifier qu'il existe
  ofstream ofs(argv[1]);
  if(!ofs.is_open()){return 2;}

  //ecrire dans le fichier
  while(!cin.eof()){
    string s;
    getline(cin,s);
    if(!ofs.eof()){
      ofs << s << endl;
    }
  }

  ofs.close();

  for(int i = 2; i < argc;i++){
  //ouvrir le fichier et verifier qu'il existe  
    ifstream ifs(argv[1]);
    ofstream ofs(argv[i]);
    if(!ifs.is_open()){return 2;}
    if(!ofs.is_open()){return 2;}

    //afficher le contenu du fichier
    while(!ifs.eof()){
      string s;
      getline(ifs,s);
      if(!ofs.eof()){
	ofs << s << endl;
      }
    }
    ofs.close();
    ifs.close();
  }

  
  return 0;
}
