/*
   Ejercicio 2: Programa que lee la edad de una persona y su salario.
   			    Si dicha persona est� jubilada y su salario es inferior
   			    a 300 euros, entonces dicho salario se le aumentar� un 5%.
                 
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez.
*/

#include<iostream>

using namespace std;

int main(){
   
   // Declaraci�n de variables
   
	int edad;
	double ingresos, ingresos_final;
	double porcentaje = 1;
	bool datos_incorrectos;
	bool ingresos_menor_300;
	bool jubilado;
	bool aumento_ingresos;
	const string SEPARADOR = "\n\n ------------------------------------ \n\n";
	
	// Entrada de datos iniciales
	
	cout << "Introduzca la edad: ";
	cin >> edad;
	cout << "Introduzca el salario: ";
	cin >> ingresos;
	
	// Variables booleanas
	
	datos_incorrectos = (edad <= 0) || (ingresos <= 0);
	ingresos_menor_300 = ingresos <= 300;
	jubilado = edad >= 65;
	aumento_ingresos = jubilado && ingresos_menor_300;
	
	/*
	*************************
	      APARTADO A)
	*************************
	
	Mezclando E/S con c�mputos dentro de la misma estructura condicional
	*/
	
	cout << "\nApartado a): Se mezclan E/S con c�mputos dentro de la misma estructura condicional" << endl;
	
	if(datos_incorrectos){
		cout << endl << "\tDatos introducidos no validos" << endl;	
	}
	
	else if(aumento_ingresos){
		ingresos_final = ingresos + (ingresos * 0.05);
		cout << endl << "\tPor ser jubilado, el ingreso sera de " << ingresos_final << " euros" << endl;	
	}
	
	else{
		cout << endl << "\tNo es aplicable la subida";
		cout << "\n\tPor tanto, el ingreso se mantendra en " << ingresos << " euros" << endl;
	}
	
	cout << SEPARADOR;
	
	/*
	*************************
	      APARTADO B)
	*************************
	
	Separaci�n de E/S y c�mputos en bloques distintos
	*/
	
	cout << "Apartado b): Se separan E/S y c�mputos en bloques distintos" << endl;
	
		
	if(datos_incorrectos){
		cout << endl << "\tDatos introducidos no validos" << endl;	
		exit(-1);
	}
	
	if(aumento_ingresos){
		porcentaje = 1.05;	
	}
	
	ingresos_final = ingresos * porcentaje;
	
	if(aumento_ingresos){
		cout << endl << "\tPor ser jubilado, el ingreso sera de " << ingresos_final << " euros" << endl << endl;	
	}
	
   else{
		cout << endl << "\tNo es aplicable la subida";
		cout << "\n\tPor tanto, el ingreso se mantendra en " << ingresos << " euros" << endl << endl;	
	}
	
	system("pause");
}
