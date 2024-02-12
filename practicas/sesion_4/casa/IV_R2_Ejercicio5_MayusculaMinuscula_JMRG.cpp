/*
   Ejercicio 5: Programa que lee un carácter y comprueba mediante
					 un condicional si es una letra mayúscula. En dicho caso,
					 calcula y muestra la minúscula correspondiente. En cualquier
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
	const int DISTANCIA_MAY_MIN = 'a' - 'A';
	
	// Entrada de datos
	
	cout << "Introduzca un caracter: ";							
	cin >> letra_original;
	
	// Variable booleana para comprobar si el carácter introducido es una letra mayúscula
	
	es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');
	
	// Condicionales
	
	if(es_mayuscula){																	// Si es una letra mayúscula, esta pasa a ser minúscula
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;
	}
	
	else{																					// Si es cualquier otro carácter, se mantiene igual
		letra_convertida = letra_original;										
	}
	
	// Salida de datos
	
	cout << endl << "El caracter '" << letra_original << "' una vez convertido es: " << letra_convertida << endl << endl;
	
	system("pause");

}
