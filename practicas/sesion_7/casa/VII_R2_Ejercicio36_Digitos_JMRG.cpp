/*
	Ejercicio 36: Programa que lee un numero entero y muestra
	              todos sus digitos separados por un espacio
	              en blanco.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int numero, auxiliar1, auxiliar2, digito, divisor, contador_digitos = 0;
   
   /*
      Algoritmo:
      
      Introducir un numero.
      
      Calcular el numero de digitos de dicho numero.
      
      Calcular el primer digito del numero. Mostrarlo en pantalla.
      Eliminar dicho digito del numero y repetir el proceso hasta que
      numero sea distinto de cero.
      
   */

   cout << " Introduzca un numero: ";
   cin >> numero;
   
   cout << endl;
   
   auxiliar1 = numero;
   auxiliar2 = numero;
   
   while(auxiliar1 != 0){
   	contador_digitos++;
		auxiliar1 /= 10;	
   }
   
   divisor = pow(10, contador_digitos - 1);
   
	while(auxiliar2 != 0){
   	digito = auxiliar2 / divisor;
   	
		cout << " " << digito;
		
		auxiliar2 %= divisor;
		divisor /= 10;
   }
   
   cout << endl << endl;
   
   system("pause");
}
