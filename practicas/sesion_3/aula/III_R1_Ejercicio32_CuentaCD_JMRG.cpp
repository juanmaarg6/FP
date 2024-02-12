/*
   Ejercicio 32: Programa para trabajar con "struct". Indicar en cada
                 caso qu� tipo de dato tienen las variables del programa.
                 En caso de que sean err�neas, indicar d�nde esta el error.
                 
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez

*/

#include<iostream>

using namespace std;

struct CuentaCD{						// Creaci�n de tipo de dato
   double saldo;
   double tasa_de_intereses;
   int plazo;
   char inicial1;
   char inicial2;
};

int main(){
   
   CuentaCD cuenta;
   
   const string SEPARADOR = "\n\n----------------------------";

   // Apartado a): variable "cuenta.saldo"
   
   cout << "\nApartado a)";
   cout << "\n\n\tVariable: cuenta.saldo";
   cout << "\n\n\tVariable correcta";
   cout << "\n\n\tTipo de dato: double (numero real)";
   cout << SEPARADOR;
   
   // Apartado b): variable "cuenta.tasa_de_intereses"
   
   cout << "\nApartado b)";
   cout << "\n\n\tVariable: cuenta.tasa_de_intereses";
   cout << "\n\n\tVariable correcta";
   cout << "\n\n\tTipo de dato: double (numero real)";
   cout << SEPARADOR;
   
   // Apartado c): variable "CuentaCD.plazo"
   
   cout << "\nApartado c)";
   cout << "\n\n\tVariable: CuentaCD.plazo";
   cout << "\n\n\tVariable erronea. Deberia ser: cuenta.plazo";
   cout << "\n\n\tTipo de dato: int (numero entero)";
   cout << SEPARADOR;
   
   // Apartado d): variable "cuenta_ahorros.inicial1"
   
   cout << "\nApartado d)";
   cout << "\n\n\tVariable: cuenta_ahorros.inicial1";
   cout << "\n\n\tVariable erronea. Deberia ser: cuenta.inicial1";
   cout << "\n\n\tTipo de dato: char (caracter)";
   cout << SEPARADOR;
   
   // Apartado e): variable "cuenta.inicial2"
   
   cout << "\nApartado e)";
   cout << "\n\n\tVariable: cuenta.inicial2";
   cout << "\n\n\tVariable correcta";
   cout << "\n\n\tTipo de dato: char (caracter)";
   cout << SEPARADOR;
   
   // Apartado g): variable "cuenta"
   
   cout << "\nApartado f)";
   cout << "\n\n\tVariable: cuenta";
   cout << "\n\n\tVariable erronea. Falta el campo: cuenta.<campo>";
   cout << SEPARADOR;
   
   cout << "\n\n";
   
   system("pause");
}
