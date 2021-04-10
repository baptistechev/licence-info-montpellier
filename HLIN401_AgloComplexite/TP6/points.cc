#include <iostream>
#include <fstream>

#include "points.h"

#define LARGEUR 1000
#define HAUTEUR 1000

using namespace std;

void pointsAleatoires(int n, coord* points)
{
  for(int i=0;i<n;i++){
    points[i].x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX/LARGEUR);
    points[i].y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX/HAUTEUR);
  }
}

void dessinPoints(int n, coord* points, string nom)
{
  ofstream output;                        
  output.open(nom + ".svg",ios::out);
  output << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
  output << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" " 
         << "width=\"" << LARGEUR << "\" height=\"" << HAUTEUR << "\">" << endl;
  output << "<rect width=\"100%\" height=\"100%\" fill=\"white\" x=\"0\" y=\"0\"/>" << endl;
  output << endl;  
  for (int i=0;i<n;i++)
    output << "<circle cx=\"" << points[i].x << "\" cy=\"" << points[i].y << "\" "
           << "r=\"5\" fill=\"red\" stroke=\"black\" stroke-width=\"2\" />" << endl;
  output << endl;
  output << "</svg>" << endl;
  output.close();
}

void dessinTsp(int n, coord* points, int* circuit, string nom)
{
  ofstream output;                        
  output.open(nom + ".svg",ios::out);
  output << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
  output << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" " 
         << "width=\"" << LARGEUR << "\" height=\"" << HAUTEUR << "\">" << endl;
  output << "<rect width=\"100%\" height=\"100%\" fill=\"white\" x=\"0\" y=\"0\"/>" << endl;
  output << endl;  
  for (int i=0; i < n; i++)
    output << "<line x1=\"" << points[circuit[i]].x << "\" y1=\"" << points[circuit[i]].y << "\" "
           << "x2=\"" << points[circuit[(i+1)%n]].x << "\" y2=\"" << points[circuit[(i+1)%n]].y << "\" "
           << "stroke=\"black\" stroke-width=\"2\" />" << endl;

  for (int i=0;i<n;i++)
    output << "<circle cx=\"" << points[i].x << "\" cy=\"" << points[i].y << "\" "
           << "r=\"5\" fill=\"red\" stroke=\"black\" stroke-width=\"2\" />" << endl;
  output << endl;
  output << "</svg>" << endl;
  output.close();
}

ostream& operator<<(ostream& os, const coord& p)
{
  os << "(" << p.x << "," << p.y << ")";
  return os;
}

void affichePoints(int n, coord* points)
{
  for (int i = 0; i < n-1; i++)
    cout << points[i] << ", ";
  cout << points[n-1] << endl;
}

#undef LARGEUR
#undef HAUTEUR
