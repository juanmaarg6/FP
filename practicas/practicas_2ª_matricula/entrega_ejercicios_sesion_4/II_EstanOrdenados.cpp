/*
	Relaci�n de ejercicios 2

	Ejercicio 3: Programa que, dados tres n�meros enteros, dice si est�n 
				 ordenados (ya sea de forma ascendente o descendente) o no.
	
	Entradas: Tres n�meros enteros (entero1, entero2, entero3).
	Salidas: Ver si los n�meros enteros est�n ordenados o no.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal

int main(){
   
   // Declaraci�n de variables
   
	int entero1 = 0, entero2 = 0, entero3 = 0;
	
	// Entradas de datos
	
	cout << " Introduzca el primer numero entero: ";
	cin >> entero1;
	cout << " Introduzca el segundo numero entero: ";
	cin >> entero2;
	cout << " Introduzca el tercer numero entero: ";
	cin >> entero3;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Si 'entero1' es menor que 'entero2' y 'entero2' es menor que 'entero3',
		entonces los n�meros est�n ordenados de forma ascendente.
		
		Si 'entero1' es mayor que 'entero2' y 'entero2' es mayor que 'entero3',
		entonces los n�meros est�n ordenados de forma descendente.
		
		Si los n�meros no est�n ordenados de forma ascendente ni descendente,
		entonces no est�n ordenados.
		
		*/
		
	bool ordenados_ascendente = ( (entero1 < entero2) && (entero2 < entero3) );
	bool ordenados_descendente = ( (entero1 > entero2) && (entero2 > entero3) );
	bool no_ordenados = ( !(ordenados_ascendente) && !(ordenados_descendente) );
	
	// Salidas
	
	if(ordenados_ascendente)
		cout << endl << " Los numeros introducidos estan ordenados"
		     << " de forma ascendente" << endl << endl;
	
	if(ordenados_descendente)
		cout << endl << " Los numeros introducidos estan ordenados"
		     << " de forma descendente" << endl << endl;
	
	if(no_ordenados)
		cout << endl << " Los numeros introducidos no estan ordenados" 
		<< endl << endl;
	
	return 0;
}
