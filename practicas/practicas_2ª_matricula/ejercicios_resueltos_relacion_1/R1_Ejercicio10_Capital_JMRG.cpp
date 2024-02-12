/*
	Relaci�n de ejercicios 1

	Ejercicio 10: Programa que, dados un capital y un inter�s, calcula
	              el total de dinero que se tendr� al cabo de un a�o a 
	              plazo fijo tras aplicar la siguiente f�rmula:
	               
					
				        							interes
				 		total = capital + capital * ------- 
	                                           	      100
	                                           	      
	Entrada: Cantidad de euros depositada (capital), 
	         Inter�s aplicado (interes).
	Salidas: Dinero total obtenido (total).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main(){	
	
	// Declaraci�n de variables
	     
	double capital = 0.0;
	double interes = 0.0;
	double total = 0.0;	   

	// Entradas de datos
	
	cout << " Introduzca la cantidad de euros que desea depositar: ";
	cin >> capital;
	cout << " Introduzca el interes aplicado: ";
	cin >> interes;
	
	// C�lculos
	
	total = capital + capital * (interes / 100);
			
	// Salidas
	
	cout << endl;
	cout << " Tras aplicar el interes, el capital final sera de " << total
	     << " euros" << endl << endl;

	/*
		Responda razonadamente a la siguiente pregunta: Supongamos que queremos 
		modificar la variable original capital con el nuevo valor de total. 
		�Es posible hacerlo directamente en la expresi�n de arriba?
		
		RESPUESTA: No ser�a posible realizarlo directamente en la expresi�n de 
		arriba ya que primero se tendr�a que calcular el nuevo valor de total y, 
		una vez calculado, s� se podr�a modificar la variable original capital 
		con dicho nuevo valor de la variable total.
	*/
	
	system("pause");
	return 0;
}
