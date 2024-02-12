/*
   Ejercicio 11: Programa que lee valores enteros desde teclado y calcula cuántos se han introducido y
					  cuál es el mínimo de dichos valores (pueden ser positivos o negativos).
                    
   Código fuente escrito por Juan Manuel Rodríguez Gómez
*/

#include <iostream>

using namespace std;

int main(){	
	
   int entero, dato, minimo_entero;
   
   /*
   	1) Introducir un número entero desde teclado y almacenarlo en "entero".
   	2) minimo_entero = entero.
   	3) Mientras que entero sea distinto de 0:
   		3.1) Si entero < minimo_entero, entonces minimo_entero = entero (almacena el número más pequeño). 
   		3.2) Introducir un número entero desde teclado y almacenarlo "entero".
   		3.3) Aumentar "dato" (es un contador) en 1 .
   	4) Mostrar "dato".
   	5) Mostrar "minimo_entero".  	
   */
   
   cout << " Introduce un numero entero (0 para finalizar): ";
  	cin >> entero;
	minimo_entero = entero; 
	
	while(entero != 0){
   	
   	if(entero < minimo_entero){
   		minimo_entero = entero;	
   	}
   	
   	cout << " Introduce un numero entero (0 para finalizar): ";
   	cin >> entero;
   	
   	dato++;
	}
	
	cout << "\n Total de numeros introducidos = " << dato;
	cout << "\n Valor minimo introducido = " << minimo_entero;
	cout << "\n\n";
	
	system("pause");
}
