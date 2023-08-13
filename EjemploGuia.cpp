//Listas de longitud varriable
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>

const int MAX = 100;
typedef struct
{
    string nombre;
    string apellido;
    int edad;
    string nif;
    double nota;
}tEstudiante;

typedef struct {
    tEstudiante elementos[MAX];
    int contador;
}tLista;

//Prototipos
int menu();
void cargar(tLista &lista, bool &ok);
void guardar(const tLista lista);
void leerEstudiante(tEstudiante &estudiante);
void insertarEstudiante(tLista &lista, tEstudiante estudiante, bool &ok);
void eliminarEstudiante(tLista &lista, int pos, bool &ok);
string nombreCompleto(tEstudiante estudiante);
void calificar(tLista &lista);
double mediaClase(const tLista lista);
int mayorNota(const tLista lista);
void mostrarEstudiante(tEstudiante estudiante);
void listado(const tLista lista, double media, int mayor);


int main(){
    tLista lista;
    tEstudiante estudiante;
    bool exito;
    int op, pos;
    cargar(lista, exito);
    if (!exito){
        cout << "No se pudo cargar la lista" << endl;
    }
    else
    {
        do{
            op = menu();
            switch (op)
            {
            case 1:
            {
                leerEstudiante(estudiante);
                insertarEstudiante(lista, estudiante, exito);
                if (!exito){
                    cout << "Lista llena: imposible  insertar" << endl;
                }
            }
            break;
            case 2:
            {
                cout << "Posicion: ";
                cin >> pos;
                eliminarEstudiante(lista, pos-1, exito);
                if (!exito){
                    cout << "Elemento inexistente" << endl;
                }
            }
            break;
            case 3:
            {
                calificar(lista);
            }
            break;
            case 4:
            {
                listado(lista, mediaClase(lista),mayorNota(lista));
            }
            }
        }while(op != 0);
        guardar(lista);
    }
    return 0;
}

int menu(){
    int opcion;
    do{
        cout << "1. Añadir un nuevo estudiante" << endl;
        cout << "2. Eliminar un estudiante" << endl;
        cout << "3. Calificar a los estudiantes" << endl;
        cout << "4. Listado de estudiantes" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
    }while((opcion < 0 ) || (opcion >4));
    return opcion;
}
void cargar(tLista &lista, bool &ok)/*Resive una variable lista (obvio porque necesitaremos 
guardar en el arreglo y el contador) tambien resive un boleano para 
de no cargar solo presentar el error y detener el programa*/
{
    tEstudiante estudiante;// Lo usaremos para en el guardar todos los datos y una vez que finalicemos de recolectar es cuando lo agregamos a la lista de estudiantes y aunmentamos el contador porque si lo hacemos directamente puede generar problemas al futuro 
    ifstream archivo;//para leer del archivo
    char aux; // usar porque en otros lenjuages no funciona el cin.ignore o cin .syn 
    lista.contador = 0; // Inicializa el contador porque lo usaremos
    archivo.open("clase.txt"); // lo abre y verifica
    if (!archivo.is_open()){
        ok = false; //Para detener pero en el programa del main
    }
    else{
        ok = true;
        getline(archivo, estudiante.nombre); //Usa al tipo estudiante 
        while((estudiante.nombre != "XXX") && (lista.contador < MAX))//Controlar que el contador no haya llegado al maximo no olvidar de ello 
        {
            getline(archivo, estudiante.apellido);
            archivo >> estudiante.edad;
            archivo >> estudiante.nif;
            archivo >> estudiante.nota;
            archivo.get(aux);
            lista.elementos[lista.contador] = estudiante;
            lista.contador++;
            getline(archivo, estudiante.nombre);
        }
        archivo.close();
    }
}
void guardar(const tLista lista){
    ofstream archivo;
    archivo.open("clase.txt");
    for(int i = 0; i < lista.contador; i++){
        archivo << lista.elementos[i].nombre << endl;
        archivo << lista.elementos[i].apellido << endl;
        archivo << lista.elementos[i].edad << endl;
        archivo << lista.elementos[i].nif << endl;
        archivo << lista.elementos[i].nota << endl;
    }
    archivo << "XXX" << endl;
    archivo.close();
}
void leerEstudiante(tEstudiante &estudiante){
    cin.sync();
    cout << "Nombres: ";
    getline(cin, estudiante.nombre);
    cout << "Apellidos: ";
    getline(cin, estudiante.apellido);
    cout << "Edad: ";
    cin >> estudiante.edad;
    cout << "NIF: ";
    cin >> estudiante.nif;
    estudiante.nota = -1;
    cin. sync();
}

void insertarEstudiante(tLista &lista, tEstudiante estudiante, bool &ok){
    ok = true;
    if(lista.contador == MAX){
        ok = false;
    }
    else{
        //inserta al final
        lista.elementos[lista.contador] = estudiante;
        lista.contador++;
    }
}

void eliminarEstudiante(tLista &lista, int pos, bool &ok){
    if((pos < 0) || (pos>lista.contador -1)){
        ok = false; //Elemento inexistente
    }
    else{
        ok = true;
        for(int i = pos; i <lista.contador -1 ; i++){
            lista.elementos[i] = lista.elementos[i+1];
        }
        lista.contador--;
    }
}
string nombreCompleto(tEstudiante estudiante){
    return estudiante.nombre + " " + estudiante.apellido;
}

void calificar(tLista &lista){
    for (int i = 0; i < lista.contador; i ++){
        cout << "Nota del estudiante " 
             << nombreCompleto(lista.elementos[i]) << ": ";
        cin >> lista.elementos[i].nota;
    }
}

double mediaClase(const tLista lista){
    double total = 0.0;
    for (int i = 0; i < lista.contador; i ++){
        total = total + lista.elementos[i].nota;
    }
    return total / lista.contador;
}
int mayorNota(const tLista lista){
    double max = 0;
    int pos = 0;
    for (int i = 0; i < lista.contador; i ++){
        if(lista.elementos[i].nota > max){
            max = lista.elementos[i].nota;
            pos = i;
        }
    }
    return pos;
}
void mostrarEstudiante(tEstudiante estudiante){
    cout << setw(35) << left << nombreCompleto(estudiante);
    cout << estudiante.nif << " ";
    cout << setw(2) << estudiante.edad << "años";
    cout << fixed << setprecision(1) << estudiante.nota;
}

void listado(const tLista lista, double media, int mayor){
    for (int i = 0; i < lista.contador; i ++){
        cout << setw(3) << i << ": ";
        mostrarEstudiante(lista.elementos[i]);
        if( i == mayor){
            cout << "<-- Mayor nota";
        }
        cout << endl;
    }
    cout << "Media de la clase:  " << fixed << setprecision(1) << media 
    << endl << endl;
}