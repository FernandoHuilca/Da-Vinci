// Author Fernando Huilca 

#include <iostream>
#include <string>
using namespace std;
#include <chrono>
#include <thread>

//Funciones externas:

#include "rlutil.h"

//Prototipos de funciones
void ColorSeleccion(string text, int posX, int posY, bool selected);
//Presenta el menu con las opciones principales
int menu_principal();
//Dibuja un cuadrado uselo cuando sea necesario
void dibujo_cuadrado();
// Escribe el nombre del author del programa en la parte inferior derecha
void creador_Fer();
//Dibuja adornos (estrellas) en el menu principal
void dibujo_estrellas();
//Diuja un robot en la parte derecha del menu principal 
void dibujo_robot();
//Funcion que presenta una animacion de carga en pantalla (en realida no es necesario pero da estetica)
void animacion_de_carga();
//Dibuja estrellas en la parte derecha del programa
void dibujo_estrellas_derecha();
//Dibuja un hexagono al rededor del menu principal
void dibujo_hexagono();

/*************************** INICIO DEL MAIN ***************************************/
int main()
{
    creador_Fer();
    animacion_de_carga();
    dibujo_estrellas();
    dibujo_estrellas_derecha();

    switch (menu_principal())
    {
    case 0: 
    {

        break;
    }
    case 1:
    {

        break;
    }
    case 2:
    {

        break;
    }
    case 3:
    {

        break;
    }
    case 4:
    {

        break;
    }
    default:
        break;
    }

    int a = menu_principal(); 

}
/*************************** FINAL DEL MAIN ***************************************/


//Funcion que da color al texto seleccionado en cada momento
void ColorSeleccion(string text, int posX, int posY, bool selected)
{
    if (selected)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED); // damos color al contorno del texto seleccionado 
        rlutil::setColor(rlutil::COLOR::BLACK); //Le da color a las letras 
        rlutil::locate(posX, posY);
        cout << text << endl;
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK); //Igual damos contorno pero del mismo color de consola pa disimular XD
        rlutil::setColor(rlutil::COLOR::WHITE); //Le da color a las letras 
        rlutil::locate(posX, posY);
        cout << " " << text << endl;
    }
}


//Funcion que presenta el menu principal del programa
int menu_principal()
{

    system("color 0C"); //Pinta la consola
    creador_Fer();
    int key; //almacenar el valor de cada tecla tecleada xd 
    int subir_bajar = 0; //para controlar la flecha que aplaste y devolver donde esta el cursor 
    int Columna = 52; //MODIFICAR LA COLUMNA EN LA QUE APARECEN 
    int FILA = 12; //MODIFICAR LA FILA EN LA QUE APARECEN 

    while (true)
    {

        rlutil::setColor(rlutil::COLOR::WHITE); //Le da color a las letras 

        //Dibujar_contorno(Nombre_Del_Usuario);
        dibujo_hexagono();
        ColorSeleccion("____________________", Columna, FILA, subir_bajar == 7);
        ColorSeleccion("  SALUDAR            ", Columna, FILA + 1, subir_bajar == 0);
        ColorSeleccion("  BAILAR             ", Columna, FILA + 2, subir_bajar == 1);
        ColorSeleccion("  CONTROL MANUAL     ", Columna, FILA + 3, subir_bajar == 2);
        ColorSeleccion("  MOD DESTRUCTOR     ", Columna, FILA + 4, subir_bajar == 3);
        ColorSeleccion("  SALIR              ", Columna, FILA + 5, subir_bajar == 4);
        ColorSeleccion("--------------------", Columna, FILA + 6, subir_bajar == 5);

        rlutil::locate(Columna - 2, FILA + 1 + subir_bajar);
        cout << (char)175 << endl; //(char)175 estamos casteando interpretando lo que se imprime

        key = rlutil::getkey(); //Me permite asignar un numero al aplastar una tecla 

        switch (key)
        {
        case 14: //Subir
        {
            rlutil::locate(Columna - 2, FILA + 1 + subir_bajar);
            cout << " " << endl; // DONDE ESTABA >> Dibuja un espacio vacio jeje 
            subir_bajar--;
            if (subir_bajar < 0)
            {
                subir_bajar = 0; // Para que no suba mas de las opciones dadas 
            }
            break;
        }
        case 15: //bajar 
        {
            rlutil::locate(Columna - 2, FILA + 1 + subir_bajar);
            cout << " " << endl;
            subir_bajar++;
            if (subir_bajar > 4)
            {
                subir_bajar = 4; // Para que no baje mas de las opciones dadas
            }
            break;
        }
        case 1: // Enter
        {
            return subir_bajar;

        }
        default: //Si preciona cualquier otra tecla no hace nada, hasta que "deje de ser necio"
            break;
        }



    }
}

void dibujo_cuadrado()
{
    int columna = 43, fila = 10;
    int largo = columna + 37, ancho = fila + 10;
    // Línea superior
    rlutil::locate(columna - 1, fila);
    cout << (char)218;
    for (int i = columna; i <= largo; i++)
    {
        rlutil::locate(i, fila);
        cout << (char)196;
    }
    cout << (char)191;
    // Líneas verticales izquierda 
    for (int i = fila + 1; i < ancho; i++)
    {
        rlutil::locate(columna - 1, i);
        cout << (char)179;
    }
    rlutil::locate(columna - 1, ancho);
    cout << (char)192;
    // Lineas verticales derecha
    for (int i = fila + 1; i < ancho; i++)
    {
        rlutil::locate(largo + 1, i);
        cout << (char)179;
    }
    rlutil::locate(largo + 1, ancho);
    cout << (char)217;

    // Línea inferior
    for (int i = columna; i <= largo; i++)
    {
        rlutil::locate(i, ancho);
        cout << (char)196;
    }
}

void creador_Fer()
{
    rlutil::setColor(rlutil::COLOR::WHITE); //Le da color a las letras 
    rlutil::locate(108, 30);
    cout << "~ Fernando H.";
}

void dibujo_estrellas()
{
    rlutil::setColor(rlutil::COLOR::LIGHTBLUE); //Le da color a las letras 
    rlutil::locate(2, 2);
    cout << "                 '\n";
    cout << "            *          .\n";
    cout << "                   *       '\n";
    cout << "              *                *\n";
    cout << "\n";
    cout << "   *   '*\n";
    cout << "           *\n";
    cout << "                *\n";
    cout << "                       *\n";
    cout << "               *\n";
    cout << "                     *\n";
    cout << "\n";
    cout << "         .                      .\n";
    cout << "         .                      ;\n";
    cout << "         :                  - --+- -\n";
    cout << "         !           .          !\n";
    cout << "         |        .             .\n";
    cout << "         |_         +\n";
    cout << "      ,  | `.\n";
    cout << "--- --+-<#>-+- ---  --  -\n";
    cout << "      `._|_,'\n";
    cout << "         T\n";
    cout << "         |\n";
    cout << "         !\n";
    cout << "         :         . : \n";
    cout << "         .       *\n";
}

void dibujo_robot()
{
    rlutil::setColor(rlutil::COLOR::LIGHTBLUE); //Le da color a las letras 
    rlutil::locate(55, 2);
    cout << "         __" << endl;
    rlutil::locate(55, 3);
    cout << " _ (\\    |@@|" << endl;
    rlutil::locate(55, 4);
    cout << "(__/\\__ \\--/ __" << endl;
    rlutil::locate(55, 5);
    cout << "    \\___|----|  |   __" << endl;
    rlutil::locate(55, 6);
    cout << "        \\ }{ /\\ )_ / _\\" << endl;
    rlutil::locate(55, 7);
    cout << "        /\\__/\u005C\\__O (__" << endl;
    rlutil::locate(55, 8);
    cout << "       (--/\u005C--)    \\__/" << endl;
    rlutil::locate(55, 9);
    cout << "       _)(  )(_" << endl;
    rlutil::locate(55, 10);
    cout << "      `---''---`" << endl;

}

void animacion_de_carga()
{
    rlutil::locate(42, 12);
        cout << "Realizando carga en pantalla..." << endl;

        const int numFrames = 30;
        const int frameDelayMs = 100;

        const char frames[] = { '-', '\\', '|', '/' };

        for (int i = 0; i < numFrames; ++i) 
        {
            rlutil::locate(52, 14);
            cout << "Cargando " << frames[i % 4] << "\r";
            cout.flush();

            this_thread::sleep_for(chrono::milliseconds(frameDelayMs));
        }
        system("cls");
}

void dibujo_estrellas_derecha()
{
    rlutil::setColor(rlutil::COLOR::LIGHTMAGENTA); //Le da color a las letras 
    cout << "         .                      .\n";    rlutil::locate(85, 3);
    cout << "         .                      ;\n";    rlutil::locate(85, 4);
    cout << "         :                  - --+- -\n"; rlutil::locate(85, 5);
    cout << "         !           .          !\n"; rlutil::locate(85, 6);
    cout << "         |        .             .\n"; rlutil::locate(85, 7);
    cout << "         |_         +\n"; rlutil::locate(85, 8);
    cout << "      ,  | `.\n"; rlutil::locate(85, 9);
    cout << "--- --+-<#>-+- ---  --  -\n"; rlutil::locate(85, 10);
    cout << "      `._|_,'\n"; rlutil::locate(85, 11);
    cout << "         T\n"; rlutil::locate(85, 12);
    cout << "         |\n"; rlutil::locate(85, 13);
    cout << "         !\n"; rlutil::locate(85, 14);
    cout << "         :         . : \n"; rlutil::locate(85, 15);
    cout << "         .       *\n"; rlutil::locate(85, 16);
    cout << "                 '\n"; rlutil::locate(85, 17);
    cout << "            *          .\n"; rlutil::locate(85, 18);
    cout << "                   *       '\n"; rlutil::locate(85, 19);
    cout << "              *                *\n"; rlutil::locate(85, 20);
    cout << "\n"; rlutil::locate(85, 21);
    cout << "   *   '*\n"; rlutil::locate(85, 22);
    cout << "           *\n"; rlutil::locate(85, 23);
    cout << "                *\n"; rlutil::locate(85, 24);
    cout << "                       *\n"; rlutil::locate(85, 25);
    cout << "               *\n"; rlutil::locate(85, 26);
    cout << "                     *\n";  rlutil::locate(85, 27);
    cout << "\n"; rlutil::locate(85, 28);
}


void dibujo_hexagono()
{
    int columna = 49, fila = 9;
    int largo = columna + 25, ancho = fila + 7;
    int aux = 0;
    for (int i = columna; i <= largo; i++)
    {
        rlutil::locate(i, fila);
        if (aux % 2 == 0)
        {
            cout << " ";
        }
        else
        {
            cout << (char)42;
        }
        aux++;

    }
    aux = 0;
    // Líneas oblicuas izquierda 
    for (int i = fila + 1; i < ancho; i++)
    {
        rlutil::locate((columna - 1) - aux, i);
        cout << (char)42;
        aux++;
    }
    for (int i = fila + 1; i < ancho; i++)
    {
        rlutil::locate((columna + 1) - aux, i + (ancho - fila) - 1);
        cout << (char)42;
        aux--;
    }
    //linea oblicuas derechas
    for (int i = fila + 1; i < ancho; i++)
    {
        rlutil::locate((largo + 1) + aux, i);
        cout << (char)42;
        aux++;
    }
    for (int i = fila + 1; i < ancho; i++)
    {
        rlutil::locate((largo)+aux, i + (ancho - fila) - 2);
        cout << (char)42;
        aux--;
    }

    // Línea inferior 
    for (int i = columna; i <= largo; i++)
    {
        rlutil::locate(i, ancho + (ancho - fila) - 2);
        if (aux % 2 == 0)
        {
            cout << " ";
        }
        else
        {
            cout << (char)42;
        }

        aux++;
    }

}