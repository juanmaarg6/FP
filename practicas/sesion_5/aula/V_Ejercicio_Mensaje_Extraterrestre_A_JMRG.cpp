/*
	Programa que lee un mensaje extraterrestre y decodifica el
	número secreto contenido en él.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>															

using namespace std;

int main(){	

	int numero = 0, contador_de_0 = 0, contador_de_1 = 0;										
	int resultado = 1;
	
	/*
		Algoritmo:
		
		Hacer...:
		
			Introducir un 0 o un 1. Se almacena en "numero".
			
			Si "numero == 1":
				Poner a 0 "contador_de_0".
				Aumentar "contador_de_1" en 1.
				
			Sino (en este caso, "numero = 0"):
				Aumentar "contador_de_0" en 1.
				
				Si "contador_de_1" es distinto de 0:
					resultado = resultado * contador_de_1
				
			Poner a 0 "contador_de_1".
			
		... mientras "contador_de_0" sea menor o igual que 4
		y "numero" sea igual a 0 o a 1.
		
		Mostrar "resultado" en pantalla.
	*/

	do{							
		cout << " Introduzca el mensaje extraterrestre: ";
		cin >> numero;	
		
		if(numero == 1){	
			contador_de_0 = 0;															
			contador_de_1++;
		}
		
		else{
			contador_de_0++;
			
			if(contador_de_1 != 0)													
				resultado *= contador_de_1;
			
			contador_de_1 = 0;
		} 
	}while((contador_de_0 <= 4) && (numero == 1 || numero == 0));
	
	cout << "\n El numero secreto del mensaje extraterrestre es: " << resultado << "\n";
}
