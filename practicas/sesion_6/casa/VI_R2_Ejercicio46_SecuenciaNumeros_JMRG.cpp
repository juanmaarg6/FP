/*
	Ejercicio 46: Programa que lee una secuencia de n�meros enteros
		           en el rango de 0 a 100 y encuentra la subsecuencia
		           de n�meros ordenada, de menor a mayor, de mayor longitud.
	
	C�digo fuente realizado por Juan Manuel Rodr�guez G�mez.
*/

#include <iostream>

using namespace std;

int main(){	
	
	int numero, numero_anterior;
	int posicion = 0, posicion_menor_numero = 0;

	int longitud = 1, longitud_mayor_subsecuencia = 0, contador_posicion = 1;
	bool finalizar;
	
	/*
		Algoritmo:
		
		Introducir un n�mero y almacenarlo en "numero".
		
		Mientras no "finalizar" (es decir, mientras "numero" est� 
		en el rango 0-100):
		
			Si el n�mero introducido es mayor que el anterior, la 
			longitud aumenta en 1.
			
			Si no, la posici�n del n�mero se iguala al contador de posici�n y se
			resetea la longitud.
			
			Si la posici�n del n�mero es mayor o igual a la posici�n del menor n�mero
			y la longitud de esa subsecuencia es mayor que la longitud de la mayor subsecuencia,
			entonces se igualan valores.
			
			Aumentar "contador_posicion" en 1.
			
			Igualar el valor de "numero_anterior" al de "numero".
			
			Introducir un n�mero y almacenarlo en "n�mero".
			
			Comprobar si se da "finalizar".
			
		Mostrar en pantalla la posici�n del menor n�mero de la subsecuencia
		y la longitud de dicha subsecuencia (la cual es la mayor).	
	*/
	
	cout << " Introduzca una secuencia de numeros del 0 al 100 (-1 o 101 para finalizar): ";			
	cin >> numero;
	
	finalizar = (numero < 0) || (numero > 100);										
	
	while(!finalizar){	
	
		if(numero >= numero_anterior)
			longitud++;																											
		
		else{
			posicion = contador_posicion;											
			longitud = 1;													
		}
		
		if((posicion >= posicion_menor_numero) && (longitud > longitud_mayor_subsecuencia)){																
			posicion_menor_numero = posicion;
			longitud_mayor_subsecuencia = longitud;
		}
		
		contador_posicion++;
		numero_anterior = numero;
		
		cout << " Introduzca una secuencia de numeros del 0 al 100 (-1 o 101 para finalizar): ";			
		cin >> numero;
		
		finalizar = (numero < 0) || (numero > 100);	
	}
		
	cout << "\n Posicion: " << posicion_menor_numero;
	cout << "\n Longitud: " << longitud_mayor_subsecuencia << endl << endl;
	
	system("pause");
}
