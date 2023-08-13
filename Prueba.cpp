#include <iostream>
using namespace std; 
#include <string> 
#include <iomanip> 
void cambio(int &b);

int main() 
{

    int a = 11;
    cout << " 1. EL NUMERO DE LA VARIABLE ES: " << a << endl; 
    cambio(a); 
    cout << " 4. EL NUMERO DE LA VARIABLE ES: " << a << endl; 


    return 0; 
}

void cambio(int &b)
{
    cout << " 2 . EL NUMERO DE LA VARIABLE ES: " << b << endl; 
    b = 222; 
    cout << " 3 .EL NUMERO DE LA VARIABLE ES: " << b << endl; 
}