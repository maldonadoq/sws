#include <iostream>

using namespace std;

class nodo
{
    public:
        int dato;
        nodo* sig;
        nodo(int);
        virtual ~nodo();
};

nodo::nodo(int a){
    dato=a;
    sig=NULL;
}
nodo::~nodo(){}



class lista{

public:
    static lista* getinstancia(){
        if (unico == NULL)
            unico = new lista();
        return unico;
    }
    nodo* primero;
    nodo* ultimo;
        
    void add(int );
    void print();
    virtual ~lista(); 

private:
        lista();
        static lista* unico;
};

lista* lista::unico = NULL;

lista::lista(){
    primero = NULL;
    ultimo = NULL;
}

void lista::add(int x){
    if (!primero){
        primero=new nodo(x);
        ultimo=primero;
    }
    else{
        ultimo->sig=new nodo(x);
        ultimo=ultimo->sig;
    }
}

void lista:: print(){

    nodo* temp;
    temp=primero;
    while(temp!=NULL){
        cout <<temp->dato<<endl;
        temp=temp->sig;
    }
}

lista::~lista(){   }

int main(int argc, char const *argv[])
{
    lista *a = lista::getinstancia();
    a->add(5);
    a->add(4);
    a->add(24);
    a->print();

    lista *b = lista::getinstancia();
    b->print();

    return 0;
}
