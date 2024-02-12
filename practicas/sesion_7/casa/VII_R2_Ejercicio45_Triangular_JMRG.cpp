/*
	Ejercicio 45: Programa que muestra todos los numeros triangulares
	              menores que un numero entero introducido desde teclado.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){
	
	int numero_tope, numero_triangular = 0, aumento_en_1 = 1;
   
   /*
      Algoritmo:
      
      Introducir un numero para calcular todos los numeros
      triangulares menores a dicho numero.
      
      Ir mostrando en pantalla cada numero triangular hasta que
      se alcance el numero tope.   
   */

   cout << " Introduzca un numero: ";
   cin >> numero_tope;
   
   cout << "\n Los numeros triangulares menores que " << numero_tope << " son: " << endl << endl;
   
	while(numero_triangular < numero_tope){
		cout << " " << numero_triangular;
   	numero_triangular += aumento_en_1;	
   	
   	aumento_en_1++;
   }
	
	cout << endl << endl;
	
   system("pause");
}
