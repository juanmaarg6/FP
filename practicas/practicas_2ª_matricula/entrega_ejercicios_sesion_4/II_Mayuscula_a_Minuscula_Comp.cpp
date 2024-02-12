/*
	Relaci�n de ejercicios 2

	Modificaci�n del Ejercicio 25
	de la Relaci�n de Ejercicios 1: Programa que, dada una letra en may�scula, 
								    muestra dicha letra en min�scula.
	              
	Entradas: Car�cter en may�scula (mayuscula).
	Salidas: Car�cter en min�scula (minuscula).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal

int main() {				
	
	// Declaraci�n de constantes
	
	const int distancia_mayus_minus = 'a'-'A';
	
	/*
		La constante distancia_mayus_minus indica el n�mero de caracteres que 
		hay entre 'A' y 'a' en el c�digo ASCII. Esta distancia (32) ser� la 
		misma para cualquier letra en may�scula con su respectiva min�scula.
	*/
   													   	   
	// Declaraci�n de variables
	
	char mayuscula;
							
	// Entradas de datos
	
	cout << " Introduzca una letra en mayuscula: ";
	cin >> mayuscula;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Si 'mayuscula' es una letra may�scula:
		
			Sumar a la letra may�scula el n�mero de car�cteres que hay entre 
			ella y su correspondiente letra min�scula en el c�digo ASCII.
			
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
