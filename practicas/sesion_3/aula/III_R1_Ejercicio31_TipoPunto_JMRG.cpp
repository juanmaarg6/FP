/*
   Ejercicio 31: Programa que pide los nombres y las coordenadas de dos ciudades al usuario
                 y crea una nueva ciudad cuyo nombre es la concatenación del nombre
                 de ambas y cuya situación es la multiplicación de cada una de las 
                 coordenadas de las dos ciudades.
                 
   Código fuente escrito por Juan Manuel Rodríguez Gómez

*/

#include<iostream>

using namespace std;

struct TipoPunto{					// Creación de tipo de dato para las coordenadas de las ciudades
   int abscisa;
   int ordenada;
};

struct TipoCiudad{			   // Creación de tipo de dato para los nombres de las ciudades
   TipoPunto situacion;
   string nombre;
};

int main(){
	
	// Declaración de variables
   
   TipoCiudad ciudad1, ciudad2, nueva_ciudad;
   
   // Entrada de datos

   // Primera ciudad
   
   cout << "\nIntroduzca el nombre de la primera ciudad: ";
   cin >> ciudad1.nombre;
   cout << "Introduzca la coordenada x de la primera ciudad: ";
   cin >> ciudad1.situacion.abscisa;
   cout << "Introduzca la coordenada y de la primera ciudad: ";
   cin >> ciudad1.situacion.ordenada;
   
   // Segunda ciudad
   
   cout << "\nIntroduzca el nombre de la segunda ciudad: ";
   cin >> ciudad2.nombre;
   cout << "Introduzca la coordenada x de la segunda ciudad: ";
   cin >> ciudad2.situacion.abscisa;
   cout << "Introduzca la coordenada y de la segunda ciudad: ";
   cin >> ciudad2.situacion.ordenada;
   
   // Calculos
   
   nueva_ciudad.nombre = ciudad1.nombre + ciudad2.nombre;
   nueva_ciudad.situacion.abscisa = ciudad1.situacion.abscisa * ciudad2.situacion.abscisa;
   nueva_ciudad.situacion.ordenada = ciudad1.situacion.ordenada * ciudad2.situacion.ordenada;
   
   // Muestra los resultados en pantalla

   cout << "\nEl nombre de la nueva ciudad es: " <<  nueva_ciudad.nombre;
   cout << "\nLa abscisa (primera coordenada) de la nueva ciudad es: " <<  nueva_ciudad.situacion.abscisa;
   cout << "\nLa ordenada (segunda coordenada) de la nueva ciudad es: " <<  nueva_ciudad.situacion.ordenada;
   cout << "\n\n";
   
   system("pause");
}
