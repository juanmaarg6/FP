/*
	Relaci�n de ejercicios 2

	Ejercicio 28: Programa que, dado un n�mero entero positivo, 
	              devuelve los d�gitos de dicho n�mero 
				  separados por una barra vertical.
	              
	Entradas: N�mero positivo (entero).
	Salidas: Cifras del n�mero introducido separadas cada una de ellas
	         por una barra vertical (cad_resultado).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <string>		// Inclusi�n de los recursos del tipo de dato string
			
using namespace std;

// Programa principal

int main() {
	
	// Declaraci�n de constantes
	
	const string SEPARADOR = "|"; 

	// Declaraci�n de variables
	
	int entero = 0;
	
	// Entradas de datos
		
	do {
		
		cout << " Introduzca un entero positivo: ";
		cin >> entero; 
	}while(entero < 0);

	// C�lculos
	
	/*
		Algoritmo:
		
		Hacer una copia de la variable 'entero' ('copia_entero').
		
		Mientras 'copia_entero' sea distinto de 0:
			
			Obtener el �ltimo d�gito de 'copia_entero'.
			A�adir el d�gito a 'cad_resultado'.
			Eliminar el �ltimo d�gito de 'copia_entero'. 
			Incrementar el contador de d�gitos.
	*/
	
	int copia_entero = entero;
	int digito = 0;
	int contador_digitos = 0;
	string cad_resultado;
	
	while(copia_entero != 0) {
		
		digito = copia_entero % 10;
		
		cad_resultado = SEPARADOR + to_string(digito) + cad_resultado;
				
		copia_entero /= 10;
		
		contador_digitos++;
	}
	
	cad_resultado += SEPARADOR;
		
	// Salidas
	
	cout << endl;
	cout << " El numero introducido tiene " << contador_digitos << " digitos.";
	cout << endl << endl;
	cout << " " << cad_resultado;
	cout << endl << endl;	

	return 0;
}
