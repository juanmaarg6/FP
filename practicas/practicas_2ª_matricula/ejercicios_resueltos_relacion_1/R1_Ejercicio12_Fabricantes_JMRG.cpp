/*
	Relación de ejercicios 1

	Ejercicio 12: Programa que, dadas las ganancias de una empresa, muestra
	              cuánto cobran el diseñador y los tres fabricantes de la 
	              misma, sabiendo que el diseñador cobra el doble que cada
	              uno de los fabricantes.
	                                           	      
	Entrada: Salario base (salario_base).
	Salidas: Salario final (salario_final).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal

int main() {	
	
	// Declaración de variables
	     
	double ganancia_total = 0.0;
	double salario_diseniador_double = 0.0;
	double salario_fabricante_double = 0.0;
	int salario_diseniador_int = 0;
	int salario_fabricante_int = 0;

	// Entradas de datos
	
	cout << " Introduzca la ganancia total de la empresa: ";
	cin >> ganancia_total;
	
	// Cálculos
	
	/*
	Cada fabricante cobrará una cantidad de x euros. El diseñador (al cobrar el 
	doble) cobrará 2x euros. Como en este caso hay 3 fabricantes y 1 diseñador, 
	entonces 3x + 2x = 100. Despejando tenemos que x = 20. Esto quiere decir 
	que cada fabricante cobrará un 20% de las ganancias totales y el diseñador 
	cobrara un 40%.
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
	cout << "\t Sueldo del diseñador: " << salario_diseniador_double 
	     << " euros" << endl << endl;
	     
	cout << " b) Usando variables int: " << endl << endl;
	cout << "\t Sueldo de cada fabricante: " << salario_fabricante_int
	     << " euros" << endl;
	cout << "\t Sueldo del diseñador: " << salario_diseniador_int
	     << " euros";
	cout << endl << endl;
	
	system("pause");
	return 0;
}
