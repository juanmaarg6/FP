/*
	Programa que, dada una imagen.pgm, muestra dicha imagen 
	rotada 90º a la derecha.
	              
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include<iostream>
#include<string>

using namespace std;

typedef short int color;

const int MAX_FILAS = 650;
const int MAX_COLUMNAS = 650;

// Estructura que representa una imagen.
struct Imagen{
	int filas;		// Numero de filas de la imagen.
	int columnas;		// Numero de columnas de la imagen.
	color matriz_pixels[MAX_FILAS][MAX_COLUMNAS];		// Matriz que contiene los pixeles de la imagen.	
};

/*
	Funcion que lee los datos de entrada de la imagen inicial.
	
	Parametros: cadena_magica (string), maximo_valor_gris (string), imagen_inicial (Imagen).
	
	Devuelve: -
*/
void LeerImagen(string &cadena_magica, int &maximo_valor_gris, Imagen &imagen_inicial);

/*
	Funcion que rota la imagen 90º a la derecha.
	
	Parametros: imagen_final (Imagen).
	
	Devuelve: -
*/
void ImagenRotada90Derecha(Imagen &imagen_final);

/*
	Funcion que muestra la imagen final.
	
	Parametros: cadena_magica (string), maximo_valor_gris (string), imagen_inicial (Imagen).
	
	Devuelve: -
*/
void MostrarImagen(string &cadena_magica, int &maximo_valor_gris, Imagen &imagen_final);

int main(){
	
	Imagen imagen_inicial;
	Imagen imagen_final;
	string cadena_magica;
	int maximo_valor_gris;
	
	/*
		Algoritmo:
		
		Se leen los datos de entrada de la imagen inicial.
		
		La imagen final se iguala a la imagen inicial.
		
		La imagen final se rota 90º a la derecha.
		
		Se muestra la imagen final.
	*/

	LeerImagen(cadena_magica, maximo_valor_gris, imagen_inicial);
	
	imagen_final = imagen_inicial;
	
	ImagenRotada90Derecha(imagen_final);
	
	MostrarImagen(cadena_magica, maximo_valor_gris, imagen_final);
}

void LeerImagen(string &cadena_magica, int &maximo_valor_gris, Imagen &imagen_inicial){

	/*
		Algoritmo:
		
		Se lee la cadena magica del archivo de texto .pgm (siempre es P2).
		
		Se leen el numero de columnas y filas de la imagen inicial.
		
		Se lee el valor maximo de gris (siempre es 255).
		
		Se lee cada pixel de la imagen inicial.
	*/
	
	cin >> cadena_magica;
	
	cin >> imagen_inicial.columnas;
	cin >> imagen_inicial.filas;
	
	cin >> maximo_valor_gris;
	
	for(int i = 0; i < imagen_inicial.filas; i++)
		for(int j = 0; j < imagen_inicial.columnas; j++)
			cin >> imagen_inicial.matriz_pixels[i][j];
}

void ImagenRotada90Derecha(Imagen &imagen_final){
	
	Imagen imagen_rotada;
	
	/*
		Algoritmo:
		
		La primera fila de pixeles de la imagen se traspone y pasa
		a ser la ultima columna de la matriz de pixeles de la imagen.
		
		La segunda fila de pixeles de la imagen se traspone y pasa
		a ser la penultima columna de la matriz de pixeles de la imagen.
		
		La tercera fila de pixeles de la imagen se traspone y pasa
		a ser la antepenultima columna de la matriz de pixeles de la imagen.
		
		Así sucesivamente hasta la ultima fila de pixeles de la imagen (esta
		ultima fila tambien esta incluida).
	*/
	
	imagen_rotada.filas = imagen_final.columnas;
	imagen_rotada.columnas = imagen_final.filas;
	
	for(int i = 0; i < imagen_rotada.filas; i++)
		for(int j = 0; j < imagen_rotada.columnas; j++)
			imagen_rotada.matriz_pixels[i][j] = imagen_final.matriz_pixels[imagen_rotada.columnas - j - 1][i];
	
	imagen_final = imagen_rotada;
}

void MostrarImagen(string &cadena_magica, int &maximo_valor_gris, Imagen &imagen_final){

	/*
		Algoritmo:
		
		Se muestra la cadena magica del archivo de texto .pgm (siempre es P2).
		
		Se muestran el numero de columnas y filas de la imagen final.
		
		Se muestra el valor maximo de gris (siempre es 255).
		
		Se muestra cada pixel de la imagen final.
	*/
	
	cout << cadena_magica << endl;
	
	cout << imagen_final.columnas;
	cout << " " << imagen_final.filas << endl;
	
	cout << maximo_valor_gris << endl;
	
	for(int i = 0; i < imagen_final.filas; i++){
		for(int j = 0; j < imagen_final.columnas; j++)
			cout << imagen_final.matriz_pixels[i][j] << " ";
			
		cout << endl;
	}
}
