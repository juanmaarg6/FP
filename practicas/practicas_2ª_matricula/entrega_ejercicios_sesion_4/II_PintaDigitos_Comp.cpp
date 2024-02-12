/*
	Relaci�n de ejercicios 2

	Modificaci�n del Ejercicio 26
	de la Relaci�n de Ejercicios 1: Programa que, dado un n�mero entero de tres 
									d�gitos como un dato de tipo string, 
									devuelve los tres d�gitos de dicho n�mero 
									separados por tres espacios en blanco.
	              
	Entradas: N�mero de tres d�gitos (cad_3digitos).
	Salidas: Cifras del n�mero introducido separadas cada una de ellas
	         por tres espacios (centenas, decenas, unidades).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <string>		// Inclusi�n de los recursos del tipo de dato string
						
using namespace std;

// Programa principal

int main() {
	
	// Declaraci�n de constantes
	
	const string SEPARADOR = "..."; 

	// Declaraci�n de variables
	
	string cad_3digitos;
	
	// Entradas de datos
	
	cout << " Introduzca un entero de tres digitos: ";
	cin >> cad_3digitos; 

	// C�lculos
	
	/*
		Algoritmo:
		
		Si 'cad_3digitos' es un numero entero con 3 digitos:
		
			Transformar cad_3digitos (string) a numero_3dig (int).
			
			Obtener el valor de las centenas de numero_3dig y quedarse con las
			dos cifras menos significativas (numero_2dig).
			
			Obtener el valor de las decenas de numero_3dig y quedarse con la
			cifra menos significativa (unidades).
		
		Si no, mostrar mensaje de error.
	*/
	
	bool datos_correctos = (cad_3digitos.length() == 3);
	
	if(datos_correctos) {
		
		int numero_2dig = 0, numero_3dig = 0;
		int centenas = 0, decenas = 0, unidades = 0;
	
		numero_3dig = stoi(cad_3digitos);	
		
		centenas    = numero_3dig / 100;
		numero_2dig = numero_3dig % 100;
		
		decenas     = numero_2dig / 10; 
		unidades    = numero_2dig % 10;
	
		string cad_resultado = SEPARADOR + to_string(centenas) + 
							   SEPARADOR + to_string(decenas) + 
		                       SEPARADOR + to_string(unidades) + 
							   SEPARADOR; 
		
		// Salidas
		
		cout << endl << " " << cad_resultado << endl << endl;	
	}
	else {
		
		// Mensaje de error
		
		cout << endl << " Error: El valor de 'cad_3digitos' es incorrecto.";
		cout << endl << "        Se requiere: Numero de 3 digitos";
		cout << endl << endl;				
	}

	return 0;
}
