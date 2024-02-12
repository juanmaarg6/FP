/*
   Ejercicio 15: Programa que lee una letra mayúscula y muestra en 
					  pantalla su correspondiente minúscula.
                    
   Código fuente escrito por Juan Manuel Rodríguez Gómez
*/

#include <iostream>

using namespace std;

int main()														
{
	char mayuscula, minuscula;
	const int distancia_mayus_minus = 'a' - 'A';
	
	/*
   	1) Introducir una letra mayúscula desde teclado y almacenarla
		   en "mayuscula" mientras que el carácter introducido no sea
			una letra mayúscula.
   	2) minuscula = mayuscula + distancia_mayus_minus.
   	3) Mostrar "mayúscula" y "minúscula".
   */
		
	do{
		cout << " Inserte una letra mayuscula: ";
		cin >> mayuscula;
	}while((mayuscula < 'A') || (mayuscula > 'Z'));	
	
   minuscula = mayuscula + distancia_mayus_minus;   
	
	cout << "\n Letra mayuscula introducida: " << mayuscula;
	cout << "\n Letra minuscula correspondiente: " << minuscula;
	cout << "\n\n";
	
	system("pause");					
}
