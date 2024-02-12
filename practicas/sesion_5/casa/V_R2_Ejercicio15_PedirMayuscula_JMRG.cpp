/*
   Ejercicio 15: Programa que lee una letra may�scula y muestra en 
					  pantalla su correspondiente min�scula.
                    
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez
*/

#include <iostream>

using namespace std;

int main()														
{
	char mayuscula, minuscula;
	const int distancia_mayus_minus = 'a' - 'A';
	
	/*
   	1) Introducir una letra may�scula desde teclado y almacenarla
		   en "mayuscula" mientras que el car�cter introducido no sea
			una letra may�scula.
   	2) minuscula = mayuscula + distancia_mayus_minus.
   	3) Mostrar "may�scula" y "min�scula".
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
