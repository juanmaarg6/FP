/*
	Relaci�n de ejercicios 6

	Ejercicio 22:	Usando como referencia la clase Punto2D para representar 
	                un punto en el plano, dise�amos e implementamos las clases 
					Rectangulo y Triangulo.

					Nota: Consideramos �nicamente rect�ngulos cuyos lados 
					      sean paralelos a los ejes de coordenadas. No hay 
						  restricciones para los tri�ngulos.
						  
					Usamos las propiedades siguientes para la clase Rectangulo:
					
						1) esi, esquina superior izquierda (de la clase 
						   Punto2D).
						2) b, longitud de la base (double).
						3) a, longitud de la altura (double).

					Para la representaci�n de la clase Triangulo usamos las 
					coordenadas de sus tres v�rtices (V_A, V_B, V_C).
					
					Adem�s de los constructores y los m�todos Get oportunos,
					a�adimos el siguiente conjunto m�nimo de m�todos:

						a) Calcular el �rea del rect�ngulo.
						b) Calcular el per�metro del rect�ngulo.
						c) Calcular si un punto est� dentro de un rect�ngulo.
						d) Calcular el per�metro del tri�ngulo.
						e) Calcular si un tri�ngulo es rect�ngulo.
						f) Obtener el tri�ngulo inferior de un rect�ngulo, 
						   considerando su diagonal principal.
						g) Obtener el tri�ngulo superior de un rect�ngulo, 
						   considerando su otra diagonal.
	              
	Entradas: Rect�ngulo (r),
	          Tri�ngulo (t),
	          Tri�ngulo rect�ngulo (tr).
	Salidas: Per�metro y �rea del rect�ngulo,
	         Comprobaci�n de si ciertos puntos del plano pertenecen al
	         rect�ngulo,
	         Per�metro del tri�ngulo,
	         Comprobaci�n si el tri�ngulo rect�ngulo es realmente rect�ngulo,
	         Tri�ngulo inferior del rect�ngulo, considerando su diagonal 
			 principal (t_inf),
	         Tri�ngulo superior del rect�ngulo, considerando su otra 
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
// Funci�n: SonIguales()
// Descripci�n: Funci�n global (asociada a la constante PRECISION_SON_IGUALES)
//              que permite que dos n�meros reales muy pr�ximos sean 
//              considerados iguales.
// Recibe: Dos n�meros reales (numero1, numero2)
// Devuelve: True (1) si los dos n�meros reales se consideran iguales y
//           False (0) si no es as�
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
		// Constructor sin par�metros
		/*******************************************************************/
		Punto2D() : x(0.0), y(0.0) { }

		/*******************************************************************/
		// Constructor con par�metros
		/*******************************************************************/
		Punto2D(double abscisaPunto, double ordenadaPunto) {
			
			SetCoordenadas (abscisaPunto, ordenadaPunto);
		}
		
		/*******************************************************************/
		// M�todo: SetCoordenadas()
		// Descripci�n: Establece las coordenadas de un punto del plano
		// Recibe: Abscisa del punto (abscisaPunto), 
		//         Ordenada del punto (ordenadaPunto)
		// Devuelve: -
		/*******************************************************************/
		void SetCoordenadas(double abscisaPunto, double ordenadaPunto) {
			
			x = abscisaPunto;
			y = ordenadaPunto;
		}
		
		/*******************************************************************/
		// M�todo: GetX()
		// Descripci�n: Devuelve la abscisa de un punto del plano
		// Recibe: -
		// Devuelve: Abscisa de un punto del plano (x)
		/*******************************************************************/
		double GetX() {
			
			return x;
		}
		
		/*******************************************************************/
		// M�todo: GetY()
		// Descripci�n: Devuelve la ordenada de un punto del plano
		// Recibe: -
		// Devuelve: Ordenada de un punto del plano (y)
		/*******************************************************************/
		double GetY() {
			
			return y;
		}
		
		/*******************************************************************/
		// M�todo: EsIgual()
		// Descripci�n: Comprueba si un punto del plano es igual al punto
		//              impl�cito
		// Recibe: Punto del plano (otro)
		// Devuelve: True (1) si los dos puntos son iguales y False (0) si
		//           no lo son
		/*******************************************************************/
		bool EsIgual(Punto2D otro) {
			
			return ( SonIguales(x, otro.x) && SonIguales(y, otro.y) );
		}
		
		/*******************************************************************/
		// M�todo: DistanciaEuclidea()
		// Descripci�n: Calcula la distancia eucl�dea del punto impl�cito 
		//              a otro punto del plano
		// Recibe: Punto del plano (otro)
		// Devuelve: Distancia eucl�dea entre los dos puntos.
		/*******************************************************************/
		double DistanciaEuclidea(Punto2D otro) {
			
			double dif_x = pow(x - otro.x, 2);
			double dif_y = pow(y - otro.y, 2);

			return ( sqrt(dif_x + dif_y) );
		}
		
		/*******************************************************************/
		// M�todo: ToString()
		// Descripci�n: Compone un string con las coordenadas del punto 
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
		
		Punto2D vertice_A;		// V�rtice A del tri�ngulo
		Punto2D vertice_B;		// V�rtice B del tri�ngulo
		Punto2D vertice_C;		// V�rtice C del tri�ngulo
		
	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Triangulo() : vertice_A(Punto2D(0.0,0.0)), 
		              vertice_B(Punto2D(1.0,0.0)),
					  vertice_C(Punto2D(0.0,1.0)) { }
		
		/*******************************************************************/
		// Constructor con par�metros
		/*******************************************************************/	  
		Triangulo(Punto2D valor_vertice_A, Punto2D valor_vertice_B, 
		          Punto2D valor_vertice_C)
		         : vertice_A(valor_vertice_A), vertice_B(valor_vertice_B), 
				   vertice_C(valor_vertice_C) { }
		
		/*******************************************************************/
		// M�todo: SetVerticeA()
		// Descripci�n: Establece el v�rtice A del tri�ngulo
		// Recibe: V�rtice A del tri�ngulo (valor_vertice_A)
		// Devuelve: -
		/*******************************************************************/
		void SetVerticeA(Punto2D valor_vertice_A) {
			
			vertice_A.SetCoordenadas( valor_vertice_A.GetX(), 
			                          valor_vertice_A.GetY() );
		}
		
		/*******************************************************************/
		// M�todo: SetVerticeB()
		// Descripci�n: Establece el v�rtice B del tri�ngulo
		// Recibe: V�rtice B del tri�ngulo (valor_vertice_B)
		// Devuelve: -
		/*******************************************************************/
		void SetVerticeB(Punto2D valor_vertice_B) {
			
			vertice_B.SetCoordenadas( valor_vertice_B.GetX(), 
			                          valor_vertice_B.GetY() );
		}
		
		/*******************************************************************/
		// M�todo: SetVerticeC()
		// Descripci�n: Establece el v�rtice C del tri�ngulo
		// Recibe: V�rtice C del tri�ngulo (valor_vertice_C)
		// Devuelve: -
		/*******************************************************************/
		void SetVerticeC(Punto2D valor_vertice_C) {
			
			vertice_C.SetCoordenadas( valor_vertice_C.GetX(), 
			                          valor_vertice_C.GetY() );
		}
		
		/*******************************************************************/
		// M�todo: GetVerticeA()
		// Descripci�n: Devuelve el v�rtice A del tri�ngulo
		// Recibe: -
		// Devuelve: V�rtice A del tri�ngulo (vertice_A)
		/*******************************************************************/
		Punto2D GetVerticeA() {
			
			return vertice_A;
		}
		
		/*******************************************************************/
		// M�todo: GetVerticeB()
		// Descripci�n: Devuelve el v�rtice B del tri�ngulo
		// Recibe: -
		// Devuelve: V�rtice B del tri�ngulo (vertice_B)
		/*******************************************************************/
		Punto2D GetVerticeB() {
			
			return vertice_B;
		}
		
		/*******************************************************************/
		// M�todo: GetVerticeC()
		// Descripci�n: Devuelve el v�rtice C del tri�ngulo
		// Recibe: -
		// Devuelve: V�rtice C del tri�ngulo (vertice_C)
		/*******************************************************************/
		Punto2D GetVerticeC() {
			
			return vertice_C;
		}
		
		/*******************************************************************/
		// M�todo: Perimetro()
		// Descripci�n: Calcula el per�metro del tri�ngulo
		// Recibe: -
		// Devuelve: Per�metro del tri�ngulo (perimetro)
		/*******************************************************************/
		double Perimetro() {
			
			double perimetro = ( vertice_A.DistanciaEuclidea(vertice_B) ) +
			                   ( vertice_B.DistanciaEuclidea(vertice_C) ) +
					           ( vertice_C.DistanciaEuclidea(vertice_A) );
			
			return perimetro;
		}
		
		/*******************************************************************/
		// M�todo: LadoA()
		// Descripci�n: Calcula y devuelve el lado "a" del tri�ngulo, el cual 
		//              es el segmento que une los vertices B y C del tri�ngulo
		// Recibe: -
		// Devuelve: Lado "a" del tri�ngulo (lado_a)
		/*******************************************************************/
		double LadoA() {
			
			double lado_a = vertice_B.DistanciaEuclidea(vertice_C);
			
			return lado_a;
		}
		
		/*******************************************************************/
		// M�todo: LadoB()
		// Descripci�n: Calcula y devuelve el lado "b" del tri�ngulo, el cual 
		//              es el segmento que une los vertices A y C del tri�ngulo
		// Recibe: -
		// Devuelve: Lado "b" del tri�ngulo (lado_b)
		/*******************************************************************/
		double LadoB() {
			
			double lado_b = vertice_A.DistanciaEuclidea(vertice_C);
			
			return lado_b;
		}
		
		/*******************************************************************/
		// M�todo: LadoC()
		// Descripci�n: Calcula y devuelve el lado "c" del tri�ngulo, el cual 
		//              es el segmento que une los vertices A y B del tri�ngulo
		// Recibe: -
		// Devuelve: Lado "c" del tri�ngulo (lado_c)
		/*******************************************************************/
		double LadoC() {
			
			double lado_c = vertice_A.DistanciaEuclidea(vertice_B);
			
			return lado_c;
		}
		
		/*******************************************************************/
		// M�todo: EsRectangulo()
		// Descripci�n: Comprueba si un triangulo es rectangulo. Para ello,
		//              primero suponemos que es rect�ngulo y establecemos
		//              el lado de mayor longitud como la hipotenusa y 
		//              los otros dos como catetos. Finalmente, vemos si se
		//              verifica el Teorema de Pit�goras para ver si realmente
		//              el tri�ngulo es rect�ngulo.
		// Recibe: -
		// Devuelve: True (1) si el tri�ngulo es rect�ngulo y False (0) si no
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
		// M�todo: ToString()
		// Descripci�n: Compone un string con los v�rtices del tri�ngulo
		// Recibe: -
		// Devuelve: String con los v�rtices del tri�ngulo (cadena)
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
		
		Punto2D esquina_sup_izq;   // Esquina superior izquierda del rect�ngulo
		
		// PRE: 0 < altura
		// PRE: 0 < base
		double base;			   // Base del rect�ngulo
		double altura;			   // Altura del rect�ngulo
		
	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Rectangulo() : esquina_sup_izq( Punto2D(0.0, 0.0) ), 
		               base(1.0), altura(1.0) { }
		
		/*******************************************************************/
		// Constructor con dos par�metros
		/*******************************************************************/
		Rectangulo(double longitud_base, double longitud_altura)
		          : esquina_sup_izq( Punto2D(0.0, 0.0) ), 
				    base(longitud_base), altura(longitud_altura) { }
		
		/*******************************************************************/
		// Constructor con res par�metros
		/*******************************************************************/   
		Rectangulo(Punto2D valor_esquina_sup_izq, double longitud_base, 
		           double longitud_altura)
                  : esquina_sup_izq(valor_esquina_sup_izq), 
				    base(longitud_base), altura(longitud_altura) { }
		
		/*******************************************************************/
		// M�todo: SetEsquinaSupIzq()
		// Descripci�n: Establece la esquina superior izquierda del rect�ngulo
		// Recibe: Esquina superior izquierda del rect�ngulo 
		//         (valor_esquina_sup_izq), 
		// Devuelve: -
		/*******************************************************************/
		void SetEsquinaSupIzq(Punto2D valor_esquina_sup_izq) {
			
			esquina_sup_izq.SetCoordenadas( valor_esquina_sup_izq.GetX(), 
			                                valor_esquina_sup_izq.GetY() );
		}
		
		/*******************************************************************/
		// M�todo: SetBase()
		// Descripci�n: Establece la base del rect�ngulo
		// Recibe: Base del rect�ngulo (longitud_base), 
		// Devuelve: -
		// PRE: 0 < longitud_base
		/*******************************************************************/
		void SetBase(double longitud_base) {
			
			base = longitud_base;
		}
		
		/*******************************************************************/
		// M�todo: SetAltura()
		// Descripci�n: Establece la altura del rect�ngulo
		// Recibe: Altura del rect�ngulo (longitud_altura), 
		// Devuelve: -
		// PRE: 0 < longitud_altura
		/*******************************************************************/
		void SetAltura(double longitud_altura) {
			
			altura = longitud_altura;	
		}
		
		/*******************************************************************/
		// M�todo: GetEsquinaSupIzq()
		// Descripci�n: Devuelve la esquina superior izquierda del rect�ngulo
		// Recibe: -
		// Devuelve: Esquina superior izquierda del rect�ngulo 
		//           (esquina_sup_izq)
		/*******************************************************************/
		Punto2D GetEsquinaSupIzq() {
			
			return esquina_sup_izq;
		}
		
		/*******************************************************************/
		// M�todo: GetBase()
		// Descripci�n: Devuelve la base del rect�ngulo
		// Recibe: -
		// Devuelve: Base del rect�ngulo (base)
		/*******************************************************************/
		double GetBase() {
			
			return base;	
		}
		
		/*******************************************************************/
		// M�todo: GetAltura()
		// Descripci�n: Devuelve la altura del rect�ngulo
		// Recibe: -
		// Devuelve: Altura del rect�ngulo (altura)
		/*******************************************************************/
		double GetAltura() {
			
			return altura;
		}
		
		/*******************************************************************/
		// M�todo: EsquinaSupDer()
		// Descripci�n: Calcula y devuelve la esquina superior derecha 
		//              del rect�ngulo
		// Recibe: -
		// Devuelve: Esquina superior derecha del rect�ngulo 
		//           (esquina_sup_der)
		/*******************************************************************/
		Punto2D EsquinaSupDer() {
			
			Punto2D esquina_sup_der(esquina_sup_izq.GetX() + base,
			                        esquina_sup_izq.GetY());
			                        
			return esquina_sup_der;
		}
		
		/*******************************************************************/
		// M�todo: EsquinaInfIzq()
		// Descripci�n: Calcula y devuelve la esquina inferior izquierda 
		//              del rect�ngulo
		// Recibe: -
		// Devuelve: Esquina inferior izquierda del rect�ngulo 
		//           (esquina_inf_izq)
		/*******************************************************************/
		Punto2D EsquinaInfIzq() {
			
			Punto2D esquina_inf_izq(esquina_sup_izq.GetX(), 
			                        esquina_sup_izq.GetY() - altura);
			
			return esquina_inf_izq;
		}
		
		/*******************************************************************/
		// M�todo: EsquinaInfDer()
		// Descripci�n: Calcula y devuelve la esquina inferior derecha 
		//              del rect�ngulo
		// Recibe: -
		// Devuelve: Esquina inferior derecha del rect�ngulo 
		//           (esquina_inf_der)
		/*******************************************************************/
		Punto2D EsquinaInfDer() {
			
			Punto2D esquina_inf_der(esquina_sup_izq.GetX() + base,
			                        esquina_sup_izq.GetY() - altura);
			                        
			return esquina_inf_der;
		}
		
		/*******************************************************************/
		// M�todo: PuntoCentral()
		// Descripci�n: Calcula y devuelve el punto central del rect�ngulo
		// Recibe: -
		// Devuelve: Punto central del rect�ngulo (punto_central)
		/*******************************************************************/
		Punto2D PuntoCentral() {
			
			Punto2D punto_central( ( esquina_sup_izq.GetX() + 
			                         EsquinaSupDer().GetX() ) / 2.0,
			                       ( esquina_sup_izq.GetY() + 
								     EsquinaInfIzq().GetY() ) / 2.0 );	
			                       	
			return punto_central;
		}
		
		/*******************************************************************/
		// M�todo: Perimetro()
		// Descripci�n: Calcula y devuelve el per�metro del rect�ngulo
		// Recibe: -
		// Devuelve: Per�metro del rect�ngulo (perimetro)
		/*******************************************************************/
		double Perimetro() {
			
			double perimetro = 2 * (base + altura);
			
			return perimetro;
		}
		
		/*******************************************************************/
		// M�todo: Area()
		// Descripci�n: Calcula y devuelve el �rea del rect�ngulo
		// Recibe: -
		// Devuelve: �rea del rect�ngulo (area)
		/*******************************************************************/
		double Area() {
			
			double area = base * altura;
			
			return area;
		}
		
		/*******************************************************************/
		// M�todo: Contiene()
		// Descripci�n: Comprueba si un punto del plano est� contenido en
		//              un rect�ngulo
		// Recibe: Punto del plano (punto)
		// Devuelve: True (1) si el rect�ngulo contiene al punto y
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
		// M�todo: TrianguloInferior()
		// Descripci�n: Calcula y devuelve el tri�ngulo inferior de un 
		//              rect�ngulo, considerando su diagonal principal
		// Recibe: -
		// Devuelve: Tri�ngulo inferior del rect�ngulo, considerando su 
		//           diagonal principal (triangulo_inf)
		/*******************************************************************/
		Triangulo TrianguloInferior() {
			
			Triangulo triangulo_inf( EsquinaInfIzq(), 
			                         esquina_sup_izq, 
			                         EsquinaInfDer() );
			
			return triangulo_inf;
		}
		
		/*******************************************************************/
		// M�todo: TrianguloSuperior()
		// Descripci�n: Calcula y devuelve el tri�ngulo superior de un 
		//              rect�ngulo, considerando su otra diagonal respecto
		//              la diagonal principal
		// Recibe: -
		// Devuelve: Tri�ngulo superior del rect�ngulo, considerando su 
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
		// M�todo: ToString()
		// Descripci�n: Compone un string con la esquina superior izquierda,
		//              la base y la altura del rect�ngulo
		// Recibe: -
		// Devuelve: String con con la esquina superior izquierda,
		//           la base y la altura del rect�ngulo (cadena)
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
// Funci�n principal
/***************************************************************************/
int main() {
	
    cout.setf(ios::fixed);        // Notaci�n de punto fijo para los reales
    cout.setf(ios::showpoint);    // Mostrar siempre decimales 

    // Crear un rect�ngulo
    
    Rectangulo r(Punto2D(10, 8), 6, 2);

    cout << " Rectangulo:" << endl << endl;
    cout << r.ToString() << endl << endl;

    cout << "\t Area = " << r.Area() << endl;
    cout << "\t Perimetro = " << r.Perimetro() << endl;
    cout << endl << endl;
    
    // Pruebas de pertenencia a un rect�ngulo
    
    cout << " Pertenencia a Rectangulo: " << endl << endl;    
    cout << ( Punto2D(12, 11).ToString() ) << " --> " 
         << ( ( r.Contiene(Punto2D(12, 11) ) ) ? "SI":"NO") << endl; 
    cout << ( Punto2D(9, 8).ToString() ) << " --> " 
         << ( ( r.Contiene(Punto2D(9, 8) ) ) ? "SI":"NO") << endl; 
    cout << ( Punto2D(16, 8).ToString() ) << " --> " 
         << ( ( r.Contiene(Punto2D(16, 8) ) ) ? "SI":"NO") << endl; 
    cout << endl;
    
    // Crear un tri�ngulo
    
    Triangulo t( Punto2D(12, 7), Punto2D(17, 11), Punto2D(20, 7) );
    
    cout << " Triangulo:" << endl << endl;
    cout << t.ToString() << endl << endl;        
    cout << "\t Perimetro = " << t.Perimetro() << endl;    
    cout << endl << endl;    
    
    // Crear otro tri�ngulo (el cual es rect�ngulo)
    
    Triangulo tr( Punto2D(10, 3), Punto2D(10, 6), Punto2D(16, 6) );

    cout << " Triangulo rectangulo:" << endl << endl;    
    cout << tr.ToString() << endl;    
    cout << endl << endl;
    
    if( tr.EsRectangulo() )
    	cout << "\t El triangulo introducido es rectangulo.";
    else
    	cout << "\t El triangulo introducido no es rectangulo.";
    	
    cout << endl << endl;
    
    // Crear un tri�ngulo a partir de un rect�ngulo (tri�ngulo inferior) 
    
    Triangulo t_inf = r.TrianguloInferior();

    cout << " Triangulo inferior del rectangulo:" << endl << endl;    
    cout << t_inf.ToString() << endl;    
    cout << endl << endl;
    
    // Crear otro tri�ngulo a partir de un rect�ngulo (tri�ngulo superior) 
    
    Triangulo t_sup = r.TrianguloSuperior();

    cout << " Triangulo superior del rectangulo:" << endl << endl;    
    cout << t_sup.ToString() << endl;    
    cout << endl << endl; 
        
    return 0;
}
