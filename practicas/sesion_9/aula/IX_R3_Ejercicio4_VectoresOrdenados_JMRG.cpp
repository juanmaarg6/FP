/*
	Ejercicio 4: Programa que, dados dos vectores ya ordenados
	             ascendentemente, muestra un nuevo vector
	             ordenado cuyas componentes son todas las
	             componentes de los otros dos vectores.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){
   const int LONGITUD_MAXIMA = 1000;
   int vector1[LONGITUD_MAXIMA], vector2[LONGITUD_MAXIMA], vector_resultante[LONGITUD_MAXIMA];
    
   int longitud1, longitud2, longitud_resultante;
   
   int a = 0, b = 0;
   int valor_minimo = 0, posicion_valor_minimo = 0, intercambio;
   
   /*
   	Algoritmo:
   	
   	El usuario introduce las longitudes y los elementos
   	de los dos vectores (se supone que introduce los
   	elementos ya ordenados de forma ascendente).
   	
   	La longitud del vector resultante sera la suma
   	de las longitudes de los dos vectores ya introducidos.
   	
   	Los elementos del vector resultante son todas las
   	componentes de los dos vectores ya introducidos.
   	
   	Se ordenan las componentes del vector resultante.
   	
   	Se muestra en pantalla el vector resultante.
   */

	cout << " Introduzca la longitud del primer vector: ";
	cin >> longitud1;

	if(longitud1 > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}

	cout << "\n Introduzca los elementos del primer vector: ";
	for(int i = 0; i < longitud1; i++)
		cin >> vector1[i];
		
	cout << "\n Introduzca la longitud del segundo vector: ";
	cin >> longitud2;

	if(longitud2 > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}

	cout << "\n Introduzca los elementos del segundo vector: ";
	for(int i = 0; i < longitud2; i++)
		cin >> vector2[i];
				
	longitud_resultante = longitud1 + longitud2;
		
	while(a < longitud1){
		vector_resultante[a] = vector1[a];
		a++;
	}
	
	for(int c = a; c < longitud_resultante; c++){
		vector_resultante[c] = vector2[b];	
		b++;
	}
						
	for(int limite_partes = 0; limite_partes < longitud_resultante; limite_partes++){
		valor_minimo = vector_resultante[limite_partes];
		posicion_valor_minimo = limite_partes;
		
		for(int i = limite_partes; i < longitud_resultante; i++){
			if(vector_resultante[i] < valor_minimo){
				valor_minimo = vector_resultante[i];
				posicion_valor_minimo = i;
			}
		}
		
		intercambio = vector_resultante[limite_partes];
		vector_resultante[limite_partes] = valor_minimo;
		vector_resultante[posicion_valor_minimo] = intercambio;	
	}
			
	cout << "\n Vector resultante: ";
	for(int i = 0; i < longitud_resultante; i++)
		cout << vector_resultante[i] << " ";				
		
	cout << endl << endl;
	
	system("pause");
}
