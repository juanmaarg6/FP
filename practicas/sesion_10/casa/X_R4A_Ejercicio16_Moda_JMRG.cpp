/*
	Ejercicio 16: Programa que lee un vector de caracteres
	              y devuelve la moda, es decir, el caracter
	              que mas veces se repite
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

struct FrecuenciaCaracter{
	char caracter;
	int frecuencia;
};

/*
	Funcion que ordena alfabeticamente los caracteres de un vector
	
	Parametros: cadena[] (char), longitud (int)
	
	Algoritmo:
		Recorrer todo los elementos cadena[limite_partes] del vector cadena.
		
			Hallar la posicion posicion_valor_minimo del menor elemento del
			subvector delimitado por las componentes [limite_partes, longitud - 1].
			
			Intercambiar cadena[limite_partes] con cadena[posicion_valor_minimo].
		
	Devuelve: -
*/
void OrdenarSecuencia(char cadena[], int longitud);

/*
	Funcion que busca el caracter con mas apariciones en una cadena de caracteres
	
	Parametros: cadena[] (char)
	
	Algoritmo:
		Una vez ordenado el vector alfabeticamente, se comprueba si cada caracter
		es igual al anterior.
		
		Si lo es, aumenta en 1 el numero de repeticiones de ese caracter.
		Si no, si el numero de veces que se repite el nuevo caracter es
		mayor que las repeticiones del caracter anterior, se almacena
		el nuevo caracter como la nueva moda y su numero de apariciones.
	
	Devuelve: dato tipo FrecuenciaCaracter con el caracter mas frecuente
             y el numero de apariciones.
*/
FrecuenciaCaracter BuscarModa(char cadena[]);

int main(){
   const int LONGITUD_MAXIMA = 1000;
   
	char cadena[LONGITUD_MAXIMA];
	int longitud = 0, a = 0;
   FrecuenciaCaracter moda;
   
   /*
   	Algoritmo:
   		El usuario introduce una cadena de caracteres.
   		
   		Se ordena dicha cadena de caracteres.
   		
   		Se calcula la moda de la cadena de caracteres y
   		el numero de veces que se repite dicha moda.
   		
   		Se muestra en pantalla la moda y las veces que
   		se repite.	
   */
    
	cout << " Introduzca una cadena de caracteres: ";
	cin.getline(cadena, LONGITUD_MAXIMA);
	
	while(cadena[a] != '\0'){
		longitud++;
		a++;
	}
	
   OrdenarSecuencia(cadena, longitud);
   
	moda = BuscarModa(cadena);
	
	cout << " \n La moda es " << moda.caracter << ". Se repite " << moda.frecuencia << " veces" << endl << endl;
	
	system("pause");
}

void OrdenarSecuencia(char cadena[], int longitud){
	int valor_minimo = 0, posicion_valor_minimo = 0, intercambio;

	for(int limite_partes = 0; limite_partes < longitud; limite_partes++){
		valor_minimo = cadena[limite_partes];
		posicion_valor_minimo = limite_partes;
		
		for(int i = limite_partes; i < longitud; i++){
			if(cadena[i] < valor_minimo){
				valor_minimo = cadena[i];
				posicion_valor_minimo = i;
			}
		}
		
		intercambio = cadena[limite_partes];
		cadena[limite_partes] = valor_minimo;
		cadena[posicion_valor_minimo] = intercambio;	
	}
}

FrecuenciaCaracter BuscarModa(char cadena[]){
   FrecuenciaCaracter SalidaModa;
    
   int caracter_anterior = cadena[0];
   int caracter = caracter_anterior;
   int moda = caracter_anterior;

   int repeticiones = 0;
   int apariciones_moda = repeticiones;
    
   int i = 1;
   while(caracter != '\0'){
   	caracter = cadena[i];
   	
      if(caracter == caracter_anterior)
         repeticiones++;
      else
      	if(repeticiones > apariciones_moda){
         	moda = caracter_anterior;
            apariciones_moda = repeticiones;
            repeticiones = 1;
         }
         
        caracter_anterior = caracter;
        i++;
    }
    
   SalidaModa.caracter = moda;
   SalidaModa.frecuencia = apariciones_moda;
    
   return SalidaModa;
}
