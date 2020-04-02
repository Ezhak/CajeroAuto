/* 
Inicio: 31/03/2020

Este es un software que simula un cajero automatico, sin utilizacion de base de datos, el mismo comienza con un saldo de 10000 USD.


*/

#include <iostream>
using namespace std;

int menu(); // conviene poner primero las funciones y después las llamadas, así ya fueron definidas las funciones para llamarlas.
int validarpass();
int retirom();

int pin;
int i = 0; //usar nombres descriptivos, 
int opc = 0; //usar nombres completos
int saldo = 10000; //buscar de a poco hacer en ingles los nombres de las variables
int retiro = 0;
int deposito = 0;

int main(){
    validarpass();

    if (pin == 4774) { // a esto se le llama nro magico, si debes llamarla en otro lado debes colocar el valor y lleva a problemas, conviene definir una constante y llamarla.
     menu();
    }
    else {
      
        cout << "PIN Incorrecto, intente nuevamente" << endl << endl;
       
       while (pin != 4774) { // esta validacion de pin podes hacerla en otra funcion aparte que devuelva un booleano.
           validarpass();
       }
       if (pin == 4774)
       {
           menu();
       }
    }   
    while (i<=0) { // esto no le encuentro el sentido, debería haber un while que consulte si quiere hacer otra operación
     menu(); // y en caso de poner no debería salir.
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
    saldo -= retiro; //si retira más de lo que posee en saldo, puede tener saldo negativo?
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
        cout << "\tSu saldo es: $" << saldo << " USD" << endl << endl; // (1) estos couts mandalos a una funcion que los arme, así quedan más organizados y no se muestran en crudo dependiendo del texto que se pasa como parametro.
        break;
       
    case 2:
        retirom();
        while(retiro > saldo){ //esta validación debería estar en una función aparte, el switch debería solo derivar
            cout << "Usted no posee ese monto, ingrese nuevamente" << endl;
              retirom();
        }
        cout << "\t\t Su nuevo saldo ahora es de: $" << saldo << " USD" << endl << endl << endl << endl; // comentario (1)
        break;
        

    case 3:
        cout << "\t Digite la cantidad a depositar por favor" << endl; // comentario (1)
        cin >> deposito; //en función aparte
        saldo += deposito;
        cout << "\t\t Su nuevo saldo ahora es de: $" << saldo << " USD" << endl << endl << endl << endl; // comentario (1)
        break;
       

    case 4:
        cout << "Gracias por elegirnos como su servicio de Cajero Automatico, hasta pronto." << endl; // comentario (1)
        break;
        return 0;

    default:
        cout << "Opcion incorrecta" << endl << endl << endl << endl; // comentario (1)
      
    }
    return 0;
 
}
