#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class CircularList{
    private:
    node *head;

    public:
    CircularList();
    ~CircularList();
    void addFront(int);
    void addBack(int);
    void addAscendingOrder(int);
    void addNodeFront();
    void addNodeBack();
    void addNodeAsc();
    void printForward();
    void deleteCircularListRec(node *);

};

CircularList::CircularList(){
    head = NULL;
}

CircularList::~CircularList(){
    cout << "Destructor ejecutándose" << endl;
    if(head){
        deleteCircularListRec(head);
        head = NULL;
    }
}

void CircularList::deleteCircularListRec(node *h){
    if(h->next != head)
        deleteCircularListRec(h->next);
    delete h;
}

void CircularList::addFront(int data){
    node *nd;
    nd = new node;
    nd->data = data;
    if(!head){
        head = nd;
        head->next = head;
    }
    else{
        nd->next = head;
        node *aux = head;
        while(aux->next != head){
            aux = aux->next;
        }
        aux->next = nd;
        head = nd;
    }
}

void CircularList::addNodeFront(){
    int data;
    char opc;
    cout << "Agregar dato (s/n): ";
    cin >> opc; cin.ignore();
    while(opc != 'n' && opc != 'N'){
        cout << "Digite un numero: ";
        cin >> data; cin.ignore();
        addFront(data);
        cout << "Agregar dato (s/n): ";
        cin >> opc; cin.ignore();       
    }
}

void CircularList::addBack(int data){
    node *nd, *aux;
    nd = new node;
    nd->data = data;
    if(!head){
        head = nd;
        head->next = head;
    }
    else{
        nd->next = head;
        aux = head;
        while(aux->next != head)
            aux = aux->next;
        aux->next = nd;
    }
}

void CircularList::addNodeBack(){
    int data;
    char opc;
    cout << "Agregar dato (s/n): ";
    cin >> opc; cin.ignore();
    while(opc != 'n' && opc != 'N'){
        cout << "Digite un numero: ";
        cin >> data; cin.ignore();
        addBack(data);
        cout << "Agregar dato (s/n): ";
        cin >> opc; cin.ignore();       
    }
}

void CircularList::addAscendingOrder(int data){
    node *nd, *aux;
    nd = new node;
    nd->data = data;
    if(!head){
        head = nd;
        head->next = head;
    }
    else{
        if(data < head->data){ // si el dato es menor al primero de la lista, se inserta al inicio
            nd->next = head;
            aux = head;
            while(aux->next != head)
                aux = aux->next;
            aux->next = nd;
            head = nd;
        }
        else{ //si el dato es mayor que todos los de la lista
            aux = head;
            while(aux->next != head && aux->next->data < data)
                aux = aux->next;
            nd->next = aux->next;
            aux->next = nd;
        }
    }
}

void CircularList::addNodeAsc(){
    int data;
    char opc;
    cout << "Agregar dato (s/n): ";
    cin >> opc; cin.ignore();
    while(opc != 'n' && opc != 'N'){
        cout << "Digite un numero: ";
        cin >> data; cin.ignore();
        addAscendingOrder(data);
        cout << "Agregar dato (s/n): ";
        cin >> opc; cin.ignore();       
    }
}

void CircularList::printForward(){
    node *aux;
    if(head){
        aux = head;
        do{
            cout << aux->data << endl;
            aux = aux->next;
        }while(aux != head);
    }
}

int main(void){
    CircularList objCL;

    //cout << "Insertando datos al inicio" << endl;
    //objCL.addNodeFront();
    
    //cout << "Insertando datos al final" << endl;
    //objCL.addNodeBack();

    cout << "Insertando datos en orden ascendente" << endl;
    objCL.addNodeAsc();

    cout << "Mostrando elementos en orden directo" << endl;
    objCL.printForward();

    return 0;
}