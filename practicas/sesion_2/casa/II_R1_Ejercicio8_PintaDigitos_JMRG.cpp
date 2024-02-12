/*
	Ejercicio 8: Programa que lee un numero entero introducido por el usuario
					 y devuelve los digitos del numero separados por tres espacios
					 en blanco.
	
	Entrada: numero introducido por el usuario (numero)
	Salidas: cada digito del numero por separado (digito1, digito2, digito3)

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>	

using namespace std;

int main(){							      
	int numero_3digitos, numero_2digitos;		 // Datos de entrada
	int digito1, digito2, digito3;			  	 // Datos de salida
							
	cout << "Introduzca un numero entero de tres cifras: ";				// El usuario introduce el dato requerido								
	cin >> numero_3digitos;
	
	digito3 = numero_3digitos % 10;		       // Se almacena la ultima cifra de la variable "numero_3digitos" en "digito3"
	numero_2digitos = numero_3digitos / 10;	 
	digito2 = numero_2digitos % 10;	          // Se almacena la ultima cifra de la variable "numero_2digitos" en "digito2"
	digito1 = numero_2digitos / 10;		       // Se almacena la primera cifra de la variable "numero_2digitos" en "digito1"
   
   cout << "\n" << digito1 << "   " << digito2 << "   " << digito3 << "\n\n";				// Se muestran al usuario los tres digitos del numero separados
   
	system("pause");
}
