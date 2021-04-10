#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>
#include "ABR.h"

using namespace std;

//------------------------------------------------------
// Inserer un noeud z dans l'arbre A
//------------------------------------------------------

void ABR::inserer(int k)
{
  noeud* x = this->racine;
  noeud* p = NULL;
  while(x!=NULL){
    p = x;
    if(k < x->val){
      x = x->filsG;
    }else{
      x = x->filsD;
    }
  }
  noeud* z = new noeud(k);
  z->pere = p;
  if(p == NULL){
    this->racine = z;
  }else if(z->val < p->val){
    p->filsG = z;
  }else{
    p->filsD = z;
  }
}

//------------------------------------------------------
// Parcours infixe
//------------------------------------------------------

void ABR::parcoursInfixe(noeud* x)
{
  if(x!=NULL){
    parcoursInfixe(x->filsG);
    cout << x->val << " ";
    parcoursInfixe(x->filsD);
  }
}

//------------------------------------------------------
// Noeud de valeur minimale dans l'arbre
//------------------------------------------------------

noeud* ABR::minimum(noeud* x)
{
  while(x->filsG != NULL){
    x = x->filsG;
  }
  return x;
}

//------------------------------------------------------
// Recherche d'un noeud de valeur k
//------------------------------------------------------

noeud* ABR::rechercher(int k)
{
  noeud* x = this->racine;
  while(x!=NULL && x->val!=k){
    if(k < x->val){
      x = x->filsG;
    }else{
      x = x->filsD;
    }
  }
  return x;
}

//------------------------------------------------------
// Recherche du successeur du noeud x
//------------------------------------------------------

noeud* ABR::successeur(noeud *x)
{
  if(x->filsD != NULL){
    return minimum(x->filsD);
  }
  noeud* p = x->pere;
  while( p != NULL && x == p->filsD){
    x = p;
    p = x->pere;
  }
  return p;
}

//------------------------------------------------------
// Suppression d'un noeud
//------------------------------------------------------

void ABR::supprimer(noeud* z)
{
  if(z->filsG == NULL){
    remplacer(z,z->filsD);
  }else if(z->filsD == NULL){
    remplacer(z,z->filsG);
  }else{
    noeud* y = successeur(z);
    remplacer(y,y->filsD);
    y->filsD = z->filsD; z->filsD = NULL;
    y->filsG = z->filsG; z->filsG = NULL;
    if(y->filsD != NULL){
      y->filsD->pere = y;
    }
    if(y->filsG != NULL){
      y->filsG->pere = y;
    }
    remplacer(z,y);
  }
}


//------------------------------------------------------
// Rotations
//------------------------------------------------------

void ABR::rotationGauche(noeud* z)
{
  noeud* pere = z->pere;
  noeud* pivot = z->filsD;
  z->filsD = pivot->filsG;
  pivot->filsG = z;
  z = pivot;
  pere->filsG = z;
}

void ABR::rotationDroite(noeud* z)
{
  noeud* pere = z->pere;
  noeud* pivot = z->filsG;
  z->filsG = pivot->filsD;
  pivot->filsD = z;
  z = pivot;
  pere->filsG = z;
}
