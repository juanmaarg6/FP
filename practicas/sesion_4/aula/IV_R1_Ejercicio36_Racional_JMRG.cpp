/*
   Ejercicio 36: Programa que:
   
                 a) Inicializa un número racional introducido por el usuario.
                 b) Simplifica dicho número racional a su fracción irreducible.
                 c) Suma dos números racionales.
                 d) Multiplica dos números racionales.
                 e) "Evalua" un número racional, es decir, devuelve la división
                    del numerador entre el denominador.
                    
   Código fuente escrito por Juan Manuel Rodríguez Gómez
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Estructura de un nuevo tipo de dato (Racional)

struct Racional{
   int numerador, denominador; 
   int numerador_reducido, denominador_reducido;
};

int main(){
   
   // Declaración de variables
   
   Racional racional1, racional2;
   int suma_numerador, suma_denominador;
   int multiplicacion_numerador, multiplicacion_denominador;
   double evaluacion_racional;
   int mcd_reduccion, mcd_suma, mcm_suma;
   bool denominadores_iguales;
   
   /*
   	********************
   	    APARTADO A)
   	********************

		Introducción de un número racional por parte del usuario (racional1).
		Muestra en pantalla de racional1.	
   */
   
   cout << "\n Introduzca el numerador del numero racional 1: ";
   cin >> racional1.numerador;
   
   cout << " Introduzca el denominador del numero racional 1: ";
   cin >> racional1.denominador;
   
   cout << "\n El numero racional 1 introducido es: " << racional1.numerador << "/" << racional1.denominador;
   
   /*
   	********************
   	    APARTADO B)
   	********************

		Fracción irreducible del número racional 1:
		
		Calcular el máximo común divisor (mcd_reduccion) del numerador y el denominador.
		Dividir el numerador por el mcd (se obtiene el numerador de la fracción irreducible).
		Dividir el denominador por el mcd (se obtiene el denominador de la fracción irreducible).
		Muestra en pantalla de la fracción irreducible del número racional 1.
   */
   
   mcd_reduccion = __gcd(racional1.numerador, racional1.denominador);
   racional1.numerador_reducido = racional1.numerador / mcd_reduccion;
   racional1.denominador_reducido = racional1.denominador / mcd_reduccion;
   
   cout << "\n\n La fraccion irreducible de " <<  racional1.numerador << "/" << racional1.denominador << " es: " << racional1.numerador_reducido << "/" << racional1.denominador_reducido;
   
   /*
   	********************
   	    APARTADO C)
   	********************

		Suma de dos números racionales:
		
		Introducción de otro número racional por parte del usuario (racional2).
		Muestra en pantalla de racional2.
		Calcular el máximo común divisor (mcd_suma) de los denominadores de racional1 y racional2.
		Calcular el mínimo común múltiplo (mcm_suma) de los denominadores. Para ello:
		
			            mcd(a, b) * mcm(a, b) = a * b
			            
		Calcular la suma de los numeradores.
		Mostrar en pantalla la suma de racional1 y racional2.
   */
   
   
   cout << "\n\n Introduzca el numerador del numero racional 2: ";
   cin >> racional2.numerador;
   
   cout << " Introduzca el denominador del numero racional 2: ";
   cin >> racional2.denominador;
   
   cout << "\n El segundo numero racional introducido es: " << racional2.numerador << "/" << racional2.denominador; 
   
	mcd_suma = __gcd(racional1.denominador, racional2.denominador);
   mcm_suma = (racional1.denominador * racional2.denominador) / mcd_suma;
   
   denominadores_iguales = racional1.denominador == racional2.denominador;
   
   if (denominadores_iguales){
	   suma_numerador = racional1.numerador + racional2.numerador;
	}
	
	else{
	   suma_numerador = ((mcm_suma / racional1.denominador) * racional1.numerador) + ((mcm_suma / racional2.denominador) * racional2.numerador);
	}
	
	suma_denominador = mcm_suma;


   cout << "\n\n La suma de ambos numeros racionales es:";
   cout << "\n\n\t" << racional1.numerador << "/" << racional1.denominador << " + " << racional2.numerador << "/" << racional2.denominador << " = " << suma_numerador << "/" << suma_denominador;
   
   /*
   	********************
   	    APARTADO D)
   	********************

		Multiplicación de dos números racionales:
		
		Multiplicar los numeradores de racional1 y racional2
		Multiplicar los denominadores de racional1 y racional2.		
		Mostrar en pantalla la multiplicación de racional1 y racional2.
   */
   
   multiplicacion_numerador = racional1.numerador * racional2.numerador;
   multiplicacion_denominador = racional1.denominador * racional2.denominador;
   
   cout << "\n\n La multiplicacion de ambos numeros racionales es:";
   cout << "\n\n\t" << racional1.numerador << "/" << racional1.denominador << " * " << racional2.numerador << "/" << racional2.denominador << " = " << multiplicacion_numerador << "/" << multiplicacion_denominador;
   
   /*
   	********************
   	    APARTADO D)
   	********************

		"Evaluación" de un número racional:
		
		División de numerador y denominador. 
		Se suma 0.0 al numerador para que el resultado de la división sea real y no entero.
   */
   
   evaluacion_racional = (racional1.numerador + 0.0) / racional1.denominador;
   
   cout << "\n\n La evaluacion del numero racional 1 es:";
   cout << "\n\n\t" << racional1.numerador << "/" << racional1.denominador << " = " << evaluacion_racional << endl << endl;
   
   system("pause");
}
