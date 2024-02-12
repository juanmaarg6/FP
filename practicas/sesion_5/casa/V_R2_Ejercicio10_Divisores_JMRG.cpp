/*
   Ejercicio 10: Programa que lee desde teclado un numero entero e imprime en pantalla todos sus
					  divisores propios. 
                    
   Código fuente escrito por Juan Manuel Rodríguez Gómez
*/

#include <iostream>

using namespace std;

int main(){	
	
   int tope, contador = 1;
	bool es_divisor;     
	
	/*
   	1) Introducir un número entero desde teclado y almacenarlo en "tope" mientras tope <= 0.
   	2) Mientras contador <= tope:
   		2.1) Si el resto de la división tope/contador es igual a 0, entonces ese valor de "contador"
   			  es divisor de "tope".
   		2.2) Mostrar "contador" (es decir, el divisor de "tope").
   		2.3) Aumentar "contador" en 1 . 	
   */         													
			
	do{					
	   cout << " Introduzca un numero entero: ";      
	   cin >> tope;
	}while(tope <= 0);
	
	cout << "\n Los divisores de " << tope << " son los siguientes: ";
	
	while(contador <= tope){
		es_divisor = (tope % contador) == 0;
		
		if(es_divisor){
			cout << contador << " ";
		}
		
		contador++;
	}
	
	cout << "\n\n";
	
	system("pause");
}
