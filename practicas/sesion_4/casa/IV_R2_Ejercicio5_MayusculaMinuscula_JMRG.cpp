/*
   Ejercicio 5: Programa que lee un car�cter y comprueba mediante
					 un condicional si es una letra may�scula. En dicho caso,
					 calcula y muestra la min�scula correspondiente. En cualquier
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
	const int DISTANCIA_MAY_MIN = 'a' - 'A';
	
	// Entrada de datos
	
	cout << "Introduzca un caracter: ";							
	cin >> letra_original;
	
	// Variable booleana para comprobar si el car�cter introducido es una letra may�scula
	
	es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');
	
	// Condicionales
	
	if(es_mayuscula){																	// Si es una letra may�scula, esta pasa a ser min�scula
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;
	}
	
	else{																					// Si es cualquier otro car�cter, se mantiene igual
		letra_convertida = letra_original;										
	}
	
	// Salida de datos
	
	cout << endl << "El caracter '" << letra_original << "' una vez convertido es: " << letra_convertida << endl << endl;
	
	system("pause");

}
