#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class ALUMNO_UCSP
{
	public:
    		string _nombre;
    		string _carrera;
    		string _universidad;
		int _cui;
		
		void obt_infor(int);	
		void mostrar_info();	
		int get_cui();
};

void ALUMNO_UCSP :: obt_infor(int x)
{
	cout << "nombre: "; cin >> _nombre;
    	cout << "carrera: "; cin >> _carrera;
    	cout << "univesidad: "; cin >> _universidad;
    	cout << "cui: "; cin >> _cui;
}

void ALUMNO_UCSP :: mostrar_info()
{
	cout << "nombre: " << _nombre << endl;
        cout << "carrera: " << _carrera << endl;
        cout << "univesidad: " << _universidad << endl;
        cout << "cui: " << _cui << endl;
}


int ALUMNO_UCSP :: get_cui()
{
    	return _cui;
}

int main()
{
    	// OBTENER INFORMACION
    	int i,j,n;
    	cout << "tamaño: ";
    	cin >> n;
    	ALUMNO_UCSP v[n];
    	system("clear");
    	for(i=0;i<n;i++)
    	{
        	v[i].obt_infor(i);
        	system("clear");
    	}
    	
    	// ORDENAR (BURBUJASO)
	ALUMNO_UCSP temp;
	for (i=0;i<n;i++)
        	for (j=i;j<n;j++)
       			if (v[i].get_cui() > v[j].get_cui())
            		{
                		temp = v[i];
                		v[i] = v[j];
                		v[j] = temp;
            		}

	//MOSTRAR INFORMACION
	for(i=0;i<n;i++){
        	v[i].mostrar_info();
		cout << endl;
    	}
	return 0;
}
