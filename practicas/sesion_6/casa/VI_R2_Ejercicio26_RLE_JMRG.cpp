/*
	Ejercicio 26: Programa que lee una secuencia de números
	              naturales terminada con un número negativo
	              y la codifica mediante el método RLE.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>														

using namespace std;

int main(){
	
	int numero, contador = 0 , numero_siguiente = 0;
	
	/*
		Algoritmo:
		
		Introducir un número natural y almacenarlo en "numero".
		
		El valor de "numero_siguiente" pasa a ser igual al valor de "numero".
		
		Mientras "numero_siguiente" sea distinto de -1:
			
			Hacer:
				Aumentar "contador" en 1.
				Introducir "numero_siguiente".
			Mientras "numero_siguiente" sea igual a "numero".
			
			Mostrar en pantalla "contador" y "numero".
			El valor de "numero" pasa a ser igual al valor de "numero_siguiente".
			Resetear "contador" a 0.				
	*/											
	
	cout << " Introduzca una secuencia de numeros naturales (-1 al final): ";						
	cin >> numero;
	
	cout << "\n";
	
	numero_siguiente = numero;

	while(numero_siguiente != -1){
				
		do{
			contador++;
			cin >> numero_siguiente;
		}while(numero_siguiente == numero);
		
		cout << " " << contador << " " << numero;
		numero = numero_siguiente;
		contador = 0;
	}
	
	cout << "\n\n";
	
	system("pause");				
}
