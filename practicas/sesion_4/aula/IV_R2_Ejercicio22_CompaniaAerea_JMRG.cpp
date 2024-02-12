/*
   Ejercicio 22: Programa que dado un viaje, se aplican diferentes descuentos
   				  según la distancia a la que este el destino y si eres cliente
   				  previo de la empresa. Además se rebajan 15 euros en todo tipo
   				  de viajes.
   				  
   				  Todos los billetes parten de una tarifa base de 150 euros.
   				  
   				  Si el destino está a menos de 200km, el precio del billete es la tarifa base (150 euros).
   				  
   				  Si el destino está a más de 200km, a partir del Km 200) se suman 10 céntimos 
					  por cada km restante para llegar al destino.
   				  
   				  Descuento 3% --> Destinos a más de 600km.
   				  Descuento 4% --> Destinos a más de 1100km (No se aplica el anterior descuento).
   				  Descuento 5% --> El comprador es cliente previo de la empresa.
                    
   Código fuente escrito por Juan Manuel Rodríguez Gómez
*/

#include <iostream>

using namespace std;


int main(){
   
   // Declaración de variables
   
   const int TARIFA_BASE = 150;
   const int REBAJA_LINEAL = 15;
   const double REBAJA_DIST_MAYOR_600KM = 0.97;
   const double REBAJA_DIST_MAYOR_1100KM = 0.96;
   const double REBAJA_CLIENTE_PREVIO = 0.95;
   
   double precio_billete, distancia_destino_km, suma_10cent_km;
   char cliente_previo;
   bool datos_incorrectos;
   bool distancia_menor_200km, distancia_mayor_600km_menor_1100km, distancia_mayor_1100km, es_cliente_previo, no_es_cliente_previo;
   
		   
   cout << "\n Distancia al destino (en km): ";
   cin >> distancia_destino_km;
   
   cout << " ¿Es cliente previo de la empresa? (S [Si] o N [No]): ";
   cin >> cliente_previo;
   
   // Variables booleanas para valorar las diferentes situaciones
   
   distancia_menor_200km = distancia_destino_km < 200;
   distancia_mayor_600km_menor_1100km = (distancia_destino_km > 600) && (distancia_destino_km < 1100);
   distancia_mayor_1100km = distancia_destino_km > 1100;
   es_cliente_previo = (cliente_previo == 's') || (cliente_previo == 'S');
   no_es_cliente_previo = (cliente_previo == 'n') || (cliente_previo == 'N');
   datos_incorrectos = (distancia_destino_km < 0) || !(es_cliente_previo) && !(no_es_cliente_previo);
   
   
   suma_10cent_km = (distancia_destino_km - 200) * 0.10;
   
   if(datos_incorrectos){
   	cout << "\n\n Datos introducidos no validos" << endl << endl;
   	exit(-1);
   }
   
   /*
   	***********************************
   	     POLÍTICA DE DESCUENTO A)
   	***********************************

		Siendo cliente previo de la empresa, se le aplican los otros descuentos (según la distancia
		a la que esté su destino).
   */
   
   cout << "\n Primer metodo: si es cliente previo de la empresa, se le aplican otros descuentos." << endl << endl;
   
   if(distancia_menor_200km){
      precio_billete = TARIFA_BASE - REBAJA_LINEAL;
   }
   
   else{
      precio_billete = TARIFA_BASE + suma_10cent_km;
      
      if(distancia_mayor_600km_menor_1100km && es_cliente_previo){
      	precio_billete = precio_billete * REBAJA_DIST_MAYOR_600KM * REBAJA_CLIENTE_PREVIO - REBAJA_LINEAL;
      }
      
      else if(distancia_mayor_600km_menor_1100km && no_es_cliente_previo){
      	precio_billete = precio_billete * REBAJA_DIST_MAYOR_600KM - REBAJA_LINEAL;
      }
      
      if(distancia_mayor_1100km && es_cliente_previo){
			precio_billete = precio_billete * REBAJA_DIST_MAYOR_1100KM * REBAJA_CLIENTE_PREVIO - REBAJA_LINEAL;
		}
		
		else if(distancia_mayor_1100km && no_es_cliente_previo){
      	precio_billete = precio_billete * REBAJA_DIST_MAYOR_1100KM - REBAJA_LINEAL;
      }
   }
   
   cout << "\t Precio final de su billete: " << precio_billete << " euros";
   
   /*
   	***********************************
   	     POLÍTICA DE DESCUENTO B)
   	***********************************

		Siendo cliente previo de la empresa, no se le aplican los otros descuentos.
   */   
   
   cout << "\n\n Segundo metodo: si es cliente previo de la empresa, no se le aplican otros descuentos." << endl << endl;
   
   // El precio del billete vuelve a ser igual a la tarifa base para 
	// aplicar la nueva política de descuento dicha anteriormente.
   
   precio_billete = TARIFA_BASE;
   
   if(distancia_menor_200km){
      precio_billete = TARIFA_BASE - REBAJA_LINEAL;
   }
   
   else{
      precio_billete = TARIFA_BASE + suma_10cent_km;
      
      if(es_cliente_previo){
      	precio_billete = precio_billete * REBAJA_CLIENTE_PREVIO - REBAJA_LINEAL;
      }
      
      else{
      	
			if(distancia_mayor_600km_menor_1100km && no_es_cliente_previo){
	      	precio_billete = precio_billete * REBAJA_DIST_MAYOR_600KM - REBAJA_LINEAL;
	      }
	      
	      if(distancia_mayor_1100km && no_es_cliente_previo){
				precio_billete = precio_billete * REBAJA_DIST_MAYOR_1100KM - REBAJA_LINEAL;
			}
	   }
   }
   
   cout << "\t Precio final de su billete: " << precio_billete << " euros" << endl << endl;
   
   system("pause");
}
