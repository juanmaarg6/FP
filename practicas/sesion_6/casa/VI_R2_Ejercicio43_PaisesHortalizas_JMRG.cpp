/*
	Ejercicio 43: Programa que lee un país (España, Francia o Alemania),
					  una hortaliza (Tomate, Patata o Espinaca) y el número de 
					  toneladas vendidas de dicha hortaliza, e indica cuál es
					  es el país que más toneladas de hortalizas ha exportado
					  y cuál es dicha cantidad. 
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){	

	char pais, hortaliza;											
	int toneladas = 0, ventas_espania = 0, ventas_francia = 0, ventas_alemania = 0;
	
	bool espania_mayor_ventas, francia_mayor_ventas, alemania_mayor_ventas;											
	
	/*
		Algoritmo:
		
		Mientras "pais" sea distinto de '@':
		
			Introducir "pais", "hortaliza" y "toneladas".
			
			Calcular las ventas del país introducido.
			
			Comprobar cuál es el país con el mayor número de ventas.
		
		Mostrar en pantalla el país con el mayor número de ventas y cuántas
		toneladas ha vendido.
	*/
	
	while(pais != '@'){
		
		cout << " Introduzca pais ['E' (España), 'F' (Francia) o 'A' (Alemania)]	[@ para finalizar] : ";
		cin >> pais;
		
		if(pais != '@'){
			
			cout << " Introduzca hortaliza ['T' (Tomate), 'P' (Patata) o 'E' (Espinaca)] :  ";
			cin >> hortaliza;
			
			cout << " Introduzca numero de toneladas vendidas: ";
			cin >> toneladas;
			
			if(pais == 'E')															
				ventas_espania += toneladas;
			
			else if(pais == 'F')														
				ventas_francia += toneladas;
			
			else if(pais == 'A')		
				ventas_alemania += toneladas;							
		}
		
		cout << "\n\n";
	}
	
	espania_mayor_ventas = (ventas_espania > ventas_francia) && (ventas_espania > ventas_alemania);								
	francia_mayor_ventas = (ventas_francia > ventas_espania) && (ventas_francia > ventas_alemania);
	alemania_mayor_ventas = (ventas_alemania > ventas_espania) && (ventas_alemania > ventas_francia);
	
	if(espania_mayor_ventas){
	
		cout << "\n Pais que mas ha vendido: España";
		cout << "\n Numero de toneladas vendidas: " << ventas_espania << endl << endl;
	}
	
	else if(francia_mayor_ventas){
		
		cout << "\n Pais que mas ha vendido: Francia";
		cout << "\n Numero de toneladas vendidas: " << ventas_francia << endl << endl;
	}
	
	else if(alemania_mayor_ventas){
		
		cout << "\n Pais que mas ha vendido: Alemania";
		cout << "\n Numero de toneladas vendidas: " << ventas_alemania << endl << endl;
	}
	
	system("pause");
}
