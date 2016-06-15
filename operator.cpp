#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class nodo
{
    	public:
        	int  _dato;
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
            void ordenar();
            lista& operator+(lista a);
            lista operator-(lista a);
            lista operator<<(lista a);
            lista operator>>(lista a);
};

nodo::nodo(int a){
    	_dato=a;
    	sig=NULL;
}

lista::lista(){
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


void lista::ordenar()
{
    nodo *temp;
    nodo *aux;
    int s, r;
    for(temp=primero;temp!=NULL;temp=temp->sig)
        for(aux=temp;aux!=NULL;aux=aux->sig)
            if(temp->_dato > aux->_dato){
                s=temp->_dato;
                temp->_dato = aux->_dato;
                aux->_dato = s;         
            }
}


lista& lista::operator+(lista a){
	nodo *temp = primero;
    nodo *aux = a.primero;

    lista A;
  
    bool t=true;
    while(t){
    	A.inser(temp->_dato + aux->_dato);
    	temp = temp->sig;
    	aux = aux->sig;
    	if(aux==NULL){
    		while(temp!=NULL){
    			A.inser(temp->_dato);
    			temp = temp->sig;
    		}
    		t = false;
    	}
    	else if(temp==NULL){
    		while(aux!=NULL){
    			A.inser(aux->_dato);
    			aux = aux->sig;
    		}
    		t = false;
    	}
    }

    return A;  
}

lista lista::operator-(lista a){
	nodo *temp = primero;
    nodo *aux = a.primero;
    lista A;
  
    bool t=true;
    while(t){
    	A.inser(temp->_dato - aux->_dato);
    	temp = temp->sig;
    	aux = aux->sig;
    	
    	if(temp==NULL){
    		while(aux!=NULL){
    			A.inser(0 - (aux->_dato));
    			aux = aux->sig;
    		}
    		t = false;
   		}

    	else if(aux==NULL){
    		while(temp!=NULL){
    			A.inser(temp->_dato);
    			temp = temp->sig;
    		}
    		t = false;
    	}
    }

    return A;
}

lista lista::operator<<(lista a){
	nodo *temp = primero;
	nodo *aux = a.primero;
	lista A;

	while(temp!=NULL){
		A.inser(temp->_dato);
		temp = temp->sig;
	}
	while(aux!=NULL){
		A.inser(aux->_dato);
		aux = aux->sig;
	}

	return A;
}


lista lista::operator>>(lista a){
	nodo *temp = primero;
	nodo *aux = a.primero;
	lista A;

	while(temp!=NULL){
		A.inser(temp->_dato);
		temp = temp->sig;
	}
	while(aux!=NULL){
		A.inser(aux->_dato);
		aux = aux->sig;
	}
	A.ordenar();
	return A;
}

void lista:: print()
{
    	nodo* temp;
    	temp=primero;
    	while(temp != NULL){
        	cout << temp->_dato << "  ";
        	temp = temp->sig;
    	}
        cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	    lista sws;
    	sws.inser(2);
    	sws.inser(7);
	    sws.inser(9);
        sws.inser(1);
        sws.inser(5);
        sws.inser(4);
        sws.inser(11);
        cout << "lista sws: " << endl;
        sws.print();

        lista asd;
        asd.inser(8);
        asd.inser(3);
        asd.inser(6);
        asd.inser(10);
        cout << "lista asd: " << endl;
        asd.print();

        lista A, B, C, D;

        A = sws + asd;
        cout << "sws + asd: " << endl;
        A.print();

        B = sws - asd;
        cout << "sws - asd: " << endl;
        B.print();

        C = sws << asd;
        cout << "sws concatenacion asd: " << endl;
        C.print();

        D = sws >> asd;
        cout << "sws merge asd: " << endl;
        D.print();

	return 0;
}