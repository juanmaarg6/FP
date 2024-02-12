/*
	Relación de ejercicios 2

	Modificación del Ejercicio 36
	de la Relación de Ejercicios 1: Programa que, dado un número real y un 
									número entero, trunca el número real tantas 
									cifras decimales como indique el número 
									entero.
	
	Entradas: Número real (r),
	          Número entero (n).
	Salidas: Número real truncado (r_truncado).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos

using namespace std;

// Programa principal

int main() {				

	// Declaración de variables
	
	double r = 0.0;
	int n = 0;
					
	// Entradas de datos
	
	cout << " Introduzca un numero real 'r': ";
	cin >> r;
	cout << " Introduzca un numero entero 'n': ";
	cin >> n;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Si 'n' es mayor o igual que 0:
		
			Separar la parte entera y la parte real del número real.
		
			Truncar la parte real. Para ello la multiplicamos por 10 tantas 
			veces como cifras decimales queramos truncar. Luego obtenemos la 
			parte entera de ese resultado para eliminar el resto de decimales. 
			Finalmente, dividimos por 10 tantas veces como cifras decimales 
			queramos truncar, obteniendo así la parte real truncada del número 
			real.
			
			Sumar la parte entera y la parte real truncada del número real.
			
		Si no, mostrar mensaje de error.
	*/
	
	bool datos_correctos = (n >= 0);
	
	if(datos_correctos) {
	
		double r_truncado = 0.0;
		double parte_real_r = 0.0, parte_real_truncada_r = 0.0;
		int parte_entera_r = 0;
	
		parte_entera_r = int(r);
		parte_real_r = r - parte_entera_r;
		parte_real_truncada_r = int(parte_real_r * pow(10, n)) / pow(10, n);
		r_truncado = parte_entera_r + parte_real_truncada_r;
		
		// Salidas
		
		cout << endl << " Tras truncar " << n << " cifras decimales el numero " 
		     << r << ", el resultado es " << r_truncado << endl << endl;
	}
	else {
		
		// Mensaje de error
		
		cout << endl << " Error: El valor de 'n' es incorrecto.";
		cout << endl << "        Se requiere: 'n' >= 0";
		cout << endl << endl;	
	}
	
	return 0;
}
