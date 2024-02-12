/*
   Ejercicio 35: Programa que dada una fecha:
   				  a) Almacena esta fecha en una variable
   				  b) Muestra la fecha del d�a siguiente
   				  c) Muestra la fecha del d�a anterior
   				  d) Almacena una copia de la fecha en otra variable
   				  e) Indica si el a�o de la fecha es bisiesto o no
                  
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez
*/

#include<iostream>

using namespace std;

struct fecha{				// Creaci�n de un tipo de dato	
   int dia;
   int mes;
   int anio;
};

int main(){
   
   // Declaracion de variables
   
   fecha fecha_original, fecha_copia;
   fecha fecha_anterior, fecha_siguiente;
   
   const string SEPARADOR = "\n\n--------------------------------------\n\n";
   
   /*
   **********************************
            APARTADO A)
   **********************************
   */
   
   cout << "Apartado a)";
   cout << "\n\n\tIntroduzca una fecha de la forma dia/mes/a�o";
      
   cout << "\n\n\tDia (1-31): ";
   cin >> fecha_original.dia;
   cout << "\n\tMes (1-12): ";
   cin >> fecha_original.mes;
   cout << "\n\tA�o: ";
   cin >> fecha_original.anio;
   
	// Comprobaci�n de la fecha
	
	// Comprueba si el d�a introducido se encuentra en el rango 1-31
	
	if(fecha_original.dia < 1 || fecha_original.dia > 31){
	   cout << "\n\nError al introducir la fecha (El dia introducido tiene que estar entre 1 y 31).";
         
		cout << "\n\n";
			
      system("pause");
      exit(-1);
	}
	
	// Comprueba si el mes introducido se encuentra en el rango 1-12
	
	if(fecha_original.mes < 1 || fecha_original.mes > 12){
	   cout << "\n\nError al introducir la fecha (El mes introducido tiene que estar entre 1 y 12).";
         
		cout << "\n\n";
			
      system("pause");
      exit(-1);
	}
      
   // Comprueba si el d�a 31 est� o no en el mes introducido por el usuario
      
   if(fecha_original.dia == 31){
      // Para meses anteriores a Julio --> Los meses pares (Febrero, Abril...) no tienen 31 d�as
      
      if((fecha_original.mes < 7) && (fecha_original.mes % 2 == 0)){
         cout << "\n\nError al introducir la fecha (Dia no incluido en el mes).";
			cout << "\n\n";
			
         system("pause");
         exit(-1);
      }
      
      // Para meses posteriores a Agosto --> Los meses impares (Septiembre y Noviembre) no tienen 31 d�as
   
      if((fecha_original.mes > 8) && (fecha_original.mes % 2 != 0)){
         cout << "\n\nError al introducir la fecha (Dia no incluido en el mes).";
			cout << "\n\n";
			
         system("pause");
         exit(-1);
      }
   }

   // Comprueba si se ha introducido el d�a 30 en el mes de Febrero
   
   if((fecha_original.dia == 30) && (fecha_original.mes == 2)){
   	cout << "\n\nError al introducir la fecha (Dia no incluido en el mes).";
		cout << "\n\n";
			
      system("pause");
      exit(-1);
	}
	
	// Comprueba si se ha introducido el d�a 29 en el mes de Febrero sin ser a�o bisiesto
   
	if((fecha_original.anio % 4) != 0){
      if((fecha_original.dia == 29) && (fecha_original.mes == 2)){
         cout << "\n\nError al introducir la fecha (Dia no incluido en el mes).";
         
			cout << "\n\n";
			
         system("pause");
         exit(-1);
      }
   }
   
   // Muestra en pantalla de la fecha introducida por el usuario
      
   cout << "\n\n\tHa introducido la siguiente fecha: " << fecha_original.dia << "/" << fecha_original.mes << "/" << fecha_original.anio;
   cout << SEPARADOR;
   
   /*
   **********************************
            APARTADO B)
   **********************************
   */  
	 
   cout << "Apartado b)";
   
   // Ajuste de la fecha
   
   if(fecha_original.mes == 2){														   // Si el mes introducido es Febrero...
		
      if(fecha_original.dia == 28){														   // Si el d�a introducido es 28...
      	
      	if(fecha_original.anio % 4 == 0){										         // Si el a�o introducido es bisiesto, el d�a siguiente al 28/02 
      		fecha_siguiente.dia = 29;													      // ser� el 29/02 (no el 01/03)
      		fecha_siguiente.mes = fecha_original.mes;
      		fecha_siguiente.anio = fecha_original.anio;
      	}
      	
      	else{																						   // Si el a�o introducido no es bisiesto, el d�a siguiente al 28/02
      		fecha_siguiente.dia = 1;														   // ser� el 01/03
      		fecha_siguiente.mes = 3;
      		fecha_siguiente.anio = fecha_original.anio;
			}
		}
		
		else if(fecha_original.dia == 29){													// Si el d�a introducido es 29 (el a�o, por tanto, es bisiesto),
			fecha_siguiente.dia = 1;															// el d�a siguiente al 29/02 ser� el 01/03
      	fecha_siguiente.mes = 3;
      	fecha_siguiente.anio = fecha_original.anio;
		}
		
		else{																							// Si el d�a introducido no es ni 28 ni 29...
			fecha_siguiente.dia = fecha_original.dia + 1;								
			fecha_siguiente.mes = fecha_original.mes;
      	fecha_siguiente.anio = fecha_original.anio;
		}
	}
	
	else{																							// Si el mes introducido no es Febrero...
		
		if(fecha_original.dia == 30){													      // Si el d�a introducido es 30...
			
			if((fecha_original.mes < 7) && (fecha_original.anio % 2 == 0)){         // Para meses antes que Julio que tengan 30 d�as...
				fecha_siguiente.dia = 1;
      		fecha_siguiente.mes = fecha_original.mes + 1;
      		fecha_siguiente.anio = fecha_original.anio;
			}
			
			if((fecha_original.mes > 8) && (fecha_original.anio % 2 != 0)){         // Para meses despu�s de Agosto que tengan 30 d�as...
				fecha_siguiente.dia = 1;
      		fecha_siguiente.mes = fecha_original.mes + 1;
      		fecha_siguiente.anio = fecha_original.anio;
			}
			
			if(6 < fecha_original.mes < 9){													   // Para Julio y Agosto...
				fecha_siguiente.dia = 31;
      		fecha_siguiente.mes = fecha_original.mes;
      		fecha_siguiente.anio = fecha_original.anio;
			}
		}
		
		else if(fecha_original.dia == 31){													// Si el d�a introducido es 31...
			
			if((fecha_original.mes <= 7) && (fecha_original.anio % 2 != 0)){			// Para meses antes que Julio que tengan 31 d�as...
				fecha_siguiente.dia = 1;
      		fecha_siguiente.mes = fecha_original.mes + 1;
      		fecha_siguiente.anio = fecha_original.anio;
			}
			
			if(((fecha_original.mes >= 8) != 12) && (fecha_original.anio % 2 == 0)){ // Para meses despu�s de Agosto que tengan 31 d�as (sin contar Diciembre)...
				fecha_siguiente.dia = 1;
      		fecha_siguiente.mes = fecha_original.mes + 1;
      		fecha_siguiente.anio = fecha_original.anio;
			}
			
			if((fecha_original.dia == 31) && (fecha_original.mes == 12)){				// Para el d�a 31 del mes de Diciembre...
				fecha_siguiente.dia = 1;
      		fecha_siguiente.mes = 1;
      		fecha_siguiente.anio = fecha_original.anio + 1;
			}
		}
		
		else{																							// Para cualquier otra fecha...
      	fecha_siguiente.dia = fecha_original.dia + 1; 
      	fecha_siguiente.mes = fecha_original.mes;
      	fecha_siguiente.anio = fecha_original.anio;
		}
	}
	
	// Muestra en pantalla la fecha del d�a siguiente con respecto a la fecha introducida por el usuario
	
	cout << "\n\n\tUn dia despues, la fecha sera: " << fecha_siguiente.dia << "/" << fecha_siguiente.mes << "/" << fecha_siguiente.anio;
	cout << SEPARADOR;

   /*
   **********************************
            APARTADO C)
   **********************************
   */   
   
   cout << "Apartado c)";
   
   // Ajuste de la fecha
   
   if(fecha_original.mes == 3){														   // Si el mes introducido es Marzo...
		
      if(fecha_original.dia == 1){														   // Si el d�a introducido es 1...
      	
      	if(fecha_original.anio % 4 == 0){										         // Si el a�o introducido es bisiesto, el d�a anterior al 01/03
      		fecha_anterior.dia = 29;													      // ser� el 29/02 (no el 28/02)
      		fecha_anterior.mes = 2;
      		fecha_anterior.anio = fecha_anterior.anio;
      	}
      	
      	else{																						   // Si el a�o introducido no es bisiesto, el d�a anterior al 01/03
      		fecha_anterior.dia = 28;														   // ser� el 28/02
      		fecha_anterior.mes = 2;
      		fecha_anterior.anio = fecha_original.anio;
			}
		}
		
		else{																							// Si el d�a introducido no es 1...
			fecha_anterior.dia = fecha_original.dia - 1;								
			fecha_anterior.mes = fecha_original.mes;
      	fecha_anterior.anio = fecha_original.anio;
		}
	}
	
	else{																							// Si el mes introducido no es Marzo...
		
		if(fecha_original.dia == 1){													      // Si el d�a introducido es 1...
			
			if((fecha_original.mes < 7) && (fecha_original.anio % 2 == 0)){         // Para meses antes que Julio que tengan 30 d�as...
				fecha_anterior.dia = 30;
      		fecha_anterior.mes = fecha_original.mes - 1;
      		fecha_anterior.anio = fecha_original.anio;
			}
			
			if(((fecha_original.mes <= 7) != 1) && (fecha_original.anio % 2 != 0)){	// Para meses antes que Julio que tengan 31 d�as (sin contar Enero)...
				fecha_anterior.dia = 31;
      		fecha_anterior.mes = fecha_original.mes - 1;
      		fecha_anterior.anio = fecha_original.anio;
			}
			
			if((fecha_original.mes > 8) && (fecha_original.anio % 2 != 0)){         // Para meses despu�s de Agosto que tengan 30 d�as...
				fecha_anterior.dia = 30;
      		fecha_anterior.mes = fecha_original.mes - 1;
      		fecha_anterior.anio = fecha_original.anio;
			}
			
			if((fecha_original.mes >= 8)  && (fecha_original.anio % 2 == 0)){       // Para meses despu�s de Agosto que tengan 31 d�as...
				fecha_anterior.dia = 31;
      		fecha_anterior.mes = fecha_original.mes - 1;
      		fecha_anterior.anio = fecha_original.anio;
			}
			
			if((fecha_original.dia == 1) && (fecha_original.mes == 1)){				// Para el d�a 1 del mes de Enero...
				fecha_anterior.dia = 31;
      		fecha_anterior.mes = 12;
      		fecha_anterior.anio = fecha_original.anio - 1;
			}
		}
		
		else{																							// Para cualquier otra fecha...
      	fecha_anterior.dia = fecha_original.dia - 1; 
      	fecha_anterior.mes = fecha_original.mes;
      	fecha_anterior.anio = fecha_original.anio;
		}
	}
	
	cout << "\n\n\tUn dia antes, la fecha era: " << fecha_anterior.dia << "/" << fecha_anterior.mes << "/" << fecha_anterior.anio;
	cout << SEPARADOR;
	
   /*
   **********************************
            APARTADO D)
   **********************************
   */   
		
	cout << "Apartado d)";
	
	// Se realiza la copia
	
	fecha_copia.dia = fecha_original.dia;
	fecha_copia.mes = fecha_original.mes;
	fecha_copia.anio = fecha_original.anio;
	
	// Muestra en pantalla de la copia
	
	cout << "\n\n\tCopia de la fecha realizada correctamente";
	cout << "\n\n\tCopia de la fecha = " << fecha_copia.dia << "/" << fecha_copia.mes << "/" << fecha_copia.anio;
	cout << SEPARADOR;
	
   /*
   **********************************
            APARTADO E)
   **********************************
   */ 
		
	cout << "Apartado e)";
	
	// Muestra en pantalla si el a�o es bisiesto o no una vez realizado el c�lculo
	
	if(fecha_original.anio % 4 == 0){
		cout << "\n\n\tEl a�o " << fecha_original.anio << " es bisiesto";
	}
	
	else{
		cout << "\n\n\tEl a�o " << fecha_original.anio << " no es bisiesto";
	}
	
	cout << SEPARADOR;
         
   system("pause");
}
