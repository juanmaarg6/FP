/*
	Relaci�n de ejercicios 4

	Ejercicio 14: Programa que, dado un n�mero entero positivo, calcula
	              los n�meros primos que hay hasta dicho entero usando
	              la Criba de Erat�stenes.
	              
	Entradas: N�mero entero positivo (entero).
	Salidas: N�meros primos hasta 'entero' almacenados en un vector
	         (primos),
	         Total de n�meros primos hasta 'entero' (total_primos).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main () {	
	
	// Vectores de datos
	const int MAX_PRIMO = 5000;
	const int MAX_DATOS = 100; 
	bool es_primo[MAX_PRIMO];
	int primos[MAX_DATOS];
	int total_primos = 0;
	
	int entero;
	
	// Entradas de datos 
	
	do {
		cout << " Introduzca un numero entero positivo (menor que 5000): ";
		cin >> entero;
	}while( (entero <= 0) || (entero > MAX_PRIMO) );
		
	// C�lculos
	
	// Inicializamos todos los valores del vector 'es_primo' a true
	for(int i = 0; i < entero; i++)
		es_primo[i] = true;
	
	// Aplicamos la Criba de Erat�stenes de forma que le asignamos el valor
	// false a las casillas del vector 'es_primo' que sean m�ltiplos de 
	// un n�mero (comenzando por el 2 y llegando hasta el n�mero 'entero'
	// introducido)
	for(int i = 2; i < entero; i++)
		for(int j = 2; i*j < entero; j++)
			es_primo[i*j] = false;
	
	// Recorremos 'es_primo' y si el valor de la posici�n 'i' correspondiente
	// es true, entonces a�adimos dicha posici�n 'i' al vector 'primos', el
	// cual contiene todos los n�meros primos hasta 'entero'
	for(int i = 1; i < entero; i++)
		if(es_primo[i]) {
			primos[total_primos] = i;
			total_primos++;
		}
	
	// Salidas
	
	cout << endl;
	cout << " Numeros primos: ";
	cout << endl;
	for(int i = 0; i < total_primos; i++) {
		
		cout << endl;
		cout << "\t Primo numero " << setw(5) << i+1 << ": " 
		     << primos[i] << " ";
	}
	
	cout << endl << endl;
	cout << " Entre el numero 1 y el numero " << entero << " hay "
	     << total_primos << " numeros primos.";
				 
	cout << endl << endl;
	
	return 0;
}
