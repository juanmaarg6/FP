/*
	Relación de ejercicios 2

	Ejercicio 20: Programa que, dados los valores de la edad y el salario
				  de una persona, se le subira el salario según las siguientes
				  condiciones:
				  
				  1) Si es mayor de 65 años o menor de 35 años, se le sube
				     el salario un 4 %.
				  2) Si además de cumplir la condición 1), también tiene un
				     salario inferior a a 300 euros, se le subirá otro 3 % 
				     y si su salario es mayor o igual que 300 euros pero
				     inferior a 900 euros, se le subirá un 1'5 %.
				  
	
	Entradas: Edad de la persona (edad),
			  Salario de la persona (salario).
	Salidas: Subida de salario (subida_salario).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaración de constantes
	
	const double SUBIDA_4_PORCIENTO = 1.04;
	const double SUBIDA_3_PORCIENTO = 1.03;
	const double SUBIDA_1_5_PORCIENTO = 1.015;
	
	
	// Declaración de variables
	
	int edad = 0;
	double salario = 0.0;
					
	// Entradas de datos
	
	cout << " Introduzca la edad del empleado (en anios): ";
	cin >> edad;
	cout << " Introduzca el salario del empleado (en euros): ";
	cin >> salario;
		
	// Cálculos
	
	/*
		Algoritmo:
		
		Si los datos introducidos son correctos:
		
			Si la edad del empleado es menor que 35 y mayor que 65:
				Se aplica una subida salarial del 4 %.
			Si no:
				No se aplica ninguna subida.
				
			Si la edad del empleado es menor que 35 y mayor que 65 y el
			salario es menor que 300 euros:
				Primero se aplica una subida salario del 4 % y, al resultado,
				se le aplica otra subida del 3 %.
				
			Si la edad del empleado es menor que 35 y mayor que 65 y el
			salario es mayor o igual que 300 euros y menor que 900 euros:
				Primero se aplica una subida salario del 4 % y, al resultado,
				se le aplica otra subida del 1.5 %.
				
		Si no, mostrar mensaje de error.
	*/
	
	bool datos_correctos = ( (edad > 0) && (salario >= 0.0) );
	
	if(datos_correctos) {
		
		enum class Empleado {EdadEntre35y65, EdadMenor35Mayor65, 
							 SalarioMenor300, SalarioEntre300y900};
		
		Empleado empleado;
		
		bool edad_menor_35_mayor_65 = ( (edad < 35) || (edad > 65) );
		bool salario_menor_300 = (salario < 300);
		bool salario_entre_300_y_900 = ( (salario >= 300) && (salario < 900) );
				
		double subida_salario = salario;
		
		if(edad_menor_35_mayor_65) {
			
			empleado = Empleado::EdadMenor35Mayor65;
			subida_salario *= SUBIDA_4_PORCIENTO;
		}
		else {
			
			empleado = Empleado::EdadEntre35y65;
		}
		
		if(edad_menor_35_mayor_65 && salario_menor_300) {
			
			empleado = Empleado::SalarioMenor300;
			subida_salario *= SUBIDA_3_PORCIENTO;
		}
				
		if(edad_menor_35_mayor_65 &&  salario_entre_300_y_900) {
				
			empleado = Empleado::SalarioEntre300y900;
			subida_salario *= SUBIDA_1_5_PORCIENTO;
		}
		
		// Salidas
		
		cout << endl;
		
		switch(empleado) {
			
			case(Empleado::EdadEntre35y65) :
				cout << " No se ha aplicado ninguna subida salarial";
				cout << endl << " Salario final: " << subida_salario 
				     << " euros";
				break;

			case(Empleado::EdadMenor35Mayor65) :
				cout << " Se ha aplicado una subida salarial del 4 %";
				cout << endl << " Salario final: " << subida_salario 
				     << " euros";
				break;
				
			case(Empleado::SalarioMenor300) :
				cout << " Primero se ha aplicado una subida salarial del 4 %"
				     << " y, al resultado, se le ha aplicado otra subida"
					 << " del 3 %";
				cout << endl << " Salario final: " << subida_salario 
				     << " euros";		
				break;
				
			case(Empleado::SalarioEntre300y900) :
				cout << " Primero se ha aplicado una subida salarial del 4 %"
				     << " y, al resultado, se le ha aplicado otra subida"
					 << " del 1.5 %";
				cout << endl << " Salario final: " << subida_salario 
				     << " euros";		
				break;
		}
	} 
	else {
		
		// Mensaje de error
		
		cout << endl << " Error: La entrada de datos es incorrecta.";
		cout << endl << "        Se requiere: 'edad' > 0";
		cout << endl << "                     'salario' >= 0";
	}
	
	cout << endl << endl;				

	return 0;
}
