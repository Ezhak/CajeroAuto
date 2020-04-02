/* 
Inicio: 31/03/2020

Este es un software que simula un cajero automatico, sin utilizacion de base de datos, el mismo comienza con un saldo de 1000 USD.


*/

#include <iostream>
using namespace std;

int menu();
int validarpass();
int retirom();

int pin;
int i = 0;
int opc = 0;
int saldo = 10000;
int retiro = 0;
int deposito = 0;

int main(){
    validarpass();

    if (pin == 4774) {
     menu();
    }
    else {
      
        cout << "PIN Incorrecto, intente nuevamente" << endl << endl;
       
       while (pin != 4774) {
           validarpass();
       }
       if (pin == 4774)
       {
           menu();
       }
    }   
    while (i==0) {
     menu();
    }
    



}


int validarpass() {
    cout << "\t\tBievenido a su Cajero Automatico Personal »(CAP)» , por favor, para iniciar, ingrese su clave PIN" << endl << endl;
    cin >> pin;
    return pin;
}

int retirom() {
    cout << "\t Digite la cantidad a retirar por favor" << endl;
    cin >> retiro;
    saldo -= retiro;
    return saldo; 
}

int menu(){
    cout << " ------------------------/»/--------------------------- " << endl << endl << endl;
    cout << "\n\n\n\t\tEscoja a operacion a realizar" << endl << endl;
    cout << "1. Consulta de saldo" << endl << "2. Retirar dinero" << endl << "3. Depositar dinero" << endl << "4. Salir" << endl << endl << endl << endl;
    cout << " ------------------------/»/--------------------------- " << endl << endl << endl;
    cin >> opc;

    switch (opc) {
    case 1:
        cout << "\tSu saldo es: $" << saldo << " USD" << endl << endl;
        break;
        menu();
    case 2:
        retirom();
        while(retiro > saldo){
            cout << "Usted no posee ese monto, ingrese nuevamente" << endl;
              retirom();
        }
        cout << "\t\t Su nuevo saldo ahora es de: $" << saldo << " USD" << endl << endl << endl << endl;
        break;
        menu();

    case 3:
        cout << "\t Digite la cantidad a depositar por favor" << endl;
        cin >> deposito;
        saldo += deposito;
        cout << "\t\t Su nuevo saldo ahora es de: $" << saldo << " USD" << endl << endl << endl << endl;
        break;
        menu();

    case 4:
        cout << "Gracias por elegirnos como su servicio de Cajero Automatico, hasta pronto." << endl;
        break;
        return 0;

    default:
        cout << "Opcion incorrecta" << endl << endl << endl << endl;
        menu();
    }
    return 0;
 
}