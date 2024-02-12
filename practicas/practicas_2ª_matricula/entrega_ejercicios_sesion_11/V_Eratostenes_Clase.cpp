/*
	Relación de ejercicios 5

	Ejercicio 22: La criba de Eratóstenes permite hallar todos los números
				  primos menores que un número natural dado n. Hemos trabajado 
				  sobre este problema en el ejercicio 14 de la Relación de 
				  Ejercicios IV.

				  En esta ocasión se trata de definir una clase llamada 
				  Eratostenes. Un objeto de la clase podrá almacenar los 
				  números primos calculados en un vector de enteros:
				  
					// Todos los primos calculados serán menores que TAMANIO.
				  	static const int TAMANIO = 500;
				  	int vector_privado[TAMANIO];

                  	// PRE: 0 <= total_utilizados <= TAMANIO
                  	int total_utilizados; // Número de casillas ocupadas
	              
	              La clase ofrecerá, al menos, estos métodos:
                  
				  	1) void CalculaHasta(int n) para que calcule los primos 
				       menores que n. Este es el método que implementa el 
					   algoritmo de Eratóstenes. Cuando se ejecute el método, 
					   se almacenarán en un vector interno del objeto todos 
					   los primos menores que n.
				  
				  	2) int TotalCalculados() que devuelva cuántos primos hay 
				       actualmente almacenados.

                  	3) int Elemento(int k) para que devuelva el k-ésimo primo.
                  	
					4) int GetMaximo() que devuelva el máximo valor de la 
				       criba, n: todos los primos almacenados son menores 
					   que él.
				     
				  Un programa que use esta clase podría ser, esquemáticamente:
				  
				  	Eratostenes primos;
                    int n = 100;

				    primos.CalculaHasta(n);
					int tope = primos.TotalCalculados();
					
					for (int i=0; i<tope; i++)
						cout << primos.Elemento(i) << " ";
						
	Entradas: Número hasta el cual queremos calcular todos los primos
	          menores que él (n).
	Salidas: Números primos hasta un número "n" dado.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>

using namespace std;


/***************************************************************************/
// Clase ManipuladorString: permite modificar un string
/***************************************************************************/
class ManipuladorString {
	
	private:
		
		string cadena;		// Cadena que queremos manipular
		
	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		ManipuladorString() {
			
			cadena = "";
		}
		
		/*******************************************************************/
		// Constructor con parámetros
		/*******************************************************************/
		ManipuladorString(string la_cadena) : cadena(la_cadena) { }
		
		/*******************************************************************/
		// Método: SetCadena()
		// Descripción: Establece el texto que va a almacenar "cadena"
		// Recibe: Texto que va a almacenar "cadena" (la_cadena)
		// Devuelve: -
		/*******************************************************************/
		void SetCadena(string la_cadena) {
			
			cadena = la_cadena;	
		}
		
		/*******************************************************************/
		// Método: GetCadena()
		// Descripción: Devuelve el texto almacenado en "cadena"
		// Recibe: -
		// Devuelve: Texto almacenado en "cadena" (cadena)
		/*******************************************************************/
		string GetCadena() {
			
			return cadena;	
		}

		/*******************************************************************/
		// Método: EliminaPrimerosSeparadores()
		// Descripción: Elimina los caracteres separadores iniciales 
		//              de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaPrimerosSeparadores() {	
		
			int pos = 0;
			
			int longitud_cadena = cadena.length();
			
			while( ( pos < longitud_cadena ) && ( isspace(cadena.at(pos)) ) ) 
				pos++;
			
			cadena = cadena.substr(pos, cadena.length()-pos);
		}
		
		/*******************************************************************/
		// Método: EliminaUltimosSeparadores()
		// Descripción: Elimina los caracteres separadores finales de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaUltimosSeparadores() {
		
		   	while( ( cadena.length() > 0 ) && ( isspace(cadena.back()) ) )
				cadena.pop_back();
		}
		
		/*******************************************************************/
		// Método: EliminaSeparadoresInicialesyFinales()
		// Descripción: Elimina los caracteres separadores iniciales y 
		//              finales de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaSeparadoresInicialesyFinales() {	
		
			EliminaPrimerosSeparadores();
			EliminaUltimosSeparadores();
		}		
		
		/*******************************************************************/
		// Método: CuentaPalabras()
		// Descripción: Devuelve el número de palabras que forman "cadena"
		// Recibe: -
		// Devuelve: Número de palabras que forman "cadena" (cont_palabras)
		/*******************************************************************/
		int CuentaPalabras() {
			
			ManipuladorString manip_local(cadena);
			manip_local.EliminaSeparadoresInicialesyFinales();
			string cadena_limpia = manip_local.GetCadena();
			
			int cont_palabras = 0;
			int longitud_cadena = cadena_limpia.length();
			
			if(longitud_cadena > 0) {				
				
				if( isalnum(cadena_limpia.at(0)) )
		   			cont_palabras++;
		
				for (int i = 1; i < longitud_cadena; i++)
		   			if( (isalnum(cadena_limpia.at(i)) ) && 
					    (!isalnum(cadena_limpia.at(i-1))) )
		       			cont_palabras++;
		    }
		    
		    return cont_palabras;
        }

		/*******************************************************************/
		// Método: ConvierteAMayusculas()
		// Descripción: Convierte todos los caracteres de "cadena" a mayúsculas
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void ConvierteAMayusculas() {
			
			int longitud_cadena = cadena.length();
			
			for(int i = 0; i < longitud_cadena; i++)
				cadena.at(i) = toupper(cadena.at(i));
		}
		
		/*******************************************************************/
		// Método: ConvierteAMinusculas()
		// Descripción: Convierte todos los caracteres de "cadena" a minúsculas
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void ConvierteAMinusculas() {
			
			int longitud_cadena = cadena.length();
			
			for(int pos = 0; pos < longitud_cadena; pos++)
				cadena.at(pos) = tolower(cadena.at(pos));
		}
};

/***************************************************************************/
// Clase Eratostenes: permite calcular los números primos hasta un número
//                    "n" dado, mediante la Criba de Eratóstenes
/***************************************************************************/
class Eratostenes {
	
	private:
		
		static const int TAMANIO = 500; // Número casillas disponibles
	    int vector_privado[TAMANIO];
	
	    // PRE: 0 <= total_utilizados <= TAMANIO
	    int total_utilizados; 			// Número de casillas ocupadas
	
	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Eratostenes() : total_utilizados(0) { }
		
		/*******************************************************************/
		// Método: CalculaHasta()
		// Descripción: Calcula los números primos menores que "n"
		// Recibe: Número hasta el cual queremos calcular todos los
		//         números primos menores que él
		// Devuelve: -
		// PRE: 0 <= n <= TAMANIO
		/*******************************************************************/
		void CalculaHasta(int n) {
			
			bool es_primo[TAMANIO]; 
			
			for(int i = 0; i < n; i++) 
				es_primo[i] = true;
			
			for(int num = 2; num*num <= n; num++)	
				if(es_primo[num]) 
					for(int k = 2; k*num <= n; k++)
						es_primo[k*num] = false;
						
			for(int i = 1; i < n; i++)
				if(es_primo[i]) {
					vector_privado[total_utilizados] = i;
					total_utilizados++;
				}
		}
		
		/*******************************************************************/
		// Método: TotalCalculados()
		// Descripción: Devuelve cuántos primos hay almacenados
		// Recibe: -
		// Devuelve: Número de primos almacenados (total_utilizados)
		/*******************************************************************/
		int TotalCalculados() {
			
			return total_utilizados;	
		}
		
		/*******************************************************************/
		// Método: Elemento()
		// Descripción: Devuelve el primo k-ésimo
		// Recibe: Casilla del vector que almacena el número primo que
		//         queremos obtener (k)
		// Devuelve: Primo k-ésimo (vector_privado[k])
		// PRE: 0 <= k < total_utilizados
		/*******************************************************************/
		int Elemento(int k) {
			
			return vector_privado[k];	
		}
		
		/*******************************************************************/
		// Método: GetMaximo()
		// Descripción: devuelva el máximo valor de la criba
		// Recibe: -
		// Devuelve: Máximo valor de la criba 
		//           (vector_privado[total_utilizados-1])
		/*******************************************************************/
		int GetMaximo() {
			
			return vector_privado[total_utilizados-1];	
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con todos los primos que están
		//              almacenados en la criba y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los primos que están almacenados
		//           en la criba (cadena)
		/*******************************************************************/
		string ToString() {
			
			string cadena;
						
			for(int i = 0; i < total_utilizados; i++)
				cadena = cadena + to_string(vector_privado[i]) + " ";
		
			return cadena;
		}
};

/*******************************************************************/
// Función: EsEntero()
// Descripción: Comprueba si una cadena es un número entero
// Recibe: Cadena a comprobar si es un número entero (cadena)
// Devuelve: True (1) si "cadena" es un número entero y False (0) si 
//           no lo es
/*******************************************************************/
bool EsEntero(string cadena) {
	
	ManipuladorString m(cadena);
	m.EliminaSeparadoresInicialesyFinales();
	cadena = m.GetCadena();
	
	bool es_entero = true;
	int longitud_cadena = cadena.length();
	
	if(longitud_cadena == 0)
		es_entero = false;
	else {
		
		int pos;
		
		if( (cadena.at(0) == '-') || (cadena.at(0) == '+') )
			pos = 1;	
		else
			pos = 0;
			
		while( (pos < longitud_cadena) && es_entero) {
		
			if( !isdigit(cadena.at(pos)) )
				es_entero = false;
			else
				pos++;
		}
	}
	
	return es_entero;
}

/*******************************************************************/
// Función: LeeEntero()
// Descripción: Lee un número entero
// Recibe: Texto que etiqueta la lectura (titulo)
// Devuelve: Número entero (numero).
/*******************************************************************/
int LeeEntero(string titulo) {
	
	string numero;
	
	do {
		
		cout << titulo;
		getline(cin, numero);
		
	}while( !EsEntero(numero) );
	
	return ( stoi(numero) ); 
}

/*******************************************************************/
// Función: LeeEnteroMayorOIgual()
// Descripción: Lee un número entero mayor o igual que "referencia"
// Recibe: Texto que etiqueta la lectura (titulo),
//         Número entero de referencia (referencia)
// Devuelve: Número entero mayor o igual que "referencia" (numero)
/*******************************************************************/
int LeeEnteroMayorOIgual(string titulo, int referencia) {
	
	int numero; 
	
	do {
		numero = LeeEntero(titulo);		
	}while(numero < referencia);
	
	return numero;	
}
		
/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
	// Declaración de variables y objetos
	
	Eratostenes primos;
	int n;
	
	// Entradas de datos
	
	n = LeeEnteroMayorOIgual(" Introduzca un numero entero (mayor que 0): ", 0);
	
	// Cálculos
	
	primos.CalculaHasta(n);
	int tope = primos.TotalCalculados();
	
	// Salidas
	
	cout << endl;
	cout << " Numeros primos menores que " << n << ": ";
	cout << endl << endl;
	cout << " " << primos.ToString();
	cout << endl << endl;
	cout << " Hay " << tope << " primos menores que " << n;
	cout << endl << endl;
	
	return 0;
}
