/*
	Relaci�n de ejercicios 2

	Ejercicio 51: Programa que, dada la media, la desviaci�n t�pica y un punto
	              de abscisa 'x' de una funci�n gaussiana, muestra el �rea que
	              cubre la funci�n gaussiana en el intervalo [-infinito, x].
	              
	              Este �rea se calcula con la distribuci�n acumulada en el
	              punto 'x', abreviado CDF(x).
	              
	Entradas: Media (media),
	          Desviaci�n t�pica (desviacion)
	          Abscisa en la que se evaluar� la funci�n (abscisa).
	Salidas: �rea que cubre la funci�n gaussiana en el intervalo
	         [-infinito, x] (distribucion_acumulada).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de los recursos de E/S
#include <cmath>		    // Inclusi�n de los recursos matematicos

using namespace std;

// Programa principal

int main() {
	
	// Declaraci�n de constantes
	
	const double PI = asin(0.5) * 6;
	
	const double SALTO = 0.001;
	
	// Declaraci�n de variables
 		             
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
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Calcular la parte racional de la funci�n gaussiana dada por:
		
						       1
				   -------------------------
					              ---------
					Desviaci�n * V  2 * PI
		
		Mientras 'incrementos' sea menor que 'extremo_superior_intervalo':
		
			Calcular la parte exponencial de la funci�n gaussiana evaluada en
			'incrementos' dada por:
			
													
							   1      Incrementos - Media  2 
						  { - --- * (--------------------)	 }				
							   2	      Desviaci�n		
						e
					
			Multiplicar la parte racional por la parte exponencial, 
			obteniendo as� el valor que toma la funci�n gaussiana en el 
			punto 'incrementos'.
			
			Sumar el valor de la funci�n gaussiana evaluada en 'incrementos' 
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
