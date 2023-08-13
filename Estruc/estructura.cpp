#include <iostream>
using namespace std; 
#include <string> 
#include <iomanip> 
#include <fstream>
#include <windows.h> 
#define color SetConsoleTextAttribute //Para poner color a la vida
HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE ); //Para el color
const int DIM = 8; 
typedef struct 
{
    string name;
    double gravity;
    double tamanio;
    string composicion_atmosferica;
    double distancia_sol;
    string estrellas;  

}tPlaneta;

typedef struct 
{
    tPlaneta lista[DIM];
    int contador; 
}tLista;


//Prototipos
//Funcion de saludo inicial
void saludo();
//Funcion que muestra el menu 
int menu();
//Funcion para ingresar datos a los planetas
void leerPlaneta (tPlaneta & planeta);
//Funcion para imprimir
void imprimir (tPlaneta &Planeta);


/*************************************************************************************************/
int main ()
{ 
int opcion; 
saludo(); 
opcion = menu();
tPlaneta planeta1, planeta2; 

leerPlaneta(planeta1);
imprimir (planeta1);


return 0; 
}
/*************************************************************************************************/


void saludo()
{
    string name; 
    cout << "Escriba su nombre: ";
    getline(cin, name);
    color(hConsole, 13); 
    cout << "____Bienbenido al Sistema Solar " << name  << "____" << endl;
     color(hConsole, 7); 
    cout << endl;
}

int menu()
{   
    int op; 
    do
    {
    cout  << "MENU EJERCICIOS REALIZADOS" << endl;
        cout << "-------------------------" << endl;
        cout << endl;
        cout << "1. Mostrar lista de planetas" << endl;
        cout << "2. Mostrar datos del planeta" << endl;
        cout << "3. Modificar un planeta" << endl;
        cout << "4. Borrar un planeta" << endl;
        cout << "5. Aniadir un nuevo planeta" << endl;
        cout << "0. Salir" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> op;
        if (op < 0 || op > 5)
        {
            
            color(hConsole, 4);
            cout << "ERROR: " << endl;
            color(hConsole, 7);
            cout << "Por favor digite un numero de las opciones " << endl << endl;
        }
            
    } while (op < 0 || op > 4);

    return op; 
    
}

void cargar (bool &ok)
{
    ifstream leer_archivo; 
    leer_archivo.open("planetas.txt"); 
    if (!leer_archivo.is_open())
        ok = false; 
    else
    {
        ok = true; //No hace falta pero pa estar seguros
        while (leer_archivo != "xxx")
        {
            /* code */
        }
        
    }
    
}


