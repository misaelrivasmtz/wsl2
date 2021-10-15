#include<iostream>

using namespace std;

//nodo
struct nodo{
    int dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
    nodo *head;
    
    public:
    ListaDoble();
    ~ListaDoble();

    void insInicio(int);
    void insNodoInicio();
    void mostrarListaDirectaIter();
    void mostrarListaDirInvIter();
    void insFinal(int);
    void insNodoFinal();
    void insDespuesElemento(int, int);
    void insNodoDespuesElto();
    void insAntesElemento(int, int);
    void insNodoAntesElto();
    void eliminarElemento(int);
    void eliminarNodo();
};

ListaDoble::ListaDoble(){
    head = NULL;
}

ListaDoble::~ListaDoble(){
    nodo *p;
    while(head){
        p = head;
        head = head->sig;
        delete p;
    }
}

void ListaDoble::insInicio(int dato){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = head;
    if(head){
        head->ant = nuevo;
    }
    head = nuevo;
}

void ListaDoble::insNodoInicio(){
    int dato;
    cout<<"Digite un entero o Ctrl-d para terminar: ";
    while(cin>>dato){
        insInicio(dato);
        cout<<"Digite un entero o Ctrl-d para terminar: ";
    }
    cout<<endl;
}

void ListaDoble::mostrarListaDirectaIter(){
    nodo *saltarin;
    saltarin = head;
    while(saltarin){
        cout<<saltarin->dato<<endl;
        saltarin = saltarin->sig;
        
    }
}

void ListaDoble::mostrarListaDirInvIter(){
    nodo *p, *q;
    p = head;
    q = NULL;
    while(p){
        cout<<p->dato<<endl;
        q = p;
        p = p->sig;
    }
    while(q){
        cout<<q->dato<<endl;
        q = q->ant;
    }
}

void ListaDoble::insFinal(int dato){
    nodo *nuevo, *saltarin;
    nuevo = new nodo;
    nuevo->dato = dato;
    if(!head){
        head = nuevo;
        head->sig = NULL;
        head->ant = NULL;
    }
    else{
        saltarin = head;
        while(saltarin->sig){
            saltarin = saltarin->sig;
        }
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::insNodoFinal(){
    int dato;
    cout<<"Digite un entero o Ctrl-d para terminar: ";
    while(cin>>dato){
        insFinal(dato);
        cout<<"Digite un entero o Ctrl-d para terminar: ";
    }
    cout<<endl;
}

void ListaDoble::insDespuesElemento(int dato, int datoRef){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;
    if(!head){
        head = nuevo;
        head->sig = NULL;
        head->ant = NULL;
    }
    else{
        nodo *saltarin;
        saltarin = head;
        while(saltarin->sig && saltarin->dato != datoRef){
            saltarin = saltarin->sig;
        }
        nuevo->sig = saltarin->sig;
        nuevo->ant = saltarin;
        if(saltarin->sig != NULL){
            saltarin->sig->ant = nuevo;
        }
        saltarin->sig = nuevo;
    }
}

void ListaDoble::insNodoDespuesElto(){
    int dato, datoRef;
    cout<<"Digite un entero o Ctrl-d para terminar: ";
    while(cin>>dato){
        cout<<"Digite el dato después del cual insertar: ";
        cin>>datoRef;
        insDespuesElemento(dato, datoRef);
        cout<<"Digite un entero o Ctrl-d para terminar: ";
    }
    cin.ignore();
    cout<<endl;
}

void ListaDoble::insAntesElemento(int dato, int datoRef){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;
    //caso lista vacia
    if(!head){
        head = nuevo;
        head->sig = NULL;
        head->ant = NULL;
    }
    else{
        nodo *saltarin;
        saltarin = head;
        while(saltarin->sig && saltarin->dato != datoRef){
            saltarin = saltarin->sig;
        }
        //caso insercion al inicio si datoRef no está en la lista
        if(saltarin->dato != datoRef){
            saltarin->sig = nuevo;
            nuevo->ant = saltarin;
            nuevo->sig = NULL;
        }
        //caso de insercion al final, si datoRef está al principio de la lista.
        else if(!saltarin->ant){
            nuevo->sig = head;
            head->ant = nuevo;
            head = nuevo;
            head->ant = NULL;
        }
        //caso de inserción enmedio.
        else if(saltarin && saltarin->ant){
            nuevo->sig = saltarin;
            nuevo->ant = saltarin->ant;
            saltarin->ant->sig = nuevo;
            saltarin->ant =  nuevo;
        }
    }
}

void ListaDoble::insNodoAntesElto(){
    int dato, datoRef;
    char opc;
    cout<<"Desea ingresar un dato (s/n): ";
    cin>>opc;
    while(opc != 'n' && opc != 'N'){
        cout<<"Digite un numero: ";
        cin>>dato;
        cout<<"Digite el dato antes del cual ingresar: ";
        cin>>datoRef;
        insAntesElemento(dato, datoRef);
        cout<<"Desea ingresar un dato (s/n): ";
        cin>>opc;
    }
    cout<<endl;
}

void ListaDoble::eliminarElemento(int datoRef){
    //si la lista esta vacia
    if(!head){
        cout<<"La lista está vacía"<<endl;
    }
    else{
        nodo *saltarin = head;
        while(saltarin && saltarin->dato != datoRef){  //(saltarin->dato).titulo.compare(datoRef.titulo) != 0 
            saltarin = saltarin->sig;                  // esto se utiliza para comparar strings
        }
        if(!saltarin){
            cout<<"El dato no está en la lista"<<endl;
        }
        //caso que el dato esté al inicio
        else if(!saltarin->ant && saltarin->sig){
            head = head->sig;
            head->ant = NULL;
            delete saltarin;
        }
        //caso que el dato esté al final
        else if(saltarin->ant && !saltarin->sig){
            saltarin->ant->sig = NULL;
            delete saltarin;
        }
        //caso que el dato esté enmedio
        else if(saltarin->ant && saltarin->sig){
            saltarin->ant->sig = saltarin->sig;
            saltarin->sig->ant = saltarin->ant;
            delete saltarin;
        }
        //caso que el dato sea único
        else{
            head = NULL;
            delete saltarin;
        }
    cout<<"Elemento eliminado correctamente"<<endl;
  }
}

void ListaDoble::eliminarNodo(){
    int dato;
    cout<<"Digite el dato a eliminar: ";
    cin>>dato;
    eliminarElemento(dato);
}


int main(void){
    ListaDoble objListaDoble;
    cout<<"Manejo de listas doblemente enlazadas"<<endl;

    cout<<"Ingresando elementos en lista: "<<endl;
    objListaDoble.insNodoAntesElto();

    cout<<"Eliminando Nodo"<<endl;
    objListaDoble.eliminarNodo();
    
    cout<<"Mostrando lista de forma directa: "<<endl;
    objListaDoble.mostrarListaDirectaIter();

    cout<<"Mostrando lista de forma indirecta: "<<endl;
    objListaDoble.mostrarListaDirInvIter();
    
    return 0;
}