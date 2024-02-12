/*
	Relación de ejercicios 6

	Ejercicio 22:	Usando como referencia la clase Punto2D para representar 
	                un punto en el plano, diseñamos e implementamos las clases 
					Rectangulo y Triangulo.

					Nota: Consideramos únicamente rectángulos cuyos lados 
					      sean paralelos a los ejes de coordenadas. No hay 
						  restricciones para los triángulos.
						  
					Usamos las propiedades siguientes para la clase Rectangulo:
					
						1) esi, esquina superior izquierda (de la clase 
						   Punto2D).
						2) b, longitud de la base (double).
						3) a, longitud de la altura (double).

					Para la representación de la clase Triangulo usamos las 
					coordenadas de sus tres vértices (V_A, V_B, V_C).
					
					Además de los constructores y los métodos Get oportunos,
					añadimos el siguiente conjunto mínimo de métodos:

						a) Calcular el área del rectángulo.
						b) Calcular el perímetro del rectángulo.
						c) Calcular si un punto está dentro de un rectángulo.
						d) Calcular el perímetro del triángulo.
						e) Calcular si un triángulo es rectángulo.
						f) Obtener el triángulo inferior de un rectángulo, 
						   considerando su diagonal principal.
						g) Obtener el triángulo superior de un rectángulo, 
						   considerando su otra diagonal.
	              
	Entradas: Rectángulo (r),
	          Triángulo (t),
	          Triángulo rectángulo (tr).
	Salidas: Perímetro y área del rectángulo,
	         Comprobación de si ciertos puntos del plano pertenecen al
	         rectángulo,
	         Perímetro del triángulo,
	         Comprobación si el triángulo rectángulo es realmente rectángulo,
	         Triángulo inferior del rectángulo, considerando su diagonal 
			 principal (t_inf),
	         Triángulo superior del rectángulo, considerando su otra 
			 diagonal (t_sup).
			 
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

/***************************************************************************/
const double PRECISION_SON_IGUALES = 1e-6; // 0.000001
/***************************************************************************/

/***************************************************************************/
// Función: SonIguales()
// Descripción: Función global (asociada a la constante PRECISION_SON_IGUALES)
//              que permite que dos números reales muy próximos sean 
//              considerados iguales.
// Recibe: Dos números reales (numero1, numero2)
// Devuelve: True (1) si los dos números reales se consideran iguales y
//           False (0) si no es así
/***************************************************************************/
bool SonIguales(double numero1, double numero2) {
	
	return ( fabs(numero1 - numero2) <= PRECISION_SON_IGUALES );
}

/***************************************************************************/
// Clase Punto2D: representa un punto (x,y) en el plano
/***************************************************************************/
class Punto2D {

	private:

		double x;		// Coordenada X del punto en el plano
		double y;		// Coordenada Y del punto en el plano

	public:

		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Punto2D() : x(0.0), y(0.0) { }

		/*******************************************************************/
		// Constructor con parámetros
		/*******************************************************************/
		Punto2D(double abscisaPunto, double ordenadaPunto) {
			
			SetCoordenadas (abscisaPunto, ordenadaPunto);
		}
		
		/*******************************************************************/
		// Método: SetCoordenadas()
		// Descripción: Establece las coordenadas de un punto del plano
		// Recibe: Abscisa del punto (abscisaPunto), 
		//         Ordenada del punto (ordenadaPunto)
		// Devuelve: -
		/*******************************************************************/
		void SetCoordenadas(double abscisaPunto, double ordenadaPunto) {
			
			x = abscisaPunto;
			y = ordenadaPunto;
		}
		
		/*******************************************************************/
		// Método: GetX()
		// Descripción: Devuelve la abscisa de un punto del plano
		// Recibe: -
		// Devuelve: Abscisa de un punto del plano (x)
		/*******************************************************************/
		double GetX() {
			
			return x;
		}
		
		/*******************************************************************/
		// Método: GetY()
		// Descripción: Devuelve la ordenada de un punto del plano
		// Recibe: -
		// Devuelve: Ordenada de un punto del plano (y)
		/*******************************************************************/
		double GetY() {
			
			return y;
		}
		
		/*******************************************************************/
		// Método: EsIgual()
		// Descripción: Comprueba si un punto del plano es igual al punto
		//              implícito
		// Recibe: Punto del plano (otro)
		// Devuelve: True (1) si los dos puntos son iguales y False (0) si
		//           no lo son
		/*******************************************************************/
		bool EsIgual(Punto2D otro) {
			
			return ( SonIguales(x, otro.x) && SonIguales(y, otro.y) );
		}
		
		/*******************************************************************/
		// Método: DistanciaEuclidea()
		// Descripción: Calcula la distancia euclídea del punto implícito 
		//              a otro punto del plano
		// Recibe: Punto del plano (otro)
		// Devuelve: Distancia euclídea entre los dos puntos.
		/*******************************************************************/
		double DistanciaEuclidea(Punto2D otro) {
			
			double dif_x = pow(x - otro.x, 2);
			double dif_y = pow(y - otro.y, 2);

			return ( sqrt(dif_x + dif_y) );
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con las coordenadas del punto 
		//              del plano
		// Recibe: -
		// Devuelve: String con las coordenadas del punto del plano (cadena)
		/*******************************************************************/	
		string ToString () {
			
			string cadena;
			
			cadena += "\t [" + to_string(x) + ", " + to_string(y) + "]";
			
			return cadena;
		}
};

/***************************************************************************/
// Clase Triangulo: representa un triangulo en el plano
/***************************************************************************/
class Triangulo {
	
	private:
		
		Punto2D vertice_A;		// Vértice A del triángulo
		Punto2D vertice_B;		// Vértice B del triángulo
		Punto2D vertice_C;		// Vértice C del triángulo
		
	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Triangulo() : vertice_A(Punto2D(0.0,0.0)), 
		              vertice_B(Punto2D(1.0,0.0)),
					  vertice_C(Punto2D(0.0,1.0)) { }
		
		/*******************************************************************/
		// Constructor con parámetros
		/*******************************************************************/	  
		Triangulo(Punto2D valor_vertice_A, Punto2D valor_vertice_B, 
		          Punto2D valor_vertice_C)
		         : vertice_A(valor_vertice_A), vertice_B(valor_vertice_B), 
				   vertice_C(valor_vertice_C) { }
		
		/*******************************************************************/
		// Método: SetVerticeA()
		// Descripción: Establece el vértice A del triángulo
		// Recibe: Vértice A del triángulo (valor_vertice_A)
		// Devuelve: -
		/*******************************************************************/
		void SetVerticeA(Punto2D valor_vertice_A) {
			
			vertice_A.SetCoordenadas( valor_vertice_A.GetX(), 
			                          valor_vertice_A.GetY() );
		}
		
		/*******************************************************************/
		// Método: SetVerticeB()
		// Descripción: Establece el vértice B del triángulo
		// Recibe: Vértice B del triángulo (valor_vertice_B)
		// Devuelve: -
		/*******************************************************************/
		void SetVerticeB(Punto2D valor_vertice_B) {
			
			vertice_B.SetCoordenadas( valor_vertice_B.GetX(), 
			                          valor_vertice_B.GetY() );
		}
		
		/*******************************************************************/
		// Método: SetVerticeC()
		// Descripción: Establece el vértice C del triángulo
		// Recibe: Vértice C del triángulo (valor_vertice_C)
		// Devuelve: -
		/*******************************************************************/
		void SetVerticeC(Punto2D valor_vertice_C) {
			
			vertice_C.SetCoordenadas( valor_vertice_C.GetX(), 
			                          valor_vertice_C.GetY() );
		}
		
		/*******************************************************************/
		// Método: GetVerticeA()
		// Descripción: Devuelve el vértice A del triángulo
		// Recibe: -
		// Devuelve: Vértice A del triángulo (vertice_A)
		/*******************************************************************/
		Punto2D GetVerticeA() {
			
			return vertice_A;
		}
		
		/*******************************************************************/
		// Método: GetVerticeB()
		// Descripción: Devuelve el vértice B del triángulo
		// Recibe: -
		// Devuelve: Vértice B del triángulo (vertice_B)
		/*******************************************************************/
		Punto2D GetVerticeB() {
			
			return vertice_B;
		}
		
		/*******************************************************************/
		// Método: GetVerticeC()
		// Descripción: Devuelve el vértice C del triángulo
		// Recibe: -
		// Devuelve: Vértice C del triángulo (vertice_C)
		/*******************************************************************/
		Punto2D GetVerticeC() {
			
			return vertice_C;
		}
		
		/*******************************************************************/
		// Método: Perimetro()
		// Descripción: Calcula el perímetro del triángulo
		// Recibe: -
		// Devuelve: Perímetro del triángulo (perimetro)
		/*******************************************************************/
		double Perimetro() {
			
			double perimetro = ( vertice_A.DistanciaEuclidea(vertice_B) ) +
			                   ( vertice_B.DistanciaEuclidea(vertice_C) ) +
					           ( vertice_C.DistanciaEuclidea(vertice_A) );
			
			return perimetro;
		}
		
		/*******************************************************************/
		// Método: LadoA()
		// Descripción: Calcula y devuelve el lado "a" del triángulo, el cual 
		//              es el segmento que une los vertices B y C del triángulo
		// Recibe: -
		// Devuelve: Lado "a" del triángulo (lado_a)
		/*******************************************************************/
		double LadoA() {
			
			double lado_a = vertice_B.DistanciaEuclidea(vertice_C);
			
			return lado_a;
		}
		
		/*******************************************************************/
		// Método: LadoB()
		// Descripción: Calcula y devuelve el lado "b" del triángulo, el cual 
		//              es el segmento que une los vertices A y C del triángulo
		// Recibe: -
		// Devuelve: Lado "b" del triángulo (lado_b)
		/*******************************************************************/
		double LadoB() {
			
			double lado_b = vertice_A.DistanciaEuclidea(vertice_C);
			
			return lado_b;
		}
		
		/*******************************************************************/
		// Método: LadoC()
		// Descripción: Calcula y devuelve el lado "c" del triángulo, el cual 
		//              es el segmento que une los vertices A y B del triángulo
		// Recibe: -
		// Devuelve: Lado "c" del triángulo (lado_c)
		/*******************************************************************/
		double LadoC() {
			
			double lado_c = vertice_A.DistanciaEuclidea(vertice_B);
			
			return lado_c;
		}
		
		/*******************************************************************/
		// Método: EsRectangulo()
		// Descripción: Comprueba si un triangulo es rectangulo. Para ello,
		//              primero suponemos que es rectángulo y establecemos
		//              el lado de mayor longitud como la hipotenusa y 
		//              los otros dos como catetos. Finalmente, vemos si se
		//              verifica el Teorema de Pitágoras para ver si realmente
		//              el triángulo es rectángulo.
		// Recibe: -
		// Devuelve: True (1) si el triángulo es rectángulo y False (0) si no
		//           lo es
		/*******************************************************************/
		bool EsRectangulo() {
			
			double hipotenusa;
			double cateto1, cateto2;
			
			if( ( LadoA() > LadoB() ) && ( LadoA() > LadoC() ) ) {
				hipotenusa = LadoA();
				cateto1 = LadoB();
				cateto2 = LadoC();
			}
			else if( ( LadoB() > LadoA() ) && ( LadoB() > LadoC() ) ) {
				hipotenusa = LadoB();
				cateto1 = LadoA();
				cateto2 = LadoC();
			}
			else if( ( LadoC() > LadoA() ) && ( LadoC() > LadoB() ) ) {
				hipotenusa = LadoC();
				cateto1 = LadoA();
				cateto2 = LadoB();
			}
			
			bool es_rectangulo = SonIguales( (hipotenusa * hipotenusa), 
			                       (cateto1 * cateto1) + (cateto2 * cateto2) );
			
			return es_rectangulo;
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con los vértices del triángulo
		// Recibe: -
		// Devuelve: String con los vértices del triángulo (cadena)
		/*******************************************************************/
		string ToString() {
			
			string cadena;
			
			cadena = cadena + "\t Vertice A =  " + vertice_A.ToString() + "\n" 
			                + "\t Vertice B =  " + vertice_B.ToString() + "\n" 
							+ "\t Vertice C =  " + vertice_C.ToString();
					 
			return cadena;
		}
};

/***************************************************************************/
// Clase Rectangulo: representa un rectangulo en el plano
/***************************************************************************/
class Rectangulo {
	
	private:
		
		Punto2D esquina_sup_izq;   // Esquina superior izquierda del rectángulo
		
		// PRE: 0 < altura
		// PRE: 0 < base
		double base;			   // Base del rectángulo
		double altura;			   // Altura del rectángulo
		
	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Rectangulo() : esquina_sup_izq( Punto2D(0.0, 0.0) ), 
		               base(1.0), altura(1.0) { }
		
		/*******************************************************************/
		// Constructor con dos parámetros
		/*******************************************************************/
		Rectangulo(double longitud_base, double longitud_altura)
		          : esquina_sup_izq( Punto2D(0.0, 0.0) ), 
				    base(longitud_base), altura(longitud_altura) { }
		
		/*******************************************************************/
		// Constructor con res parámetros
		/*******************************************************************/   
		Rectangulo(Punto2D valor_esquina_sup_izq, double longitud_base, 
		           double longitud_altura)
                  : esquina_sup_izq(valor_esquina_sup_izq), 
				    base(longitud_base), altura(longitud_altura) { }
		
		/*******************************************************************/
		// Método: SetEsquinaSupIzq()
		// Descripción: Establece la esquina superior izquierda del rectángulo
		// Recibe: Esquina superior izquierda del rectángulo 
		//         (valor_esquina_sup_izq), 
		// Devuelve: -
		/*******************************************************************/
		void SetEsquinaSupIzq(Punto2D valor_esquina_sup_izq) {
			
			esquina_sup_izq.SetCoordenadas( valor_esquina_sup_izq.GetX(), 
			                                valor_esquina_sup_izq.GetY() );
		}
		
		/*******************************************************************/
		// Método: SetBase()
		// Descripción: Establece la base del rectángulo
		// Recibe: Base del rectángulo (longitud_base), 
		// Devuelve: -
		// PRE: 0 < longitud_base
		/*******************************************************************/
		void SetBase(double longitud_base) {
			
			base = longitud_base;
		}
		
		/*******************************************************************/
		// Método: SetAltura()
		// Descripción: Establece la altura del rectángulo
		// Recibe: Altura del rectángulo (longitud_altura), 
		// Devuelve: -
		// PRE: 0 < longitud_altura
		/*******************************************************************/
		void SetAltura(double longitud_altura) {
			
			altura = longitud_altura;	
		}
		
		/*******************************************************************/
		// Método: GetEsquinaSupIzq()
		// Descripción: Devuelve la esquina superior izquierda del rectángulo
		// Recibe: -
		// Devuelve: Esquina superior izquierda del rectángulo 
		//           (esquina_sup_izq)
		/*******************************************************************/
		Punto2D GetEsquinaSupIzq() {
			
			return esquina_sup_izq;
		}
		
		/*******************************************************************/
		// Método: GetBase()
		// Descripción: Devuelve la base del rectángulo
		// Recibe: -
		// Devuelve: Base del rectángulo (base)
		/*******************************************************************/
		double GetBase() {
			
			return base;	
		}
		
		/*******************************************************************/
		// Método: GetAltura()
		// Descripción: Devuelve la altura del rectángulo
		// Recibe: -
		// Devuelve: Altura del rectángulo (altura)
		/*******************************************************************/
		double GetAltura() {
			
			return altura;
		}
		
		/*******************************************************************/
		// Método: EsquinaSupDer()
		// Descripción: Calcula y devuelve la esquina superior derecha 
		//              del rectángulo
		// Recibe: -
		// Devuelve: Esquina superior derecha del rectángulo 
		//           (esquina_sup_der)
		/*******************************************************************/
		Punto2D EsquinaSupDer() {
			
			Punto2D esquina_sup_der(esquina_sup_izq.GetX() + base,
			                        esquina_sup_izq.GetY());
			                        
			return esquina_sup_der;
		}
		
		/*******************************************************************/
		// Método: EsquinaInfIzq()
		// Descripción: Calcula y devuelve la esquina inferior izquierda 
		//              del rectángulo
		// Recibe: -
		// Devuelve: Esquina inferior izquierda del rectángulo 
		//           (esquina_inf_izq)
		/*******************************************************************/
		Punto2D EsquinaInfIzq() {
			
			Punto2D esquina_inf_izq(esquina_sup_izq.GetX(), 
			                        esquina_sup_izq.GetY() - altura);
			
			return esquina_inf_izq;
		}
		
		/*******************************************************************/
		// Método: EsquinaInfDer()
		// Descripción: Calcula y devuelve la esquina inferior derecha 
		//              del rectángulo
		// Recibe: -
		// Devuelve: Esquina inferior derecha del rectángulo 
		//           (esquina_inf_der)
		/*******************************************************************/
		Punto2D EsquinaInfDer() {
			
			Punto2D esquina_inf_der(esquina_sup_izq.GetX() + base,
			                        esquina_sup_izq.GetY() - altura);
			                        
			return esquina_inf_der;
		}
		
		/*******************************************************************/
		// Método: PuntoCentral()
		// Descripción: Calcula y devuelve el punto central del rectángulo
		// Recibe: -
		// Devuelve: Punto central del rectángulo (punto_central)
		/*******************************************************************/
		Punto2D PuntoCentral() {
			
			Punto2D punto_central( ( esquina_sup_izq.GetX() + 
			                         EsquinaSupDer().GetX() ) / 2.0,
			                       ( esquina_sup_izq.GetY() + 
								     EsquinaInfIzq().GetY() ) / 2.0 );	
			                       	
			return punto_central;
		}
		
		/*******************************************************************/
		// Método: Perimetro()
		// Descripción: Calcula y devuelve el perímetro del rectángulo
		// Recibe: -
		// Devuelve: Perímetro del rectángulo (perimetro)
		/*******************************************************************/
		double Perimetro() {
			
			double perimetro = 2 * (base + altura);
			
			return perimetro;
		}
		
		/*******************************************************************/
		// Método: Area()
		// Descripción: Calcula y devuelve el área del rectángulo
		// Recibe: -
		// Devuelve: Área del rectángulo (area)
		/*******************************************************************/
		double Area() {
			
			double area = base * altura;
			
			return area;
		}
		
		/*******************************************************************/
		// Método: Contiene()
		// Descripción: Comprueba si un punto del plano está contenido en
		//              un rectángulo
		// Recibe: Punto del plano (punto)
		// Devuelve: True (1) si el rectángulo contiene al punto y
		//           False (0) si no lo contiene
		/*******************************************************************/
		bool Contiene(Punto2D punto) {
	
			bool punto_pertenece_a_rectangulo =  false;
	
			if( ( punto.GetX() >= esquina_sup_izq.GetX() ) &&
			    ( punto.GetX() <= (esquina_sup_izq.GetX() + base) )  && 
			    ( punto.GetY() <= esquina_sup_izq.GetY() ) && 
				( punto.GetY() >= (esquina_sup_izq.GetY() - altura) ) ) {
				  	
			    	punto_pertenece_a_rectangulo = true;
			}
	    	
			return punto_pertenece_a_rectangulo;
		}
		
		/*******************************************************************/
		// Método: TrianguloInferior()
		// Descripción: Calcula y devuelve el triángulo inferior de un 
		//              rectángulo, considerando su diagonal principal
		// Recibe: -
		// Devuelve: Triángulo inferior del rectángulo, considerando su 
		//           diagonal principal (triangulo_inf)
		/*******************************************************************/
		Triangulo TrianguloInferior() {
			
			Triangulo triangulo_inf( EsquinaInfIzq(), 
			                         esquina_sup_izq, 
			                         EsquinaInfDer() );
			
			return triangulo_inf;
		}
		
		/*******************************************************************/
		// Método: TrianguloSuperior()
		// Descripción: Calcula y devuelve el triángulo superior de un 
		//              rectángulo, considerando su otra diagonal respecto
		//              la diagonal principal
		// Recibe: -
		// Devuelve: Triángulo superior del rectángulo, considerando su 
		//           otra diagonal respecto la diagonal principal 
		//           (triangulo_sup)
		/*******************************************************************/
		Triangulo TrianguloSuperior() {
			
			Triangulo triangulo_sup( EsquinaInfIzq(), 
			                         esquina_sup_izq, 
									 EsquinaSupDer() );
			
			return triangulo_sup;
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con la esquina superior izquierda,
		//              la base y la altura del rectángulo
		// Recibe: -
		// Devuelve: String con con la esquina superior izquierda,
		//           la base y la altura del rectángulo (cadena)
		/*******************************************************************/
		string ToString() {
			
			string cadena;
			
			cadena = cadena + "\t Esquina superior izquierda =  " 
			                + esquina_sup_izq.ToString() + "\n" 
							+ "\t Base = " + to_string(base) + "\n" 
							+ "\t Altura = " + to_string(altura);
					 
			return cadena;
		}
};

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
    cout.setf(ios::fixed);        // Notación de punto fijo para los reales
    cout.setf(ios::showpoint);    // Mostrar siempre decimales 

    // Crear un rectángulo
    
    Rectangulo r(Punto2D(10, 8), 6, 2);

    cout << " Rectangulo:" << endl << endl;
    cout << r.ToString() << endl << endl;

    cout << "\t Area = " << r.Area() << endl;
    cout << "\t Perimetro = " << r.Perimetro() << endl;
    cout << endl << endl;
    
    // Pruebas de pertenencia a un rectángulo
    
    cout << " Pertenencia a Rectangulo: " << endl << endl;    
    cout << ( Punto2D(12, 11).ToString() ) << " --> " 
         << ( ( r.Contiene(Punto2D(12, 11) ) ) ? "SI":"NO") << endl; 
    cout << ( Punto2D(9, 8).ToString() ) << " --> " 
         << ( ( r.Contiene(Punto2D(9, 8) ) ) ? "SI":"NO") << endl; 
    cout << ( Punto2D(16, 8).ToString() ) << " --> " 
         << ( ( r.Contiene(Punto2D(16, 8) ) ) ? "SI":"NO") << endl; 
    cout << endl;
    
    // Crear un triángulo
    
    Triangulo t( Punto2D(12, 7), Punto2D(17, 11), Punto2D(20, 7) );
    
    cout << " Triangulo:" << endl << endl;
    cout << t.ToString() << endl << endl;        
    cout << "\t Perimetro = " << t.Perimetro() << endl;    
    cout << endl << endl;    
    
    // Crear otro triángulo (el cual es rectángulo)
    
    Triangulo tr( Punto2D(10, 3), Punto2D(10, 6), Punto2D(16, 6) );

    cout << " Triangulo rectangulo:" << endl << endl;    
    cout << tr.ToString() << endl;    
    cout << endl << endl;
    
    if( tr.EsRectangulo() )
    	cout << "\t El triangulo introducido es rectangulo.";
    else
    	cout << "\t El triangulo introducido no es rectangulo.";
    	
    cout << endl << endl;
    
    // Crear un triángulo a partir de un rectángulo (triángulo inferior) 
    
    Triangulo t_inf = r.TrianguloInferior();

    cout << " Triangulo inferior del rectangulo:" << endl << endl;    
    cout << t_inf.ToString() << endl;    
    cout << endl << endl;
    
    // Crear otro triángulo a partir de un rectángulo (triángulo superior) 
    
    Triangulo t_sup = r.TrianguloSuperior();

    cout << " Triangulo superior del rectangulo:" << endl << endl;    
    cout << t_sup.ToString() << endl;    
    cout << endl << endl; 
        
    return 0;
}
