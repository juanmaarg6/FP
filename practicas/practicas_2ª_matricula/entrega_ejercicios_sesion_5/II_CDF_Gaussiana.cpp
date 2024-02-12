/*
	Relación de ejercicios 2

	Ejercicio 51: Programa que, dada la media, la desviación típica y un punto
	              de abscisa 'x' de una función gaussiana, muestra el área que
	              cubre la función gaussiana en el intervalo [-infinito, x].
	              
	              Este área se calcula con la distribución acumulada en el
	              punto 'x', abreviado CDF(x).
	              
	Entradas: Media (media),
	          Desviación típica (desviacion)
	          Abscisa en la que se evaluará la función (abscisa).
	Salidas: Área que cubre la función gaussiana en el intervalo
	         [-infinito, x] (distribucion_acumulada).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de los recursos de E/S
#include <cmath>		    // Inclusión de los recursos matematicos

using namespace std;

// Programa principal

int main() {
	
	// Declaración de constantes
	
	const double PI = asin(0.5) * 6;
	
	const double SALTO = 0.001;
	
	// Declaración de variables
 		             
	double media = 0.0, desviacion = 0.0, extremo_superior_intervalo = 0.0; 	
	double gaussiana = 0.0;			     
	double distribucion_acumulada = 0.0;
	double fraccion = 0.0, exponencial = 0.0;
	
	// Entradas de datos
						
	cout << " Introduzca el valor de la media: ";
	cin >> media;
	
	do {
		cout << " Introduzca el valor de la desviacion tipica: ";	
		cin >> desviacion;
	}while(desviacion < 0);
	
	cout << " Introduzca el extremo superior del intervalo: ";
	cin >> extremo_superior_intervalo;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Calcular la parte racional de la función gaussiana dada por:
		
						       1
				   -------------------------
					              ---------
					Desviación * V  2 * PI
		
		Mientras 'incrementos' sea menor que 'extremo_superior_intervalo':
		
			Calcular la parte exponencial de la función gaussiana evaluada en
			'incrementos' dada por:
			
													
							   1      Incrementos - Media  2 
						  { - --- * (--------------------)	 }				
							   2	      Desviación		
						e
					
			Multiplicar la parte racional por la parte exponencial, 
			obteniendo así el valor que toma la función gaussiana en el 
			punto 'incrementos'.
			
			Sumar el valor de la función gaussiana evaluada en 'incrementos' 
			a 'distribucion_acumulada'.
			
			Sumar un salto establecido a 'incrementos'.
	*/
	
	
	double extremo_inferior_intervalo = media - (3 * desviacion);
	double incrementos = extremo_inferior_intervalo;
	
	fraccion = (1 / (desviacion * sqrt(2 * PI)));

	while(incrementos < extremo_superior_intervalo) {
		
		exponencial = exp(-0.5 * pow((incrementos - media) / desviacion, 2));
	
		gaussiana = fraccion * exponencial;
		
		distribucion_acumulada += gaussiana * SALTO;
		
		incrementos += SALTO;
	}
	
	// Salidas
	
	cout << endl << endl;
	cout << " El area que cubre la funcion gaussiana en el intervalo" 
	     << " [-infinito, " << extremo_superior_intervalo << "],"
	     << " es igual a " << distribucion_acumulada;
	cout << endl << endl;
	
	return 0;
}
