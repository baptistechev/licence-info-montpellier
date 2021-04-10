class B1
{
    private:
        virtual void y(){}
    public:
        virtual void mb1(){}
};

class B2
{
    private:
        virtual void x(){}
        friend class A;
    public:
        virtual void mb2(){}
};

class B : virtual public B1, virtual public B2
{
    protected:
        virtual void mbprivA();
    public:
    virtual void mbprivB();
        virtual void mb();
};

class A
{
    public:
        virtual void ma();
};

class C
{
    public:
        virtual void mc();
};

void B1::mb1(){
    B * b;
    b->x();
    b->y();
}

void B2::mb2(){
    B * b;
    b->x();
    b->y();
}

void B::mb(){
    B * b;
    b->x();
    b->y();
}

void A::ma(){
    B * b;
    b->x();
    b->y();
    b->mbprivA();
    b->mbprivB();
}

void C::mc(){
    B * b;
    b->x();
    b->y();
}

int main(int argc, char const *argv[])
{
    
}
