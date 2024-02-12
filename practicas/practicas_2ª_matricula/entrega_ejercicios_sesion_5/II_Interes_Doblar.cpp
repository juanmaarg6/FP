/*
	Relaci�n de ejercicios 2

	Ejercicio 30: Programa que, dado un capital inicial y un inter�s, muestra 
				  cu�ntos a�os tienen que pasar para, como m�nimo, doblar el 
				  capital inicial.
	              
	Entradas: Capital inicial (capital_inicial),
	          Inter�s (interes).
	Salidas: N�mero de a�os que tienen que pasar para doblar el capital
	         inicial (anios).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <iomanip>		// Inclusi�n de los recursos de modificaci�n de E/S

using namespace std;

// Programa principal

int main() {
	
	cout.setf (ios::fixed);
	cout.setf (ios::showpoint);
	
	// Declaraci�n de constantes
	
	const double MINIMO_INTERES = 0;
	const double MAXIMO_INTERES = 10;

	// Declaraci�n de variables
	
	double capital_inicial = 0.0, interes = 0.0;
	
	// Entradas de datos
		
	do {
		
		cout << " Introduzca el capital inicial (en euros): ";
		cin >> capital_inicial; 
	}while(capital_inicial < 0);
	
	do {
		cout << " Introduzca el porcentaje de interes (0-10]: ";
		cin >> interes; 
	}while( (interes <= MINIMO_INTERES) || (interes > MAXIMO_INTERES) );

	// C�lculos
	
	/*
		Algoritmo:
		
		Hacer una copia de la variable 'capital_inicial' 
		('copia_capital_inicial').
		
		Mientras 'copia_capital_inicial' sea menor que el doble del capital
		inicial:
		
			Calcular el capital obtenido tras un a�o seg�n el inter�s aplicado.
			Incrementar el contador de a�os.
			Mostrar el capital obtenido en el a�o correspondiente.
	*/
	
	double doble_capital = 2 * capital_inicial;
	double copia_capital_inicial = capital_inicial;
	int contador_anios = 0;
	
	while(copia_capital_inicial < doble_capital) {
		
		copia_capital_inicial *= ( 1 + (interes / 100) );
		
		contador_anios++;
		
		cout << endl << " Capital obtenido tras el anio " << contador_anios
		     << ": " << setprecision(2) << copia_capital_inicial;
	}
			
	// Salidas
	
	cout << endl << endl;
	cout << " Para doblar el capital inicial (" << capital_inicial 
	     << " euros) tienen que pasar " << contador_anios << " anios";
	cout << endl << endl;

	return 0;
}
