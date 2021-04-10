#ifndef Vers_h 
#define Vers_h
#include<iostream>
#include<string>
using namespace std;

class Vers{

private:
    
    string suiteMots;
    string rime;

public:

    Vers(); 
    explicit Vers(string sm); 
    Vers(string sm, string r);
    virtual ~Vers();
    virtual string getSuiteMots()const;
    virtual void setSuiteMots(string sm);
    virtual string getRime()const;
    virtual void setRime(string r);
    virtual void saisie(istream& is);
    virtual void affiche(ostream& os)const;

};
#endif