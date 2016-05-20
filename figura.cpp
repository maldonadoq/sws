#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class figura
{
	protected:
		string _name;
	public:
		figura(string );
		void set_name(string );
		const string get_name();
};

class circulo : public figura
{
	double _radio;

	public:
		circulo(string w, double y) : figura(w)
		{_radio = y;}
        	void set_radio(double);
		const double get_radio();
		const double get_area()
        	{   return 3.1416*_radio*_radio;    }
};


class rectangulo : public figura
{
	double _lg, _ancho;

    	public:
            	rectangulo(string n, double l, double w) : figura(n)
            	{ _lg = l ; _ancho = w;}
            	void set_lg(double);
            	void set_ancho(double);
            	const double get_lg();
            	const double get_ancho();
            	const double get_area()
            	{   return _lg*_ancho;    }
};

class triangulo : public figura
{
	double _base, _altura;

    	public:
		triangulo(string n, double l, double w) : figura(n)
            	{ _base = l ; _altura = w;}
            	void set_base(double);
            	void set_altura(double);
            	const double get_base();
            	const double get_altura();
            	const double get_area()
            	{   return 0.5*_base*_altura;    }
};


// Implementacion de class figure

figura::figura(string a){	_name = a;	}
void figura::set_name(string a){	_name = a;	}
const string figura::get_name(){	return _name;	}

// Implementacion de la clase circulo

void circulo::set_radio(double r){	_radio = r;	}
const double circulo::get_radio(){	return _radio;	}

// implementacion de la clase rectangulo

void rectangulo::set_lg(double q){   	 _lg = q;	}
void rectangulo::set_ancho(double d){  	_ancho = d;	}
const double rectangulo::get_lg(){    	return _lg;	}
const double rectangulo::get_ancho(){	return _ancho;	}

// Implementacion de la clase triangulo

void triangulo::set_base(double b){    	_base = b;	}
void triangulo::set_altura(double h){  	_altura = h;	}
const double triangulo::get_base(){    	return _base;	}
const double triangulo::get_altura(){  	return _altura;	}


int main()
{
	circulo c("circulo", 2.1);
	cout << c.get_name() << endl;
	cout << "radio: " << c.get_radio() << endl;
	cout << "radio: " << c.get_area() << endl;
    	cout << endl << endl;

	rectangulo r("rectangulo", 4.3 , 2.5);
	cout << r.get_name() << endl;
	cout << "ancho: " << r.get_ancho() << " -- " << "longitud: " << r.get_lg() << endl;
	cout << "area: " << r.get_area() << endl;
    	cout << endl << endl;

    	triangulo t("triangulo", 4, 2);
    	cout << t.get_name() << endl;
    	cout << "base: " << t.get_base() << " -- " << "altura: " << t.get_altura() << endl;
    	cout << "area: " << t.get_area() << endl;

	/*
    	figura *sha[3]={new circulo("circulo", 2.1),
    	new rectangulo("rectangulo", 3.2, 5.2),
    	new triangulo("triangulo", 3.4, 7.2)
    	};
    	int i;
    	for(i=0;i<3;i++){
        	cout << "shave ->  " << i+1 << "  area: " << sha[i]->get_area() << endl;
    	}*/

	return 0;
}
