/*
	Relaci�n de ejercicios 1

	Ejercicio 36: Programa que, dado un n�mero real y un n�mero entero, 
				  trunca el n�mero real tantas cifras decimales como indique
				  el n�mero entero.
	
	Entradas: N�mero real (r),
	          N�mero entero (n).
	Salidas: N�mero real truncado (r_truncado).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std;

// Programa principal

int main() {				

	// Declaraci�n de variables
	
	double r = 0.0, r_truncado = 0.0;
	double parte_real_r = 0.0, parte_real_truncada_r = 0.0;
	int parte_entera_r = 0;
	int n = 0;
					
	// Entradas de datos
	
	cout << " Introduzca un numero real: ";
	cin >> r;
	cout << " Introduzca un numero entero: ";
	cin >> n;
	
	// C�lculos
	
	/*
		Algoritmo:
				
		Separar la parte entera y la parte real del n�mero real.
		
		Truncar la parte real. Para ello la multiplicamos por 10 tantas veces
		como cifras decimales queramos truncar. Luego obtenemos la parte entera
		de ese resultado para eliminar el resto de decimales. Finalmente, 
		dividimos por 10 tantas veces como cifras decimales queramos truncar,
		obteniendo as� la parte real truncada del n�mero real.
		
		Sumar la parte entera y la parte real truncada del n�mero real.
	*/
	
	parte_entera_r = int(r);
	parte_real_r = r - parte_entera_r;
	parte_real_truncada_r = int(parte_real_r * pow(10, n)) / pow(10, n);
	r_truncado = parte_entera_r + parte_real_truncada_r;
	
	// Salidas
	
	cout << endl << " Tras truncar " << n << " cifras decimales el numero " 
	     << r << ", el resultado es " << r_truncado << endl << endl;
	
	return 0;
}
