/*
	Relación de ejercicios 1

	Ejercicio 10: Programa que, dados un capital y un interés, calcula
	              el total de dinero que se tendrá al cabo de un año a 
	              plazo fijo tras aplicar la siguiente fórmula:
	               
					
				        							interes
				 		total = capital + capital * ------- 
	                                           	      100
	                                           	      
	Entrada: Cantidad de euros depositada (capital), 
	         Interés aplicado (interes).
	Salidas: Dinero total obtenido (total).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal

int main(){	
	
	// Declaración de variables
	     
	double capital = 0.0;
	double interes = 0.0;
	double total = 0.0;	   

	// Entradas de datos
	
	cout << " Introduzca la cantidad de euros que desea depositar: ";
	cin >> capital;
	cout << " Introduzca el interes aplicado: ";
	cin >> interes;
	
	// Cálculos
	
	total = capital + capital * (interes / 100);
			
	// Salidas
	
	cout << endl;
	cout << " Tras aplicar el interes, el capital final sera de " << total
	     << " euros" << endl << endl;

	/*
		Responda razonadamente a la siguiente pregunta: Supongamos que queremos 
		modificar la variable original capital con el nuevo valor de total. 
		¿Es posible hacerlo directamente en la expresión de arriba?
		
		RESPUESTA: No sería posible realizarlo directamente en la expresión de 
		arriba ya que primero se tendría que calcular el nuevo valor de total y, 
		una vez calculado, sí se podría modificar la variable original capital 
		con dicho nuevo valor de la variable total.
	*/
	
	system("pause");
	return 0;
}
