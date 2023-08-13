#include <iostream>
using namespace std; 
#include <string> 
#include <iomanip> 
#include <windows.h> 
#define color SetConsoleTextAttribute //Para poner color a la vida
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

tPlaneta planeta1, planeta2; 

leerPlaneta(planeta1);
imprimir (planeta1);


return 0; 
}
/*************************************************************************************************/


void leerPlaneta (tPlaneta & planeta) 
{
cout << "Escriba el nombre del planeta: "  ;
cin >> planeta.name; 
cout << "Escriba la gravedad que tiene el planeta: " ;
cin >> planeta.gravity;  
cout << "Escriba el tamanio del planeta: " ;
cin >> planeta.tamanio;
cin.ignore();
cout << "Escriba la composicion atmosferica del planeta: " ;
getline (cin, planeta.composicion_atmosferica);    
cout << "Escriba la distancia al sol del planeta: " ;
cin >> planeta.distancia_sol;    
cout << "Escriba las estrellas del planeta: " ;
cin >> planeta.estrellas;    

}

void imprimir (tPlaneta &Planeta)
{
cout << "El nombre del planeta es: " << Planeta.name << endl;
cout << "La gravedad del planeta es: " << Planeta.gravity << endl;
cout << "El tamanio del planeta es: " << Planeta.tamanio << endl;
cout << "La composicion atmosferica del planeta es: " << Planeta.composicion_atmosferica << endl;  
cout << "La distancia al sol del planeta es: " << Planeta.distancia_sol << endl;
cout << "Las estrellas del planeta son: " << Planeta.estrellas << endl;

}

int menu()
{

}

void saludo()
{
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE ); //Para el color
    string name; 
    cout << "Escriba su nombre: " << endl;
    cin >> name; 
     color(hConsole, 1); 
    cout << "Bienbenido al Sistema Solar"
}

