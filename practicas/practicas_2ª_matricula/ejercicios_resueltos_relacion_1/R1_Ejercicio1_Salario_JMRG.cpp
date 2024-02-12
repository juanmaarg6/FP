/*
	Relaci�n de ejercicios 1
	
	Ejercicio 1: Dado un programa que trata sobre el salario, 
				 describir las operaciones que se realizan.
	
	Entrada: -
	Salidas: Salario final (salario_final).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal
	    
int main(){						
	
	// Declaraci�n de variables
			
	int salario_base = 0;			
	int salario_final = 0;
	int incremento = 0;

	// C�lculos 
	
	salario_base = 1000;			  // salario_base = 1000
	salario_final = salario_base;	  // salario_final = salario_base = 1000 
	incremento = 200;				  // incremento = 200

	salario_final = salario_final + incremento;	   // salario_final = 1200
	salario_base = 3500;						  // salario_base = 3500

	// Salidas
	
	cout << endl;
	cout << " Salario base: " << salario_base << endl;	// "Salario base: 3500"
	cout << " Salario final: " << salario_final;       // "Salario final: 1200"
	cout << endl << endl;
	
	/*
		Responda razonadamente a la siguiente pregunta: �El hecho de realizar 
		la asignaci�n salario_final = salario_base; hace que ambas variables 
		est�n ligadas durante todo el programa y que cualquier modificaci�n 
		posterior de salario_base afecte a salario_final?
		
		RESPUESTA: El hecho de realizar la asignaci�n 
		salario_final = salario_base; NO hace que ambas variables est�n ligadas 
		durante todo el programa. Se puede observar en el c�digo del programa 
		que se realiza la asignaci�n salario_base = 3500; y esto no hace que 
		salario_final cambie su valor tambi�n a 3500, sino que mantiene su 
		valor que tiene (siendo en este caso 1200). Esto se puede comprobar al 
		ejecutar este programa.
	*/
	
	system("pause");
	return 0;
}
