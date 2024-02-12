/*
	Relación de ejercicios 6

	Ejercicio 20:	Consideramos la clase AlumnoFP desarrollada en el 
					ejercicio 17 de la Relación de Problemas V. Ahora
					escribimos la clase Grupo_AlumnosFP para gestionar un 
					grupo de alumnos. Su representación es un array de 
					TAMANIO datos de la clase AlumnoFP:
					
						- static const int TAMANIO = 100;
						- AlumnoFP vector_alumnos[TAMANIO];
						- int total_alumnos;

					Escribimos los métodos públicos que permiten su gestión. 
					El conjunto de métodos mínimos lo deducimos del hecho de 
					que se trata de una secuencia. Añadimos un método que 
					ordena los alumnos de acuerdo a su nota media. En caso de 
					coincidir la nota media, se ordenarán por la nota de 
					teoría; en caso de coincidencia, por la nota del segundo 
					examen práctico; si siguen coincidiendo, por el del 
					primero; si aún coinciden, por la evaluación continua, y 
					si persiste el empate, por la tercera letra del apellido.

					Escribimos un programa que lee los datos de una serie 
					indefinida de alumnos (termina cuando se escribe FIN ante 
					la petición del apellido), los guarda en un objeto
					Grupo_AlumnosFP, los ordena y muestra el resultado de la 
					ordenación.
						              
	Entradas: Grupo de alumnos de FP (grupos_alumnos).
	Salidas: Grupo de alumnos de FP ordenado según el criterio dado 
	         (grupos_alumnos_ordenado).
			 
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>

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
// Clase Lector: representa una lectura etiquetada de datos int y double
/***************************************************************************/
class Lector {
	
	private:
		
		string titulo;		// Texto que etiqueta la lectura
		
	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Lector() : titulo("") { }
		
		/*******************************************************************/
		// Constructor con parámetros
		/*******************************************************************/
		Lector(string valor_titulo) : titulo(valor_titulo) { }	
		
		/*******************************************************************/
		// Método: SetTitulo()
		// Descripción: Establece el texto que etiqueta la lectura
		// Recibe: Texto que etiqueta la lectura (valor_titulo)
		// Devuelve: -
		/*******************************************************************/
		void SetTitulo(string valor_titulo) {
			
			titulo = valor_titulo;
		}
		
		/*******************************************************************/
		// Método: GetTitulo()
		// Descripción: Devuelve el texto que etiqueta la lectura
		// Recibe: -
		// Devuelve: Texto que etiqueta la lectura (titulo)
		/*******************************************************************/
		string GetTitulo() {
			
			return titulo;	
		}
		
		/*******************************************************************/
		// Método: LeeEntero()
		// Descripción: Lee un número entero
		// Recibe: -
		// Devuelve: Número entero (numero).
		/*******************************************************************/
		int LeeEntero() {
			
			string cadena;
			
			do {
				
				cout << titulo;
				getline(cin, cadena);
				
			}while( !EsEntero(cadena) );
			
			return ( stoi(cadena) ); 
		}
		
		/*******************************************************************/
		// Método: LeeEnteroEnRango()
		// Descripción: Lee un número entero dentro del rango 
		//              ["menor" , "mayor"]
		// Recibe: Valor mínimo del rango (menor),
		//		   Valor máximo del rango (mayor)
		// Devuelve: Número entero dentro del rango (numero)
		/*******************************************************************/
		int LeeEnteroEnRango(int menor, int mayor) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while( (numero < menor) || (numero > mayor) );
			
			return numero;	
		}
		
		/*******************************************************************/
		// Método: LeeEnteroMayorOIgual()
		// Descripción: Lee un número entero mayor o igual que "referencia"
		// Recibe: Número entero de referencia (referencia)
		// Devuelve: Número entero mayor o igual que "referencia" (numero)
		/*******************************************************************/
		int LeeEnteroMayorOIgual(int referencia) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while(numero < referencia);
			
			return numero;	
		}	
		
		/*******************************************************************/
		// Método: LeeEnteroMayor()
		// Descripción: Lee un número entero mayor que "referencia"
		// Recibe: Número entero de referencia (referencia)
		// Devuelve: Número entero mayor que "referencia" (numero)
		/*******************************************************************/
		int LeeEnteroMayor(int referencia) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while(numero <= referencia);
			
			return numero;	
		}
		
		/*******************************************************************/
		// Método: LeeDouble()
		// Descripción: Lee un número real
		// Recibe: -
		// Devuelve: Número real (numero).
		/*******************************************************************/
		double LeeDouble() {
			
			string cadena;
			
			do {
				
				cout << titulo;
				getline(cin, cadena);
				
			}while( !EsReal(cadena) );
			
			return ( stod(cadena) ); 
		}
		
		/*******************************************************************/
		// Método: LeeDoubleEnRango()
		// Descripción: Lee un número real dentro del rango ["menor" , "mayor"]
		// Recibe: Valor mínimo del rango (menor),
		//		   Valor máximo del rango (mayor)
		// Devuelve: Número real dentro del rango (numero)
		/*******************************************************************/
		double LeeDoubleEnRango(double menor, double mayor) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while( (numero < menor) || (numero > mayor) );
			
			return numero;	
		}
		
		/*******************************************************************/
		// Método: LeeDoubleMayorOIgual()
		// Descripción: Lee un número real mayor o igual que "referencia"
		// Recibe: Número real de referencia (referencia)
		// Devuelve: Número real mayor o igual que "referencia" (numero)
		/*******************************************************************/
		double LeeDoubleMayorOIgual(double referencia) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while(numero < referencia);
			
			return numero;	
		}
		
		/*******************************************************************/
		// Método: LeeDoubleMayor()
		// Descripción: Lee un número real mayor que "referencia"
		// Recibe: Número real de referencia (referencia)
		// Devuelve: Número real mayor que "referencia" (numero)
		/*******************************************************************/
		double LeeDoubleMayor(double referencia) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while(numero <= referencia);
			
			return numero;	
		}
				
	private:
		
		/*******************************************************************/
		// Método: EsEntero()
		// Descripción: Comprueba si un número es entero.
		// Recibe: Cadena (cadena)
		// Devuelve: True (1) si "cadena" es un número entero y False (0)
		//           si no lo es
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
		// Método: EsReal()
		// Descripción: Comprueba si un número es real.
		// Recibe: Cadena (cadena)
		// Devuelve: True (1) si "cadena" es un número real y False (0)
		//           si no lo es
		/*******************************************************************/
		bool EsReal(string cadena) {
			
			ManipuladorString m(cadena);
			m.EliminaSeparadoresInicialesyFinales();
			cadena = m.GetCadena();
			
			bool es_real = true;
			int longitud_cadena = cadena.length();
			
			if(longitud_cadena == 0)
				es_real = false;
			else {
				
				int pos;
				
				if( (cadena.at(0) == '-') || (cadena.at(0) == '+') )
					pos = 1;	
				else
					pos = 0;
					
				bool encontrado_un_punto = false;
				
				while( (pos < longitud_cadena) && es_real) {
					
					char c = cadena.at(pos);
					
					if( !isdigit(c) ) {
						
						if(c == '.') {
							
							if(encontrado_un_punto)	
								es_real = false;
							else
								encontrado_un_punto = true;
						}
						else
							es_real = false;
					}
					
					pos++;
				}
			}
			
			return es_real;
		}
};

/***************************************************************************/
// Clase AlumnoFP: permite representar las notas de un alumno de la
//                 asignatura "Fundamentos de Programación"
/***************************************************************************/
class AlumnoFP {
	
	private:
		
		string nombre;		// Nombre del alumno
		string apellidos;	// Apellidos del alumno
		string dni;			// DNI del alumno
		
		double nota_examen_teoria;		   // Nota del alumno en el examen de 
		                                   // teoría
		double nota_examen_practico1;	   // Nota del alumno en el primer 
		                                   // examen práctico
		double nota_examen_practico2;      // Nota del alumno en el segundo 
		                                   // examen práctico
		double nota_evaluacion_continua;   // Nota del alumno en la evaluación
		                                   // continua
		
	public:
		
				
		static const double PORCENTAJE_EXM_TEORIA;	// Ponderación del examen
		                                            // de teoría
		static const double PORCENTAJE_EXM_PRACT1;  // Ponderación del primer
		                                            // examen práctico
		static const double PORCENTAJE_EXM_PRACT2;  // Ponderación del segundo
		                                            // examen práctico
		static const double PORCENTAJE_EV_CONT;     // Ponderación de la
		                                            // evaluación continua
		                                            
		static const double NOTA_MINIMA_PARA_MEDIA; // Nota mínima que hay
		 											// que obtener en el
		 											// examen de teoría para
		 											// hacer media

		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		AlumnoFP() : nombre(""), apellidos(""), dni(""), 
		             nota_examen_teoria(0.0), nota_examen_practico1(0.0), 
					 nota_examen_practico2(0.0), nota_evaluacion_continua(0.0)
					 { }
	
		/*******************************************************************/
		// Constructor con parámetros
		// PRE: 0 <= nota_exm_teoria <= 10
		//      0 <= nota_exm_pract1 <= 10
		//      0 <= nota_exm_pract2 <= 10
		//      0 <= nota_ev_cont <= 10
		/*******************************************************************/
		AlumnoFP(string nombre_alumno, string apellidos_alumno, 
		         string dni_alumno, double nota_exm_teoria, 
				 double nota_exm_pract1, double nota_exm_pract2,
				 double nota_ev_cont)
				:  nombre(nombre_alumno), apellidos(apellidos_alumno),
				   dni(dni_alumno), nota_examen_teoria(nota_exm_teoria),
				   nota_examen_practico1(nota_exm_pract1), 
				   nota_examen_practico2(nota_exm_pract2),
				   nota_evaluacion_continua(nota_ev_cont) { }
		
		/*******************************************************************/
		// Método: SetNombre()
		// Descripción: Establece el nombre del alumno
		// Recibe: Nombre del alumno (nombre_alumno)
		// Devuelve: -
		/*******************************************************************/
		void SetNombre(string nombre_alumno) {
			
			nombre = nombre_alumno;	
		}
		
		/*******************************************************************/
		// Método: SetApellido1()
		// Descripción: Establece el primer apellido del alumno
		// Recibe: Primer apellido del alumno (apellido1_alumno)
		// Devuelve: -
		/*******************************************************************/
		void SetApellidos(string apellidos_alumno) {
			
			apellidos = apellidos_alumno;
		}
		
		/*******************************************************************/
		// Método: SetDni()
		// Descripción: Establece el DNI del alumno
		// Recibe: DNI del alumno (dni_alumno)
		// Devuelve: -
		/*******************************************************************/
		void SetDni(string dni_alumno) {
			
			dni = dni_alumno;	
		}
		
		/*******************************************************************/
		// Método: SetNotaExamenTeoria()
		// Descripción: Establece la nota del alumno en el examen de teoría
		// Recibe: Nota del alumno en el examen de teoría (nota_exm_teoria)
		// Devuelve: -
		// PRE: 0 <= nota_exm_teoria <= 10
		/*******************************************************************/
		void SetNotaExamenTeoria(double nota_exm_teoria) {
			
			nota_examen_teoria = nota_exm_teoria;
		}
		
		/*******************************************************************/
		// Método: SetNotaExamenPractico1()
		// Descripción: Establece la nota del alumno en el primer examen
		//              práctico
		// Recibe: Nota del alumno en el primer examen práctico 
		//         (nota_exm_pract1)
		// Devuelve: -
		// PRE: 0 <= nota_exm_pract1 <= 10
		/*******************************************************************/
		void SetNotaExamenPractico1(double nota_exm_pract1) {
			
			nota_examen_practico1 = nota_exm_pract1;
		}
		
		/*******************************************************************/
		// Método: SetNotaExamenPractico2()
		// Descripción: Establece la nota del alumno en el segundo examen
		//              práctico
		// Recibe: Nota del alumno en el segundo examen práctico 
		//         (nota_exm_pract2)
		// Devuelve: -
		// PRE: 0 <= nota_exm_pract2 <= 10
		/*******************************************************************/
		void SetNotaExamenPractico2(double nota_exm_pract2) {
			
			nota_examen_practico2 = nota_exm_pract2;
		}
		
		/*******************************************************************/
		// Método: SetNotaEvaluacionContinua()
		// Descripción: Establece la nota del alumno en la evaluación continua
		// Recibe: Nota del alumno en la evaluación continua
		//         (nota_ev_cont)
		// Devuelve: -
		// PRE: 0 <= nota_ev_cont <= 10
		/*******************************************************************/
		void SetNotaEvaluacionContinua(double nota_ev_cont) {
			
			nota_evaluacion_continua = 	nota_ev_cont;
		}
		
		/*******************************************************************/
		// Método: GetNombre()
		// Descripción: Devuelve el nombre del alumno
		// Recibe: -
		// Devuelve: Nombre del alumno (nombre)
		/*******************************************************************/
		string GetNombre() {
			
			return nombre;
		}
		
		/*******************************************************************/
		// Método: GetApellido1()
		// Descripción: Devuelve el primer apellido del alumno
		// Recibe: -
		// Devuelve: Primer apellido del alumno (apellido1)
		/*******************************************************************/
		string GetApellidos() {
			
			return apellidos;	
		}
		
		/*******************************************************************/
		// Método: GetDni()
		// Descripción: Devuelve el DNI del alumno
		// Recibe: -
		// Devuelve: DNI del alumno (dni)
		/*******************************************************************/
		string GetDni() {
			
			return dni;	
		}
		
		/*******************************************************************/
		// Método: GetNotaExamenTeoria()
		// Descripción: Devuelve la nota del alumno en el examen de teoría
		// Recibe: -
		// Devuelve: Nota del alumno en el examen de teoría 
		//           (nota_examen_teoria)
		/*******************************************************************/
		double GetNotaExamenTeoria() {
			
			return nota_examen_teoria;
		}
		
		/*******************************************************************/
		// Método: GetNotaExamenPractico1()
		// Descripción: Devuelve la nota del alumno en el primer examen 
		//              práctico
		// Recibe: -
		// Devuelve: Nota del alumno en el primer examen práctico
		//           (nota_examen_practico1)
		/*******************************************************************/
		double GetNotaExamenPractico1() {
			
			return nota_examen_practico1;
		}
		
		/*******************************************************************/
		// Método: GetNotaExamenPractico2()
		// Descripción: Devuelve la nota del alumno en el segundo examen 
		//              práctico
		// Recibe: -
		// Devuelve: Nota del alumno en el segundo examen práctico
		//           (nota_examen_practico2)
		/*******************************************************************/
		double GetNotaExamenPractico2() {
			
			return nota_examen_practico2;
		}
		
		/*******************************************************************/
		// Método: GetNotaEvaluacionContinua()
		// Descripción: Devuelve la nota del alumno en la evaluación continua
		// Recibe: -
		// Devuelve: Nota del alumno en la evaluación continua
		//           (nota_evaluacion_continua)
		/*******************************************************************/
		double GetNotaEvaluacionContinua() {
			
			return nota_evaluacion_continua;
		}
		
		/*******************************************************************/
		// Método: GetMinimaNotaParaMedia()
		// Descripción: Devuelve la nota mínima que hay que obtener en el
		//              examen de teoría para que se le haga media al alumno
		// Recibe: -
		// Devuelve: Nota mínima que hay que obtener en el examen de teoría 
		//           para que se le haga media al alumno
		//           (NOTA_MINIMA_PARA_MEDIA)
		/*******************************************************************/
		double GetMinimaNotaParaMedia() {
			
			return NOTA_MINIMA_PARA_MEDIA;
		}
		
		/*******************************************************************/
		// Método: CalcularNotaFinal()
		// Descripción: Devuelve la nota final del alumno en la asignatura
		// Recibe: -
		// Devuelve: Nota final del alumno en la asignatura (nota_final)
		/*******************************************************************/
		double CalcularNotaFinal() {
			
			double nota_final;
			
			if(nota_examen_teoria >= NOTA_MINIMA_PARA_MEDIA)
				nota_final = nota_examen_teoria * PORCENTAJE_EXM_TEORIA +
				             nota_examen_practico1 * PORCENTAJE_EXM_PRACT1 +
				             nota_examen_practico2 * PORCENTAJE_EXM_PRACT2 +
				             nota_evaluacion_continua * PORCENTAJE_EV_CONT;
			else
				nota_final = nota_examen_teoria;
			
			return nota_final;
		}
		
		/*******************************************************************/
		// Método: ExamenTeoriaSuspenso()
		// Descripción: Comprueba si el alumno ha suspendido el examen de
		//              teoría
		// Recibe: -
		// Devuelve: True (1) si el alumno ha suspendido el examen de teoría
		//           y False (0) si no
		/*******************************************************************/
		bool ExamenTeoriaSuspenso() {
			
			bool examen_teoria_suspenso = (nota_examen_teoria < 5.0);	
			
			return examen_teoria_suspenso;
		}
		
		/*******************************************************************/
		// Método: ExamenPractico1Suspenso()
		// Descripción: Comprueba si el alumno ha suspendido el primer
		//              examen práctico
		// Recibe: -
		// Devuelve: True (1) si el alumno ha suspendido el primer examen
		//           práctico y False (0) si no
		/*******************************************************************/
		bool ExamenPractico1Suspenso() {
			
			bool examen_practico1_suspenso = (nota_examen_practico1 < 5.0);	
			
			return examen_practico1_suspenso;
		}
		
		/*******************************************************************/
		// Método: ExamenPractico2Suspenso()
		// Descripción: Comprueba si el alumno ha suspendido el segundo
		//              examen práctico
		// Recibe: -
		// Devuelve: True (1) si el alumno ha suspendido el segundo examen
		//           práctico y False (0) si no
		/*******************************************************************/
		bool ExamenPractico2Suspenso() {
			
			bool examen_practico2_suspenso = (nota_examen_practico2 < 5.0);	
			
			return examen_practico2_suspenso;
		}
		
		/*******************************************************************/
		// Método: EvContinuaSuspensa()
		// Descripción: Comprueba si el alumno ha suspendido la evaluación
		//              continua
		// Recibe: -
		// Devuelve: True (1) si el alumno ha suspendido la evaluacion 
		//           continua y False (0) si no
		/*******************************************************************/
		bool EvContinuaSuspensa() {
			
			bool ev_continua_suspensa = (nota_evaluacion_continua < 5.0);	
			
			return ev_continua_suspensa;
		}
		
		/*******************************************************************/
		// Método: MostrarNotasSuspensas()
		// Descripción: Devuelve un mensaje con las notas de las partes de la
		//              asignatura que el alumno ha suspendido
		// Recibe: -
		// Devuelve: Mensaje con las notas de las partes de la asignatura 
		//           que el alumno ha suspendido (mensaje)
		/*******************************************************************/
		string MostrarNotasSuspensas() {
			
			string mensaje = "";
			
			if( ExamenTeoriaSuspenso() )
				mensaje += "\t Nota del examen de teoria: " + 
				           to_string(nota_examen_teoria) + "\n";	
			if( ExamenPractico1Suspenso() )
				mensaje += "\t Nota del examen practico 1: " + 
				           to_string(nota_examen_practico1) + "\n";
			
			if( ExamenPractico2Suspenso() )
				mensaje += "\t Nota del examen practico 2: " + 
				           to_string(nota_examen_practico2) + "\n";
				           
			if( EvContinuaSuspensa() )
				mensaje += "\t Nota de la evaluacion continua: " + 
				           to_string(nota_evaluacion_continua) + "\n";
				           
			if( !ExamenTeoriaSuspenso() && !ExamenPractico1Suspenso() &&
			    !ExamenPractico2Suspenso() && !EvContinuaSuspensa() )
			   mensaje += "\t El alumno no ha suspendido ninguna de las partes";
						   
			return mensaje;			
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con todos los datos y notas de
		//              un alumno
		// Recibe: -
		// Devuelve: String con todos los datos y notas de un alumno
		//           (cadena)
		/*******************************************************************/
		string ToString() {
			
			string cadena;
			
			cadena = cadena + "\t" + apellidos + ", " + nombre + "--> "
			                + to_string( CalcularNotaFinal() ) + " ("
			                + to_string(nota_examen_teoria) + ", "
			                + to_string(nota_examen_practico1) + ", "
			                + to_string(nota_examen_practico2) + ", "
			                + to_string(nota_evaluacion_continua) + ")"
			                + "\n";
							    
			return cadena;
		}	
};

/***************************************************************************/
const double AlumnoFP::PORCENTAJE_EXM_TEORIA = 0.6;
const double AlumnoFP::PORCENTAJE_EXM_PRACT1 = 0.1;
const double AlumnoFP::PORCENTAJE_EXM_PRACT2 = 0.2;
const double AlumnoFP::PORCENTAJE_EV_CONT = 0.1;
const double AlumnoFP::NOTA_MINIMA_PARA_MEDIA = 4.0;
/***************************************************************************/

/***************************************************************************/
// Clase Grupo_AlumnosFP: representa una conjunto de datos de tipo AlumnoFP
/***************************************************************************/
class Grupo_AlumnosFP {
	
	private:
		
		static const int TAMANIO = 100;		// Número máximo de alumnos que
											// puede haber en el grupo
		AlumnoFP vector_alumnos[TAMANIO];
		
		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_alumnos;           		// Número de alumnos del grupo
				
	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Grupo_AlumnosFP() : total_alumnos(0) { }
				
		/*******************************************************************/
		// Método: TotalAlumnos()
		// Descripción: Devuelve el número de alumnos del grupo
		// Recibe: -
		// Devuelve: Número de alumnos del grupo (total_alumnos)
		/*******************************************************************/
		int TotalAlumnos() {
			
			return total_alumnos;
		}
		
		/*******************************************************************/
		// Método: Capacidad()
		// Descripción: Devuelve el número máximo de alumnos que puede haber 
		//              en el grupo
		// Recibe: -
		// Devuelve: Número máximo de alumnos que puede haber en el grupo 
		//           (TAMANIO)
		/*******************************************************************/
		int Capacidad() {
			
			return TAMANIO;
		}
		
		/*******************************************************************/
		// Método: EliminaTodos()
		// Descripción: "Vacía" completamente el vector de alumnos
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaTodos() {
			
			total_alumnos = 0;
		}
		
		/*******************************************************************/
		// Método: Aniade()
		// Descripción: Añade un nuevo alumno al final del vector de alumnos. 
		//              La adición se realiza si hay alguna casilla disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nuevo alumno a añadir al final del vector de alumnos (nuevo)
		// Devuelve: -
		// PRE: total_alumnos < TAMANIO
		/*******************************************************************/
		void Aniade(AlumnoFP nuevo) {
			
			if(total_alumnos < TAMANIO) {
				vector_alumnos[total_alumnos] = nuevo;
				total_alumnos++;
			}
		}
		
		/*******************************************************************/
		// Método: Elemento()
		// Descripción: Devuelve el alumno que se encuentra la casilla 
		//              "indice" del vector de alumnos
		// Recibe: Índice de la casilla del alumno a devolver (indice)
		// Devuelve: Alumno almacenado en la casilla "indice" del vector 
		//           de alumnos
		// PRE: 0 <= indice < total_alumnos
		/*******************************************************************/
		AlumnoFP Elemento(int indice) {
			
			return vector_alumnos[indice];
		}
		
		/*******************************************************************/
		// Método: Modifica()
		// Descripción: Cambia el alumno de la casilla "indice" por otro
		//              alumno dado en "nuevo". El tamaño del vector de 
		//              alumnos no cambia
		// Recibe: Índice de la casilla del alumno a cambiar (indice)
		//         Nuevo alumno a almacenar en la casilla "indice" del
		//         vector de alumnos (nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_alumnos
		/*******************************************************************/
		void Modifica(int indice, AlumnoFP nuevo) {
			
			if( (indice >= 0) && (indice < total_alumnos) )
				vector_alumnos[indice] = nuevo;
		}
		
		/*******************************************************************/
		// Método: Elimina()
		// Descripción: Eliminar el alumno de la posición dada por "indice"
		//              en el vector de alumnos.
		//              Realiza un borrado físico (desplazamiento 
		//              y sustitución)
		// Recibe: Índice de la casilla del alumno a eliminar (indice)
		// Devuelve: -
		// PRE: 0 <= indice < total_alumnos
		/*******************************************************************/
		void Elimina(int indice) {
			
			if( (indice >= 0) && (indice < total_alumnos) ) {
				
				int tope = total_alumnos - 1;
				
				for(int i = indice ; i < tope ; i++) {
					vector_alumnos[i] = vector_alumnos[i+1];
					total_alumnos--;
				}
			}
		}
		
		/*******************************************************************/
		// Método: Inserta()
		// Descripción: Inserta el alumno "nuevo" en el vector de alumnos justo
		//              en la posición dada por "indice". Desplaza todos los 
		//              alumnos una posición a la derecha antes de copiar en 
		//              "indice" el alumno "nuevo"
		// Recibe: Índice de la casilla del alumno a insertar (indice),
		//         Nuevo alumno a insertar (nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_alumnos
		/*******************************************************************/
		void Inserta(int indice, AlumnoFP nuevo) {
			
			if( (total_alumnos < TAMANIO) && (indice >= 0) && 
			     (indice < total_alumnos) ) {
		
				for(int i = total_alumnos ; i > indice ; i--)
					vector_alumnos[i] = vector_alumnos[i-1];
		
				vector_alumnos[indice] = nuevo;
				total_alumnos++;
			}
		}
		
		/*******************************************************************/
		// Método: PosicionMinimoEntre()
		// Descripción: Devuelve la posición en el vector de alumnos del
		//              elemento mínimo que se encuentra entre "izda" y "dcha"
		// Recibe: Extremos del rango de casillas en las cuales queremos 
		//         encontrar la posición del elemento mínimo (izda, dcha).
		// Devuelve: Posición en la secuencia del elemento mínimo 
		//           situado entre "izda" y "dcha" (posicion_minimo)
		// PRE: 0 <= izda <= dcha < total_alumnos
		/*******************************************************************/
		int PosicionMinimoEntre(int izda, int dcha){
			
			int posicion_minimo = -1;
			AlumnoFP minimo;
			
			minimo = vector_alumnos[izda];
			
			posicion_minimo = izda;
		
			for(int i = izda+1; i <= dcha; i++) {
				
				double nota_final = vector_alumnos[i].CalcularNotaFinal();
				double nota_final_minima = minimo.CalcularNotaFinal();
				bool empate_nota_final = (nota_final == nota_final_minima);
				bool nota_final_es_menor = (nota_final < nota_final_minima);
				
				double nota_teoria = vector_alumnos[i].GetNotaExamenTeoria();
				double nota_teoria_minima = minimo.GetNotaExamenTeoria();
				bool empate_nota_teoria = (nota_teoria == nota_teoria_minima);
				bool nota_teoria_es_menor = (nota_teoria < nota_teoria_minima);
				
				double nota_practico2 = vector_alumnos[i].
				                        GetNotaExamenPractico2();
				double nota_practico2_minima = minimo.GetNotaExamenPractico2();
				bool empate_nota_practico2 = (nota_practico2 == 
				                              nota_practico2_minima);
				bool nota_practico2_es_menor = (nota_practico2 <
				                                nota_practico2_minima);
												
				double nota_practico1 = vector_alumnos[i].
				                        GetNotaExamenPractico1();
				double nota_practico1_minima = minimo.GetNotaExamenPractico1();
				bool empate_nota_practico1 = (nota_practico1 == 
				                              nota_practico1_minima);
				bool nota_practico1_es_menor = (nota_practico1 < 
				                                nota_practico1_minima);
																							  
				double nota_ev_cont = vector_alumnos[i].
				                      GetNotaEvaluacionContinua();
				double nota_ev_cont_minima = minimo.GetNotaEvaluacionContinua();
				bool empate_nota_ev_cont = (nota_ev_cont == 
				                            nota_ev_cont_minima);
				bool nota_ev_cont_es_menor = (nota_ev_cont < 
				                              nota_ev_cont_minima);
				                              
				char letra3_apellido1 = vector_alumnos[i].GetApellidos().at(2);
				char letra3_apellido1_minima = minimo.GetApellidos().at(2);
				bool letra3_apellido1_es_menor = (letra3_apellido1 <
				                                  letra3_apellido1_minima);
				
				if(nota_final_es_menor) {
					minimo = vector_alumnos[i];
					posicion_minimo = i;
				}
				else if(empate_nota_final && nota_teoria_es_menor) {
				    minimo = vector_alumnos[i];
					posicion_minimo = i;
				}
				else if(empate_nota_final && empate_nota_teoria && 
				        nota_practico2_es_menor) {
				        	
					minimo = vector_alumnos[i];
					posicion_minimo = i;	
				}
				else if(empate_nota_final && empate_nota_teoria && 
				        empate_nota_practico2 && nota_practico1_es_menor) {
				        	
					minimo = vector_alumnos[i];
					posicion_minimo = i;	
				}
				else if(empate_nota_final && empate_nota_teoria && 
				        empate_nota_practico2 && empate_nota_practico1 &&
						nota_ev_cont_es_menor) {
							
					minimo = vector_alumnos[i];
					posicion_minimo = i;	
				}
				else if(empate_nota_final && empate_nota_teoria && 
				        empate_nota_practico2 && empate_nota_practico1 &&
						empate_nota_ev_cont && letra3_apellido1_es_menor) {

					minimo = vector_alumnos[i];
					posicion_minimo = i;	
				}
			}
						
			return posicion_minimo;
		}
		
		/*******************************************************************/
		// Método: OrdenaAlumnos()
		// Descripción: Ordena el grupo de alumnos mediante el algoritmo
		//              de ordenación por selección
		// Recibe: -
		// Devuelve: Grupo de alumnos de FP ordenado (grupo_alumnos_ordenado)
		/*******************************************************************/
		Grupo_AlumnosFP OrdenaAlumnos() {
			
			Grupo_AlumnosFP grupo_alumnos_ordenado;
			
			grupo_alumnos_ordenado.total_alumnos = total_alumnos;
			
			for(int i = 0; i < total_alumnos; i++)
				grupo_alumnos_ordenado.vector_alumnos[i] = vector_alumnos[i];
			
			int pos_min;
			
			for(int izda = 0; izda < total_alumnos; izda++) {
				pos_min = grupo_alumnos_ordenado.PosicionMinimoEntre
				                                 (izda, total_alumnos-1);
				grupo_alumnos_ordenado.IntercambiaComponentesEnPosiciones
				                       (izda, pos_min);
			}		
			
			return grupo_alumnos_ordenado;
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con todos los alumnos que pertenecen
		//              al grupo
		// Recibe: -
		// Devuelve: String con todos los alumnos que pertenecen al grupo
		//           (cadena)
		/*******************************************************************/
		string ToString() {
			
			string cadena;
						
			for(int i = 0; i < total_alumnos; i++)
				cadena = cadena + vector_alumnos[i].ToString();;

			return cadena;
		}
		
	private:
	
		/*******************************************************************/
		// Método: IntercambiaComponentesEnPosiciones()
		// Descripción: Intercambia los alumnos situadas en las casillas
		//              "pos_izda" y "pos_dcha" del vector de alumnos
		// Recibe: Índice de las casillas  a intercambiar del vector de alumnos
		//         (pos_izda, pos_dcha)
		// Devuelve: -
		/*******************************************************************/
		void IntercambiaComponentesEnPosiciones(int pos_izda, int pos_dcha) {
			
			AlumnoFP intercambia;
			
			intercambia = vector_alumnos[pos_izda];
			vector_alumnos[pos_izda] = vector_alumnos[pos_dcha];
			vector_alumnos[pos_dcha] = intercambia;
		}
};

/*******************************************************************/
// Función: DNICorrecto()
// Descripción: Comprueba si una cadena es un DNI
// Recibe: Cadena a comprobar si es un DNI (cadena)
// Devuelve: True (1) si "cadena" es un DNI y False (0) si 
//           no lo es
/*******************************************************************/
bool DNICorrecto(string cadena) {
	
	ManipuladorString m(cadena);
	m.EliminaSeparadoresInicialesyFinales();
	cadena = m.GetCadena();
	
	bool dni_correcto = true;
	int longitud_cadena = cadena.length();
	
	if(longitud_cadena != 9)
		dni_correcto = false;
	else {
		
		for(int i = 0; i < longitud_cadena-1 && dni_correcto; i++)
			if( !isdigit( cadena.at(i) ) )
				dni_correcto = false;
		
		if( !isalpha( toupper( cadena.at(longitud_cadena-1) ) ) ) {
		    dni_correcto = false;
		}
	}
			
	return dni_correcto;
}

/*******************************************************************/
// Función: LeeDNI()
// Descripción: Lee un DNI
// Recibe: Texto que etiqueta la lectura (titulo)
// Devuelve: DNI (dni)
/*******************************************************************/
string LeeDNI(string titulo) {
	
	string dni;
	
	do {
		
		cout << titulo;
		getline(cin, dni);
		
	}while( !DNICorrecto(dni) );
	
	return dni; 
}

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
    cout.setf(ios::fixed);        // Notación de punto fijo para los reales
    cout.setf(ios::showpoint);    // Mostrar siempre decimales 
    
    // Declaración de constantes
    
    const string FINALIZAR = "FIN";
    
    // Declaración de variables y objetos
    
    string nombre_alumno, apellidos_alumno, dni_alumno;
	double nota_exm_teoria, nota_exm_pract1, nota_exm_pract2, nota_ev_cont;
	
	Lector lector_notas;
	
    Grupo_AlumnosFP grupo_alumnos;
    
	// Entradas de datos
	
	int i = 1;
    bool finalizar = false;
    
    cout << " Grupo de alumnos de FP: " << endl << endl;
	
	while(!finalizar) {

	    cout << "\t Alumno " << i << ": " << endl << endl;

		cout << "\t\t Nombre del alumno (FIN para finalizar): ";
		getline(cin, nombre_alumno);
		
		finalizar = (nombre_alumno == FINALIZAR);
		
		if(!finalizar) {
			
			cout << "\t\t Apellidos del alumno: ";
			getline(cin, apellidos_alumno);

			dni_alumno = LeeDNI("\t\t Introduzca el DNI del alumno: ");
			
			lector_notas.SetTitulo("\t\t Nota del examen de teoria: ");
			nota_exm_teoria = lector_notas.LeeDoubleEnRango(0.0, 10.0);
			
			lector_notas.SetTitulo("\t\t Nota del examen practico 1: ");       
			nota_exm_pract1 = lector_notas.LeeDoubleEnRango(0.0, 10.0);
			  
			lector_notas.SetTitulo("\t\t Nota del examen practico 2: ");       
			nota_exm_pract2 = lector_notas.LeeDoubleEnRango(0.0, 10.0);
								
			lector_notas.SetTitulo("\t\t Nota de la evaluacion continua: ");      
			nota_ev_cont = lector_notas.LeeDoubleEnRango(0.0, 10.0);
			
			AlumnoFP alumno(nombre_alumno, apellidos_alumno, dni_alumno,
			                nota_exm_teoria, nota_exm_pract1, nota_exm_pract2,
							nota_ev_cont);
			
			grupo_alumnos.Aniade(alumno);
			
			i++;
		}
		
		cout << endl;
	}
    
    // Cálculos
    
    if(grupo_alumnos.TotalAlumnos() > 0) {
    
	    Grupo_AlumnosFP grupo_alumnos_ordenado;
	    
	    grupo_alumnos_ordenado = grupo_alumnos.OrdenaAlumnos();
	    
	    // Salidas
	    
	    cout << " LISTA DE ALUMNOS: " << endl << endl;
	    cout << grupo_alumnos.ToString();
	    
	    cout << endl;
	    cout << " LISTA DE ALUMNOS ORDENADOS POR NOTA: " << endl << endl;
	    cout << grupo_alumnos_ordenado.ToString();
	}
	
	cout << endl << endl;
        
    return 0;
}
