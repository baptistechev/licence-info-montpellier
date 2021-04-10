#include <string>
#include <iostream>

using namespace std;

class Cellule{

 public:
  enum Color{BLUE,GREEN,RED,BLACK};
    
  //Attributs
 private:
  
  bool estVivante;
  int x,y;
  Color color;

  //Constructeur
 public:
  Cellule();
  Cellule(bool estVivante, int x, int y, Color color);

  //Methodes

  bool estVoisine(Cellule c) const;
  bool getEstVivante() const;
  void setEstVivante(bool estVivante);
  int getX() const;
  void setX(int x);
  int getY() const;
  void setY(int y);
  Color getColor() const;
  void setColor(Color color);
  string afficherColor();
  
};
