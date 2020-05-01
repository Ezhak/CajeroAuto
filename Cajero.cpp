/* 
Inicio: 31/03/2020

Este es un software que simula un cajero automatico, sin utilizacion de base de datos, el mismo comienza con un saldo de 10000 USD.


*/

#include <iostream>
#include "rlutil.h"

using namespace rlutil;
using namespace std;



int menu();
int validarpass();
int retirom();

int pin=0;
int i = 0;
int opc = 0;
int saldo = 10000;
int retiro = 0;
int deposito = 0;






int main(){

    setColor(BLACK);
    setBackgroundColor(DARKGREY);
    cls();

    PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
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
    while (opc!=4) {
     menu();
    }
    



}


int validarpass() {
    PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
    cout << "\t\tBievenido a su Cajero Automatico Personal »(CAP)» , por favor, para iniciar, ingrese su clave PIN" << endl << endl;
    cin >> pin;
    PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
    PlaySound(TEXT("processingstuff.wav"), NULL, SND_ALIAS);
    return pin;
}

int retirom() {
    PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
    cout << "\t Digite la cantidad a retirar por favor" << endl;
    cin >> retiro;
    PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
    PlaySound(TEXT("processingstuff.wav"), NULL, SND_ALIAS);
    saldo -= retiro;
    return saldo; 
}

int menu(){
    PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
    cout << " ------------------------/»/--------------------------- " << endl << endl << endl;
    cout << "\n\n\n\t\tEscoja a operacion a realizar" << endl << endl;
    cout << "1. Consulta de saldo" << endl << "2. Retirar dinero" << endl << "3. Depositar dinero" << endl << "4. Salir" << endl << endl << endl << endl;
    cout << " ------------------------/»/--------------------------- " << endl << endl << endl;
    cin >> opc;
    PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
   

    switch (opc) {
    case 1:
        cout << "\tSu saldo es: $" << saldo << " USD" << endl << endl;
        PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
        break;
       
    case 2:
        retirom();
        while(retiro > saldo){
            cout << "Usted no posee ese monto, ingrese nuevamente" << endl;
            PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
              retirom();
        }
        cout << "\t\t Su nuevo saldo ahora es de: $" << saldo << " USD" << endl << endl << endl << endl;
        PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
        break;
        

    case 3:
        cout << "\t Digite la cantidad a depositar por favor" << endl;
        cin >> deposito;
        PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
        PlaySound(TEXT("processingstuff.wav"), NULL, SND_ALIAS);
        saldo += deposito;
        cout << "\t\t Su nuevo saldo ahora es de: $" << saldo << " USD" << endl << endl << endl << endl;
        break;
       

    case 4:
        cout << "Gracias por elegirnos como su servicio de Cajero Automatico, hasta pronto." << endl << endl << endl << endl << endl;
        PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
        break;
        return 0;

    default:
        cout << "Opcion incorrecta" << endl << endl << endl << endl;
        PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
        PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
      
    }
    return 0;
 
}
