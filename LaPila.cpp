
// ADMINISTRACIÓN DE UNA PILA A PARTIR DE UNA LISTA LINEAL SIMPLEMENTE ENLAZADA
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class Pila{

    private:
        nodo *pTope;
    
    public:
        Pila();
        ~Pila();
        void insertaNodo(void);
        void insertar(int);
        void mostrarPilaIter(void);
        void mostrarPilaIter2(void);
        void mostrarListaRec(void);
        void mostrarListaRecAux(nodo *);
        void eliminarNodo(void);
};

Pila::Pila(void){
    pTope = NULL;
}

Pila::~Pila(){
    cout << "Destructor ejecutándose" << endl;
    nodo *p;
    while(pTope){
        cout << "Me metí al while" << endl;
        p = pTope;
        pTope = pTope->sig;
        delete p;
    }
}

void Pila::insertaNodo(void){
    int dato;

    cout << "Digite un entero o Ctrl-d para terminar: ";
    while(cin >> dato){
        insertar(dato);
        cout << "Digite un entero o Ctrl-d para terminar: ";
    }
    cout << endl;
}

void Pila::insertar(int dato){
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pTope;
    pTope = nuevo;
}

void Pila::mostrarPilaIter(void){
    nodo *saltarin;

    cout << endl;
    saltarin = pTope;
    while(saltarin != NULL){
        cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}

void Pila::mostrarPilaIter2(void){
    nodo *saltarin;

    cout << endl;
    saltarin = pTope;
    while(pTope){
        saltarin = pTope;
        pTope = pTope->sig;
        cout << saltarin->dato << endl;
        delete saltarin;
    }
}

void Pila::mostrarListaRec(void)
{
    mostrarListaRecAux(pTope);
}

void Pila::mostrarListaRecAux(nodo *saltarin)
{
    if(saltarin){
        mostrarListaRecAux(saltarin->sig);
        cout << saltarin->dato << endl;
    }
}

void Pila::eliminarNodo(void)
{
    nodo *aux;

    if(pTope){
        aux = pTope;
        pTope = pTope->sig;
        cout << aux->dato << endl;
        delete aux;
    }
}

int main(void){
    cout<<endl;
    cout<<"ADMINISTRACIÓN DE PILA CON UNA LISTA LINEAL SIMPLEMENTE ENLAZADA"<<endl<<endl;

    Pila objPila;

    cout<<"Insertar datos en la pila:"<<endl;
    objPila.insertaNodo();

    cout<<"Los elementos de la pila son:"<<endl;
    objPila.mostrarPilaIter2();

    cout<<"Eliminar solo el nodo del tope:"<<endl;
    objPila.eliminarNodo();

    cout<<"Los elementos de la pila son:"<<endl;
    objPila.mostrarPilaIter();

    cout<<endl;
    return 0;
}
