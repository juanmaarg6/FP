/*
	Ejercicio 18: Programa que pasa un carácter (dígito entre '0' y '9')
				     a un número entero.
					  


	Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){	

	const string SEPARADOR = "\n\n-------------------------------------";

	// Apartado a)

	bool apartado_a = 2 + 3 < 5 + 8;
	cout << "Apartado a)";
   cout << "\n\n\t2 + 3 < 5 + 8: " << apartado_a;
   cout << SEPARADOR;
    
   // Devuelve un dato de tipo: booleano
	// Muestra en pantalla: 1 (true)
	// Expresión: Correcta pero es recomendable colocar paréntesis --> (2 + 3) < (5 + 8)
    
   // Apartado b)

   bool apartado_b = 2 < 3 < 4;
	cout << "\n\nApartado b)";
   cout << "\n\n\t2 < 3 < 4: " << apartado_b;
   cout << SEPARADOR;    
   
   // Devuelve un dato de tipo: booleano
	// Muestra en pantalla: 1 (true)
	// Expresión: Incorrecta. Si cambiamos el 2 por el 3 (3 < 2 < 4), devuelve 1 (true). Debería devolver 0 (false)
    
   // Apartado c)
   
   double apartado_c = 7/3 + 4.0;
	cout << "\n\nApartado c)";
   cout << "\n\n\t7/3 + 4.0: " << apartado_c;
   cout << SEPARADOR;    

   // Devuelve un dato de tipo: entero
	// Muestra en pantalla: 6
	// Expresión: Incorrecta. Si queremos obtener el verdadero resultado (6.3333...) hay que sustituir 7/3 (devuelve 2) por 7.0/3.0 (devuelve 2.3333...)
	
	// Apartado d)
   
   int x_1 = 4, y = 4, z_1 = 4;
   bool apartado_d = x_1 == 4 && y == 3 || z_1 != 2 == 1 != 2;
   cout << "\n\nApartado d)";
   cout << "\n\n\tx == 4 && y == 3 || z != 2 == 1 != 2: " << apartado_d;
   cout << SEPARADOR;
   
   // Devuelve un dato de tipo: booleano
	// Muestra en pantalla: 1 (true)
	// Expresión: Colocar paréntesis --> ((x_1 == 4) && (y == 3)) || ((z_1 != 2) == (1 != 2))
	
	// Apartado e)
   
   int x_2;
   bool apartado_e = x_2 <= 4 || x_2 >= 4;
   cout << "\n\nApartado e)";
   cout << "\n\n\tx <= 4 || x >= 4: " << apartado_e;
   cout << SEPARADOR;
   
   // Devuelve un dato de tipo: booleano
	// Muestra en pantalla: 1 (true)
	// Expresión: Correcta
	
	// Apartado f)
   
   int x_3;
   bool apartado_f = x_3 < 4 && x_3 > 4;
   cout << "\n\nApartado f)";
   cout << "\n\n\tx < 4 && x > 4: " << apartado_f;
   cout << SEPARADOR;
   
   // Devuelve un dato de tipo: booleano
	// Muestra en pantalla: 0 (false)
	// Expresión: Correcta
	
	// Apartado g)
   
   int z_2 = 7;
   char a;
   bool apartado_g = z_2 > 6 || a < 'z' && a > 'a' || z_2 < 6;
   cout << "\n\nApartado g)";
   cout << "\n\n\tz > 6 || a < 'z' && a > 'a' || z < 6: " << apartado_g;
   cout << SEPARADOR << "\n\n";
   
   // Devuelve un dato de tipo: booleano
	// Muestra en pantalla: 1 (true)
	// Expresión: Colocar paréntesis. En función del valor de z_2 y de cómo coloquemos dichos paréntesis, devolverá 1 (true) o 0 (false)
		// Para z_2 = 7 --> (z_2 > 6 || a < 'z') && (a > 'a' || z_2 < 6) devuelve: 0 (false)
		// Para z_2 = 7 --> z_2 > 6 || (a < 'z' && a > 'a') || z_2 < 6 devuelve: 1 (true)
    
	system("pause");
}
