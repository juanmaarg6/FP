/*
	Ejercicio 49: Programa que muestra el mayor número perfecto
	              que es menor a un número dado por el usuario.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>														

using namespace std;

int main(){
	
	int numero_tope, posible_numero_perfecto, numero_perfecto, suma_divisores = 0;
	bool calculo_numero_perfecto = true, es_divisible, numero_tope_mayor_6;
	
	/*
		Algoritmo:
		
		Introducir "numero_tope".
		
		Calcular el valor de "posible_numero_perfecto".
		
		Mientras "calculo_numero_perfecto":
		
			Calcular los divisores de "posible_numero_perfecto" y sumarlos.
			El valor de dicha suma se almacena en "suma_divisores".
			
			Si "suma_divisores" es igual a "posible_numero_perfecto", entonces
			se encuentra el mayor "numero_perfecto" menor a "numero_tope". Se 
			detiene el bucle.
			
			Si no, "suma_divisores" pasa a ser 0, "posible_numero_perfecto" disminuye
			en 1 y el bucle continúa.
			
		Mostrar "numero_perfecto" en pantalla, en función de si "numero_tope" es 
		menor o mayor que 6.
	*/
		
	cout << " Introduzca un numero natural: ";
	cin >> numero_tope;
	
	posible_numero_perfecto = numero_tope - 1;
		
	while(calculo_numero_perfecto){
				
		for (int divisor = 1; divisor < posible_numero_perfecto; divisor++){
			
			es_divisible = (posible_numero_perfecto % divisor) == 0;

			if(es_divisible)
				suma_divisores += divisor;
		}
		
		if(suma_divisores == posible_numero_perfecto){
			numero_perfecto = posible_numero_perfecto;
			calculo_numero_perfecto = false;
		}
				
		else{
			suma_divisores = 0;
			posible_numero_perfecto--;
		}
	}
	
	numero_tope_mayor_6 = numero_tope > 6;

	if(numero_tope_mayor_6)
		cout << "\n El mayor numero perfecto que es menor a " << numero_tope << " es el " << numero_perfecto << endl << endl;
		
	else
		cout << "\n El numero perfecto mas pequeño es el 6. De forma que no hay numeros perfectos menores que " << numero_tope << endl << endl;

	system("pause");
}
