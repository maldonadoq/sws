#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class nodo
{
    public:
        int _dato;
        nodo *sig;
        nodo(int );
};

class lista
{
    public:
        lista();
        nodo *primero;
        nodo *ultimo;
        void inser(int );
        void print();
};

nodo::nodo(int a)
{
    _dato=a;
    sig=NULL;
}


lista::lista()
{
    primero=NULL;
    ultimo=NULL;
}

void lista::inser(int x)
{
    if(!primero){
        primero = new nodo(x);
        ultimo = primero;
    }
    else{
        ultimo->sig = new nodo(x);
        ultimo = ultimo->sig;
    }
}

void lista:: print()
{
    nodo* temp;
    temp=primero;
    while(temp != ultimo->sig){
        cout << temp->_dato << endl;
        temp = temp->sig;
    }
}


int main()
{
    lista sws;
    sws.inser(4);
    sws.inser(4);
    sws.print();
    return 0;
}

