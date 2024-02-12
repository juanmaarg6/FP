/*
	Ejercicio 1: Programa que calcula la media aritmética muestral y la desviación
					 típica muestral de las alturas de tres personas.
					 
					 Una vez calculadas, se mostrará si los valores de las alturas
					 introducidos inicialmente están por encima o por debajo de la media.
					  


	Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){	

	// Declaración de variables
	
	int altura1, altura2, altura3;			// Datos de entrada
	double argumento_raiz;						// Variable para almacenar el argumento de la raiz de la desviacion tipica
	double media, desviacion;			     	// Datos de salida
	
	const string DEBAJO_MEDIA = " cm esta por debajo de la media";		
	const string IGUAL_MEDIA = " cm es igual a la media	";											
	const string ENCIMA_MEDIA = " cm esta por encima de la media";															
	
	// Entrada de datos
							
	cout << "Introduzca la primera altura (en cm): ";			//El usuario introduce los datos requeridos
	cin >> altura1;
	cout << "Introduzca la segunda altura (en cm): ";	
	cin >> altura2;
	cout << "Introduzca la tercera altura (en cm): ";	
	cin >> altura3;
	
	// Cálculos de la media y la desviación típica
	
	media = (altura1 + altura2 + altura3) / 3;		 																
	argumento_raiz = (pow(altura1 - media,2) + pow(altura2 - media,2) + pow(altura3 - media,2)) / 3;
	desviacion = sqrt(argumento_raiz);
	
	// Resultados mostrados en pantalla

	cout << "\nMedia aritmetica: " << media;		                      
	cout << "\nDesviacion tipica: " << desviacion << "\n";	           
	
	// Evalúa si la primera altura está por encima o por debajo de la media o es igual
	
	if(altura1 < media){
		
		cout << "\nPrimera altura: " << altura1 << DEBAJO_MEDIA;
	}
	
	if(altura1 == media){
		
		cout << "\nPrimera altura: " << altura1 << IGUAL_MEDIA;
	}
	
	if(altura1 > media){
		
		cout << "\nPrimera altura: " << altura1 << ENCIMA_MEDIA;		
	}
	
	// Evalúa si la segunda altura está por encima o por debajo de la media o es igual
	
	if(altura2 < media){
		
		cout << "\nSegunda altura: " << altura2 << DEBAJO_MEDIA;
	}
	
	if(altura2 == media){
		
		cout << "\nSegunda altura: " << altura2 << IGUAL_MEDIA;
	}
	
	if(altura2 > media){
		
		cout << "\nSegunda altura: " << altura2 << ENCIMA_MEDIA;	
	}
	
	// Evalúa si la tercera altura está por encima o por debajo de la media o es igual
	
	if(altura3 < media){
		
		cout << "\nTercera altura: " << altura3 << DEBAJO_MEDIA << "\n\n";
	}
	
	if(altura3 == media){
		
		cout << "\nTercera altura: " << altura3 << IGUAL_MEDIA << "\n\n";
	}
	
	if(altura3 > media){
		
		cout << "\nTercera altura: " << altura3 << ENCIMA_MEDIA << "\n\n";	
	}
	
	system("pause");
}
