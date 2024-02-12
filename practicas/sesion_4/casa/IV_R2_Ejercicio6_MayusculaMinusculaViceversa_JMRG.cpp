/*
   Ejercicio 6: Programa que lee un carácter y comprueba mediante
					 un condicional:
					 
					 1) Si es una letra mayúscula. En dicho caso, calcula y muestra la minúscula correspondiente.
					 2) Si es una letra minúscula. En dicho caso, calcula y muestra la mayúscula correspondiente.
					 3) Si no es un carácter alfabético. En dicho caso, muestra el carácter original introducido .
					 otro caso, muestra el carácter original.  
                 
   Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/

#include<iostream>

using namespace std;

int main(){
   
   // Declaración de variables
	
	char letra_original;																
	char letra_convertida;
	bool es_mayuscula;
	bool es_minuscula;
	const int DISTANCIA_MAY_MIN = 'a' - 'A';
	const int DISTANCIA_MIN_MAY = 'A' - 'a';

	// Entrada de datos
	
	cout << "Introduzca un caracter: ";							
	cin >> letra_original;
	
	// Variables booleanas para comprobar si el carácter introducido es una letra mayúscula o minúscula
	
	es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');
	es_minuscula = (letra_original >= 'a') && (letra_original <= 'z');
	
	// Condicionales
	
	if(es_mayuscula){																	// Si es una letra mayúscula, esta pasa a ser minúscula
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;
	}
	
	else if(es_minuscula){															// Si es una letra minúscula, esta pasa a ser mayúscula
		letra_convertida = letra_original + DISTANCIA_MIN_MAY;
	}
	
	else{																					// Si es cualquier otro carácter, se mantiene igual
		letra_convertida = letra_original;
	}
	
	// Salida de datos
	
	cout << endl << "El caracter '" << letra_original << "' una vez convertido es: " << letra_convertida << endl << endl;
	
	system("pause");

}
