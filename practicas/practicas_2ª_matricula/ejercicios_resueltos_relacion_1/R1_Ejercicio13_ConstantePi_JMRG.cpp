/*
	Relaci�n de ejercicios 1

	Ejercicio 13: Programa para calcular la longitud de una circunferencia 
	             en cent�metros y el area de un c�rculo en cent�metros 
				 cuadrados.
	
	Entrada: Longitud del radio de la circunferencia (radio_circunferencia).
	Salidas: Longitud de la circunferencia (longitud_circunferencia), 
	         �rea del c�rculo (area_circulo).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main(){
	
	// Declaraci�n de constantes
	
	const double PI = 3.1415927;

	// Declaraci�n de variables	

	double radio_circunferencia = 0.0;
	double longitud_circunferencia = 0.0;
	double area_circulo = 0.0;			
						
	// Entradas de datos
	
	cout << " Introduzca la longitud del radio (en centimetros): ";	
	cin >> radio_circunferencia;
				
	// C�lculos 
	
	area_circulo = PI * radio_circunferencia  * radio_circunferencia;
	longitud_circunferencia  = 2 * PI  * radio_circunferencia;				 
			
	// Salidas
	
	cout << endl << " La longitud de la circunferencia es igual a " 
	     << longitud_circunferencia  << " centimetros";  
	cout << endl << " El area del circulo es igual a " << area_circulo 
	     << " centimetros cuadrados" << endl << endl;
		 
	/*
		Esta soluci�n es mejor que la del ejercicio 3 porque si quisi�ramos
		a�adir m�s decimales al valor de PI, solo tendr�amos que cambiar
		su valor en la constante que definimos. Si us�ramos literales,
		tendr�amos que cambiar el valor de PI cada vez que aparezca en 
		una expresi�n, siendo m�s d�ficil de modificar el programa.
	*/		
	
	system("pause");
	return 0;
}
