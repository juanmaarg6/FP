/*
	Ejercicio 20: Programa que, dada una matriz cuadrada
	              de numeros positivos y con un numero
					  impar de filas y columnas, indica si 
					  dicha matriz es un cuadrado magico.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

const int DIMENSION_MAXIMA = 50;

/*
	Funcion para determinar si una matriz cuadrada es un cuadrado magico.
	
	Parametros: matriz[][DIMENSION_MAXIMA] (int), filas (int), columnas (int).
	
	Devuelve: es_cuadrado_magico (bool).
*/
bool EsCuadradoMagico(int matriz[][DIMENSION_MAXIMA], int filas, int columnas);

int main(){
   int matriz[DIMENSION_MAXIMA][DIMENSION_MAXIMA];
   int filas, columnas;
   bool cuadrado_magico;
   
   /*
   	Algoritmo:
   	
	   	Introducir el numero de filas y columnas de la matriz, ademas de la
	   	propia matriz.
	   	
	   	Comprobar si la matriz es un cuadrado magico.
	   	
	   	Si lo es, mostrar que la matriz es un cuadrado magico.
	   	Si no, mostrar que la matriz no es un cuadrado magico.
   */
    
   cout << " Introduzca el numero de filas y columnas de la matriz: ";
   cin >> filas >> columnas;
    
   cout << "\n Introduzca la matriz: \n\n";
   for(int i = 0; i < filas; i++)
      for(int j = 0; j < columnas; j++)
         cin >> matriz[i][j];

   cuadrado_magico = EsCuadradoMagico(matriz, filas, columnas);
    
   if(cuadrado_magico)
      cout << "\n La matriz introducida es un cuadrado magico" << endl << endl;
   else
      cout << "\n La matriz introducida no es un cuadrado magico" << endl << endl;
      
   system("pause");
}

bool EsCuadradoMagico(int matriz[][DIMENSION_MAXIMA], int filas, int columnas){
	
   bool candidato_cuadrado_magico;
   bool es_cuadrado_magico = true;
   int suma_comun = 0;
   int suma = 0;
   
   /*
   	Algoritmo:
   	
   	Comprobar si la matriz introducida es cuadrada y ademas tiene dimension
   	impar.
   	
   	Si es asi:
   	
   		Calcular la suma de los elementos de la primera fila.
   		
   		Comprobar si los elementos de cada fila, cada columna y cada diagonal
   		principal suman lo mismo que la suma de la primera fila.
   		
   		Si es asi, la matriz es un cuadrado magico.
   		Si no, la matriz no es un cuadrado magico.
   		
   	Si no, mostrar en pantalla las condiciones que tiene que cumplir la matriz
   	para ser un posible candidato a cuadrado magico.
   */
   
   candidato_cuadrado_magico = (filas == columnas) && (filas % 2 != 0);

	if(candidato_cuadrado_magico){
      for(int j = 0; j < columnas; j++)
         suma_comun += matriz[0][j];
         
      for(int i = 1; i < filas && es_cuadrado_magico; i++){
      	suma = 0;
      	
         for(int j = 0; j < columnas && es_cuadrado_magico; j++)
             suma += matriz[i][j];
             
         if(suma != suma_comun)
            es_cuadrado_magico = false;
      }
        
      for(int j = 0; j < columnas && es_cuadrado_magico; j++){
         suma = 0;
         
         for(int i = 0; i < filas && es_cuadrado_magico; i++)
            suma += matriz[i][j];
             
         if(suma != suma_comun)
            es_cuadrado_magico = false;
      }
        
      suma = 0;
      for(int diagonal = 0; diagonal < columnas && es_cuadrado_magico; diagonal++)
            suma += matriz[diagonal][diagonal];
      if(suma != suma_comun)
         es_cuadrado_magico = false;
        
      suma = 0;
      for(int diagonal = 0; diagonal < columnas && es_cuadrado_magico; diagonal++)
            suma += matriz[diagonal][filas - diagonal - 1];
		if(suma != suma_comun)
         es_cuadrado_magico = false;
   }
   else{
   	cout << "\n Error. La matriz introducida tiene que ser cuadrada y tiene que contener un numero impar de filas y columas" << endl << endl;
   	exit(-1);
   }
    
    return es_cuadrado_magico;
}
