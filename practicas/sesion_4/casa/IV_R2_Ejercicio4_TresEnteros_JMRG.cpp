/*
   Ejercicio 4: Programa que lee tres n�meros enteros y dice
   				 si est�n ordenados (ya sea de forma ascendente
					 o descendente) o no. 
                 
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez.
*/

#include<iostream>

using namespace std;

int main(){
   
   // Declaraci�n de variables
   
	int entero1, entero2, entero3;
	bool ordenados_ascendente;
	bool ordenados_descendente;
	bool no_ordenados;
	
	// Entrada de datos
	
	cout << "Introduzca el primer numero entero: ";
	cin >> entero1;
	cout << "Introduzca el segundo numero entero: ";
	cin >> entero2;
	cout << "Introduzca el tercer numero entero: ";
	cin >> entero3;
	
	// Variables booleanas para comprobar si los n�meros estan ordenados (ya sea en orden ascendente o descendente) o no
	
	ordenados_ascendente = (entero1 < entero2) && (entero2 < entero3);
	ordenados_descendente = (entero1 > entero2) && (entero2 > entero3);
	no_ordenados = !(ordenados_ascendente) && !(ordenados_descendente);
	
	// Condicionales y salida de datos
	
	if(ordenados_ascendente){
		cout << endl << "Los numeros introducidos estan ordenados de forma ascendente" << endl << endl;
	}
	
	if(ordenados_descendente){
		cout << endl << "Los numeros introducidos estan ordenados de forma descendente" << endl << endl;
	}
	
	if(no_ordenados){
		cout << endl << "Los numeros introducidos no estan ordenados" << endl << endl;
	}
	
	system("pause");
}
