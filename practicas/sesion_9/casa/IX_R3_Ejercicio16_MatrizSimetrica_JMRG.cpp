/*
	Ejercicio 16: Programa que dada una matriz cuadrada simetrica
	              de tamaño kxk, esta se almacena en forma de 
	              vector, cuyas componentes van a ser los
	              valores de la diagonal principal de la matriz
	              mas todos los que esten por debajo de dicha
	              diagonal principal.
	              
	              Tambien hace el proceso inverso, es decir, pasar
	              de vector a matriz cuadrada simetrica.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

// Funcion menu de opciones

void MenuOpciones(){
	cout << " Menu de opciones: \n";
	cout << " 1) Convertir de Matriz a Vector\n";
	cout << " 2) Convertir de Vector a Matriz\n";
	cout << "\n\n Introduzca una opcion: ";
}

// Funcion para introducir los elementos de la matriz

int IntroducirMatriz(int dimension, int Matriz[20][20]){
	cout << "\n Introduzca los elementos de la matriz: \n";
	for(int i = 0; i < dimension; i++){
		for(int j = 0; j < dimension; j++){
			cout << " Fila " << i << " // Columna " << j << ": ";
			cin >> Matriz[i][j];
		}
	}
		
	return 0;
}

// Funcion para comprobar si la matriz es simetrica

bool ComprobarSimetrica(int dimension, int Matriz[20][20]){
	bool es_simetrica = true;
	
	for(int i = 0; i < dimension; i++){
		for(int j = i + 1; j < dimension; j++){
			if(Matriz[i][j] != Matriz[j][i])
				es_simetrica = false;
		}
	}
	
	return es_simetrica;
}
	
// Funcion para mostrar la matriz en pantalla

int MostrarMatriz(int dimension, int Matriz[20][20]){
	for(int i = 0; i < dimension; i++){
		for(int j = 0; j < dimension; j++)
			cout << " " << Matriz[i][j];
		cout << "\n";
	}
	
	return 0;
}

// Funcion para introducir las componentes del vector

int IntroducirVector(int longitud, int vector[40]){
	cout << "\n Introduzca las componentes del vector: \n";
	for(int i = 0; i < longitud; i++){
		cout << " Posicion " << i << ": ";
		cin >> vector[i];
	}
	
	return 0;
}

// Funcion principal

int main(){
	const int MAXIMA_DIMENSION = 20;
	
	int matriz_simetrica [MAXIMA_DIMENSION][MAXIMA_DIMENSION] = {0};
	int vector_simetrica [MAXIMA_DIMENSION] = {0};

	int dimension = 0, longitud = 0, filas = 0, columnas = 0;
	int opcion = 0, k = 0;
	
	/*
		Algoritmo:
		
		Opcion 1:
		
			El usuario introduce la dimension de la matriz cuadrada simetrica.
			
			El usuario introduce los elementos de la matriz cuadrada simetrica.
			
			Mostrar la matriz introducida.
			
			Se calcula el vector relacionado con la matriz introducida.
			
			Mostrar en pantalla el vector.
			
		Opcion 2:
		
			El usuario introduce la longitud del vector.
			
			El usuario introduce las componentes del vector
						
			Se calcula la matriz cuadrada simetrica relacionada con el vector.
			
			Mostrar en pantalla la matriz.
			
	*/
		
	MenuOpciones();
	cin >> opcion;
	
	// Opcion 1: Transformar matriz cuadrada simetrica en vector
	
	if(opcion == 1){
		cout << "\n Introduzca el numero de filas y columnas de la matriz cuadrada simetrica: ";
		cin >> dimension;
	
		if(dimension > MAXIMA_DIMENSION){
			cout << "\n Error. La maxima dimension de la matriz es: " << MAXIMA_DIMENSION << "x" << MAXIMA_DIMENSION << endl << endl;
			exit(-1);
		}
		
		IntroducirMatriz(dimension, matriz_simetrica);
				
		if(!ComprobarSimetrica(dimension, matriz_simetrica)){
			cout << "\n Error. La matriz no es simetrica" << endl << endl;
			exit(-1);
		}
		
		cout << "\n La matriz introducida es: \n\n";
		MostrarMatriz(dimension, matriz_simetrica);
		
		for(int i = 0; i < dimension; i++){
			for(int j = 0; j < dimension; j++){
				if(i >= j){
					vector_simetrica[k] = matriz_simetrica[i][j];
					k++;
					longitud++;
				}
			}
		}
		
		cout << "\n El vector asociado a la matriz es: ";
		for(int i = 0; i < longitud; i++)
			cout << vector_simetrica[i] << " ";
			
		cout << endl << endl;
	}
	
	// Opcion 2: Transformar vector en matriz cuadrada simetrica

	
	if(opcion == 2){
		cout << "\n Introduzca la longitud del vector: ";
		cin >> longitud;
		
		if(longitud > MAXIMA_DIMENSION){
			cout << "\n Error. La maxima longitud permitida es: " << MAXIMA_DIMENSION << endl << endl;
			exit(-1);
		}
		
		IntroducirVector(longitud, vector_simetrica);
				
		while(k < longitud){
			for(int j = 0; j <= columnas; j++){
				matriz_simetrica[filas][j] = vector_simetrica[k];
				matriz_simetrica[j][filas] = vector_simetrica[k];
				k++;	
			}
			columnas++;
			filas++;
		}
		
		cout << "\n\n La matriz asociada al vector es: \n\n";
		MostrarMatriz(filas, matriz_simetrica);
		
		cout << endl << endl;
	}
	
	system("pause");
}
