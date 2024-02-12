/*
	Relación de ejercicios 2

	Modificación del Ejercicio 25
	de la Relación de Ejercicios 1: Programa que, dada una letra en mayúscula, 
								    muestra dicha letra en minúscula.
	              
	Entradas: Carácter en mayúscula (mayuscula).
	Salidas: Carácter en minúscula (minuscula).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {				
	
	// Declaración de constantes
	
	const int distancia_mayus_minus = 'a'-'A';
	
	/*
		La constante distancia_mayus_minus indica el número de caracteres que 
		hay entre 'A' y 'a' en el código ASCII. Esta distancia (32) será la 
		misma para cualquier letra en mayúscula con su respectiva minúscula.
	*/
   													   	   
	// Declaración de variables
	
	char mayuscula;
							
	// Entradas de datos
	
	cout << " Introduzca una letra en mayuscula: ";
	cin >> mayuscula;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Si 'mayuscula' es una letra mayúscula:
		
			Sumar a la letra mayúscula el número de carácteres que hay entre 
			ella y su correspondiente letra minúscula en el código ASCII.
			
		Si no, mostrar mensaje de error.
	*/
	
	bool datos_correctos = ( (mayuscula >= 'A') && (mayuscula <= 'Z') );
	
	if(datos_correctos) {
		
		char minuscula;
		
		minuscula = mayuscula + distancia_mayus_minus;
		
		// Salidas
	
		cout << endl << " Letra " << mayuscula 
	         << " en minuscula: " << minuscula << endl << endl;
	}
	else {
		
		// Mensaje de error
		
		cout << endl << " Error: El valor de 'mayuscula' es incorrecto.";
		cout << endl << "        Se requiere: Letra mayuscula";
		cout << endl << endl;			
	}
	
	return 0;
}
