#include "Cellule.h"

Cellule::Cellule():estVivante(true),x(0),y(0),color(BLUE){}

Cellule::Cellule(bool estVivante, int x, int y, Color color){
  this->estVivante=estVivante;
  this->x=x;
  this->y=y;
  this->color = color;
}

bool Cellule::estVoisine(Cellule c) const{
  return(estVivante &&  (((c.x-x)*(c.x-x) + (c.y-y)*(c.y-y))<=2));
}
bool Cellule::getEstVivante() const{
  return estVivante;
}
void Cellule::setEstVivante(bool estVivante){
  this->estVivante=estVivante;
}
int Cellule::getX() const{
  return x;
}
void Cellule::setX(int x){
  this->x=x;
}
int Cellule::getY() const{
  return y;
}
void Cellule::setY(int y){
  this->y=y;
}
Cellule::Color Cellule::getColor() const{
  return color;
}
void Cellule::setColor(Color color){
  this->color = color;
}
string Cellule::afficherColor(){
  switch(color){
  case RED:
    return "Rouge";
    break;
  case BLUE:
    return "Bleu";
    break;
  case GREEN:
    return "Vert";
    break;
  case BLACK:
    return "Noir";
    break;
  default:
    return "pas de couleur";
    break;
  }
}
