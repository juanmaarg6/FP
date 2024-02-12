/*
	Relación de ejercicios 4

	Ejercicio 4: Programa que, dado un rectángulo mediante su coordenada
	             superior izquierda y su coordenada inferior derecha, 
	             calcula la circunferencia centrada en el punto de corte
	             de las diagonales del rectángulo tal que su superficie
	             es la menor entre todas las circunferencias de área
	             mayor que la del rectángulo.
	
	Entradas: Rectángulo (rectangulo).
	Salidas: Circunferencia centrada en el punto de corte de las diagonales 
	         del rectángulo tal que su superficie es la menor entre todas las 
			 circunferencias de área mayor que la del rectángulo 
			 (circunferencia).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos

using namespace std;

// Registro utilizado para representar un punto del plano (x,y).
struct Punto2D {
	double x;	// Abscisa del punto
	double y;	// Ordenada del punto
};

// Registro utilizado para representar un rectángulo
struct Rectangulo {
	Punto2D punto_sup_izq;		// Esquina superior izquierda del rectángulo
	Punto2D punto_inf_der;		// Esquina inferior derecha del rectángulo
};

// Registro utilizado para representar una circunferencia
struct Circunferencia {
	Punto2D centro;			// Centro de la circunferencia
	double radio;			// Radio de la circunferencia
};

/***************************************************************************/
// Función: LeerRectangulo
// Recibe: -
// Devuelve: Rectángulo leído.
/***************************************************************************/
Rectangulo LeerRectangulo() {
	
	Rectangulo rectangulo;
	
	cout << " Coordenada x de la esquina superior izquierda del rectangulo: ";
	cin >> rectangulo.punto_sup_izq.x ;
	cout << " Coordenada y de la esquina superior izquierda del rectangulo: ";
	cin >> rectangulo.punto_sup_izq.y;
	
	do {
		cout << " Coordenada x de la esquina inferior derecha del rectangulo: ";
		cin >> rectangulo.punto_inf_der.x ;
	}while(rectangulo.punto_inf_der.x <= rectangulo.punto_sup_izq.x);
	
	do {
		cout << " Coordenada y de la esquina inferior derecha del rectangulo: ";
		cin >> rectangulo.punto_inf_der.y;
	}while(rectangulo.punto_inf_der.y >= rectangulo.punto_sup_izq.y);
	
	return rectangulo;
}
	
/***************************************************************************/
// Función: PuntoCorteDiagonales
// Recibe: Rectángulo (rectangulo).
// Devuelve: Punto de corte de las diagonales del rectángulo.
/***************************************************************************/
Punto2D PuntoCorteDiagonales(Rectangulo rectangulo) {
	
	Punto2D punto_corte;
	
	// Calculamos el punto medio del segmento que une la esquina inferior
	// derecha y la esquina superior izquierda del rectángulo
	punto_corte.x = rectangulo.punto_inf_der.x + 
	                ( (rectangulo.punto_sup_izq.x - rectangulo.punto_inf_der.x) 
					/ 2 );
	punto_corte.y = rectangulo.punto_inf_der.y + 
	                ( (rectangulo.punto_sup_izq.y - rectangulo.punto_inf_der.y) 
					/ 2 );
	
	return punto_corte;
}

/***************************************************************************/
// Función: AreaRectangulo
// Recibe: Rectángulo (rectangulo).
// Devuelve: Área del rectángulo.
/***************************************************************************/
double AreaRectangulo(Rectangulo rectangulo) {
	
	double area;
	
	area = fabs(rectangulo.punto_sup_izq.x - rectangulo.punto_inf_der.x) *
	       fabs(rectangulo.punto_sup_izq.y - rectangulo.punto_inf_der.y);
	
	return area;
}

/***************************************************************************/
// Función: AreaCircunferencia
// Recibe: Circunferencia (circunferencia).
// Devuelve: Área de la circunferencia.
/***************************************************************************/
double AreaCircunferencia(Circunferencia circunferencia) {
	
	const double PI = 6 * asin(0.5);
	
	double area;
	
	area = PI * circunferencia.radio * circunferencia.radio;
	
	return area;	
}

/***************************************************************************/
// Función: MenorCircunferencia
// Recibe: Área del rectángulo (area_rectangulo).
// Devuelve: Circunferencia centrada en el punto de corte
//	         de las diagonales del rectángulo tal que su superficie
//	         es la menor entre todas las circunferencias de área
//           mayor que la del rectángulo.
/***************************************************************************/
Circunferencia MenorCircunferencia(Rectangulo rectangulo) {
	
	const double RADIO_MIN = 0.5;
	const double INCREMENTO = 0.25;
	
	Circunferencia menor_circunferencia;
	double radio;
	double area_rectangulo, area_circunferencia;
	
	area_rectangulo = AreaRectangulo(rectangulo);
	
	menor_circunferencia.centro = PuntoCorteDiagonales(rectangulo);

	menor_circunferencia.radio = RADIO_MIN;
	
	while(area_circunferencia <= area_rectangulo){
		menor_circunferencia.radio = radio;
		area_circunferencia = AreaCircunferencia(menor_circunferencia);
		radio += INCREMENTO; 
	}
	
	return menor_circunferencia;	
}

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
	// Declaración de variables
	
	Rectangulo rectangulo;
	Circunferencia circunferencia;
	double area_rectangulo, area_circunferencia;
	
	// Entradas de datos
	
	rectangulo = LeerRectangulo();
	
	// Cálculos
	
	area_rectangulo = AreaRectangulo(rectangulo);
	
	circunferencia = MenorCircunferencia(rectangulo);
	
	area_circunferencia = AreaCircunferencia(circunferencia);
	
	// Salidas de datos
	
	cout << endl;
	cout << " Circunferencia centrada en el punto de corte de las diagonales"
	     << " del rectangulo tal que su superficie" << endl << " es la menor"
		 << " entre todas las circunferencias de area mayor que la del"
		 << "rectangulo: ";
	cout << endl << endl;	 
	cout << "\t Centro: (" << circunferencia.centro.x << "," 
	     << circunferencia.centro.y << ")";
	cout << endl;
	cout << "\t Radio: " << circunferencia.radio;
	cout << endl << endl;
	cout << " Area del rectangulo: " << area_rectangulo;
	cout << endl;
	cout << " Area de la circunferencia: " << area_circunferencia;
	cout << endl << endl;	
	
	return 0;
}
