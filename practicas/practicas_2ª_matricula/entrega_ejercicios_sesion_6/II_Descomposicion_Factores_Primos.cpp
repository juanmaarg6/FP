/*
	Relaci�n de ejercicios 2

	Ejercicio 47: Programa que, dado un n�mero entero positivo, muestra su
				  descomposici�n en factores primos de dos formas:
				  
				  1) Enumerando todos los primos de la descomposici�n
				  	 (en el caso de que un primo intervenga m�s de una
					  vez, se mostrar� tantas veces como sea preciso).
				
				  2) Como producto de potencias (en el caso de que un primo 
				     intervenga m�s de una vez se mostrar� una potencia
					 cuya base sea el valor del primo y el exponente ser� el 
					 n�mero de veces que se repite).
	              
	Entradas: N�mero entero positivo (entero).
	Salidas: Descomposici�n en factores primos del n�mero entero positivo
			 (resultado_forma1, resultado_forma2).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <string>		// Inclusi�n de los recursos del tipo de dato string

using namespace std;

// Programa principal

int main() {	
	
	// Declaraci�n de constantes
	
	const string SIMBOLO_MULTIPLICACION = " * ";
	const string SIMBOLO_POTENCIA = "^";

	// Declaraci�n de variables
	
	int entero;
	
	// Entradas de datos
	
	do {
		cout << " Introduzca un numero entero positivo: ";
		cin >> entero;
	}while(entero <= 0);
	
	/***********************************************************************/
	// Forma 1: Enumerando todos los primos de la descomposici�n
	//          (en el caso de que un primo intervenga m�s de una
	//           vez, se mostrar� tantas veces como sea preciso).
	/***********************************************************************/
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Mientras 'copia_entero_forma1' sea mayor que 1:
		
			Mientras 'primo_forma1' divida a 'copia_entero_forma1':
			
				Se a�ade 'primo_forma1' a la descomposici�n en factores
				primos del n�mero entero positivo introducido.
				
				Se divide 'copia_entero_forma1' por 'primo_forma1'.
				
			Se pasa al siguiente n�mero primo.
	*/
	
	int copia_entero_forma1 = entero;
	int primo_forma1 = 2;
	string resultado_forma1;
	
	while(copia_entero_forma1 > 1) {
		
		while(copia_entero_forma1 % primo_forma1 == 0) {
			
			resultado_forma1 += to_string(primo_forma1);	 
			copia_entero_forma1 /= primo_forma1;
			
			if(copia_entero_forma1 > 1)
				resultado_forma1 += SIMBOLO_MULTIPLICACION;
		}
		
		primo_forma1++;
	}
	
	// Salidas 
	
	if(resultado_forma1 != "") {
		cout << endl;
		cout << " Descomposicion en factores primos (Forma 1): ";
		cout << endl << endl;
		cout << "\t " << entero << " = " << resultado_forma1;
		cout << endl;
	}
	else {
		cout << endl;
		cout << " Descomposicion en factores primos (Forma 1): ";
		cout << endl << endl;
		cout << "\t El numero " << entero << " no se puede expresar como"
		     <<	" producto de factores primos";
		cout << endl;
	}
	
	/***********************************************************************/
	// Forma 2: Como producto de potencias (en el caso de que un primo 
	//		 	intervenga m�s de una vez se mostrar� una potencia
	//			cuya base sea el valor del primo y el exponente ser� el 
	//			n�mero de veces que se repite).
	/***********************************************************************/
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Mientras 'copia_entero_forma2' sea mayor que 1:
		
			Mientras 'primo_forma2' divida a 'copia_entero_forma2':
			
				Se incrementa en 1 el valor de la 'potencia' del primo
				correspondiente.
				
				Se divide 'copia_entero_forma2' por 'primo_forma2'.
				
			Si 'potencia' es mayor que 1, se a�ade 'primo_forma2' a la 
			descomposici�n en factores primos junto con su 'potencia'
			correspondiente.
			
			Si 'potencia' es igual a 1, se a�ade 'primo_forma2' a la 
			descomposici�n en factores primos junto sin la 'potencia'
			correspondiente (ya que esta es trivial).
				
			Se pasa al siguiente n�mero primo.
			
			'potencia' se iguala a 0.
	*/
	
	int copia_entero_forma2 = entero;
	int primo_forma2 = 2;
	int potencia = 0;
	string resultado_forma2;
	
	while(copia_entero_forma2 > 1) {
				
		while(copia_entero_forma2 % primo_forma2 == 0) {
			
			potencia++;	 
			copia_entero_forma2 /= primo_forma2;
		}
		
		if(potencia > 1) {
			
			resultado_forma2 += to_string(primo_forma2) + SIMBOLO_POTENCIA
			                    + to_string(potencia);
			                    
			if(copia_entero_forma2 > 1)
				resultado_forma2 += SIMBOLO_MULTIPLICACION;
		}
		
		if(potencia == 1) {
			
			resultado_forma2 += to_string(primo_forma2);
			
			if(copia_entero_forma2 > 1)
				resultado_forma2 += SIMBOLO_MULTIPLICACION;
		}

		primo_forma2++;
		potencia = 0;
	}
	
	// Salidas 
	
	if(resultado_forma1 != "") {
		cout << endl;
		cout << " Descomposicion en factores primos (Forma 2): ";
		cout << endl << endl;
		cout << "\t " << entero << " = " << resultado_forma2;
		cout << endl;
	}
	else {
		cout << endl;
		cout << " Descomposicion en factores primos (Forma 2): ";
		cout << endl << endl;
		cout << "\t El numero " << entero << " no se puede expresar como"
		     <<	" producto de factores primos";
		cout << endl;
	}
	
	return 0;
}
