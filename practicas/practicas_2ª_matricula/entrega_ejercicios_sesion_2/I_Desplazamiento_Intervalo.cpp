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
	
	int minimo, maximo;
	int a_desplazar, desplazamiento;
	int numero_desplazado;
	int long_intervalo, suma;
							
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
	
	/*
		Algoritmo:
		
		Calcular la longitud del intervalo.
		
		Sumar el desplazamiento al n�mero del intervalo introducido.
		
		Al resultado de la suma anterior, restarle el valor entero m�nimo
		del intervalo. Calcular el resto de la divisi�n de dicha resta por
		la longitud del intervalo (as�, la suma del desplazamiento y el n�mero
		del intervalo introducido sigue estando en el intervalo). Sumar el
		valor entero m�nimo del intervalo al resultado anterior.
	*/
	
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
