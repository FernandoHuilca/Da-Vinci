// Author Fernando Huilca 

#include <iostream>
#include <string>
using namespace std; 

//Funciones externas:

#include "rlutil.h"

//Prototipos de funciones
void ColorSeleccion(string text, int posX, int posY, bool selected);
//Presenta el menu con las opciones principales
int menu_principal();
//Dibuja un rectangulo al rededor de las opciones del menu principal
void Dibujar_contorno_menu_principal();
// Escribe el nombre del author del programa en la parte inferior derecha
void creador_Fer();
//Dibuja adornos (estrellas) en el menu principal
void dibujo_estrellas();
//Diuja un robot en la parte derecha del menu principal 
void dibujo_robot();


/*************************** INICIO DEL MAIN ***************************************/
int main()
{
    creador_Fer();
    dibujo_estrellas();
    dibujo_robot();
    int a = menu_principal(); 

}
/*************************** FINAL DEL MAIN ***************************************/


//Funcion que da color al texto seleccionado en cada momento
void ColorSeleccion(string text, int posX, int posY, bool selected)
{
    if (selected)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::LIGHTMAGENTA); // damos color al contorno del texto seleccionado 
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

    system("color 0D"); //Pinta la consola
    int key; //almacenar el valor de cada tecla tecleada xd 
    int subir_bajar = 0; //para controlar la flecha que aplaste y devolver donde esta el cursor 
    int Columna = 48; //MODIFICAR LA COLUMNA EN LA QUE APARECEN 
    int FILA = 12; //MODIFICAR LA FILA EN LA QUE APARECEN 

    while (true)
    {

        rlutil::setColor(rlutil::COLOR::WHITE); //Le da color a las letras 

        //Dibujar_contorno(Nombre_Del_Usuario);
        Dibujar_contorno_menu_principal();
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

void Dibujar_contorno_menu_principal()
{
    // Línea superior
    rlutil::locate(39, 10);
    cout << (char)218;
    for (int i = 40; i <= 77; i++) // Cambié < por <=
    {
        rlutil::locate(i, 10);
        cout << (char)196;
    }
    cout << (char)191;
    // Líneas verticales izquierda 
    for (int i = 11; i < 20; i++) // Comencé en 11 en lugar de 10
    {
        rlutil::locate(39, i);
        cout << (char)179;
    }
    rlutil::locate(39, 20);
    cout << (char)192;
    // Lineas verticales derecha
    for (int i = 11; i < 20; i++)
    {
        rlutil::locate(78, i);
        cout << (char)179;
    }
    rlutil::locate(78, 20);
    cout << (char)217;

    // Línea inferior
    for (int i = 40; i <= 77; i++) // Cambié < por <=
    {
        rlutil::locate(i, 20);
        cout << (char)196;
    }
}

void creador_Fer()
{
    rlutil::setColor(rlutil::COLOR::LIGHTMAGENTA); //Le da color a las letras 
    rlutil::locate(108, 30);
    cout << "~ Fernando H.";
}

void dibujo_estrellas()
{
    rlutil::setColor(rlutil::COLOR::LIGHTMAGENTA); //Le da color a las letras 
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
    rlutil::setColor(rlutil::COLOR::LIGHTMAGENTA); //Le da color a las letras 
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