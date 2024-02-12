/*
	Relaci�n de ejercicios 1

	Ejercicio 12: Programa que, dadas las ganancias de una empresa, muestra
	              cu�nto cobran el dise�ador y los tres fabricantes de la 
	              misma, sabiendo que el dise�ador cobra el doble que cada
	              uno de los fabricantes.
	                                           	      
	Entradas: Salario base (salario_base).
	Salidas: Salario final (salario_final).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main() {	
	
	// Declaraci�n de variables
	     
	double ganancia_total;
	double salario_diseniador_double, salario_fabricante_double;
	int salario_diseniador_int, salario_fabricante_int;

	// Entradas de datos
	
	cout << " Introduzca la ganancia total de la empresa: ";
	cin >> ganancia_total;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Cada fabricante cobrar� una cantidad de x euros. El dise�ador (al 
		cobrar el doble) cobrar� 2x euros. Como en este caso hay 3 fabricantes 
		y 1 dise�ador, entonces 3x + 2x = 100. Despejando tenemos que x = 20. 
		Esto quiere decir que cada fabricante cobrar� un 20% de las ganancias 
		totales y el dise�ador cobrar� un 40%.
		
		Multiplicar la ganancia total por 0.2, obteniendo as� el salario
		de cada fabricante.
		
	    Multiplicar la ganancia total por 0.4, obteniendo as� el salario
		del dise�ador.
	*/
	
	salario_fabricante_double = 0.2 * ganancia_total;
	salario_diseniador_double = 0.4 * ganancia_total;
	
	salario_fabricante_int = salario_fabricante_double;
	salario_diseniador_int = salario_diseniador_double;
	
	// Salidas
	
	cout << endl;
	cout << " a) Usando variables double: " << endl << endl;
	cout << "\t Sueldo de cada fabricante: " << salario_fabricante_double 
	     << " euros" << endl;
	cout << "\t Sueldo del dise�ador: " << salario_diseniador_double 
	     << " euros" << endl << endl;
	     
	cout << " b) Usando variables int: " << endl << endl;
	cout << "\t Sueldo de cada fabricante: " << salario_fabricante_int
	     << " euros" << endl;
	cout << "\t Sueldo del dise�ador: " << salario_diseniador_int
	     << " euros";
	cout << endl << endl;
	
	system("pause");
	return 0;
}
