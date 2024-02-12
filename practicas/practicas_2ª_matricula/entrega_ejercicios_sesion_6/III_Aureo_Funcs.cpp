/*
	Relaci�n de ejercicios 3

	Ejercicio 6: El n�mero a�reo se conoce desde la Antig�edad griega y 
	             aparece en muchos temas de la geometr�a cl�sica. La forma m�s 
				 sencilla de definirlo es como el �nico n�mero positivo que 
				 cumple que Phi^2 - Phi = 1 y por consiguiente su valor es:
	                					___
              					   1 + V 5 
							Phi = ---------- = 1,6180339887...
                  					  2
				 Se pueden construir aproximaciones al n�mero a�reo mediante 
				 la f�rmula:

		      					  fib(n + 1)
	   						a_n = -----------
                                    fib(n)

				 siendo fib(n) el t�rmino n-�simo de la sucesi�n de fibonacci, 
				 definida de la siguiente forma:
		
							fib(1) = 1
							fib(2) = 1
							fib(n) = fib(n-2) + fib(n-1) para n > 2

				 A medida que n aumenta, a_n oscila, y es alternativamente 
				 menor y mayor que la raz�n �urea.

				 Este programa calcula el menor valor de n que hace que la 
				 aproximaci�n dada por a_n difiera en menos de delta del 
				 n�mero Phi, sabiendo que n >= 1. 
	
	Entradas: Un n�mero real positivo que establece la precisi�n (delta).
	Salidas:  N�mero de iteraciones que hay que realizar para que la 
			  aproximaci�n dada por a_n difiera en menos de delta del 
			  n�mero Phi (n).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos
#include <iomanip>		// Inclusi�n de los recursos de personalizaci�n de E/S

using namespace std;

/***************************************************************************/
// Funci�n: LeerDelta
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: Un n�mero real positivo que establece la precisi�n.
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
// Funci�n: CalcularTerminoFibonacci
// Recibe: �ndice del t�rmino buscado (n).
// Devuelve: N-�simo t�rmino de la sucesi�n de Fibonacci.
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
// Funci�n: CalcularTerminoAsubN
// Recibe: N-�simo y N+1-�simo t�rmino de la sucesi�n de
//         Fibonacci (fib_n_mas_1, fib_n).
// Devuelve: N-�simo t�rmino de la sucesi�n a_n.
/***************************************************************************/
double CalcularTerminoAsubN(int fib_n_mas_1, int fib_n) {
	
	double a_n = ( (double)fib_n_mas_1 ) / fib_n;
	
	return a_n; 
}

/***************************************************************************/
// Funci�n: CalcularDiferencia
// Recibe: T�rmino n-�simo de la sucesi�n a_n (a_n),
//         Valor "real" del n�mero aureo (PHI).
// Devuelve: N-�simo t�rmino de la sucesi�n a_n.
/***************************************************************************/
double CalcularDiferencia(double a_n, double PHI) {
	
	double diferencia = fabs(a_n - PHI);
	
	return diferencia; 
}

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	// Declaraci�n de constantes
	
	const double PHI = (1 + sqrt(5.0)) / 2.0; 
	
	// Declaraci�n de variables
	
	double delta;
	
	// Entradas de datos
	
	cout << " Calculando la aproximacion al numero Aureo = "
		 << setw(15) << setprecision(13) << PHI << endl << endl;
		 
	delta = LeerDelta(" Introduzca la precision (< 1) para la aproximacion: ");
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Declaramos 'n' y lo igualamos a 1.
		
		Mientras 'diferencia' sea mayor o igual que 'delta':
		
			Se calcula 'fib_n' y 'fib_n_mas_1'.
			
			Se calcula 'a_n' a partir de 'fib_n' y 'fib_n_mas_1'.
			
			Se calcula la diferencia entre 'a_n' y 'PHI'.
			
			Si 'diferencia' es menor o igual que delta, se detiene el
			c�lculo.
			Si no, se incrementa 'n' en 1 y se vuelven a repetir los
			c�lculos para el nuevo valor de 'n'.
			
		Se muestran los resultados.
	*/
	
	int n = 1;
	int fib_n, fib_n_mas_1;
	double a_n;
	double diferencia;
	double 	diferencia_anterior = 1; // Primer m�nimo
	
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
