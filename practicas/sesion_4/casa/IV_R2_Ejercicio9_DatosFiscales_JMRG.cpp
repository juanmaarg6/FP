/*
   Ejercicio 37: Programa que que lee los datos fiscales de una persona, reajusta su renta bruta según el
                 criterio que se indica posteriormente e imprima se renta neta final.
   
					  El criterio para reajustar su renta bruta es el siguiente:

					  - Se baja un 3% la retención fiscal a los autónomos.

					  - Para los no autónomos:

					  		- Se sube un 1% la retención fiscal a todos los pensionistas.
							- Al resto de trabajadores se le sube un 2% la retención fiscal. Una vez hecha esta 
                       subida lineal del 2%, se le aplica (sobre el resultado anterior) las siguientes subidas
                       adicionales, dependiendo de su estado civil y niveles de ingresos:
                       
									* Se sube un 6% la retención fiscal si la renta bruta es menor de 20.000 euros.
									* Se sube un 8 % la retencion fiscal a los casados con renta bruta superior a 20.000 euros.
									* Se sube un 10 % la retencion fiscal a los solteros con renta bruta superior a 20.000 euros.					   
                 
   Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/

#include<iostream>

using namespace std;

// Función principal

int main(){
   
   // Declaración de variables
   
   /*
   	La fórmula para calcular una nueva retención fiscal es:
   	
   	nueva_retencion = antigua_retencion + antigua_retencion * x/100	,	donde x/100 es la subida de la retención fiscal en un x%
   	
   	Sacando antigua_retencion como factor común:
   	
   	nueva_retencion = antigua_retencion * (1 + x / 100)
   	
   	Observamos que (1 + x/100) es constante por lo que declaramos diferentes constantes con sus respectivos valores
		para la situacion de cada persona.
   */
   
   const double INDICE_VARIACION_AUTONOMO = 0.97;
   const double INDICE_VARIACION_PENSIONISTA = 1.01;
   const double INDICE_VARIACION_TRABAJADOR_NORMAL = 1.02;
   const double INDICE_VARIACION_RENTA_BAJA = 1.06;
   const double INDICE_VARIACION_RENTA_ALTA_SOLTERO = 1.1;
   const double INDICE_VARIACION_RENTA_ALTA_CASADO = 1.08;
	    	
	char autonomo, pensionista, estado_civil;	
	bool es_autonomo, es_pensionista, es_trabajador_normal, es_soltero, es_casado, renta_baja, renta_alta;														
	double renta_bruta, renta_neta, antigua_retencion, nueva_retencion, indice_variacion_retencion;											
	
	
	// Entrada de datos
	
	cout << " Introduzca la renta bruta (en euros): ";												
	cin >> renta_bruta;
	
	cout << " Introduzca la retencion (en %): ";
	cin >> antigua_retencion;
	
	cout << "\n ¿Es autonomo? (Inserte S [Si] o N [No]): ";
	cin >> autonomo;

	cout << " ¿Es pensionista? (Inserte S [Si] o N [No]): ";
	cin >> pensionista;

	cout << " ¿Estado civil (Inserte C [Casado] o S [Soltero]): ";
	cin >> estado_civil;
	
	// Variables booleanas
	
	renta_baja = (renta_bruta < 20000);																													// Comprueba si la renta bruta es inferior a 20000 euros
	renta_alta = (renta_bruta >= 20000);																												// Comprueba si la renta bruta es igual o superior a 20000 euros
	es_autonomo = (autonomo == 's') || (autonomo == 'S') ;																						// Comprueba si es autónomo							
	es_pensionista = (pensionista == 's') || (pensionista == 'S');																				// Comprueba si es pensionista
	es_trabajador_normal	= ((autonomo == 'n') || (autonomo == 'N')) && ((pensionista == 'n') || (pensionista == 'N'));		// Compruueba si es un trabajador normal
	es_soltero = (estado_civil == 's') || (estado_civil == 'S');																				// Comprueba si está soltero							
	es_casado = (estado_civil == 'c') || (estado_civil == 'C');																					// Comprueba si está casado
		
	// Condicionales para calcular el valor de la nueva retención fiscal										
	
	if(es_autonomo && es_pensionista){																													// No puede ser autónomo y pensionista a la vez
		cout << "\n Datos introducidos no validos (No puede ser autonomo y pensionista a la vez)";					
		cout << "\n\n";
		exit(-1);
	}
	
	if(es_autonomo){																																			// Si es autónomo...
		indice_variacion_retencion = INDICE_VARIACION_AUTONOMO;
	}
	
	else if(es_pensionista){																																// Si es pensionista...
		indice_variacion_retencion = INDICE_VARIACION_PENSIONISTA;
	}
	
   else if(es_trabajador_normal){																																	// Si es un trabajador normal...
      indice_variacion_retencion = INDICE_VARIACION_TRABAJADOR_NORMAL;
      
        if(renta_baja){																																			// Si su renta es inferior a 20000 euros...
            indice_variacion_retencion = indice_variacion_retencion * INDICE_VARIACION_RENTA_BAJA;
         }
         
        else if(renta_alta && es_soltero){																												// Si su renta es superior o igual a 20000 euros y está soltero...
            indice_variacion_retencion = indice_variacion_retencion * INDICE_VARIACION_RENTA_ALTA_SOLTERO;
         }
         
        else if(renta_alta && es_casado){
            indice_variacion_retencion = indice_variacion_retencion * INDICE_VARIACION_RENTA_ALTA_CASADO;							// Si su renta es superior o igual a 20000 euros y está casado...
         }
    }
	
	// Cálculo de la nueva retención fiscal y la renta neta 
	
	nueva_retencion = antigua_retencion * indice_variacion_retencion;
	
	/*
   	La fórmula para calcular la renta neta es:
   	
   	renta_neta = renta_bruta - renta_bruta * nueva_retencion/100	,
   	
   	Sacando renta_bruta como factor común:
   	
   	renta_neta = renta_bruta * (1 - nueva_retencion / 100.0)
   */
   
	renta_neta = renta_bruta * (1 - nueva_retencion / 100.0);	
	
	// Muestra en pantalla de la renta neta y de la retención fiscal aplicada finalmente
	
	cout << "\n\n La renta neta es igual a: " << renta_neta << " euros";	
	cout << "\n\n La retencion fiscal aplicada finalmente es del " << nueva_retencion << " %";	
	cout << "\n\n";				
	
	system("pause");
}
