/*
	Relación de ejercicios 5

	Ejercicio 14: Se está diseñando un sistema web que recolecta 
	              datos personales de un usuario y debe sugerirle un 
				  nombre de usuario (login). Dicho login estará basado en el 
				  nombre y los apellidos; en concreto estará formado por 
				  los n primeros caracteres de cada nombre y apellido 
				  (en minúsculas, unidos y sin espacios en blanco).
				  Por ejemplo, si el nombre es Antonio Francisco Molina Ortega 
				  y n = 2, el nombre de usuario sugerido será anfrmoor.

				  Hay que tener en cuenta que el número de palabras que forman 
				  el nombre y los apellidos puede ser cualquiera. Además, si 
				  n es mayor que alguna de las palabras que aparecen en el 
				  nombre, se incluirá la palabra completa. Por ejemplo, si 
				  el nombre es Ana CAMPOS de la Blanca y n = 4,entonces la 
				  sugerencia será anacampdelablan.

				  Implementar la clase Login que tendrá como único dato miembro 
				  el número máximo de caracteres que nos interesan de cada 
				  palabra del nombre. Hay que definir el método Codifica que 
				  recibirá una cadena de caracteres (tipo string) formada por 
				  el nombre y apellidos (separados por uno o más espacios 
				  en blanco) y devuelva otra cadena con la sugerencia de login.
				  
				  Los únicos métodos que se necesitan usar de la clase string 
				  son size (o su sinónimo length) y push_back. Para probar el 
				  programa o bien se lee una cadena de caracteres con 
				  getline(cin, cadena); o bien se usa directamente literales 
				  de tipo string.
	              
	Entradas: Nombre y apellidos del usuario (nombre_completo),
	          Número de primeros caracteres a coger del nombre
			  y apellidos del usuario (num_caracteres).
	Salidas: Login sugerido para el usuario (login_sugerido).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/***************************************************************************/
// Clase Login: representa el nombre de usuario de un sistema web.
/***************************************************************************/
class Login {
	
	private:
		
		// PRE: num_caracteres_a_coger > 0
		int num_caracteres_a_coger; // Número de primeros caracteres a coger
		                            // de un nombre y apellidos 

	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Login() {
			
			num_caracteres_a_coger = 1;
		}
		
		/*******************************************************************/
		// Constructor con parámetros
		// PRE: n > 0
		/*******************************************************************/
		Login(int n) : num_caracteres_a_coger (n) { }

		/*******************************************************************/
		// Método: SetNumeroCaracteresACoger()
		// Descripción: Establece el número de primeros caracteres a coger
		// 				de un nombre y apellidos
		// Recibe: Número de primeros caracteres a coger de un nombre y 
		//         apellidos (valor_num_caracteres_a_coger)
		// Devuelve: -
		// PRE: valor_num_caracteres_a_coger > 0
		/*******************************************************************/
		void SetNumeroCaracteresACoger(int valor_num_caracteres_a_coger) {
			
			num_caracteres_a_coger = valor_num_caracteres_a_coger;
		}
		
		/*******************************************************************/
		// Método: GetNumeroCaracteresACoger()
		// Descripción: Devuelve el número de primeros caracteres a coger
		// 				de un nombre y apellidos
		// Recibe: -
		// Devuelve: Número de primeros caracteres a coger de un nombre y 
		//           apellidos (valor_num_caracteres_a_coger)
		/*******************************************************************/
		int GetNumeroCaracteresACoger() {
			
			return 	num_caracteres_a_coger;
		}
		
		/*******************************************************************/
		// Método: Codifica()
		// Descripción: Sugerencia de login para un usuario
		// Recibe: Nombre y apellidos del usuario (nombre_completo)
		// Devuelve: Sugerencia de login para un usuario (login)
		/*******************************************************************/
		string Codifica(string nombre_completo) { 
		
			string login = ""; 

			int long_cadena = nombre_completo.length();

			int contador_copiados = 0; 

			for(int i = 0; i < long_cadena; i++) {

				if( !( isspace(nombre_completo[i]) ) && 
				     ( contador_copiados < GetNumeroCaracteresACoger() ) ) {

					char c = tolower(nombre_completo[i]);
					login = login + c;

					contador_copiados++;
				}

				if( isspace(nombre_completo[i]) )
					contador_copiados = 0; 
			}

			return login;
		}
};

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
	// Declaración de constantes
	
	const string TERMINADOR = "FIN";

	// Declaración de variables
	
	string nombre_completo;
	string login_sugerido;
		
	int num_caracteres;

	string cad_leida;
	
	
	// Lectura adelantada 

	do {			
	
		cout << " Nombre y apellidos (terminar con " << TERMINADOR <<"): ";
		getline(cin, cad_leida); 
		
	}while(cad_leida.length() == 0);

	// Ciclo principal

	while(cad_leida != TERMINADOR) {

		nombre_completo = cad_leida;
		
		do {
			
			cout << " Introduzca numero de caracteres: ";
			getline(cin, cad_leida); 
			num_caracteres = stoi(cad_leida);
			
		}while(num_caracteres <= 0);

		// Declaración e inicialización (CONSTRUCTOR) del objeto "login"
		// Hemos asegurado el cumplimiento de las precondiciones 
		Login login(num_caracteres); 

		cout << endl; 
		cout << " Nombre y apellidos: " << nombre_completo << endl; 
		cout << " Numero de caracteres = " << login.GetNumeroCaracteresACoger() 
		     << endl;

		// Cálculos
		
		login_sugerido =  login.Codifica(nombre_completo);

		// Salidas
		
		cout << endl; 
		cout << " Sugerencia de login: " << login_sugerido << endl; 

		// Nueva lectura adelantada 

		cout << endl; 
		do {
			
			cout << " Nombre y apellidos (terminar con " << TERMINADOR <<"): ";
			getline (cin, cad_leida); 
			
		}while(cad_leida.length() == 0);

	}

	cout << endl << endl; 
	
	return 0;	
}
