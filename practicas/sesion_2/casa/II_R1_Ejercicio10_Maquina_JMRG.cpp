/*
	Ejercicio 10: Programa que calcula la cantidad de dinero que una maquina
					  de refrescos tiene que devolver al cliente.	  
					  Se supone que la cantidad de dinero introducida por el cliente
					  es igual o superior al precio del producto. 
	
	Entradas: el precio del producto (precio) y la cantidad ingresada por el cliente (ingreso).
	Salida: la vuelta de la maquina de refrescos (devolucion).
	
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>	

using namespace std;

int main(){							      
	int precio, ingreso;																						// Datos de entrada
	int devolucion;		            																   // Variable que indicara el dinero a devolver al cliente
	int monedas_1euro, monedas_50cent, monedas_20cent, monedas_10cent, monedas_5cent;	// Datos de salida

							
	cout << "Introduzca el precio del producto (en centimos): ";				// El usuario introduce los datos requeridos										
	cin >> precio;
	cout << "Cantidad de dinero introducida por el cliente (en centimos): ";
	cin >> ingreso;
	
	devolucion = ingreso - precio;					      // Se calcula cuanto hay que devolverle al cliente
	monedas_1euro = devolucion / 100;
	devolucion = devolucion - monedas_1euro * 100;		// Con cada moneda se ira actualizando el dinero a devolver al cliente
	monedas_50cent = devolucion / 50;
	devolucion = devolucion - monedas_50cent * 50;
	monedas_20cent = devolucion / 20;
	devolucion = devolucion - monedas_20cent * 20;
	monedas_10cent = devolucion / 10;
	devolucion = devolucion - monedas_10cent * 10;
	monedas_5cent = devolucion / 5;
	devolucion = devolucion - monedas_50cent * 5;
	
   cout << "\nAl cliente se le devolveran: ";
   cout << "\n\nMonedas de euro:  " << monedas_1euro;
   cout << "\nMonedas de 50 centimos: " << monedas_50cent;
   cout << "\nMonedas de 20 centimos:  " << monedas_20cent;
   cout << "\nMonedas de 10 centimos:  " << monedas_10cent;
   cout << "\nMonedas de 5 centimos:  " << monedas_5cent << "\n\n";
   
	system("pause");
}
