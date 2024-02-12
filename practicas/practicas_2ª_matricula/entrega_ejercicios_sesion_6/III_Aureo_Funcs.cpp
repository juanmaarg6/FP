/*
	Relación de ejercicios 3

	Ejercicio 6: El número aúreo se conoce desde la Antigüedad griega y 
	             aparece en muchos temas de la geometría clásica. La forma más 
				 sencilla de definirlo es como el único número positivo que 
				 cumple que Phi^2 - Phi = 1 y por consiguiente su valor es:
	                					___
              					   1 + V 5 
							Phi = ---------- = 1,6180339887...
                  					  2
				 Se pueden construir aproximaciones al número aúreo mediante 
				 la fórmula:

		      					  fib(n + 1)
	   						a_n = -----------
                                    fib(n)

				 siendo fib(n) el término n-ésimo de la sucesión de fibonacci, 
				 definida de la siguiente forma:
		
							fib(1) = 1
							fib(2) = 1
							fib(n) = fib(n-2) + fib(n-1) para n > 2

				 A medida que n aumenta, a_n oscila, y es alternativamente 
				 menor y mayor que la razón áurea.

				 Este programa calcula el menor valor de n que hace que la 
				 aproximación dada por a_n difiera en menos de delta del 
				 número Phi, sabiendo que n >= 1. 
	
	Entradas: Un número real positivo que establece la precisión (delta).
	Salidas:  Número de iteraciones que hay que realizar para que la 
			  aproximación dada por a_n difiera en menos de delta del 
			  número Phi (n).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos
#include <iomanip>		// Inclusión de los recursos de personalización de E/S

using namespace std;

/***************************************************************************/
// Función: LeerDelta
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: Un número real positivo que establece la precisión.
/***************************************************************************/
double LeerDelta(string msg) {
	
	double n;
		
	cout << endl;

	do {	
		cout << msg;
		cin >> n;
	} while ( (n <= 0) || (n >= 1) );
	
	cout << endl;

	return n;
}

/***************************************************************************/
// Función: CalcularTerminoFibonacci
// Recibe: Índice del término buscado (n).
// Devuelve: N-ésimo término de la sucesión de Fibonacci.
/***************************************************************************/
int CalcularTerminoFibonacci(int n) {
	
	int fib_n = 1; 
	
	int ant1 = 1; // fib(2)
	int ant2 = 1; // fib(1) 
	
	for(int i = 2 ; i < n; i++) {
			
		fib_n = ant1 + ant2; // fib (i)
	
		// Preparamos la siguiente iteracion
		ant2 = ant1; 		// fib(n)		
		ant1 = fib_n;	// fib(n+1)	
	}
		
	return fib_n;
}

/***************************************************************************/
// Función: CalcularTerminoAsubN
// Recibe: N-ésimo y N+1-ésimo término de la sucesión de
//         Fibonacci (fib_n_mas_1, fib_n).
// Devuelve: N-ésimo término de la sucesión a_n.
/***************************************************************************/
double CalcularTerminoAsubN(int fib_n_mas_1, int fib_n) {
	
	double a_n = ( (double)fib_n_mas_1 ) / fib_n;
	
	return a_n; 
}

/***************************************************************************/
// Función: CalcularDiferencia
// Recibe: Término n-ésimo de la sucesión a_n (a_n),
//         Valor "real" del número aureo (PHI).
// Devuelve: N-ésimo término de la sucesión a_n.
/***************************************************************************/
double CalcularDiferencia(double a_n, double PHI) {
	
	double diferencia = fabs(a_n - PHI);
	
	return diferencia; 
}

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	// Declaración de constantes
	
	const double PHI = (1 + sqrt(5.0)) / 2.0; 
	
	// Declaración de variables
	
	double delta;
	
	// Entradas de datos
	
	cout << " Calculando la aproximacion al numero Aureo = "
		 << setw(15) << setprecision(13) << PHI << endl << endl;
		 
	delta = LeerDelta(" Introduzca la precision (< 1) para la aproximacion: ");
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Declaramos 'n' y lo igualamos a 1.
		
		Mientras 'diferencia' sea mayor o igual que 'delta':
		
			Se calcula 'fib_n' y 'fib_n_mas_1'.
			
			Se calcula 'a_n' a partir de 'fib_n' y 'fib_n_mas_1'.
			
			Se calcula la diferencia entre 'a_n' y 'PHI'.
			
			Si 'diferencia' es menor o igual que delta, se detiene el
			cálculo.
			Si no, se incrementa 'n' en 1 y se vuelven a repetir los
			cálculos para el nuevo valor de 'n'.
			
		Se muestran los resultados.
	*/
	
	int n = 1;
	int fib_n, fib_n_mas_1;
	double a_n;
	double diferencia;
	double 	diferencia_anterior = 1; // Primer mínimo
	
	bool continuar = true;
	
	while(continuar) {
		
		fib_n = CalcularTerminoFibonacci(n);
		fib_n_mas_1 = CalcularTerminoFibonacci(n+1);
		
		a_n = CalcularTerminoAsubN(fib_n_mas_1, fib_n);
		
		diferencia = CalcularDiferencia(a_n, PHI);

		cout << " a_" << setw(3) << n << " = "
		     << setw(15) << setprecision(13) << a_n;
		cout << " (Dif = " << setw(15) <<setprecision(13)
		     << diferencia << ")" << endl;
		    		 
		if (diferencia <= delta)
			continuar = false;
		else {
			n++;
			diferencia_anterior = diferencia;	
		}
	}
	
	// Salidas
	
	cout << endl;
	cout << " Valor buscado   = "
		 << setw(15) << setprecision(13) << PHI << endl;
	cout << " Valor calculado = "
		 << setw(15) << setprecision(13) << a_n << endl << endl;
	cout << endl;
	
	cout << " Menor valor de n = " << setw(3) << n << endl << endl; 
	cout << " Diferencia actual =   " << setw(15) << setprecision(8) 
		 << diferencia << endl;
	cout << " Precision =           " << setw(15) << setprecision(8)
		 << delta << endl;;
	cout << " Diferencia anterior = " << setw(15) << setprecision(8) 
	     << diferencia_anterior << endl;	
	cout << endl << endl;
			
	return 0;
}
