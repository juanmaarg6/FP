/*
   Ejercicio 33: Programa que lee dos valores enteros introducidos por el usuario
					  y, si cualquiera de ellos divida al otro, se muestra en pantalla
					  quién divide a quién.
   				  
   				  El programa se ha realizado en dos métodos diferentes:
   				  
   				  a) Mezclar entradas, cómputos y salidas de resultados.
   				  
   				  b) Sin mezclar entradas, cómputos y salidas de resultados.
                    
   Código fuente escrito por Juan Manuel Rodríguez Gómez
*/

#include <iostream>

using namespace std;

int main(){	
	
   int entero1, entero2;              													
								
   cout << " Introduzca el primer numero entero: ";      
   cin >> entero1;                           
   cout << " Introduzca el segundo numero entero: ";      
   cin >> entero2;  
	
	/*
		******************
			 MÉTODO A)
		******************
		
		Mezclando entradas, cómputos y salidas de resultados.
	*/ 	
	
	cout << "\n\t METODO A)" << endl;
	
	if((entero1 == 0) || (entero2 == 0)){
		cout << "\n\t\t Ninguno de los numeros divide al otro" << endl;
	}
	
	else{
				
		if((entero1 % entero2) == 0){
	      	cout << "\n\t\t " << entero2 << " divide a " << entero1 << endl;
		}
			
	  	else if((entero2 % entero1) == 0){
	      cout << "\n\t\t " << entero1 << " divide a " << entero2 << endl;
		}
			
		else{
			cout << "\n\t\t Ninguno de los numeros divide al otro" << endl;
		}
	}
	
	/*
		******************
			 MÉTODO B)
		******************
		
		Sin mezclar entradas, cómputos y salidas de resultados.
		
		En este método:
		
		Utilizamos una variable booleana (se_dividen) para ver si entero1 y entero2 se dividen o no. 
		Usamos dos variables que indiquen quién es el dividendo (dividendo) y quién es el divisor (divisor).
	*/
	
	int dividendo, divisor;                
   bool entero_es_0, dividendo_entero1, dividendo_entero2, se_dividen;	
   
   cout << "\n\t METODO B)" << endl;

   entero_es_0 = (entero1 == 0) || (entero2 == 0);

   if(entero_es_0){
		cout << "\n\t\t Ninguno de los numeros divide al otro" << endl;
		exit(-1);
	}
   
   dividendo_entero1 = (entero1 % entero2) == 0;
   dividendo_entero2 = (entero2 % entero1) == 0;
   se_dividen = dividendo_entero1 || dividendo_entero2;
	
	if(dividendo_entero1){
   	dividendo = entero1;
   	divisor = entero2;
	}
	
	else if(dividendo_entero2){
   	dividendo = entero2;
   	divisor = entero1;
	}

	if(se_dividen){
	   cout << "\n\t\t " << divisor << " divide a " << dividendo << endl;
	}
		
	else{
		cout << "\n\t\t Ninguno de los numeros divide al otro" << endl;
	} 	

	
	cout << "\n\n";
	
	system("pause");
}
