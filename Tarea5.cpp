#include<iostream>

using namespace std;

struct info{
    int id;
    string owner;
    string race;
    float weight;
    int age;
};

struct Node{
    info data;
    Node *next;
};

class CircularList{
    private:
    Node *head;

    public:
    CircularList();
    ~CircularList();
    void deleteList(Node *);
    void addPet(info);
    void addInfo();
    void printById(int);

};

CircularList::CircularList(){
    head = NULL;
}

CircularList::~CircularList(){
    cout << "Destructor ejecutándose" << endl;
    if(head){
        deleteList(head);
        head = NULL;
    }
}

void CircularList::deleteList(Node *h){
    if(h->next != head)
        deleteList(h->next);
    delete h;
}

void CircularList::addPet(info data){
    Node *nd, *aux;
    nd = new Node();
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

void CircularList::addInfo(){
    info dataPet;
    cout << "Id: ";
    cin >> dataPet.id; cin.ignore();
    cout << "Propietario: ";
    getline(cin, dataPet.owner); 
    cout << "Raza: ";
    getline(cin, dataPet.race);
    cout << "Peso: ";
    cin >> dataPet.weight; cin.ignore();
    cout << "Edad: ";
    cin >> dataPet.age; cin.ignore();
    addPet(dataPet);
}
void CircularList::printById(int ref){
    bool aux;
    if(!head)
        cout << "El registro está vacío :(" << endl;
    else{
        Node *s = head, *p;
        if(s->data.id == ref){
            aux = true;
        }
        else{
            while(s->next != head && s->next->data.id != ref)
                s = s->next;
            if(s->next == head)
                aux = false;
            else{
                p = s->next;
                s = p;
                aux = true;
            }
        }
        if(aux == true){
            cout << "\n\tResultados." << endl;
            cout << "Id: " << s->data.id <<endl; 
            cout << "Propietario: " << s->data.owner << endl;
            cout << "Raza: " <<s->data.race << endl;
            cout << "Peso: " << s->data.weight << endl;
            cout << "Edad: " << s->data.age << endl; 
        }
        else{
            cout << "No se encontró en el registro :(" << endl;  
        }
    }
}

int main(void){
    int opc, dataRef;
    CircularList veterinary;
    bool aux = true;
    do{
        cout << "1. Agregar mascota" << endl;
        cout << "2. Mostrar por Id" << endl;
        cout << "3. Eliminar mascota" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opc; cin.ignore();

        switch(opc){
            case 1:
                veterinary.addInfo();
                break;
            case 2:
                cout << "Digite el id de la mascota que desea mostrar: ";
                cin >> dataRef; cin.ignore();
                veterinary.printById(dataRef);
                break;
            case 3:
                cout << "working on it" << endl;
                break;
            case 4:
                aux = false;
                break;
            case 5:
                cout << "La opcion ingresada es invalida :(" << endl;
                break; 

        }
    }while(aux != false);

    return 0;
}