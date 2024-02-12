/*
	Relaci�n de ejercicios 5

	Ejercicio 22: La criba de Erat�stenes permite hallar todos los n�meros
				  primos menores que un n�mero natural dado n. Hemos trabajado 
				  sobre este problema en el ejercicio 14 de la Relaci�n de 
				  Ejercicios IV.

				  En esta ocasi�n se trata de definir una clase llamada 
				  Eratostenes. Un objeto de la clase podr� almacenar los 
				  n�meros primos calculados en un vector de enteros:
				  
					// Todos los primos calculados ser�n menores que TAMANIO.
				  	static const int TAMANIO = 500;
				  	int vector_privado[TAMANIO];

                  	// PRE: 0 <= total_utilizados <= TAMANIO
                  	int total_utilizados; // N�mero de casillas ocupadas
	              
	              La clase ofrecer�, al menos, estos m�todos:
                  
				  	1) void CalculaHasta(int n) para que calcule los primos 
				       menores que n. Este es el m�todo que implementa el 
					   algoritmo de Erat�stenes. Cuando se ejecute el m�todo, 
					   se almacenar�n en un vector interno del objeto todos 
					   los primos menores que n.
				  
				  	2) int TotalCalculados() que devuelva cu�ntos primos hay 
				       actualmente almacenados.

                  	3) int Elemento(int k) para que devuelva el k-�simo primo.
                  	
					4) int GetMaximo() que devuelva el m�ximo valor de la 
				       criba, n: todos los primos almacenados son menores 
					   que �l.
				     
				  Un programa que use esta clase podr�a ser, esquem�ticamente:
				  
				  	Eratostenes primos;
                    int n = 100;

				    primos.CalculaHasta(n);
					int tope = primos.TotalCalculados();
					
					for (int i=0; i<tope; i++)
						cout << primos.Elemento(i) << " ";
						
	Entradas: N�mero hasta el cual queremos calcular todos los primos
	          menores que �l (n).
	Salidas: N�meros primos hasta un n�mero "n" dado.

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
		// Constructor sin par�metros
		/*******************************************************************/
		ManipuladorString() {
			
			cadena = "";
		}
		
		/*******************************************************************/
		// Constructor con par�metros
		/*******************************************************************/
		ManipuladorString(string la_cadena) : cadena(la_cadena) { }
		
		/*******************************************************************/
		// M�todo: SetCadena()
		// Descripci�n: Establece el texto que va a almacenar "cadena"
		// Recibe: Texto que va a almacenar "cadena" (la_cadena)
		// Devuelve: -
		/*******************************************************************/
		void SetCadena(string la_cadena) {
			
			cadena = la_cadena;	
		}
		
		/*******************************************************************/
		// M�todo: GetCadena()
		// Descripci�n: Devuelve el texto almacenado en "cadena"
		// Recibe: -
		// Devuelve: Texto almacenado en "cadena" (cadena)
		/*******************************************************************/
		string GetCadena() {
			
			return cadena;	
		}

		/*******************************************************************/
		// M�todo: EliminaPrimerosSeparadores()
		// Descripci�n: Elimina los caracteres separadores iniciales 
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
		// M�todo: EliminaUltimosSeparadores()
		// Descripci�n: Elimina los caracteres separadores finales de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaUltimosSeparadores() {
		
		   	while( ( cadena.length() > 0 ) && ( isspace(cadena.back()) ) )
				cadena.pop_back();
		}
		
		/*******************************************************************/
		// M�todo: EliminaSeparadoresInicialesyFinales()
		// Descripci�n: Elimina los caracteres separadores iniciales y 
		//              finales de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaSeparadoresInicialesyFinales() {	
		
			EliminaPrimerosSeparadores();
			EliminaUltimosSeparadores();
		}		
		
		/*******************************************************************/
		// M�todo: CuentaPalabras()
		// Descripci�n: Devuelve el n�mero de palabras que forman "cadena"
		// Recibe: -
		// Devuelve: N�mero de palabras que forman "cadena" (cont_palabras)
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
		// M�todo: ConvierteAMayusculas()
		// Descripci�n: Convierte todos los caracteres de "cadena" a may�sculas
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void ConvierteAMayusculas() {
			
			int longitud_cadena = cadena.length();
			
			for(int i = 0; i < longitud_cadena; i++)
				cadena.at(i) = toupper(cadena.at(i));
		}
		
		/*******************************************************************/
		// M�todo: ConvierteAMinusculas()
		// Descripci�n: Convierte todos los caracteres de "cadena" a min�sculas
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
// Clase Eratostenes: permite calcular los n�meros primos hasta un n�mero
//                    "n" dado, mediante la Criba de Erat�stenes
/***************************************************************************/
class Eratostenes {
	
	private:
		
		static const int TAMANIO = 500; // N�mero casillas disponibles
	    int vector_privado[TAMANIO];
	
	    // PRE: 0 <= total_utilizados <= TAMANIO
	    int total_utilizados; 			// N�mero de casillas ocupadas
	
	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Eratostenes() : total_utilizados(0) { }
		
		/*******************************************************************/
		// M�todo: CalculaHasta()
		// Descripci�n: Calcula los n�meros primos menores que "n"
		// Recibe: N�mero hasta el cual queremos calcular todos los
		//         n�meros primos menores que �l
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
		// M�todo: TotalCalculados()
		// Descripci�n: Devuelve cu�ntos primos hay almacenados
		// Recibe: -
		// Devuelve: N�mero de primos almacenados (total_utilizados)
		/*******************************************************************/
		int TotalCalculados() {
			
			return total_utilizados;	
		}
		
		/*******************************************************************/
		// M�todo: Elemento()
		// Descripci�n: Devuelve el primo k-�simo
		// Recibe: Casilla del vector que almacena el n�mero primo que
		//         queremos obtener (k)
		// Devuelve: Primo k-�simo (vector_privado[k])
		// PRE: 0 <= k < total_utilizados
		/*******************************************************************/
		int Elemento(int k) {
			
			return vector_privado[k];	
		}
		
		/*******************************************************************/
		// M�todo: GetMaximo()
		// Descripci�n: devuelva el m�ximo valor de la criba
		// Recibe: -
		// Devuelve: M�ximo valor de la criba 
		//           (vector_privado[total_utilizados-1])
		/*******************************************************************/
		int GetMaximo() {
			
			return vector_privado[total_utilizados-1];	
		}
		
		/*******************************************************************/
		// M�todo: ToString()
		// Descripci�n: Compone un string con todos los primos que est�n
		//              almacenados en la criba y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los primos que est�n almacenados
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
// Funci�n: EsEntero()
// Descripci�n: Comprueba si una cadena es un n�mero entero
// Recibe: Cadena a comprobar si es un n�mero entero (cadena)
// Devuelve: True (1) si "cadena" es un n�mero entero y False (0) si 
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
// Funci�n: LeeEntero()
// Descripci�n: Lee un n�mero entero
// Recibe: Texto que etiqueta la lectura (titulo)
// Devuelve: N�mero entero (numero).
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
// Funci�n: LeeEnteroMayorOIgual()
// Descripci�n: Lee un n�mero entero mayor o igual que "referencia"
// Recibe: Texto que etiqueta la lectura (titulo),
//         N�mero entero de referencia (referencia)
// Devuelve: N�mero entero mayor o igual que "referencia" (numero)
/*******************************************************************/
int LeeEnteroMayorOIgual(string titulo, int referencia) {
	
	int numero; 
	
	do {
		numero = LeeEntero(titulo);		
	}while(numero < referencia);
	
	return numero;	
}
		
/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	// Declaraci�n de variables y objetos
	
	Eratostenes primos;
	int n;
	
	// Entradas de datos
	
	n = LeeEnteroMayorOIgual(" Introduzca un numero entero (mayor que 0): ", 0);
	
	// C�lculos
	
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
