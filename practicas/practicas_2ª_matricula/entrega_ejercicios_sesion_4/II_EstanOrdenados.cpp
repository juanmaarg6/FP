/*
	Relación de ejercicios 2

	Ejercicio 3: Programa que, dados tres números enteros, dice si están 
				 ordenados (ya sea de forma ascendente o descendente) o no.
	
	Entradas: Tres números enteros (entero1, entero2, entero3).
	Salidas: Ver si los números enteros están ordenados o no.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main(){
   
   // Declaración de variables
   
	int entero1 = 0, entero2 = 0, entero3 = 0;
	
	// Entradas de datos
	
	cout << " Introduzca el primer numero entero: ";
	cin >> entero1;
	cout << " Introduzca el segundo numero entero: ";
	cin >> entero2;
	cout << " Introduzca el tercer numero entero: ";
	cin >> entero3;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Si 'entero1' es menor que 'entero2' y 'entero2' es menor que 'entero3',
		entonces los números están ordenados de forma ascendente.
		
		Si 'entero1' es mayor que 'entero2' y 'entero2' es mayor que 'entero3',
		entonces los números están ordenados de forma descendente.
		
		Si los números no están ordenados de forma ascendente ni descendente,
		entonces no están ordenados.
		
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
