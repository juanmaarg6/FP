/*
	Ejercicio 17: Programa que lee un número e indica si
					  es narcisista o no.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <cmath>																														

using namespace std;

int main(){	

	int entero, digito, numero_digitos = 0, auxiliar1, auxiliar2, suma = 0;
	bool es_narcisista;
	
	/*
		Algoritmo:
		
		Introducir un número y almacenarlo en "entero".
		
		Calcular el número de dígitos de "entero".
		
		Realizar la suma de cada dígito de "entero" elevado al número de digitos totales.
		
		Comprobar si el número es narcisista.
		
		Mostrar en pantalla si el número es narcisista o no lo es.
	*/

	cout << " Introduzca un numero entero: ";
	cin >> entero;
	
	auxiliar1 = entero;
	auxiliar2 = entero;
			
	while(auxiliar1 != 0){
		
		auxiliar1 = auxiliar1 / 10;
		numero_digitos++;
	}
	
	for(int i = 0; i < numero_digitos; i++){
		
		digito = (auxiliar2 % 10) * 1.0;
		suma += pow(digito, numero_digitos);
		auxiliar2 = auxiliar2 / 10;
	}
	
	es_narcisista = (suma == entero);
	
	if(es_narcisista)
		cout << "\n El numero " << entero << " es narcisista" << endl << endl;	
	
	else
		cout << "\n El numero " << entero << " no es narcisista" << endl << endl;	
	
	system("pause");
}
