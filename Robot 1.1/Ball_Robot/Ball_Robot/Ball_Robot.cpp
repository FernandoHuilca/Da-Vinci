// Author Fernando Huilca 

#include <iostream>
#include <string>
using namespace std;
#include <chrono>
#include <thread>
#define color SetConsoleTextAttribute

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
//Dibuja el contorno de la pantalla principal 
void contorno_principal();
//Dibujo superior izquierdo una barra inclinada
void dibujo_superior_izquierdo();


void dibujo_inferior_derecho();


void dibujo_superior_derecho();
void linea_derecha();

void linea_inferor();

void dibujo_inferior_izquierdo();

void triangulo();



/*************************** INICIO DEL MAIN ***************************************/
int main()
{
    creador_Fer();
    animacion_de_carga();
    //dibujo_estrellas();
    //dibujo_estrellas_derecha();
    //dibujo_robot();
    contorno_principal();
    dibujo_cuadrado();

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
    int Columna = 25; //MODIFICAR LA COLUMNA EN LA QUE APARECEN 
    int FILA = 12; //MODIFICAR LA FILA EN LA QUE APARECEN 

    while (true)
    {

        rlutil::setColor(rlutil::COLOR::WHITE); //Le da color a las letras 

        //Dibujar_contorno(Nombre_Del_Usuario);
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
    int columna = 14, fila = 8;
    int largo = columna + 40, ancho = fila + 15;
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
    int columna = 75, fila = 13;
    rlutil::setColor(rlutil::COLOR::LIGHTBLUE); //Le da color a las letras 
    rlutil::locate(columna, fila);
    cout << "         __" << endl;
    rlutil::locate(columna, fila+1);
    cout << " _ (\\    |@@|" << endl;
    rlutil::locate(columna, fila+2);
    cout << "(__/\\__ \\--/ __" << endl;
    rlutil::locate(columna, fila+3);
    cout << "    \\___|----|  |   __" << endl;
    rlutil::locate(columna, fila+4);
    cout << "        \\ }{ /\\ )_ / _\\" << endl;
    rlutil::locate(columna, fila+5);
    cout << "        /\\__/\u005C\\__O (__" << endl;
    rlutil::locate(columna, fila+6);
    cout << "       (--/\u005C--)    \\__/" << endl;
    rlutil::locate(columna, fila+7);
    cout << "       _)(  )(_" << endl;
    rlutil::locate(columna, fila+8);
    cout << "      `---''---`" << endl;

}

void animacion_de_carga()
{
    int a = 0; 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    rlutil::locate(42, 12);
        cout << "Realizando carga en pantalla..." << endl;

        const int numFrames = 30;
        const int frameDelayMs = 100;

        const char frames[] = { '-', '\\', '|', '/' };

        for (int i = 0; i < numFrames; ++i) 
        {
            
            rlutil::locate(52, 14);
            color(hConsole, a);
            a++;
            cout << "Cargando " << frames[i % 4] << "\r";
            cout.flush();

            this_thread::sleep_for(chrono::milliseconds(frameDelayMs));
            if (a == 15 )
            {
                a = 0;
            }
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


void contorno_principal()
{
    //Linea superior
    for (int i = 5; i <= 39; i++)
    {
        rlutil::locate(i, 4);
        cout << (char)95;

    }
    for (int i = 0; i < 2; i++)
    {
        rlutil::locate(40+i, 4-i);
        cout << (char)47;
    }
    for (int i = 4; i <= 38; i++)
    {
        rlutil::locate(i+38, 2);
        cout << (char)95;
    }
    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(77 + i, 3 + i);
        cout << (char)92;
    }

    for (int i = 4; i <= 41; i++)
    {
        rlutil::locate(i+78, 7);
        cout << (char)95;
    }
    for (int i = 4; i <= 38; i++)
    {
        rlutil::locate(i + 38, 4);
        cout << (char)95;
    }

    for (int i = 5; i <= 37; i++)
    {
        rlutil::locate(i + 38, 3);
        cout << (char)95;
    }
    rlutil::locate(42, 4);
    cout << (char)47;
    rlutil::locate(76, 4);
    cout << (char)92;
    //Dibujos superior derecha
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(79 + i, 3 + i);
        cout << (char)92;
    }
    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(83 + i, 6);
        cout << (char)95;
    }
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(84 + i, 3 + i);
        cout << (char)92;
    }

    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(79 + i, 2);
        cout << (char)95;
    }
    //Dibujos superior derecha 2
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(86 + i, 3 + i);
        cout << (char)92;
    }
    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(90 + i, 6);
        cout << (char)95;
    }
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(91 + i, 3 + i);
        cout << (char)92;
    }

    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(86 + i, 2);
        cout << (char)95;
    }
    //Dibujos superior derecha 3
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(93 + i, 3 + i);
        cout << (char)92;
    }
    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(97 + i, 6);
        cout << (char)95;
    }
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(98 + i, 3 + i);
        cout << (char)92;
    }

    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(93 + i, 2);
        cout << (char)95;
    }
    //Dibujos superior derecha 4
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(100 + i, 3 + i);
        cout << (char)92;
    }
    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(104 + i, 6);
        cout << (char)95;
    }
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(105 + i, 3 + i);
        cout << (char)92;
    }

    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(100 + i, 2);
        cout << (char)95;
    }
    //Dibujos superior derecha 4
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(107 + i, 3 + i);
        cout << (char)92;
    }
    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(111 + i, 6);
        cout << (char)95;
    }
    for (int i = 0; i < 4; i++)
    {
        rlutil::locate(112 + i, 3 + i);
        cout << (char)92;
    }

    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(107 + i, 2);
        cout << (char)95;
    }

    //Dibujo superior Izquierdo
    dibujo_superior_izquierdo();
    dibujo_inferior_derecho();
    //barra derecha
    for (int i = 0; i < 13; i++)
    {
        rlutil::locate(120, 8+i);
        cout << "|";
    }
    for (int i = 0; i < 7; i++)
    {
        rlutil::locate(117, 23 + i);
        cout << "|";
    }
    for (int i = 0; i < 3; i++)
    {
        rlutil::locate(117 + i, 23 - i);
        cout << (char)47;
    }
    linea_derecha();

}


void dibujo_superior_izquierdo()
{
    int fila = 2, columna = 5; 
    rlutil::locate(columna, fila);
    cout << "   ________________________________";
    rlutil::locate(columna, fila+1);
    cout << "  /_______________________________/";

}

void dibujo_inferior_derecho()
{
    int fila = 22, columna = 115;
    rlutil::locate(columna, fila-1);
    cout << "     .";
    rlutil::locate(columna, fila);
    cout << "    /|";
    rlutil::locate(columna, fila + 1);
    cout << "   / |";
    rlutil::locate(columna, fila + 2);
    cout << "   | |";
    rlutil::locate(columna, fila + 3);
    cout << "   | |";
    rlutil::locate(columna, fila + 4);
    cout << "   | |";
    rlutil::locate(columna, fila + 5);
    cout << "   | |";
    rlutil::locate(columna, fila + 6);
    cout << "   | |";
    rlutil::locate(columna, fila + 7);
    cout << "   |_|";
    linea_inferor();
}
void linea_inferor()
{

    for (int i = 0; i < 48; i++)
    {
        rlutil::locate(5+i, 27);
        cout << (char)95;
    }

    for (int i = 0; i < 62; i++)
    {
        rlutil::locate(55 + i, 29);
        cout << (char)95;
    }
    rlutil::locate(53, 28);
    cout << (char)92;
    rlutil::locate(54, 29);
    cout << (char)92;
    dibujo_superior_derecho();

}

void dibujo_superior_derecho()
{
    int fila = 28, columna = 5;
    rlutil::locate(columna, fila);
    cout << "  _____________________________________________";
    rlutil::locate(columna, fila + 1);
    cout << "  \\____________________________________________\\";

}

void linea_derecha()
{
    for (int i = 0; i < 6; i++)
    {
        rlutil::locate(2, 7+i);
        cout << "|";
    }
    for (int i = 0; i < 6; i++)
    {
        rlutil::locate(4, 15 + i);
        cout << " |";
    }
    for (int i = 0; i < 2; i++)
    {
        rlutil::locate(2, 23 + i);
        cout << "|";
    }
    rlutil::locate(3, 25);
    cout << (char)92;
    rlutil::locate(4, 26);
    cout << (char)92;
    rlutil::locate(5, 27);
    cout << (char)92;
    /**************/
    rlutil::locate(3, 13);
    cout << (char)92;
    rlutil::locate(4, 14);
    cout << (char)92;
    /*************/
    rlutil::locate(3, 22);
    cout << (char)47;
    rlutil::locate(4, 21);
    cout << (char)47;
    /**************/

    rlutil::locate(4, 5);
    cout << (char)47;
    rlutil::locate(3, 6);
    cout << (char)47;
    dibujo_inferior_izquierdo();
}

void dibujo_inferior_izquierdo()
{
    int fila = 14, columna = 2;
    rlutil::locate(columna, fila-1);
    cout << ".";
    rlutil::locate(columna, fila);
    cout << "|\\";
    rlutil::locate(columna, fila+1);
    cout << "| \\";
    rlutil::locate(columna, fila + 2);
    cout << "| |";
    rlutil::locate(columna, fila + 3);
    cout << "| |";
    rlutil::locate(columna, fila + 4);
    cout << "| |";
    rlutil::locate(columna, fila + 5);
    cout << "| |";
    rlutil::locate(columna, fila + 6);
    cout << "| /";
    rlutil::locate(columna, fila + 7);
    cout << "|/";
    rlutil::locate(columna, fila + 8);
    cout << "'";
    triangulo();
}

void triangulo()
{
    int columna = 2, fila = 26; 
    rlutil::locate(columna, fila-1);
    cout << ".";
    rlutil::locate(columna, fila);
    cout << "|\\";
    rlutil::locate(columna, fila+1);
    cout << "| \\";
    rlutil::locate(columna, fila+2);
    cout << "|  \\";
    rlutil::locate(columna, fila+3);
    cout << "|___\\";
}