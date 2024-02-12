/*
	Relación de ejercicios 2

	Ejercicio 81: Programa que presenta un menú principal para que el usuario
				  pueda elegir entre las siguientes opciones:

				  A–>Calcular adición.
				  P–>Calcular producto.
				  X–>Salir.

				  Si el usuario elige en el menú principal:

				  	a) Salir, el programa terminará su ejecución.
				  	
					b) Calcular adición, se presenta un menú (secundario) 
					   para que el usuario pueda elegir entre las siguientes 
					   opciones:

					   S–>Calcular suma.
					   R–>Calcular resta.
					   X–>Salir.

					c) Calcular producto, se presenta un menú (secundario) para 
					   que el usuario pueda elegir entre las siguientes 
					   opciones:

					   M–>Calcular multiplicación.
					   D–>Calcular división.
					   X–>Salir.

				  En las operaciones seleccionadas desde los menús secundarios 
				  el programa pedirá dos números reales, realizará la operación 
				  seleccionada, mostrará el resultado y volverá a mostrar el 
				  menú secundario seleccionado anteriormente.

				  En los dos menús secundarios la selección de Salir hace que 
				  el programa vuelva a mostrar el menú principal.
	              
	Entradas: Opción del menú introducida por el usuario (opcion).
	Salidas: Opción elegida por el usuario (suma, resta, multiplicacion,
	         division).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {

	// Declaración de variables
	
	char opcion_menu_primario, opcion_menu_secundario;
	
	// Entradas de datos, Cálculos y Salidas
	
	/*
		Algoritmo:
		
		Mientras la opción elegida por el usuario sea distinta de 'X':
		
			Se muestra el menú de opciones primario.
			
			Si la opción elegida por el usuario es 'A':
				
				Mientras la opción elegida por el usuario sea distinta de 'X':
				
					Se muestra el menú secundario de adición.
				
					Si la opción elegida por el usuario es 'S':
						Se le piden dos números al usuario y se muestra la 
						suma de ambos.
					Si la opción elegida por el usuario es 'R':
						Se le piden dos números al usuario y se muestra la 
						resta de ambos.
					Si la opción elegida por el usuario es 'X':
						Se vuelve a mostrar el menú de opciones primario.
						
			Si la opción elegida por el usuario es 'P':
				
				Mientras la opción elegida por el usuario sea distinta de 'X':
				
					Se muestra el menú secundario de producto.
				
					Si la opción elegida por el usuario es 'M':
						Se le piden dos números al usuario y se muestra la 
						multiplicación de ambos.
					Si la opción elegida por el usuario es 'D':
						Se le piden dos números al usuario y se muestra la 
						división de ambos (el segundo número introducido, es
						decir, el divisor, tiene que ser distinto de 0).
					Si la opción elegida por el usuario es 'X':
						Se vuelve a mostrar el menú de opciones primario.
						
			Si la opción elegida por el usuario es 'X':
			
				Finaliza la ejecución del programa.
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
