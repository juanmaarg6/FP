/*
	Relaci�n de ejercicios 2

	Ejercicio 81: Programa que presenta un men� principal para que el usuario
				  pueda elegir entre las siguientes opciones:

				  A�>Calcular adici�n.
				  P�>Calcular producto.
				  X�>Salir.

				  Si el usuario elige en el men� principal:

				  	a) Salir, el programa terminar� su ejecuci�n.
				  	
					b) Calcular adici�n, se presenta un men� (secundario) 
					   para que el usuario pueda elegir entre las siguientes 
					   opciones:

					   S�>Calcular suma.
					   R�>Calcular resta.
					   X�>Salir.

					c) Calcular producto, se presenta un men� (secundario) para 
					   que el usuario pueda elegir entre las siguientes 
					   opciones:

					   M�>Calcular multiplicaci�n.
					   D�>Calcular divisi�n.
					   X�>Salir.

				  En las operaciones seleccionadas desde los men�s secundarios 
				  el programa pedir� dos n�meros reales, realizar� la operaci�n 
				  seleccionada, mostrar� el resultado y volver� a mostrar el 
				  men� secundario seleccionado anteriormente.

				  En los dos men�s secundarios la selecci�n de Salir hace que 
				  el programa vuelva a mostrar el men� principal.
	              
	Entradas: Opci�n del men� introducida por el usuario (opcion).
	Salidas: Opci�n elegida por el usuario (suma, resta, multiplicacion,
	         division).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal

int main() {

	// Declaraci�n de variables
	
	char opcion_menu_primario, opcion_menu_secundario;
	
	// Entradas de datos, C�lculos y Salidas
	
	/*
		Algoritmo:
		
		Mientras la opci�n elegida por el usuario sea distinta de 'X':
		
			Se muestra el men� de opciones primario.
			
			Si la opci�n elegida por el usuario es 'A':
				
				Mientras la opci�n elegida por el usuario sea distinta de 'X':
				
					Se muestra el men� secundario de adici�n.
				
					Si la opci�n elegida por el usuario es 'S':
						Se le piden dos n�meros al usuario y se muestra la 
						suma de ambos.
					Si la opci�n elegida por el usuario es 'R':
						Se le piden dos n�meros al usuario y se muestra la 
						resta de ambos.
					Si la opci�n elegida por el usuario es 'X':
						Se vuelve a mostrar el men� de opciones primario.
						
			Si la opci�n elegida por el usuario es 'P':
				
				Mientras la opci�n elegida por el usuario sea distinta de 'X':
				
					Se muestra el men� secundario de producto.
				
					Si la opci�n elegida por el usuario es 'M':
						Se le piden dos n�meros al usuario y se muestra la 
						multiplicaci�n de ambos.
					Si la opci�n elegida por el usuario es 'D':
						Se le piden dos n�meros al usuario y se muestra la 
						divisi�n de ambos (el segundo n�mero introducido, es
						decir, el divisor, tiene que ser distinto de 0).
					Si la opci�n elegida por el usuario es 'X':
						Se vuelve a mostrar el men� de opciones primario.
						
			Si la opci�n elegida por el usuario es 'X':
			
				Finaliza la ejecuci�n del programa.
	*/
	
	double numero1, numero2;
	
	do {
		
		cout << endl;
		cout << " Menu de opciones primario: ";
		cout << endl;
   		cout << "\t A -> Calcular adicion";
  		cout << endl;
   		cout << "\t P -> Calcular producto";
   		cout << endl;
   		cout << "\t X -> Salir";
   		cout << endl << endl;
   		
   		do {
	   		cout << "\t Elija una opcion: ";
			cin >> opcion_menu_primario;
		}while(opcion_menu_primario != 'a' && 
		       opcion_menu_primario != 'A' && 
			   opcion_menu_primario != 'p' && 
		       opcion_menu_primario != 'P' && 
			   opcion_menu_primario != 'x' &&  
		       opcion_menu_primario != 'X');
   		
   		opcion_menu_primario = toupper(opcion_menu_primario);
   		
   		if(opcion_menu_primario == 'A') {
			
			do {   	
				
				cout << endl;		
				cout << "\t Menu de opciones secundario: ";
				cout << endl;
		   		cout << "\t\t S -> Calcular suma";
		  		cout << endl;
		   		cout << "\t\t R -> Calcular resta";
		   		cout << endl;
		   		cout << "\t\t X -> Salir";
		   		cout << endl << endl;
		   		
		   		do {
			   		cout << "\t Elija una opcion: ";
					cin >> opcion_menu_secundario;
				}while(opcion_menu_secundario != 's' && 
				       opcion_menu_secundario != 'S' &&
					   opcion_menu_secundario != 'r' && 
				       opcion_menu_secundario != 'R' &&
					   opcion_menu_secundario != 'x' && 
				       opcion_menu_secundario != 'X');
	
				opcion_menu_secundario = toupper(opcion_menu_secundario);
	
		   		if(opcion_menu_secundario == 'S') {
		   			
	   				cout << endl;
	   				cout << "\t Introduzca un numero real: ";
	   				cin >> numero1;
	   				cout << "\t Introduzca otro numero real: ";
	   				cin >> numero2;
	   				
	   				double suma = numero1 + numero2;
	   				
	   				cout << endl;
	   				cout << "\t\t" << numero1 << " + " << numero2
	   				     << " = " << suma;
	   				cout << endl;
	   			}
		   		
				if(opcion_menu_secundario == 'R') {
	   				cout << endl;
	   				cout << "\t Introduzca un numero real: ";
	   				cin >> numero1;
	   				cout << "\t Introduzca otro numero real: ";
	   				cin >> numero2;
	   				
	   				double resta = numero1 - numero2;
	   				
	   				cout << endl;
	   				cout << "\t\t" << numero1 << " - " << numero2
	   				     << " = " << resta;
	   				cout << endl;
		   		}	   		
		   	}while(opcion_menu_secundario != 'X');
		}
		   		
   		if(opcion_menu_primario == 'P') {
   				
			do {   	
				
				cout << endl;	
				cout << "\t Menu de opciones secundario: ";
				cout << endl;
		   		cout << "\t\t M -> Calcular multiplicacion";
		  		cout << endl;
		   		cout << "\t\t D -> Calcular division";
		   		cout << endl;
		   		cout << "\t\t X -> Salir";
		   		cout << endl << endl;
		   		
		   		do {
			   		cout << "\t Elija una opcion: ";
					cin >> opcion_menu_secundario;
				}while(opcion_menu_secundario != 'm' && 
				       opcion_menu_secundario != 'M' &&
					   opcion_menu_secundario != 'd' && 
				       opcion_menu_secundario != 'D' &&
					   opcion_menu_secundario != 'x' && 
				       opcion_menu_secundario != 'X');
	
				opcion_menu_secundario = toupper(opcion_menu_secundario);
	
		   		if(opcion_menu_secundario == 'M') {
		   			
	   				cout << endl;
	   				cout << "\t Introduzca un numero real: ";
	   				cin >> numero1;
	   				cout << "\t Introduzca otro numero real: ";
	   				cin >> numero2;
	   				
	   				double multiplicacion = numero1 * numero2;
	   				
	   				cout << endl;
	   				cout << "\t\t" << numero1 << " * " << numero2
	   				     << " = " << multiplicacion;
	   				cout << endl;
		   		}
		   				     
		   		if(opcion_menu_secundario == 'D') {
		   			
	   				cout << endl;
	   				cout << "\t Introduzca un numero real: ";
	   				cin >> numero1;
	   				
	   				do {
		   				cout << "\t Introduzca otro numero real"
						     << " (distinto de 0): ";
		   				cin >> numero2;
		   			}while(numero2 == 0);
	   				
	   				double division = numero1 / numero2;
	   				
	   				cout << endl;
	   				cout << "\t\t" << numero1 << " / " << numero2
	   				     << " = " << division;
	   				cout << endl;
		   		}		   		
		   	}while(opcion_menu_secundario != 'X');
		}
   	}while(opcion_menu_primario != 'X');
	
	return 0;
}
