class C1
{
    protected: 
        virtual void f(){}
        friend class A;
        friend class B;
        // friend class C2;
        // friend class D;
        // friend int main();
    public:
        virtual void mc1();
};

class C2 : public virtual C1
{
    protected:
        virtual void f(){}
    public:
        virtual void mc2();
        friend class D;
};

void C1::mc1() {
    C1 *c1; 
    c1->f(); 
    C2 *c2; 
    c2->f();
}

void C2::mc2() {
    C1 *c1; 
    c1->f(); // sender C2, receiver C1
    C2 *c2; 
    c2->f();
}

class A
{
    public:
        virtual void ma() {
            C1 *c1; 
            c1->f(); 
            C2 *c2; 
            c2->f();
        }
};

class B : public virtual A
{
    public:
        virtual void mb() {
            C1 *c1; 
            c1->f(); 
            C2 *c2; 
            c2->f();
        }
};

class D
{
    public:
        virtual void md(){
            C1 *c1; 
            c1->f(); 
            C2 *c2; 
            c2->f();
        }
};

int main(){
    C1 *c1; 
    c1->f(); 
    C2 *c2; 
    c2->f();
}