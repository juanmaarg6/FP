/*
	Relaci�n de ejercicios 3

	Ejercicio 13: Programa que, dado un n�mero real y un n�mero de cifras
	              decimales al cual queremos redondear, calcula el 
				  redondeo del n�mero real.
	
	Entradas: Un n�mero real (numero),
	          N�mero de cifras decimales al cual queremos redondear (redondeo).
	Salidas:  N�mero real redondeado (numero_redondeado).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusi�n de los recursos de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std;

/***************************************************************************/
// Funci�n: LeerNumeroReal
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: N�mero real.
/***************************************************************************/
double LeerNumeroReal(string msg) {
	
	double numero;
		
	cout << msg;
	cin >> numero;
	
	return numero;
}

/***************************************************************************/
// Funci�n: LeerRedondeo
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: Cifra decimal del n�mero hasta la cual queremos redondear.
/***************************************************************************/
int LeerRedondeo(string msg) {
	
	int redondeo;
	
	do {
		cout << msg;
		cin >> redondeo;
	}while(redondeo < 0);
	
	return redondeo;
}

/***************************************************************************/
// Funci�n: Potencia
// Recibe: Base de la potencia (base),
//         Exponente de la potencia (exponente).
// Devuelve: Base elevada al exponente, es decir, una potencia.
/***************************************************************************/
double Potencia(double base, int exponente) {
	
	double potencia = 1;
	
	if(exponente > 0)
		for(int i = 1; i <= exponente; i++)
			potencia *= base;
			
	if(exponente < 0)
		for(int i = 1; i <= -(exponente); i++)
			potencia *= 1.0 / base;
	
	if(exponente == 0)
		potencia = 1.0;
		
	return potencia;	
}

/***************************************************************************/
// Funci�n: Redondea
// Recibe: N�mero real que queremos redondear (numero),
//         Cifra decimal del n�mero hasta la cual queremos
//		   redondear (redondeo).
// Devuelve: N�mero real redondeado.
/***************************************************************************/
double Redondea(double numero, int redondeo) {
	
	double resultado;
		
	numero *= Potencia(10, redondeo);
	
	int parte_entera = (int)numero;
	
	double diferencia = numero - parte_entera;
	
	if(diferencia >= 0.5) 
		parte_entera +=1;
	
	resultado = parte_entera * Potencia(10, -(redondeo) );
		
	return resultado;	
}

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	// Declaraci�n de variables
	
	double numero;
	int redondeo;
	
	// Entradas de datos
	
	numero = LeerNumeroReal(" Introduzca un numero real: ");
	redondeo = LeerRedondeo
	    (" Introduzca el numero de cifras decimales al cual desea redondear: ");
	
	// C�lculos
	
	double numero_redondeado = Redondea(numero, redondeo);
	
	// Salidas
	
	cout << endl;
	cout << " El resultado de redondear " << numero << " a la " 
	     << redondeo << " cifra decimal es " << numero_redondeado;
	cout << endl << endl;
		 	
	return 0;
}
