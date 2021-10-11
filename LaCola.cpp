
// ADMINISTRACIÓN DE UNA COLA CON UNA LISTA LINEAL SIMPLEMENTE ENLAZADA
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class Cola{

    private:
        nodo *pCola;
    
    public:
        Cola();
        ~Cola();
        void insertaNodo(void);
        void insertar(int);
        //void mostrarListaIter(void);
        void mostrarColaRec(void);
        void mostrarColaRecAux(nodo *);
        void mostrarColaRecAux2(nodo *);
        void eliminarUno(void);
    };

Cola::Cola(void){
    pCola = NULL;
}

Cola::~Cola(){
    cout << "Destructor ejecutándose" << endl;
    nodo *p;
    while(pCola){
        cout << "Estoy en la iteración" << endl;
        p = pCola;
        pCola = pCola->sig;
        delete p;
    }
}

void Cola::insertaNodo(void){
    int dato, datoRef;

    cout << "Digite un entero o Ctrl-d para terminar: ";
    while(cin >> dato){
        insertar(dato);
        cout << "Digite un entero o Ctrl-d para terminar: ";
    }
    cout << endl;
}

void Cola::insertar(int dato){
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pCola;
    pCola = nuevo;
}

void Cola::mostrarColaRec(void){
    //mostrarColaRecAux(pCola);
    //pCola = NULL;
    mostrarColaRecAux2(pCola);
}

void Cola::mostrarColaRecAux(nodo *saltarin){
    if(saltarin){
        mostrarColaRecAux(saltarin->sig);
        cout << saltarin->dato << endl;
        delete saltarin;
    }
}

void Cola::mostrarColaRecAux2(nodo *saltarin){
    if(saltarin){
        mostrarColaRecAux2(saltarin->sig);
        cout << saltarin->dato << endl;
    }
}

void Cola::eliminarUno(){
    nodo *saltarin1, *saltarin2;

    if(!pCola)
        cout << "La cola está vacía, no de puede eliminar nada" << endl;
    else{
        saltarin1 = pCola;
        saltarin2 = NULL;
        while(saltarin1->sig){
            saltarin2 = saltarin1;
            saltarin1 = saltarin1->sig;
        }
        if(!saltarin2){
            pCola = NULL;
            delete saltarin1;
        }
        else{
            saltarin2->sig = NULL;
            delete saltarin1;
        }
    }
}

int main(void){
    cout << endl;
    cout << "ADMINISTRACIÓN DE UNA COLA CON UNA LISTA LINEAL SIMPLEMENTE ENLAZADA" << endl << endl;

    Cola objCola;

    cout << "Insertar datos en la cola:" << endl;
    objCola.insertaNodo();

    cout << "Eliminando un nodo de la cola" << endl;
    objCola.eliminarUno();

    cout << "Monstarndo todos los nodos de la cola" << endl;
    //objCola.mostrarListaIter();
    objCola.mostrarColaRec();

    cout << endl;
    return 0;
}