/*
	Ejercicio 5: Programa que intercambia dos componentes de
					 un vector de numeros enteros.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){

	const int LONGITUD_MAXIMA = 1000;
	int longitud;
	
	int vector[LONGITUD_MAXIMA] = {0};
	bool componente[LONGITUD_MAXIMA] = {0};
	
	int intercambiar = 0, componente1 = 0, componente2 = 0;
	
	/*
		Algoritmo:
		
		EL usuario introduce la longitud del vector y dicho vector.
		
		El usuario introduce las dos componentes del vector que desea intercambiar.
		
		Si las componentes introducidas no son correctas:
			Se muestra un error y se detiene el programa.
		Si no:
			Se intercambian los valores de las componentes introducidas por el usuario.
		
		Se muestra en pantalla el vector con las componentes intercambiadas.
	*/
	
	cout << " Introduzca la longitud del vector: ";
	cin >> longitud;
	
	if(longitud > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}
	
	cout << "\n Introduzca el vector: ";
	
	for(int i = 0; i < longitud; i++){
		componente[i] = true;
		cin >> vector[i];
	}
	
	cout << "\n\n Nota: La primera posicion equivale al 0";
	cout << "\n Introduzca dos componentes (separadas por un espacio) que desea cambiar en el vector: ";
	cin >> componente1 >> componente2;
	
	if(!componente[componente1] || !componente[componente2]){
		cout << "\n Error. Alguna componente introducida no es correcta" << endl << endl;
		exit(-1);
	}
	
	else{
		intercambiar = vector[componente1];
		vector[componente1] = vector[componente2];
		vector[componente2] = intercambiar;
	}
	
	cout << "\n\n El vector con las componentes cambiadas es: ";
	
	for(int j=0; j<longitud; j++)
		cout << vector[j] << " ";
		
	cout << endl << endl;
	
	system("pause");
}
