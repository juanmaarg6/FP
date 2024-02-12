/*
	Relaci�n de ejercicios 2

	Ejercicio 52: Programa que calcula una aproximaci�n del n�mero PI usando
	              el desarrollo de Taylor de la funci�n arcotangente evaluada
				  en ( 1 / raiz(3) ). Dicho desarrollo fue calculado por 
				  el matem�tico indio Madhava.
	              
	              
	Entradas: Tope de la sumatoria (tope),
	          Decimales de precisi�n (decimales_precision).
	Salidas: Aproximaci�n del n�mero PI (aprox_pi_madhava),
			 N�mero de iteraciones realizadas para calcular dicha
			 aproximaci�n (numero_iteraciones),
			 Umbral de semejanza (umbral_semejanza).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <iomanip>		// Inclusi�n de los recursos de modificaci�n de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos
#include <string>		// Inclusi�n de los recursos del tipo de dato string

using namespace std;

// Programa principal

int main() {
	
	cout.setf (ios::fixed);
	cout.setf (ios::showpoint);
	
	// Declaraci�n de constantes
	
	const string SEPARADOR = "---------------------------------------------";
	
	const int VALOR_MINIMO_TOPE = 1;
	const int VALOR_MAXIMO_TOPE = 100000;
	
	const double PI = 3.14159265358979323846;
	const double DIVIDIR_POR_10 = 0.1;
	const double INVERSO_RAIZ_DE_3 = 1.0 / sqrt(3);
	
	// Declaraci�n de variables
 		             
	int tope = 0;
	int decimales_precision = 0;
	double umbral_semejanza = 1.0;
	
	// Entradas de datos
	
	cout << endl;
	cout << SEPARADOR;
	cout << endl << endl;
	
	do {					
		cout << " Introduzca el valor del tope (1 <= tope <= 100000): ";
		cin >> tope;
	}while( (tope < VALOR_MINIMO_TOPE) || (tope > VALOR_MAXIMO_TOPE));
	
	cout << endl;
	
	do {
		cout << " Decimales de precision: ";
		cin >> decimales_precision;
	}while(decimales_precision <= 0);

	cout << endl << endl;
	cout << SEPARADOR;
	cout << endl << endl;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Calcular 'umbral_semejanza', es decir, la cota superior de la 
		diferencia de 'PI' y 'aprox_pi_madhava'.
		
		Mientras 'numero_iteraciones' sea menor que 'tope' y se supere
		'umbral_semejanza':
			
			Si se supera 'umbral_semejanza':
			
				Calcular la iteraci�n impar correspondiente del desarrollo
				de Taylor de la funci�n arcotangente evaluada en 
				( 1 / raiz(3) ).
				Sumar la iteraci�n calculada a la aproximaci�n del n�mero PI.
				Incrementar en 1 el n�mero de iteraciones.
				 
			Si se supera 'umbral_semejanza':
			
				Calcular la iteraci�n par correspondiente del desarrollo
				de Taylor de la funci�n arcotangente evaluada en 
				( 1 / raiz(3) ).
				Sumar la iteraci�n calculada a la aproximaci�n del n�mero PI.
				Incrementar en 1 el n�mero de iteraciones.
	*/
	
	for(int i = 0; i <= decimales_precision; i++)
		umbral_semejanza *= DIVIDIR_POR_10;
		
	double aprox_pi_madhava = 6.0 * INVERSO_RAIZ_DE_3;
	
	double multiplicacion_raiz_iteracion_impar = 1.0;
	double multiplicacion_raiz_iteracion_par = 1.0;
	
	int numero_iteraciones = 1;
	
	bool iteraciones_menor_que_tope = (numero_iteraciones <= tope);
	bool se_supera_umbral_semejanza = ( abs(PI - aprox_pi_madhava) 
	                                   >= umbral_semejanza );
	
	while(iteraciones_menor_que_tope && se_supera_umbral_semejanza) {
		
		se_supera_umbral_semejanza = ( abs(PI - aprox_pi_madhava) 
                               >= umbral_semejanza );
		
		if(se_supera_umbral_semejanza) {    
		                       
			for(int i = 0; i < ( (2 * numero_iteraciones) + 1 ); i++)
				multiplicacion_raiz_iteracion_impar *= INVERSO_RAIZ_DE_3;
			
			aprox_pi_madhava -= (6.0 * multiplicacion_raiz_iteracion_impar)
			                     / ( (2 * numero_iteraciones) + 1 );
			
			numero_iteraciones++;
		}
		
	
		se_supera_umbral_semejanza = ( abs(PI - aprox_pi_madhava) 
		                               >= umbral_semejanza );
		               
		if(se_supera_umbral_semejanza) {
			
			for(int i = 0; i < ( (2 * numero_iteraciones) + 1 ); i++)
				multiplicacion_raiz_iteracion_par *= INVERSO_RAIZ_DE_3;
							
			aprox_pi_madhava +=  ( 6.0 * multiplicacion_raiz_iteracion_par )
			                     / ( (2 * numero_iteraciones) + 1 );
			                     
			numero_iteraciones++;
		}
		
		multiplicacion_raiz_iteracion_impar = 1.0;
		multiplicacion_raiz_iteracion_par = 1.0;
    }
    	
	// Salidas
	
	cout << endl;
	cout << " Umbral de semejanza: " << setw(15) << setprecision(10) 
	     << umbral_semejanza;
	
	cout << endl << endl;
	cout << " Valor ""real"" de PI: " << setw(28) << setprecision(20) << PI;
	cout << endl;
	cout << " Valor aproximado de PI: " << setprecision(20) 
	     << aprox_pi_madhava;
	
	cout << endl << endl;
	cout << " Para realizar dicha aproximacion, se han realizado "
	     << numero_iteraciones << " iteraciones";
	cout << endl << endl;
	
	return 0;
}
