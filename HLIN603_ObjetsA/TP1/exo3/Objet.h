#ifndef Objet_f
#define Objet_f
#include<iostream>
#include <string>
using namespace std;

class Objet{

    private:
        string desc;
        int ref;
    public:
        Objet();
        Objet(const string, const int);
        virtual ~Objet();
        virtual void setDesc(const string);
        virtual void setRef(const int);
        virtual string getDesc() const;
        virtual int getRef() const;
};

ostream& operator<<(ostream& os, const Objet& obj);
istream& operator>>(istream& is, Objet& obj);

#endif