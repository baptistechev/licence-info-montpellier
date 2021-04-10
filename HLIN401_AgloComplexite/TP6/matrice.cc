#include <iostream>
#include <cfloat>
#include "matrice.h"

using namespace std;

template <typename T>
T** matrice(int m, int n)
{
  T** M = new T*[m];
  for (int i=0; i < m; i++)
    M[i] = new T[n];
  return M;
}

template <typename T>
void initialise(int m, int n, T** M, T val)
{
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      M[i][j] = val;
}

template <typename T>
void afficheMatrice(int m, int n, T** M)
{
  for (int i=0; i < m; i++)
  {
    for (int j=0; j < n; j++)
    {
      if (M[i][j] == FLT_MAX) cout << "INF ";
      else cout << M[i][j] << ' ';
    }
    cout << endl;
  }
}

template int** matrice(int, int);
template float** matrice(int, int);

template void initialise(int, int, int**, int);
template void initialise(int, int, float**, float);

template void afficheMatrice(int, int, int**);
template void afficheMatrice(int, int, float**);
