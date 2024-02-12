/*
   Ejercicio 33: Programa que lee dos valores enteros introducidos por el usuario
					  y, si cualquiera de ellos divida al otro, se muestra en pantalla
					  qui�n divide a qui�n.
   				  
   				  El programa se ha realizado en dos m�todos diferentes:
   				  
   				  a) Mezclar entradas, c�mputos y salidas de resultados.
   				  
   				  b) Sin mezclar entradas, c�mputos y salidas de resultados.
                    
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez
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
			 M�TODO A)
		******************
		
		Mezclando entradas, c�mputos y salidas de resultados.
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
			 M�TODO B)
		******************
		
		Sin mezclar entradas, c�mputos y salidas de resultados.
		
		En este m�todo:
		
		Utilizamos una variable booleana (se_dividen) para ver si entero1 y entero2 se dividen o no. 
		Usamos dos variables que indiquen qui�n es el dividendo (dividendo) y qui�n es el divisor (divisor).
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
