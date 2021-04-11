#include "mm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Crèe un nouveau jeu en générant aléatoirement un nouveau mot secret
 * composé de TAILLE lettres comprises entre 0 et 9.
 * @return un pointeur sur le jeu créé dans le tas (donc à detruire !)
 */
mm mm_creer(){

  mm jeu = (mm)malloc(sizeof(struct mm));
  jeu->nbessais = 0;

  srand(time(NULL));
  for(int i =0;i<TAILLE;i++){
    int bool = 1;
    while(bool){
      jeu->secret[i] = (rand()%10) + 48;
      bool = 0;
      for(int j = 0;j<TAILLE;j++)
	if(j!=i && jeu->secret[i] == jeu->secret[j])
	  bool = 1;
    }
  }

  //  printf("%s\n",jeu->secret);
  return jeu;  
}


/**
 * Supprime un jeu en désallouant la mémoire
 * @param mm un pointeur sur la structure de jeu
 */
void mm_detruire(mm mm){

  free(mm);
  
}


/**
 * teste un mot essai face au mot secret stocké dans le jeu
 * @param jeu un pointeur sur la structure de jeu
 * @param essai la chaîne de caractères proposée par le joueur humain
 * @returns un entier contenant (TAILLE+1)*nb lettres bien placées + nb lettres
 * mal placées; -1 si l'essai est erroné (nb lettres, ...)
 */
int mm_test(mm jeu, char* essai){


  //Verification combinaison valide
  if(strlen(essai) != TAILLE)
    return -1;

  int nbFois[10];
  for(int i=0;i<10;i++)
    nbFois[i] = 0;
  
  for(int i =0;i<TAILLE;i++){
    if((int)(essai[i]-48) <0 || (int)(essai[i]-48)>9)
      return -1;
    
    nbFois[essai[i]]++;
    if(nbFois[essai[i]-48] > 1)
      return -1;
    
  }

  //nombre de chiffres identiques

  int chiffreBienPlace = 0;
  int chiffreMalPlace = 0;
  for(int i=0;i<TAILLE;i++){

    //pour les chiffres mal place
    for(int j=0;j<TAILLE;j++)
      if(jeu->secret[j] == essai[i])
	chiffreMalPlace++;

    //pour les chiffres bien place
    if(jeu->secret[i] == essai[i]){
        chiffreBienPlace++;
	chiffreMalPlace--;
    }
    
  }  

  jeu->nbessais++;
  return (TAILLE+1)*chiffreBienPlace + chiffreMalPlace;
  
}


/** 
 * Retourne le nb d'essais déjà effectués 
 * @param jeu un pointeur sur la structure de jeu
 * @returns le nombre d'essais
 */

int mm_nbessais(mm jeu){
  return jeu->nbessais;
}
