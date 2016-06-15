#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

template<class T>
class nodo
{
    	public:
        	T _dato;
        	nodo<T> *sig;
		    nodo<T> *back;
        	nodo(T );
};

template<class T>
class lista
{
    	public:
        	lista();
        	nodo<T> *primero;
        	nodo<T> *ultimo;
        	void inser(T );
        	void print();
		    void print_revez();
};

template<typename T>
nodo<T>::nodo(T a)
{
    	_dato=a;
    	sig=NULL;
	    back=NULL;
}

template<typename T>
lista<T>::lista()
{
    	primero=NULL;
    	ultimo=NULL;
}

template<typename T>
void lista<T>::inser(T x)
{
    	if(!primero){
        	primero = new nodo<T>(x);
        	ultimo = primero;
    	}
    	else{
		nodo<T> *temp;
		temp = ultimo;
        	ultimo->sig = new nodo<T>(x);
        	ultimo = ultimo->sig;
		ultimo -> back = temp;
    	}
}

template<typename T>
void lista<T>:: print()
{
    	nodo<T>* temp;
    	temp=primero;
    	while(temp != ultimo->sig){
        	cout << temp->_dato << endl;
        	temp = temp->sig;
    	}
}

template<typename T>
void lista<T>:: print_revez()
{
        nodo<T>* temp;
        temp=ultimo;
        while(temp != primero->back){
                cout << temp->_dato << endl;
                temp = temp->back;
        }
}

int main()
{
    	lista<int> sws;
    	sws.inser(2);
    	sws.inser(53);
	    sws.inser(12);
        sws.inser(76);

        lista<int> asd;
        asd.inser(24);
        asd.inser(3);
        asd.inser(1);
        asd.inser(7);

	sws.print();
	cout << endl;
	sws.print_revez();
    	return 0;
}

