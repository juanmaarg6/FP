/*
	Relaci�n de ejercicios 5

	Ejercicio 14: Se est� dise�ando un sistema web que recolecta 
	              datos personales de un usuario y debe sugerirle un 
				  nombre de usuario (login). Dicho login estar� basado en el 
				  nombre y los apellidos; en concreto estar� formado por 
				  los n primeros caracteres de cada nombre y apellido 
				  (en min�sculas, unidos y sin espacios en blanco).
				  Por ejemplo, si el nombre es Antonio Francisco Molina Ortega 
				  y n = 2, el nombre de usuario sugerido ser� anfrmoor.

				  Hay que tener en cuenta que el n�mero de palabras que forman 
				  el nombre y los apellidos puede ser cualquiera. Adem�s, si 
				  n es mayor que alguna de las palabras que aparecen en el 
				  nombre, se incluir� la palabra completa. Por ejemplo, si 
				  el nombre es Ana CAMPOS de la Blanca y n = 4,entonces la 
				  sugerencia ser� anacampdelablan.

				  Implementar la clase Login que tendr� como �nico dato miembro 
				  el n�mero m�ximo de caracteres que nos interesan de cada 
				  palabra del nombre. Hay que definir el m�todo Codifica que 
				  recibir� una cadena de caracteres (tipo string) formada por 
				  el nombre y apellidos (separados por uno o m�s espacios 
				  en blanco) y devuelva otra cadena con la sugerencia de login.
				  
				  Los �nicos m�todos que se necesitan usar de la clase string 
				  son size (o su sin�nimo length) y push_back. Para probar el 
				  programa o bien se lee una cadena de caracteres con 
				  getline(cin, cadena); o bien se usa directamente literales 
				  de tipo string.
	              
	Entradas: Nombre y apellidos del usuario (nombre_completo),
	          N�mero de primeros caracteres a coger del nombre
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
		int num_caracteres_a_coger; // N�mero de primeros caracteres a coger
		                            // de un nombre y apellidos 

	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Login() {
			
			num_caracteres_a_coger = 1;
		}
		
		/*******************************************************************/
		// Constructor con par�metros
		// PRE: n > 0
		/*******************************************************************/
		Login(int n) : num_caracteres_a_coger (n) { }

		/*******************************************************************/
		// M�todo: SetNumeroCaracteresACoger()
		// Descripci�n: Establece el n�mero de primeros caracteres a coger
		// 				de un nombre y apellidos
		// Recibe: N�mero de primeros caracteres a coger de un nombre y 
		//         apellidos (valor_num_caracteres_a_coger)
		// Devuelve: -
		// PRE: valor_num_caracteres_a_coger > 0
		/*******************************************************************/
		void SetNumeroCaracteresACoger(int valor_num_caracteres_a_coger) {
			
			num_caracteres_a_coger = valor_num_caracteres_a_coger;
		}
		
		/*******************************************************************/
		// M�todo: GetNumeroCaracteresACoger()
		// Descripci�n: Devuelve el n�mero de primeros caracteres a coger
		// 				de un nombre y apellidos
		// Recibe: -
		// Devuelve: N�mero de primeros caracteres a coger de un nombre y 
		//           apellidos (valor_num_caracteres_a_coger)
		/*******************************************************************/
		int GetNumeroCaracteresACoger() {
			
			return 	num_caracteres_a_coger;
		}
		
		/*******************************************************************/
		// M�todo: Codifica()
		// Descripci�n: Sugerencia de login para un usuario
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
// Funci�n principal
/***************************************************************************/
int main() {
	
	// Declaraci�n de constantes
	
	const string TERMINADOR = "FIN";

	// Declaraci�n de variables
	
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

		// Declaraci�n e inicializaci�n (CONSTRUCTOR) del objeto "login"
		// Hemos asegurado el cumplimiento de las precondiciones 
		Login login(num_caracteres); 

		cout << endl; 
		cout << " Nombre y apellidos: " << nombre_completo << endl; 
		cout << " Numero de caracteres = " << login.GetNumeroCaracteresACoger() 
		     << endl;

		// C�lculos
		
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
