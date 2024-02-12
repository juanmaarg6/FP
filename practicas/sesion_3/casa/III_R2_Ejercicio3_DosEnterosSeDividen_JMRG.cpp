/*
	Ejercicio 3: Programa que muestra si dos enteros se dividen.
	
	NOTA: En este programa no hace falta decir quién divide
			a quién. 
			
			Supondremos que los valores leídos desde teclado son ambos distintos de cero.

	Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){	

	// Declaración de variables
	
   int entero1, entero2;              
                        
   bool se_dividen;														
	
	// Entrada de datos
							
   cout << "Introduzca el primer numero entero: ";      
   cin >> entero1;                           
   cout << "Introduzca el segundo numero entero: ";      
   cin >> entero2;   
	
	// Comprobación de si los dos enteros se dividen. Para ello, el resto de su división tiene que ser cero
	
   se_dividen = (entero1 % entero2 == 0 || entero2 % entero1 == 0);
	
	// Resultados mostrados en pantalla

   if (se_dividen == 1){
   	
      cout << "\nUno de los dos numeros enteros divide al otro" << "\n\n";
	}
	
   if (se_dividen == 0){
   	
      cout << "\nNinguno de los dos numeros enteros divide al otro" << "\n\n";
	}
	
	system("pause");
}
