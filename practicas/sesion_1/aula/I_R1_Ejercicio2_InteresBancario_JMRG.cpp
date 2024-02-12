/*
	Ejercicio 2: Programa para calcular el dinero total obtenido tras realizar una inversion 
					 bancaria durante un año a plazo fijo.
	
	Entradas: dinero invertido (capital) e interes aplicado (interes).
	Salida: dinero total (total).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			//Inclusion de libreria de recursos de E/S

using namespace std;

int main(){							   //Programa principal
	double capital; 				   //Declaracion de variables
	double interes;
	double total;				
						
	cout << "Introduzca el capital invertido (en euros): ";			//El usuario introduce los datos requeridos
	cin >> capital;
		
	cout << "Introduzca el interes aplicado: ";
	cin >> interes;
				
	total = capital + capital * interes/100;								//Se calcula el resultado
			
	cout << "\nAl cabo de un año, el total sera igual a " << total << " euros\n\n";  		//Se muestra el resultado al usuario
	
	system("pause");
}
