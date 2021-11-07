#include <iostream>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<iomanip>

using namespace std;
void menu();
void category();
void selectCategory(int);
void startGame(char text[][15], char name[]);
void draw(int);
void submenuProbabilidad();
float caseA(int);

int main(void){
    menu();
    system("pause");
    return 0;
}

void menu(){
    bool end = false;
    int opc;
    do{
    	cout << endl << endl;
        cout << "AHORCADO" << endl;
        cout << "Menu" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Calcular la posibilidad de ganar" << endl;
        cout << "3. Salir" << endl;
        cout << "Opción: ";
        cin >> opc; cin.ignore();

        switch(opc){
            case 1:
                category();
            	break;
            case 2:
                submenuProbabilidad();
                break;
            case 3:
                end = true;
                break;
            default:
                cout << "La opción ingresada es inválida :(" << endl;
        }
    }while(end != true);   
}
void category(){
    int opc;
    bool end = false;
    do{
        cout << "\n\t\t\t\tAHORCADO" << endl << endl;  
        cout << "1. Animales" << endl;
        cout << "2. Frutas" << endl;
        cout << "3. Objetos" << endl;
        cout << "4. Paises" << endl;
        cout << "5. Cancelar y Salir" << endl;
        cout << "Opción: ";
        cin >> opc; cin.ignore();
        
        switch(opc){
            case 1: 
                selectCategory(opc);
                break;
            case 2:
                selectCategory(opc);
                break;
            case 3:
                selectCategory(opc);
                break;
            case 4:
                selectCategory(opc);
                break;
            case 5:
                end = true;
                break;
            default:
                cout << "La opción ingresada es inválida :(" << endl;
        }
    }while(end != true);
}

void selectCategory(int opc){
    char catName[4][15] = {"Animales", "Frutas", "Objetos", "Paises"};
    char frutas[15][15] = {"PERA", "MELON", "MANGO", "PAPAYA", "MANZANA",
                           "SANDIA", "NARANJA", "MARACUYA", "MANDARINA", "GUAYABA"
                           "LIMA", "FRESA", "LIMON", "CIRUELA", "CEREZA"};
	char animales[15][15] = {"PERRO","GATO","CABALLO","GALLINA","JIRAFA",
                             "MONO","VACA","CONEJO","TORTUGA","LOBO",
                             "LEOPARDO", "LEON", "PEZ", "BURRO", "AVESTRUZ"};
	char paises[15][15] = {"PERU","COLOMBIA","ARGENTINA","NICARAGUA","ITALIA",
                           "MEXICO","CANADA","VENEZUELA","ECUADOR","BRASIL",
                           "RUSIA", "FRANCIA", "PANAMA", "GUATEMALA", "CHINA"};
	char objetos[15][15] = {"MOCHILA","RELOJ","ZAPATILLA","MUEBLE","CUADERNO",
                            "SILLA","MESA","CELULAR","PUERTA","AURICULARES",
                            "CAMA", "LAPIZ", "ROPERO", "COBIJA", "FOTOGRAFIA"};
    
    switch(opc){
        case 1:
            startGame(animales, catName[opc-1]);
            break;
        case 2:
            startGame(frutas, catName[opc-1]);
            break;
        case 3:
            startGame(objetos, catName[opc-1]);
            break;
        case 4: 
            startGame(paises, catName[opc-1]);
            break;
    }
}

void startGame (char palabras[][15], char nombre[]){
	int opcion,i,j,k,longitud,espacios,puntos=1200;
	char letra;
	int aciertos = 0;
	int intentos = 0;
	int ganar = 0;
	srand(time(NULL));
	
	opcion = rand() % 15;
	longitud = strlen(palabras[opcion]);
	char frase[longitud];
	
	for(i=0; i < longitud; i++){
		frase[i] = '_';
	}
		
	do{
		aciertos = 0;
		system("cls");
		cout << "\n\t\t\tAHORCADO\n\n";
		cout << "CATEGORIA: " << nombre << endl;
		cout << "Intentos restantes: " << (6-intentos) << endl;
		cout << "Puntuación" << puntos;
		draw(intentos);
		
		cout << endl << endl;
		for(i=0; i < longitud; i++){
			cout << " " << frase[i] << " ";
		}

		if (intentos == 6){
			cout << "\n\nYou lose :(" << endl;
			cout << "La palabra era: " << palabras[opcion] << endl;
			cout << "Presiona una tecla para volver al menú principal...";
			getch();
			menu();	
		}

		espacios=0;
		
		for (i = 0; i < longitud; i++){
			if (frase[i] == '_')
				espacios++;
		}
		
		if (espacios == 0){
			printf("\n\n FELICIDADES.. GANASTE!!\n\n");
			printf(" Presiona una tecla para volver a jugar..");
			getch();
			menu();		
		}
		
		cout << "\n\nDigite una letra: ";
		cin >> letra;
		 
		for (j = 0; j < longitud; j++){
			if (letra == palabras[opcion][j]){
				frase[j] = letra;
				aciertos++;
			}	
		}
		
		if (aciertos == 0){
			intentos++;	
			puntos -= 200;
		}
			
	}while(intentos != 7);
	cout << endl << endl;	
}

void draw(int trys){
    switch(trys){
		case 0:
			cout << "\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------";
			break;
		case 1:
			cout << "\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------";
			break;
		case 2:
			cout << "\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------";
			break;
		case 3:
			cout << "\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------";
			break;
		case 4:
			cout << "\n     _______\n    |       |\n    |       0\n    |      /|";
			cout << "\\";
			cout << "\n";
			cout << "    |\n    |\n    |\n ----------";
			break;
		case 5:
			cout << "\n     _______\n    |       |\n    |       0\n    |      /|";
			cout << "\\";
			cout << "\n";
			cout << "    |      /\n    |\n    |\n ----------";
			break;
		case 6:
			cout << "\n     _______\n    |       |\n    |       0\n    |      /|";
			cout << "\\";
			cout << "\n";
			cout << "    |      / ";
			cout << "\\";
			cout << "\n";
			cout << "    |\n    |\n ----------";
			break;
	}
}

void submenuProbabilidad(){
	int nWords;
	double result;
	int opc;
	bool end = false;
	do{
		cout << endl << endl;
		cout << "1. Acertar un determinado número de palabras según la categoría escogida." << endl;
		cout << "2. Acertar la palabra sin gastar un solo intento." << endl;
		cout << "3. Acertar la palabra gastanto un determinado número de intentos." << endl;
		cout << "4. No acertar" << endl;
		cout << "Opción: ";
		cin >> opc;
		
		switch(opc){
			case 1:
				cout << "Para realizar este cálculo toma que el repertorio de palabras por categoría es 15"<< endl;
				cout << "Ingresa la cantidad de palabras a considerar: ";
				cin >> nWords;
				result = caseA(nWords);
				cout << fixed << setprecision(2);
				cout << "La probabilidad de acertar " << nWords << " palabras es: " << result << " o " << (result * 100) << "%" <<endl;
				break;
			case 2:
				cout << "working on it" << endl;
				break;
		}
	}while(end != true);
}


float caseA(int nWords){
	float value = (float)nWords/ (float)15;
	return value;
}











