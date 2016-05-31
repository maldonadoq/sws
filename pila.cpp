#include <iostream>

using namespace std;

class nodo{
public:
	int _dato;
	nodo *sig;
	nodo(int );
};

nodo::nodo(int x){
	_dato = x;
	sig = NULL;
}

class pila{
public:
	nodo *primero;
	nodo *ultimo;

	pila();
	void empilar(int );
	void print();
	void dele();
	bool clean();
};

pila::pila(){
	primero = NULL;
	ultimo = NULL;
}

void pila::empilar(int w){
	if(!primero){
		primero = new nodo(w);
		ultimo = primero;
	}
	else{
		nodo *temp = primero;
		nodo *asd;
		asd = new nodo(w);
		asd->sig = temp;
		primero = asd;	
	}
}

void pila::print(){
	nodo *temp = primero;
	while(temp!=NULL){
		cout << temp->_dato << " ";
		temp = temp->sig;
	}
}


void pila::dele(){
	nodo *temp = primero;
	primero = temp->sig;
	delete(temp);
}

bool pila::clean(){
	nodo *temp;
	while(primero != NULL){
		temp= primero;
		primero = temp->sig;
		delete(temp);
	}
	primero = NULL;
	ultimo = NULL;
	return false;
}

int main(){
	pila A;
	A.empilar(12);
	A.empilar(54);
	A.empilar(124);
	A.empilar(2);
	A.print();
	cout << endl;

	A.dele();
	A.print();
	cout << endl;

	A.dele();
	A.print();
	cout << endl;

	cout << A.clean() << endl;

	return 0;
}
