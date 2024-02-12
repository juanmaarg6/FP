/*
	Ejercicio 5: Programa que recoge la ganancia total de una empresa
					 y muestra c�mo se reparte entre el dise�ador y los tres
					 fabricantes (el dise�ador cobra el doble que cada uno
					 de los fabricantes).
	
	Entrada: ganancia total de la empresa a repartir (ganancia_total)
	Salidas: ganancia del dise�ador (ganancia_disenador) y ganancia de 
				los fabricantes (ganancia_fabricante)

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		

using namespace std;

int main(){							      
	double ganancia_total;			// Datos de entrada
	double ganancia_disenador, ganancia_fabricante;		// Datos de salida
							
	cout << "Introduzca la ganancia total de la empresa: ";			//El usuario introduce el dato requerido
	cin >> ganancia_total;
	
/*
	Cada fabricante cobrara una cantidad de x euros. El dise�ador (al cobrar el doble) cobrara 2x euros. Como en este caso hay 3 fabricantes y
	1 dise�ador, entonces 3x + 2x = 100. Despejando tenemos que x = 20. Esto quiere decir que cada fabricante cobrara un 20% de
	las ganancias totales y el dise�ador cobrara un 40%.
	
*/
	
	ganancia_disenador = 0.4 * ganancia_total ;				// Se realizan los calculos.
	ganancia_fabricante = 0.2 * ganancia_total; 
	
	cout << "\nGanancia de cada fabricante (en total son 3 fabricantes): " << ganancia_fabricante;		//Se muestra al usuario las ganancias tanto de cada uno de los tres fabricantes
	cout << "\nGanancia del dise�ador: " << ganancia_disenador << "\n\n";			   						// como del dise�ador
	
	system("pause");
}
