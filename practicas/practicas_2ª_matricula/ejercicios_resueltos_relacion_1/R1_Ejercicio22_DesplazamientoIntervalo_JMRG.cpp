/*
	Relaci�n de ejercicios 1

	Ejercicio 22: Programa que, dados un valor m�nimo y m�ximo de un 
			      intervalo, un valor entero de desplazamiento y un 
				  n�mero entero a desplazar, suma al n�mero entero el 
				  desplazamiento dado y muestra el resultado, el cual tiene
				  que permanecer dentro del intervalo.
	
	Entradas: Valor m�nimo del intervalo (minimo),
			  Valor m�ximo del intervalo (maximo),
			  Valor del desplazamiento (desplazamiento),
			  N�mero entero a desplazar (a_desplazar).
	Salidas: N�mero del intervalo ya desplazado (numero_desplazado).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaraci�n de variables
	
	int minimo = 0, maximo = 0;
	int desplazamiento = 0;
	int a_desplazar = 0;
	int numero_desplazado = 0;
	int long_intervalo = 0, suma = 0;
							
	// Entradas de datos
	
	cout << " Introduzca el valor entero minimo del intervalo: ";
	cin >> minimo;
	cout << " Introduzca el valor entero maximo del intervalo: ";
	cin >> maximo;
	cout << " Introduzcar el valor entero del desplazamiento (mayor que 0): ";
	cin >> desplazamiento;
	cout << " Introduzcar un numero entero del intervalo: ";
	cin >> a_desplazar;
	
	// C�lculos
	
	long_intervalo = maximo - minimo + 1;
	suma = a_desplazar + desplazamiento;
	numero_desplazado = minimo + ((suma - minimo) % long_intervalo);
	
	// Salidas
	
	cout << endl << " Tras un desplazamiento de " << desplazamiento 
	     << " unidades, el numero " << a_desplazar << " del intervalo [" 
		 << minimo << "," << maximo << "] pasa a ser el numero " 
		 << numero_desplazado << endl << endl; 
	
	system("pause");
	return 0;
}
