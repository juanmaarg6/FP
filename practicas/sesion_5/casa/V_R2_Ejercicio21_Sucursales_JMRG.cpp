/*
   Ejercicio 21: Programa que lee desde el teclado una serie de registros compuestos por sucursal,
                 producto, unidades y diga cuál es la sucursal que más productos ha vendido, habiendo
                 un total de 3 sucursales.
                    
   Código fuente escrito por Juan Manuel Rodríguez Gómez
*/

#include <iostream>

using namespace std;

int main()
{
	int sucursal = 4, producto = 0, ventas = 0;															
	int suma1 = 0, suma2 = 0, suma3 = 0;
	bool sucursal1_mas_ventas, sucursal2_mas_ventas, sucursal3_mas_ventas;
	
	string SUCURSAL_MAS_VENTAS = "\n Sucursal: ";
	string NUMERO_PRODUCTOS_VENDIDOS = "\n Ventas: ";
	
	cout << "\n Ejemplo de como introducir los datos: 1 2 3" << endl;
	
	/*
   	1) Mientras "sucursal" distinto de -1:
   		1.1) Introducir la serie de registros compuestos por sucursal, producto y unidades.
   		1.2) Calcular el número de ventas de cada sucursal.
   	2) Calcular cuál ha sido la sucursal con el mayor número de ventas.
   	3) Mostrar la sucursal con el mayor número de ventas.
   */	

	while(sucursal != -1){																																			
		cout << "\n Introduzca sucursal, codigo del producto y nº de productos vendidos (-1 0 0 para finalizar): ";
		cin >> sucursal >> producto >> ventas;
		
		
		if(sucursal == 1){
			suma1 += ventas;
		}
		
		else if(sucursal == 2){
			suma2 += ventas;
		}
				
		else if(sucursal == 3){
			suma3 += ventas;
		}
	}
	
	sucursal1_mas_ventas = (suma1 > suma2) && (suma1 > suma3);
	sucursal2_mas_ventas = (suma1 < suma2) && (suma2 > suma3);
	sucursal3_mas_ventas = (suma1 < suma2) && (suma2 < suma3);
	
	if(sucursal1_mas_ventas){																																															
		cout << SUCURSAL_MAS_VENTAS << "1";
		cout << NUMERO_PRODUCTOS_VENDIDOS << suma1;
	}
	
	else if(sucursal2_mas_ventas){
		cout << SUCURSAL_MAS_VENTAS << "2";
		cout << NUMERO_PRODUCTOS_VENDIDOS << suma2;
	}

	else if(sucursal3_mas_ventas){
			cout << SUCURSAL_MAS_VENTAS << "3";
			cout << NUMERO_PRODUCTOS_VENDIDOS << suma3;
	}
	
	cout << "\n\n";
	
	system("pause");
}
