#include <iostream>

using namespace std;

// POLIMORFISMO
class sell
{
    public:
        int* lista;
        int tamano;
        sell(int* a, int x);
        void print();
        void invertir();
        void busqueda_secuencial(int );
        void busqueda_binaria(int );
        virtual void ordenar()=0;
};

sell::sell(int* a, int x){  lista=a;  tamano=x;  }

void sell::busqueda_secuencial(int x){
    for(int i=0; i<tamano;i++){
        if(x == lista[i]){ 
            cout << "si se encuentra :V" << endl;
            break;
        }
        else cout << "no se encuentra :V" << endl;
    }
}

void sell::busqueda_binaria(int w){
    int m, p=0; 
    int u=tamano-1;
    while(p<=u){
        m=(p+u)/2;
        if(w==lista[m]) break;
        else if(w<lista[m]) u=m-1;
        else p=m+1;
    }
    
    if(w==lista[m]) cout << "si se encuentra :V" << endl;
    else cout << "no se encuentra :V" << endl;
}

void sell::print(){
    for (int i=0; i<tamano; i++)
        cout<<lista[i]<<" ";
}

class burbuja : public sell{
public:
    burbuja(int* a, int x) :sell(a,x) {  lista=a;  tamano=x;  }
    virtual void ordenar(){
        int temp;
        for (int i=0; i<tamano-1;i++)
            for (int j=0; j<tamano-1;j++)
                if (lista[j]>lista[j+1]){
                    temp=lista[j];
                    lista[j]=lista[j+1];
                    lista[j+1]=temp;
                }   
    }
};

class inserccion : public sell{
public:
    inserccion(int* a, int x)  :sell(a,x) {  lista=a;  tamano=x;  }
    virtual void ordenar(){
        int temp;
        for (int i=0; i<tamano; i++){
            temp=lista[i];
            for (int j=i; j>0  and temp<lista[j-1]; j--){
                lista[j]=lista[j-1];
                lista[j-1]=temp;
            }
        }
    }
};

class seleccion : public sell{
public:
    seleccion(int* a, int x) :sell(a,x) {  lista=a;  tamano=x;  }
    virtual void ordenar(){
        int temp;
        for (int i=0; i<tamano-1; i++)
            for(int j=i+1; j<tamano; j++)
                if (lista[j]<lista[i]){
                    temp=lista[j];
                    lista[j]=lista[i];
                    lista[i]=temp;
                }
    }
};

class quick_sort : public sell{
public:
    quick_sort(int* a, int x) :sell(a,x){  lista=a;  tamano=x;  }
    virtual void ordenar();
};


int quicksort(int *v, int iz, int de)
{
     int i = iz, j = de, w;
     int p = v[(iz + de) / 2];

     while (i <= j)
     {
          while (v[i] < p) i++;
          while (v[j] > p) j--;
          if (i <= j)
           {
               w = v[i];
               v[i] = v[j];
               v[j] = w;
               i++; j--;
          }
     }

     if (iz < j)
          quicksort(v, iz, j);
     if (i < de)
          quicksort(v, i, de);
    return 0;
}

void quick_sort::ordenar(){
    quicksort(lista,0,tamano-1);
}

// LISTA ENLAZADA SIMPLE

template <class W>
class nodo
{
        public:
            W _dato;
            nodo<W> *sig;
            nodo(W w);
};


template <class W>
class lista
{
        public:
            lista();
            nodo<W> *primero;
            nodo<W> *ultimo;
            void inser(W x);
            void print();
            void invertir();
};


template <typename W>
nodo<W>::nodo(W w)
{
     _dato=w;
     sig=NULL;
}

template <typename W>
lista<W>::lista()
{
     primero=NULL;
     ultimo=NULL;
}

template <typename W>
void lista<W>::inser(W x)
{
        if(!primero){
            primero = new nodo<W>(x);
            ultimo = primero;
        }
        else{
            ultimo->sig = new nodo<W>(x);
            ultimo = ultimo->sig;
        }
}

template <typename W>
void lista<W>::invertir()
{
        nodo<W>* atras = NULL;
        nodo<W>* here = primero;
        nodo<W>* asd = primero;
        while (here != NULL){
                nodo<W>* next= here->sig;
                here->sig = atras;
                atras = here;
                here = next;
        }
    primero = atras;
    ultimo = asd;
}

template <typename W>
void lista<W>::print()
{
        nodo<W>* temp;
        temp=primero;
        while(temp != NULL){
            //cout << "desordenada" << endl;
            temp->_dato->print();
            cout << endl;
            /*temp->_dato->ordenar();
            cout << "ordenada" << endl;
            temp->_dato->print();
            cout << endl << endl;*/

            temp = temp->sig;
        }
}



int main(int argc, char const *argv[])
{
/* 
    int n;
    cout << "tamaño: "; cin >> n;
    int * a = new int[n];
    cout << "datos: " << endl;
    for (int i=0; i<n;i++)
        cin>>a[i];


    int g;
    cout << "tamaño: "; cin >> g;
    int * h = new int[g];
    cout << "datos: " << endl;
    for (int i=0; i<g;i++)
        cin>>h[i];


    int j;
    cout << "tamaño: "; cin >> j;
    int * k = new int[j];
    cout << "datos: " << endl;
    for (int i=0; i<j;i++)
        cin>>k[i];

    int l;
    cout << "tamaño: "; cin >> l;
    int * m = new int[l];
    cout << "datos: " << endl;
    for (int i=0; i<l;i++)
        cin>>m[i];
*/

    int n;
    cout << "tamaño: "; cin >> n;
    int * a = new int[n];
    cout << "datos: " << endl;
    for (int i=0; i<n;i++)
        cin>>a[i];


    sell *w = new burbuja(a,n);
    sell *x = new inserccion(a,n);
    sell *y = new seleccion(a,n);
    sell *v = new quick_sort(a,n);

    lista<sell *> A;
    A.inser(w);
    A.inser(x);
    A.inser(y);
    A.inser(v);
    A.print();

    return 0;
}