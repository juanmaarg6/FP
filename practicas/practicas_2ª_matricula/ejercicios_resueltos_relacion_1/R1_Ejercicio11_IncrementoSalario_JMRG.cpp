/*
	Relaci�n de ejercicios 1

	Ejercicio 11: Programa que, dado un salario base, lo incrementa un 2%
			      y se muestra el resultado en pantalla.
	                                           	      
	Entrada: Salario base (salario_base).
	Salidas: Salario final (salario_final).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main() {	
	
	// Declaraci�n de constantes
	
	const double INCREMENTO = 1.02;
	
	// Declaraci�n de variables
	     
	double salario_base = 0.0;
	double salario_final = 0.0;

	// Entradas de datos
	
	cout << " Introduzca el salario base: ";
	cin >> salario_base;
	
	// C�lculos
	
	salario_final = salario_base * INCREMENTO;
			
	// Salidas
	
	cout << endl;
	cout << " El salario final es de " << salario_final << " euros";
	cout << endl << endl;

	/*
		El enunciado de este ejercicio nos ofrec�a tres alternativas para
		implementar el programa:
		
		a) Calcular 1.02 * salario_base dentro de la sentencia cout.
		b) Introducir una variable salario_final, asignarle la expresi�n
		   anterior y mostrar su contenido en la sentencia cout.
		c) Modificar la variable original salario_base con el resultado de
		   incrementarla un 2%.
		
		He elegido la alternativa b) ya que tanto la a) como la c) son
		malas pr�cticas de programaci�n. La a) es una mala pr�ctica de 
		programaci�n porque en la sentencia cout se deber�a mostrar el
		contenido de variables, no de expresiones. La c) es una mala
		pr�ctica de programaci�n porque no se debe cambiar el valor
		original de una variable ya que dicho valor puede hacer falta 
		m�s adelante.
	*/
	
	system("pause");
	return 0;
}
