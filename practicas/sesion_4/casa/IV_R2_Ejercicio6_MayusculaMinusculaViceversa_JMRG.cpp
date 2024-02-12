/*
   Ejercicio 6: Programa que lee un car�cter y comprueba mediante
					 un condicional:
					 
					 1) Si es una letra may�scula. En dicho caso, calcula y muestra la min�scula correspondiente.
					 2) Si es una letra min�scula. En dicho caso, calcula y muestra la may�scula correspondiente.
					 3) Si no es un car�cter alfab�tico. En dicho caso, muestra el car�cter original introducido .
					 otro caso, muestra el car�cter original.  
                 
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez.
*/

#include<iostream>

using namespace std;

int main(){
   
   // Declaraci�n de variables
	
	char letra_original;																
	char letra_convertida;
	bool es_mayuscula;
	bool es_minuscula;
	const int DISTANCIA_MAY_MIN = 'a' - 'A';
	const int DISTANCIA_MIN_MAY = 'A' - 'a';

	// Entrada de datos
	
	cout << "Introduzca un caracter: ";							
	cin >> letra_original;
	
	// Variables booleanas para comprobar si el car�cter introducido es una letra may�scula o min�scula
	
	es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');
	es_minuscula = (letra_original >= 'a') && (letra_original <= 'z');
	
	// Condicionales
	
	if(es_mayuscula){																	// Si es una letra may�scula, esta pasa a ser min�scula
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;
	}
	
	else if(es_minuscula){															// Si es una letra min�scula, esta pasa a ser may�scula
		letra_convertida = letra_original + DISTANCIA_MIN_MAY;
	}
	
	else{																					// Si es cualquier otro car�cter, se mantiene igual
		letra_convertida = letra_original;
	}
	
	// Salida de datos
	
	cout << endl << "El caracter '" << letra_original << "' una vez convertido es: " << letra_convertida << endl << endl;
	
	system("pause");

}
