/*
	Programa que lee los números primos que forman
	un número secreto codificado en un mensaje extraterrestre 
	y muestra en pantalla dicho número descodificado.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>															

using namespace std;

int main(){	

	int numero = 1;									
	int resultado = 1;
	
	/*
		Algoritmo:
		
		Mientras "numero" sea distinto que 4:
		
			Calcular "resultado".
			Introducir "numero".
			
		Mostrar "resultado" en pantalla.
	*/
	
	while(numero != 0){
		resultado *= numero;
		cin >> numero;
	}
	
	cout << "\n El numero secreto del mensaje extraterrestre es: " << resultado << "\n"; 
}
