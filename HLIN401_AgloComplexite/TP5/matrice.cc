#include <iostream>

using namespace std;

int** matrice(int m, int n)
{
  int** M = new int*[m];
  for (int i=0; i < m; i++)
    M[i] = new int[n];
  return M;
}

void initialise(int m, int n, int** M, int val)
{
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      M[i][j] = val;
}

void desalloue(int m, int n, int** M)
{
  for (int i=0; i < m; i++) delete M[i];
  delete M;
}

void affiche(int m, int n, int** M)
{
  for (int i=0; i < m; i++)
  {
    for (int j=0; j < n; j++)
      cout << M[i][j] << ' ';
    cout << endl;
  }
}
