/*
	Programa que lee los n�meros primos que forman
	un n�mero secreto codificado en un mensaje extraterrestre 
	y muestra en pantalla dicho n�mero descodificado.
	
	C�digo fuente realizado por Juan Manuel Rodr�guez G�mez.
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
