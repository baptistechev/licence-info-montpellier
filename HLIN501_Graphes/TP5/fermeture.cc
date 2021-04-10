#include <iostream>
#include <vector>

using namespace std;

const int N=6;
const int INF=9999;                      //La valeur infinie.    

void fermetureTransitive(int arc[][N], int fermeture[][N]){
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      fermeture[i][j] = arc[i][j];
    }
    fermeture[i][i] = 1;
  }

  for (int k = 0; k < N; k++)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (fermeture[i][j] == 0 &&  (fermeture[i][k] + fermeture[k][j] == 2))
        {
          fermeture[i][j] = 1;
        }
      }
    }
  }
  
}

void affichage(int fermeture[][N]){
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << fermeture[i][j] << "   ";
    }
    cout << endl;
  }
}

void compFortConnexe(int fermeture[][N]){

    bool traite[N];
    vector<int> comp[N];

    for (int i = 0; i < N; i++)
    {
        traite[i] = false;
    }

    for (int k = 0; k < N; k++)
    {
        if(!traite[k]){

            comp[k].push_back(k);
            traite[k] = true;

            for (int i = 0; i < N; i++)
            {
                if(i!=k && fermeture[k][i] == 1){
                    bool all = true;
                    for (size_t j = 0; j<comp[k].size(); j++)
                    {
                        if(fermeture[i][comp[k][j]] == 0 || fermeture[comp[k][j]][i] == 0)
                            all = false;   
                    }
                    if(all){
                        comp[k].push_back(i);
                        traite[i] = true;
                    }     
                }
            }
        }
    }

    cout << "Les composantes fortements connexes sont : ";

    for (int i = 0; i < N; i++)
    {
        if(comp[i].size() != 0){
            cout << "{";
            for (size_t j = 0; j<comp[i].size()-1; j++)
                    cout << comp[i][j] << " ";
            cout << comp[i][comp[i].size()-1] << "}, ";
        }
    }
    
    
}

int main()
{

    int arc[N][N]= {{0,0,0,1,0,1},//La matrice d’adjacences du graphe oriente D.
                    {1,0,1,1,0,0},
                    {0,0,0,1,0,0},
                    {0,0,0,0,1,1},
                    {0,0,1,0,0,1},
                    {0,0,1,0,0,0}};
    int fermeture[N][N]; // La matrice de la fermeture transitive de D

    fermetureTransitive(arc, fermeture);
    affichage(fermeture); 
    compFortConnexe(fermeture); 

  return EXIT_SUCCESS;
}
