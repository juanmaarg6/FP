/*
	Relación de ejercicios 4

	Ejercicio 1:

	Una recta r viene determinada por tres coeficientes A, B, C, de forma 
	que todos los puntos (x, y) del plano que pertenecen a la recta verifican:
		r : Ax + By + C = 0 (ecuación general)
	
	Es más frecuente utilizar la ecuación explícita de la recta, en la que 
	se expresa la abscisa en función de la pendiente de la recta (m) y de 
	la ordenada en origen (n):
		r : y = mx + n  (ecuación explícita)
	de manera que m = -A/B y n = -C/B
	
	Este programa: 
	
		a) 	Pide los coeficientes de dos rectas.
		b) 	Muestra los puntos (x, y) por los que pasan las rectas para 
			valores de x = -10, -9, ..., 10 con Incr_x = +1 y para 
			y = -5,- 4, .... 5 con Incr_y = 0.5
			
			Usa las funciones:
				double Ordenada(Recta recta, double x);
				double Abscisa(Recta recta, double y);
			
			para calcular la ordenada "y" dada la abscisa "x" (y viceversa)  
			para la recta Ax+By+C=0.
			
		c) Escribe la ecuación explícita de las dos rectas:
		
			i) con una función que escribe directamente la ecuación:
			   		void PintaEcuacionExplicita(Recta recta);
		
			ii) con una función que devuelve un string con la expresión de 
				la ecuación:
					string ObtenEcuacionExplicita(Recta recta);
				
			En ambos casos se calcula la pendiente y la ordenada en el origen 
			con sendas funciones:
				double Pendiente(Recta recta);
				double OrdenadaEnOrigen(Recta recta);
					
		d) 	Indica si las rectas son paralelas, secantes o coincidentes 
			usando las funciones:
				bool SonCoincidentes(Recta recta1, Recta recta2);
				bool SonParalelas(Recta recta1, Recta recta2);
				bool SonSecantes(Recta recta1, Recta recta2);
				
		e) Calcula el punto de corte de las rectas usando la función:
				Punto2D PuntoDeCorte(Recta recta1, Recta recta2);
				
		f) Indica si un punto pertenece a la primera recta usando la función:
				bool PuntoPerteneceARecta(Recta recta, Punto2D punto);

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos
#include <iomanip>		// Inclusión de los recursos de modificación de E/S
#include <string>		// Inclusión de los recursos del tipo de dato string

using namespace std;

// Registro utilizado para representar un punto del plano (x,y).
struct Punto2D {
	double x;		// Abscisa del punto
	double y;		// Ordenada del punto
};

// Registro utilizado para representar una recta.
struct Recta {
	double A, B, C;		// Coeficientes de la recta
};

/***************************************************************************/
// Función: Ordenada
// Descripción: Calcula la ordenada "y" dada la abscisa "x" para la
//              recta Ax+By+C=0.
// Recibe: Recta Ax+By+C=0 (recta),
//         Valor de la abscisa (x).
// Devuelve: Ordenada "y" dada la abscisa "x" para la recta Ax+By+C=0.
// PRE: B != 0
/***************************************************************************/
double Ordenada(Recta recta, double x) {
	return ( ( ( -(recta.A) * x ) - recta.C ) / recta.B );
}

/***************************************************************************/
// Función: Abscisa
// Descripción: Calcula la abscisa "x" dada la ordenada "y" para la 
//              recta Ax+By+C=0.
// Recibe: Parámetros de la recta (A, B, C),
//         Valor de la ordenada (y).
// Devuelve: Abscisa "x" dada la ordenada "y" para la recta Ax+By+C=0.
// PRE: A != 0
/***************************************************************************/
double Abscisa(Recta recta, double y) {
	return ( ( ( -(recta.B) * y ) - recta.C ) / recta.A );
}
	
/***************************************************************************/
// Función: Pendiente
// Descripción: Calcula la pendiente m = -A/B de la recta Ax+By+C=0.
// Recibe: Recta Ax+By+C=0 (recta).
// Devuelve: Pendiente "m" de la recta Ax+By+C=0.
// PRE: B != 0
/***************************************************************************/
double Pendiente(Recta recta) {
	return (-recta.A / recta.B);
}
		
/***************************************************************************/
// Función: OrdenadaEnOrigen
// Descripción: Calcula la ordenada en el origen n = -C/B de la recta Ax+By+C=0.
// Recibe: Recta Ax+By+C=0 (recta).
// Devuelve: Ordenada en el origen "n" de la recta Ax+By+C=0.
// PRE: B != 0
/***************************************************************************/
double OrdenadaEnOrigen(Recta recta) {
	return (-recta.C / recta.B);
}
			
/***************************************************************************/
// Función: PintaEcuacionExplicita
// Descripción: Escribe directamente la ecuación explícita de una recta.
// Recibe: Recta Ax+By+C=0 (recta).
// Devuelve: -
// PRE: B != 0
/***************************************************************************/
void PintaEcuacionExplicita(Recta recta) {
	double m = Pendiente(recta);
	double n = OrdenadaEnOrigen(recta);	
	
	cout << "y = ";
	
	if(m != 0) 
		cout << setw(5) << setprecision(2) << m <<  " x ";	

	if(n != 0) {
		
		if(n > 0) 
			cout << " +";
		else     
			cout << " -";
	}
	
	cout << setw(5) << setprecision(2) << fabs(n);	
}
		
/***************************************************************************/
// Función: ObtenEcuacionExplicita
// Descripción: Devuelve un string con la expresión de la ecuación explicita.
// Recibe: Recta Ax+By+C=0 (recta).
// Devuelve: String con la ecuación explícita de la recta.
// PRE: B != 0
/***************************************************************************/
string ObtenEcuacionExplicita(Recta recta) {
	double m = Pendiente(recta);
	double n = OrdenadaEnOrigen(recta);	
	
	string explicita;
	
	explicita = "y = ";
	
	if(m != 0) 
		explicita = explicita +to_string (m) + " x ";	
	
	if(n != 0) {
		
		if(n > 0) 
			explicita = explicita + " + ";
		else     
			explicita = explicita + " - ";
	}
	
	explicita = explicita + to_string(fabs(n));	
	
	return (explicita);
}
			
/***************************************************************************/
// Función: SonCoincidentes
// Descripción: Calcula si dos rectas son coincidentes.
// Recibe: Recta (A1)x+(B1)y+(C1)=0 (recta1),
//		   Recta (A2)x+(B2)y+(C2)=0 (recta2).
// Devuelve: True (1) si las rectas son coincidentes y False (0) si no.
/***************************************************************************/
bool SonCoincidentes(Recta recta1, Recta recta2) {
	double razon = recta1.A / recta2.A;
	return ( (razon == recta1.B / recta2.B) && (razon == recta1.C / recta2.C) );
}
					 			
/***************************************************************************/
// Función: SonParalelas
// Descripción: Calcula si dos rectas son paralelas.
// Recibe: Recta (A1)x+(B1)y+(C1)=0 (recta1),
//		   Recta (A2)x+(B2)y+(C2)=0 (recta2).
// Devuelve: True (1) si las rectas son paralelas y False (0) si no.
/***************************************************************************/
bool SonParalelas(Recta recta1, Recta recta2) {
	double razon = recta1.A / recta2.A;
	return ( (razon == recta1.B / recta2.B) && (razon != recta1.C / recta2.C) );
}

/***************************************************************************/
// Función: SonSecantes
// Descripción: Calcula si dos rectas son paralelas.
// Recibe: Recta (A1)x+(B1)y+(C1)=0 (recta1),
//		   Recta (A2)x+(B2)y+(C2)=0 (recta2).
// Devuelve: True (1) si las rectas son secantes y False (0) si no.
/***************************************************************************/
bool SonSecantes(Recta recta1, Recta recta2) {
	double razon = recta1.A / recta2.A;
	return (razon != recta1.B / recta2.B);
}								  

/***************************************************************************/
// Función: PuntoDeCorte
// Descripción: Calcula el punto de corte de dos rectas.
// Recibe: Recta (A1)x+(B1)y+(C1)=0 (recta1),
//		   Recta (A2)x+(B2)y+(C2)=0 (recta2).
// Devuelve: Punto de corte de las dos rectas.
/***************************************************************************/
Punto2D PuntoDeCorte(Recta recta1, Recta recta2) {
	Punto2D punto_corte;
	
	//                       (A1)x + (B1)y = -(C1)
	// Resolver el sistema {                        usando el método de Cramer.
	//						 (A2)x + (B2)y = -(C2)
	double determinante = (recta1.A * recta2.B) - (recta1.B * recta2.A);
	
	if(determinante != 0) {
		punto_corte.x = ( (-recta1.C * recta2.B) - (recta1.B * -recta2.C) ) 
		                / determinante;	
		punto_corte.y = ( (recta1.A * -recta2.C) - (-recta1.C * recta2.A) ) 
		                / determinante;		
	}
	
	return punto_corte;
}

/***************************************************************************/
// Función: PuntoPerteneceARecta
// Descripción: Calcula si un punto dado pertenece a la recta.
// Recibe: Recta (A1)x+(B1)y+(C1)=0 (recta1),
//		   Punto del plano (punto).
// Devuelve: True (1) si el punto pertenece a la recta y False (0) si no.
/***************************************************************************/
bool PuntoPerteneceARecta(Recta recta, Punto2D punto) {
	
	bool punto_pertenece_a_recta = false;
	
	if( (recta.A * punto.x + recta.B * punto.y + recta.C) == 0 )
		punto_pertenece_a_recta = true;
		
	return punto_pertenece_a_recta;
}

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	Recta recta1;  // PRE: recta1.A y recta1.B no pueden ser ambos 0 
	Recta recta2;  // PRE: recta2.A y recta2.B no pueden ser ambos 0 
	
	// a) Lectura de los coeficientes de las dos rectas

	cout << endl;	
	cout << " Recta 1: ";

	do {
		cout << endl << endl; 
		cout << "\t A: ";
		cin >> recta1.A;
		cout << "\t B: ";
		cin >> recta1.B;
	}while( (recta1.A == 0) && (recta1.B == 0) );

	cout << "\t C: ";
	cin >> recta1.C;
	
	cout << endl;	
	cout << " Recta 2: ";
	
	do {
		cout << endl << endl; 
		cout << "\t A: ";
		cin >> recta2.A;
		cout << "\t B: ";
		cin >> recta2.B;
	}while( (recta2.A == 0) && (recta2.B == 0) );

	cout << "\t C: ";
	cin >> recta2.C;
	
	cout << endl;	

	// b) Mostrar puntos (x,y) por los que pasan las rectas
	
	if(recta1.B != 0) {
		cout << endl;	
		cout << " Recta 1. x=-10.0, -9.0, ..., 10.0" << endl;
		cout << endl;	
		
		for(double x = -10.0; x <= 10.0; x++) {
			
			cout << "\t (" << setw(6) << setprecision(2) << x << ", " 
			     << setw(6) << setprecision(2) 
				 << Ordenada(recta1, x) << ")" << endl;
		}
	}
	else // recta1.B == 0
		cout << " Recta 1 paralela al eje Y--> x = " 
		     << setw(6) << setprecision(2) << (-recta1.C / recta1.A) << endl;
		     
	cout << endl;	
	
	if(recta1.A != 0) {
		cout << endl;
		cout << " Recta 1. y=-5.0, -4.5, -4.0, ..., 5.0" << endl; 
		cout << endl;	
		
		for (double y =- 5.0; y <= 5.0; y+=0.5) {
			
			cout << "\t (" << setw(6) << setprecision(2) 
			     << Abscisa(recta1, y)  << ", " 
			     << setw(6) << setprecision(2) << y << ")" << endl;
		}
	}
	else // recta1.A == 0
		cout << " Recta 1 paralela al eje X--> y = " 
		     << setw(6) << setprecision(2) << (-recta1.C / recta1.B) << endl;
		     
	cout << endl;
		
	if(recta2.B != 0) {
		cout << endl;		
		cout << " Recta 2. x=-10.0, -9.0, ..., 10.0" << endl;
		cout << endl;	
		
		for (double x =- 10.0; x <= 10.0; x++) {
			
			cout << "\t (" << setw(6) << setprecision(2) << x << ", " 
			     << setw(6) << setprecision(2) 
				 << Ordenada(recta2, x) << ")" << endl;
		}
	}
	else // recta2.B == 0
		cout << "Recta 2 paralela al eje Y--> x = " 
		     << setw(6) << setprecision(2) << (-recta2.C / recta2.A) << endl;
		     
	cout << endl;

	if (recta2.A != 0) {			 	
		cout << endl;
		cout << " Recta 2. y=-5.0, -4.5, -4.0, ..., 5.0" << endl; 
		cout << endl;	
	
		for (double y =- 5.0; y <= 5.0; y+=0.5) {
			
			cout << "\t (" << setw(6) << setprecision(2) 
			     << Abscisa(recta2,y)  << ", " 
			     << setw(6) << setprecision(2) << y << ")" << endl;
		}
	}
	else
		cout << " Recta 2 paralela al eje X--> y = " 
		     << setw(6) << setprecision(2) << (-recta2.C / recta2.B) << endl;
		     
	cout << endl;	
				
	// c) Escribir la ecuación explícita de las dos rectas
	
	if (recta1.B != 0) {
		cout << " Recta 1: ";
		PintaEcuacionExplicita(recta1);
		cout << endl;
		
		cout << endl;
		cout << " Recta 1: " << ObtenEcuacionExplicita(recta1) << endl;
		cout << endl;
	}
	
	if (recta2.B != 0) {		
		cout << endl;
		cout << " Recta 2: ";
		PintaEcuacionExplicita (recta2);
		cout << endl;
	
		cout << endl;
		cout << " Recta 2: " << ObtenEcuacionExplicita(recta2) << endl;
		cout << endl;
	}

	// d) Posición relativa de las dos rectas
	
	cout << endl;
	cout << " Las rectas son ";	
	
	if(SonCoincidentes(recta1, recta2))
		cout << " COINCIDENTES" << endl; 
	else if (SonParalelas(recta1, recta2))
		cout << " PARALELAS" << endl; 
	else if (SonSecantes(recta1, recta2))
		cout << " SECANTES" << endl;	
	cout << endl << endl;
	
	// e) Punto de corte de las dos rectas
	
	if(SonCoincidentes(recta1, recta2))
		cout << " Al ser coincidentes, ambas rectas se cortan en todos y cada"
		     << " uno de sus puntos" << endl;
	else if (SonParalelas(recta1, recta2))
		cout << " Al ser paralelas, ambas rectas no se cortan en ningun punto" 
		     << endl; 
	else if (SonSecantes(recta1, recta2)) {
		
		Punto2D punto_corte = PuntoDeCorte(recta1, recta2);
		
		cout << " Al ser secantes, ambas rectas se cortan en el punto (" 
		     << punto_corte.x << "," << punto_corte.y << ")" << endl;	
	}
	
	cout << endl << endl;
	
	// f) Ver si un punto pertenece a la primera recta
	
	Punto2D punto1 = {1,1};
	
	bool punto1_pertenece_a_recta1 = PuntoPerteneceARecta(recta1, punto1);
	bool punto1_pertenece_a_recta2 = PuntoPerteneceARecta(recta2, punto1);
	
	if(punto1_pertenece_a_recta1)
		cout << " El punto (" << punto1.x << "," << punto1.y << ") pertenece"
		     << " a la recta 1";
	else
		cout << " El punto (" << punto1.x << "," << punto1.y << ") no pertenece"
		     << " a la recta 1";
	
	cout << endl;
		 	
	if(punto1_pertenece_a_recta2)
		cout << " El punto (" << punto1.x << "," << punto1.y << ") pertenece"
		     << " a la recta 2";
	else
		cout << " El punto (" << punto1.x << "," << punto1.y << ") no pertenece"
		     << " a la recta 2";
			 
	// g) Leer un número indeterminado de puntos y ver si forman parte de 
	//    la primera recta (finaliza cuando se escriba FIN al leer el valor 
	//    de la coordenada x).
	
	string coordenada_x;
	Punto2D punto2;
	bool finalizar = false;
	
	do {
		cout << endl << endl;

		cout << " Introduzca la coordenada x del punto: ";
		cin >> coordenada_x;
		
		finalizar = (coordenada_x == "FIN");
		
		if(!finalizar) {
			punto2.x = stod(coordenada_x);
			
			cout << " Introduzca la coordenada y del punto: ";
			cin >> punto2.y;
			
			bool punto2_pertenece_a_recta1 = PuntoPerteneceARecta(recta1, 
			                                                      punto2); 
			
			cout << endl;
			                  
			if(punto2_pertenece_a_recta1)
				cout << "\t El punto (" << punto2.x << "," << punto2.y 
				     << ") pertenece" << " a la recta 1";
			else
				cout << "\t El punto (" << punto2.x << "," << punto2.y 
				     << ") no pertenece" << " a la recta 1";
		}
	}while(!finalizar);
	
	cout << endl << endl;
	
	return 0;
}
