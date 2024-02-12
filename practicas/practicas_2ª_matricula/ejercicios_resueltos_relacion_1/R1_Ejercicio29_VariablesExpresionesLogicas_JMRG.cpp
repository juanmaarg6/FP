/*
	Relación de ejercicios 1

	Ejercicio 29: Programa que, dadas las variables count = 0, limit = 10
	              x = 2 e y = 7, calcula el valor de varias expresiones lógicas.
				  	              
	Entradas: -
	Salidas: Valores de las expresiones lógicas (expresion_logica_1,
	         expresion_logica_2, expresion_logica_3, expresion_logica_4,
	         expresion_logica_5, expresion_logica_6, expresion_logica_7).
	            
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {				
		
	// Declaración de variables
	
	int count = 0;
	int limit = 10;
	int x = 2;
	int y = 7;
		
    /**********************************************************************/
	
	// Declaración de variables
	
	bool expresion_logica_1 = false;
							
	// Cálculos
	
	/*
		Algoritmo:
		
		Comprobar si el valor de la variable count es 0 y si el valor de la
		variable limit es menor que 20. En ese caso, expresion_logica_1 = 1
		(true), en otro caso, expresion_logica_1 = 0 (false).
	*/
	
	expresion_logica_1 = count == 0 && limit < 20;
	
	// Salidas
	
	cout << " 1) count == 0 && limit < 20: " << expresion_logica_1 << endl;
	
    /**********************************************************************/
    
    // Declaración de variables
	
	bool expresion_logica_2 = false;
							
	// Cálculos
	
	/*
		Algoritmo:
		
		Comprobar si el valor de la variable limit es mayor que 20 o si el 
		valor de la	variable count es menor que 5. En ese caso, 
		expresion_logica_2 = 1 (true), en otro caso, expresion_logica_2 = 0 
		(false).
	*/
	
	expresion_logica_2 = limit > 20 || count < 5;
	
	// Salidas
	
	cout << " 2) limit > 20 || count < 5: " << expresion_logica_2 << endl;
	
    /**********************************************************************/
    
    // Declaración de variables
	
	bool expresion_logica_3 = false;
							
	// Cálculos
	
	/*
		Algoritmo:
		
		Comprobar si el valor de la variable count no es igual a 12. En ese 
		caso, expresion_logica_3 = 1 (true), en otro caso, 
		expresion_logica_3 = 0 (false).
	*/
	
	expresion_logica_3 = !(count == 12);
	
	// Salidas
	
	cout << " 3) !(count == 12): " << expresion_logica_3 << endl;
	
    /**********************************************************************/
     
    // Declaración de variables
	
	bool expresion_logica_4 = false;
							
	// Cálculos
	
	/*
		Algoritmo:
		
		Comprobar si el valor de la variable count es igual a 1 y si el valor
		de la variable x es menor que el valor de la variable y. En ese 
		caso, expresion_logica_4 = 1 (true), en otro caso, 
		expresion_logica_4 = 0 (false).
	*/
	
	expresion_logica_4 = count == 1 && x < y;
	
	// Salidas
	
	cout << " 4) count == 1 && x < y: " << expresion_logica_4 << endl;
	
    /**********************************************************************/
    
    // Declaración de variables
	
	bool expresion_logica_5 = false;
							
	// Cálculos
	
	/*
		Algoritmo:
		
		Comprobar si no se da que, el valor de la variable count es menor que
		10 o si el valor de la variable x es menor que el valor de la variable 
		y, y, que el valor de la variable count sea mayor o igual que 0. En ese 
		caso, expresion_logica_5 = 1 (true), en otro caso, 
		expresion_logica_5 = 0 (false).
	*/
	
	expresion_logica_5 = !( (count < 10 || x < y) && count >= 0 );
	
	// Salidas
	
	cout << " 5) !( (count < 10 || x < y) && count >= 0 ): " 
	     << expresion_logica_5 << endl;
	
    /**********************************************************************/
    
    // Declaración de variables
	
	bool expresion_logica_6 = false;
							
	// Cálculos
	
	/*
		Algoritmo:
		
		Comprobar si el valor de la variable count es mayor que 5 y el valor
		de la variable y es igual a 7, o si el valor de la variable count es
		menor o igual que 0 y el valor de la variable limit es el valor de la
		variable x multiplicado por 5. En ese caso, expresion_logica_6 = 1 
		(true), en otro caso, expresion_logica_6 = 0 (false).
	*/
	
	expresion_logica_6 = (count > 5 && y == 7) || (count <= 0 && limit == 5*x);
	
	// Salidas
	
	cout << " 6) (count > 5 && y == 7) || (count <= 0 && limit == 5*x): " 
	     << expresion_logica_6 << endl;
	
    /**********************************************************************/
    
    // Declaración de variables
	
	bool expresion_logica_7 = false;
							
	// Cálculos
	
	/*
		Algoritmo:
		
		Comprobar si no se da que el valor de la variable limit sea diferente
		de 10 y que el valor de la variable x sea mayor que el valor de la
		variable y. En ese caso, expresion_logica_7 = 1 (true), en otro caso, 
		expresion_logica_7 = 0 (false).
	*/
	
	expresion_logica_7 = !( limit != 10 && x > y );
	
	// Salidas
	
	cout << " 7) !( limit != 10 && x > y ): " << expresion_logica_7
	     << endl << endl;
	
    /**********************************************************************/
		
	return 0;
}
