#ifndef Compte_h
#define Compte_h

class Compte
{
    private:
        int solde;
    public:
        Compte();
        virtual ~Compte();
        virtual int getSolde()const;
        virtual void setSolde(const int);
        virtual void deposer(const int);
};

#endif