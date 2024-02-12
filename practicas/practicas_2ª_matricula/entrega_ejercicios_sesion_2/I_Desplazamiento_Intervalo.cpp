/*
	Relación de ejercicios 1

	Ejercicio 22: Programa que, dados un valor mínimo y máximo de un 
			      intervalo, un valor entero de desplazamiento y un 
				  número entero a desplazar, suma al número entero el 
				  desplazamiento dado y muestra el resultado, el cual tiene
				  que permanecer dentro del intervalo.
	
	Entradas: Valor mínimo del intervalo (minimo),
			  Valor máximo del intervalo (maximo),
			  Valor del desplazamiento (desplazamiento),
			  Número entero a desplazar (a_desplazar).
	Salidas: Número del intervalo ya desplazado (numero_desplazado).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaración de variables
	
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
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Calcular la longitud del intervalo.
		
		Sumar el desplazamiento al número del intervalo introducido.
		
		Al resultado de la suma anterior, restarle el valor entero mínimo
		del intervalo. Calcular el resto de la división de dicha resta por
		la longitud del intervalo (así, la suma del desplazamiento y el número
		del intervalo introducido sigue estando en el intervalo). Sumar el
		valor entero mínimo del intervalo al resultado anterior.
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
