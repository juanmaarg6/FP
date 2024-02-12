/*
	Ejercicio 31: Programa que muestra si un numero natural 'n'
	              introducido desde teclado es un numero feliz
	              de grado 'k' o no.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){
	
	int numero, iteraciones, auxiliar, digito,  contador = 0, suma = 0;
	bool es_numero_feliz = false;
	
	/*
		Algoritmo:
		
		Para el numero de iteraciones introducidas:
		
			Calcular la suma de cada digito elevado al cuadradado del numero introducido.
						
			Repetir el proceso para el resultado de la suma anterior.
			
			Comprobar si el numero es feliz.
		
		Si el numero es feliz, mostrar en pantalla que lo es con su respectivo grado.
		Si no, mostrar en pantalla que no lo es.
	*/
	
	cout << " Introduzca un numero natural: ";
	cin >> numero;
	
	cout << " Introduzca un numero de iteraciones: ";
	cin >> iteraciones;
	
	auxiliar = numero;
	suma = numero;
	
	while((es_numero_feliz == false) && (contador < iteraciones)){
		auxiliar = suma;
		suma = 0;
		
		while(auxiliar != 0){
			digito = auxiliar % 10;
			suma += digito * digito;
			auxiliar /= 10;
		}
		
		contador++;
		
		es_numero_feliz = (suma == 1);

	}
	

	if(es_numero_feliz)
		cout << "\n El numero " << numero << " es un numero feliz de grado " << contador << endl << endl;
	else
		cout << "\n El numero " << numero << " no es un numero feliz de grado " << contador << endl << endl;
		
	system("pause");
}
