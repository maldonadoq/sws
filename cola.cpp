#include <iostream>

using namespace std;

class nodo
{
public:
	int _dato;
	nodo *sig;
	nodo(int dato);
};

nodo::nodo(int dato)
{
	_dato = dato;
	sig = NULL;
}


class cola
{
public:
	nodo *primero;
	nodo *ultimo;
	cola();
	void encolar(int dato);
	void print();
	void dele();
	bool clean();
};

cola::cola()
{
	primero = NULL;
	ultimo = NULL;
}

void cola::encolar(int dato){
	if(!primero){
		primero = new nodo(dato);
		ultimo = primero;
	}
	else{
		ultimo->sig = new nodo(dato);
		ultimo = ultimo->sig;
	}
}

void cola::print(){
	nodo *temp = primero;
	while(temp!=NULL){
		cout << temp->_dato << " ";
		temp = temp->sig;
	}
}

void cola::dele(){
	nodo *temp = primero;
	primero = temp->sig;
	delete(temp);
}

bool cola::clean(){
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

	cola A;

	A.encolar(12);
	A.encolar(6);
	A.encolar(654);
	A.encolar(1232);
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
