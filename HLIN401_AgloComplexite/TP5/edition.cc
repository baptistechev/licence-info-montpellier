#include <iostream>
#include <string>

#include "matrice.h"

using namespace std;

int valeur(int** E, int i, int j)
{  
  if(i>=0 && j>=0)
    return E[i][j];
  else if(j == -1)
    return i+1;
  else if(i == -1)
    return j+1;
}

int min(int a, int b, int c)
{
  return min(a,min(b,c));
}

int distanceEdition(string s1, string s2, int** E)
{
  int n1 = s1.size();
  int n2 = s2.size();
  int e;
  
  for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
      e = (s1[i] == s2[j])? 0 : 1;
      E[i][j] = min(valeur(E,i-1,j)+1, valeur(E,i,j-1)+1, valeur(E,i-1,j-1)+e);
    }
  }
  return E[n1-1][n2-1];
}

string alignement(string& s1, string& s2, int** E)
{
  int i = s1.size()-1;
  int j = s2.size()-1;
  string aligne;
  char pause;


  while(i>=0 && j>=0){

    if(valeur(E,i,j) == valeur(E,i-1,j-1) && s1[i] == s2[j]){
      i--;j--;
    }else if(valeur(E,i,j) == valeur(E,i-1,j-1)+1){
      i--;j--;
    }else if(valeur(E,i,j) == valeur(E,i-1,j)+1){
      s2.insert(j+1,"_");
      i--;
    }else if(valeur(E,i,j) == valeur(E,i,j-1)+1){
      s1.insert(i+1,"_");
      j--;
    }
  }

  while(i>=0){
    s2.insert(0,"_");
    i--;
  }
  while(j>=0){
    s1.insert(0,"_");
    j--;
  }
  for(int k=0; k<s1.size(); k++){
    if(s1[k]==s2[k]){
      aligne += "|";
    }
    else if(s1[k]=='_'){
      aligne += "I";
    }
    else if(s2[k]=='_'){
      aligne += "S";
    }
    else if(s1[k]!=s2[k]){
      aligne += "R";
    }
  }
  return aligne;   
}
