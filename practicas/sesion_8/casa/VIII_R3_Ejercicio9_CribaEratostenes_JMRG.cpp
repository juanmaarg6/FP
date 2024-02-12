/*
	Ejercicio 9: Programa que muestra todos los numeros primos
					 menores que un determinado numero n mediante
					 la Criba de Eratostenes.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;


int main(){
	
	const int LONGITUD_MAXIMA = 1000;
	bool primo[LONGITUD_MAXIMA] = {0};
	
	int numero = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce un numero.
		
		Se consideran primos todos los numeros desde 0 hasta "numero".
		
		Se descartan todos los multiplos de 2. Se toma el siguiente numero
		que se encuentre sin descartar despues de 2 y se descartan todos
		sus multiplos. Este paso se repite hasta llegar a "numero".
		Los numeros que no hayan sido descartados son primos.
		
		Mostrar en pantalla los numeros primos menores que "numero".
	*/
	
	cout << " Introduzca un numero: ";
	cin >> numero;
	
	if(numero > 1000){
		cout << "\n Error. El maximo numero permitido es 1000." << endl << endl;
		exit(-1);
	}
	
	for(int i = 0; i < numero; i++)
		primo[i] = true;
	
	for(int x = 2; x < numero; x++){
		for(int y = 2; x*y < numero; y++)
			primo[x*y] = false;
	}
	 
	cout << "\n Numeros primos: ";
	for(int k = 2; k < numero; k++){
		if(primo[k])
			cout << k << " ";
	}
	
	cout << endl << endl;
	
	system("pause");	
}
