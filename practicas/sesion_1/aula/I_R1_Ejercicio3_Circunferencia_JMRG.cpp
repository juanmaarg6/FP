/*
	Ejercicio 3: Programa para calcular la longitud de una circunferencia en centimetros
					 y el area de un circulo en centimetros cuadrados.
	
	Entrada: longitud del radio (radio).
	Salidas: longitud de la circunferencia (longitud) y area del circulo (area).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			//Inclusión de librería de recursos de E/S

using namespace std;

int main(){							   //Programa principal
	double radio; 				      //Declaracion de variables
	double longitud;
	double area;
	
	const double PI = 3.1415927;
				
						
	cout << "Introduzca la longitud del radio (en centimetros): ";			//El usuario introduce los datos requeridos
	cin >> radio;
				
	area = PI * radio * radio;		 //Se calculan los resultados
	longitud = 2 * PI  * radio;							
			
	cout << "\nLa longitud de la circunferencia es igual a " << longitud << " centimetros";  		//Se muestran los resultados al usuario
	cout << "\n\nEl area del circulo es igual a " << area << " centimetros cuadrados\n\n";
	
	system("pause");
}
