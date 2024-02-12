/*
	Relaci�n de ejercicios 6

	Ejercicio 20:	Consideramos la clase AlumnoFP desarrollada en el 
					ejercicio 17 de la Relaci�n de Problemas V. Ahora
					escribimos la clase Grupo_AlumnosFP para gestionar un 
					grupo de alumnos. Su representaci�n es un array de 
					TAMANIO datos de la clase AlumnoFP:
					
						- static const int TAMANIO = 100;
						- AlumnoFP vector_alumnos[TAMANIO];
						- int total_alumnos;

					Escribimos los m�todos p�blicos que permiten su gesti�n. 
					El conjunto de m�todos m�nimos lo deducimos del hecho de 
					que se trata de una secuencia. A�adimos un m�todo que 
					ordena los alumnos de acuerdo a su nota media. En caso de 
					coincidir la nota media, se ordenar�n por la nota de 
					teor�a; en caso de coincidencia, por la nota del segundo 
					examen pr�ctico; si siguen coincidiendo, por el del 
					primero; si a�n coinciden, por la evaluaci�n continua, y 
					si persiste el empate, por la tercera letra del apellido.

					Escribimos un programa que lee los datos de una serie 
					indefinida de alumnos (termina cuando se escribe FIN ante 
					la petici�n del apellido), los guarda en un objeto
					Grupo_AlumnosFP, los ordena y muestra el resultado de la 
					ordenaci�n.
						              
	Entradas: Grupo de alumnos de FP (grupos_alumnos).
	Salidas: Grupo de alumnos de FP ordenado seg�n el criterio dado 
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
// Clase Lector: representa una lectura etiquetada de datos int y double
/***************************************************************************/
class Lector {
	
	private:
		
		string titulo;		// Texto que etiqueta la lectura
		
	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Lector() : titulo("") { }
		
		/*******************************************************************/
		// Constructor con par�metros
		/*******************************************************************/
		Lector(string valor_titulo) : titulo(valor_titulo) { }	
		
		/*******************************************************************/
		// M�todo: SetTitulo()
		// Descripci�n: Establece el texto que etiqueta la lectura
		// Recibe: Texto que etiqueta la lectura (valor_titulo)
		// Devuelve: -
		/*******************************************************************/
		void SetTitulo(string valor_titulo) {
			
			titulo = valor_titulo;
		}
		
		/*******************************************************************/
		// M�todo: GetTitulo()
		// Descripci�n: Devuelve el texto que etiqueta la lectura
		// Recibe: -
		// Devuelve: Texto que etiqueta la lectura (titulo)
		/*******************************************************************/
		string GetTitulo() {
			
			return titulo;	
		}
		
		/*******************************************************************/
		// M�todo: LeeEntero()
		// Descripci�n: Lee un n�mero entero
		// Recibe: -
		// Devuelve: N�mero entero (numero).
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
		// M�todo: LeeEnteroEnRango()
		// Descripci�n: Lee un n�mero entero dentro del rango 
		//              ["menor" , "mayor"]
		// Recibe: Valor m�nimo del rango (menor),
		//		   Valor m�ximo del rango (mayor)
		// Devuelve: N�mero entero dentro del rango (numero)
		/*******************************************************************/
		int LeeEnteroEnRango(int menor, int mayor) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while( (numero < menor) || (numero > mayor) );
			
			return numero;	
		}
		
		/*******************************************************************/
		// M�todo: LeeEnteroMayorOIgual()
		// Descripci�n: Lee un n�mero entero mayor o igual que "referencia"
		// Recibe: N�mero entero de referencia (referencia)
		// Devuelve: N�mero entero mayor o igual que "referencia" (numero)
		/*******************************************************************/
		int LeeEnteroMayorOIgual(int referencia) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while(numero < referencia);
			
			return numero;	
		}	
		
		/*******************************************************************/
		// M�todo: LeeEnteroMayor()
		// Descripci�n: Lee un n�mero entero mayor que "referencia"
		// Recibe: N�mero entero de referencia (referencia)
		// Devuelve: N�mero entero mayor que "referencia" (numero)
		/*******************************************************************/
		int LeeEnteroMayor(int referencia) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while(numero <= referencia);
			
			return numero;	
		}
		
		/*******************************************************************/
		// M�todo: LeeDouble()
		// Descripci�n: Lee un n�mero real
		// Recibe: -
		// Devuelve: N�mero real (numero).
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
		// M�todo: LeeDoubleEnRango()
		// Descripci�n: Lee un n�mero real dentro del rango ["menor" , "mayor"]
		// Recibe: Valor m�nimo del rango (menor),
		//		   Valor m�ximo del rango (mayor)
		// Devuelve: N�mero real dentro del rango (numero)
		/*******************************************************************/
		double LeeDoubleEnRango(double menor, double mayor) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while( (numero < menor) || (numero > mayor) );
			
			return numero;	
		}
		
		/*******************************************************************/
		// M�todo: LeeDoubleMayorOIgual()
		// Descripci�n: Lee un n�mero real mayor o igual que "referencia"
		// Recibe: N�mero real de referencia (referencia)
		// Devuelve: N�mero real mayor o igual que "referencia" (numero)
		/*******************************************************************/
		double LeeDoubleMayorOIgual(double referencia) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while(numero < referencia);
			
			return numero;	
		}
		
		/*******************************************************************/
		// M�todo: LeeDoubleMayor()
		// Descripci�n: Lee un n�mero real mayor que "referencia"
		// Recibe: N�mero real de referencia (referencia)
		// Devuelve: N�mero real mayor que "referencia" (numero)
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
		// M�todo: EsEntero()
		// Descripci�n: Comprueba si un n�mero es entero.
		// Recibe: Cadena (cadena)
		// Devuelve: True (1) si "cadena" es un n�mero entero y False (0)
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
		// M�todo: EsReal()
		// Descripci�n: Comprueba si un n�mero es real.
		// Recibe: Cadena (cadena)
		// Devuelve: True (1) si "cadena" es un n�mero real y False (0)
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
//                 asignatura "Fundamentos de Programaci�n"
/***************************************************************************/
class AlumnoFP {
	
	private:
		
		string nombre;		// Nombre del alumno
		string apellidos;	// Apellidos del alumno
		string dni;			// DNI del alumno
		
		double nota_examen_teoria;		   // Nota del alumno en el examen de 
		                                   // teor�a
		double nota_examen_practico1;	   // Nota del alumno en el primer 
		                                   // examen pr�ctico
		double nota_examen_practico2;      // Nota del alumno en el segundo 
		                                   // examen pr�ctico
		double nota_evaluacion_continua;   // Nota del alumno en la evaluaci�n
		                                   // continua
		
	public:
		
				
		static const double PORCENTAJE_EXM_TEORIA;	// Ponderaci�n del examen
		                                            // de teor�a
		static const double PORCENTAJE_EXM_PRACT1;  // Ponderaci�n del primer
		                                            // examen pr�ctico
		static const double PORCENTAJE_EXM_PRACT2;  // Ponderaci�n del segundo
		                                            // examen pr�ctico
		static const double PORCENTAJE_EV_CONT;     // Ponderaci�n de la
		                                            // evaluaci�n continua
		                                            
		static const double NOTA_MINIMA_PARA_MEDIA; // Nota m�nima que hay
		 											// que obtener en el
		 											// examen de teor�a para
		 											// hacer media

		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		AlumnoFP() : nombre(""), apellidos(""), dni(""), 
		             nota_examen_teoria(0.0), nota_examen_practico1(0.0), 
					 nota_examen_practico2(0.0), nota_evaluacion_continua(0.0)
					 { }
	
		/*******************************************************************/
		// Constructor con par�metros
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
		// M�todo: SetNombre()
		// Descripci�n: Establece el nombre del alumno
		// Recibe: Nombre del alumno (nombre_alumno)
		// Devuelve: -
		/*******************************************************************/
		void SetNombre(string nombre_alumno) {
			
			nombre = nombre_alumno;	
		}
		
		/*******************************************************************/
		// M�todo: SetApellido1()
		// Descripci�n: Establece el primer apellido del alumno
		// Recibe: Primer apellido del alumno (apellido1_alumno)
		// Devuelve: -
		/*******************************************************************/
		void SetApellidos(string apellidos_alumno) {
			
			apellidos = apellidos_alumno;
		}
		
		/*******************************************************************/
		// M�todo: SetDni()
		// Descripci�n: Establece el DNI del alumno
		// Recibe: DNI del alumno (dni_alumno)
		// Devuelve: -
		/*******************************************************************/
		void SetDni(string dni_alumno) {
			
			dni = dni_alumno;	
		}
		
		/*******************************************************************/
		// M�todo: SetNotaExamenTeoria()
		// Descripci�n: Establece la nota del alumno en el examen de teor�a
		// Recibe: Nota del alumno en el examen de teor�a (nota_exm_teoria)
		// Devuelve: -
		// PRE: 0 <= nota_exm_teoria <= 10
		/*******************************************************************/
		void SetNotaExamenTeoria(double nota_exm_teoria) {
			
			nota_examen_teoria = nota_exm_teoria;
		}
		
		/*******************************************************************/
		// M�todo: SetNotaExamenPractico1()
		// Descripci�n: Establece la nota del alumno en el primer examen
		//              pr�ctico
		// Recibe: Nota del alumno en el primer examen pr�ctico 
		//         (nota_exm_pract1)
		// Devuelve: -
		// PRE: 0 <= nota_exm_pract1 <= 10
		/*******************************************************************/
		void SetNotaExamenPractico1(double nota_exm_pract1) {
			
			nota_examen_practico1 = nota_exm_pract1;
		}
		
		/*******************************************************************/
		// M�todo: SetNotaExamenPractico2()
		// Descripci�n: Establece la nota del alumno en el segundo examen
		//              pr�ctico
		// Recibe: Nota del alumno en el segundo examen pr�ctico 
		//         (nota_exm_pract2)
		// Devuelve: -
		// PRE: 0 <= nota_exm_pract2 <= 10
		/*******************************************************************/
		void SetNotaExamenPractico2(double nota_exm_pract2) {
			
			nota_examen_practico2 = nota_exm_pract2;
		}
		
		/*******************************************************************/
		// M�todo: SetNotaEvaluacionContinua()
		// Descripci�n: Establece la nota del alumno en la evaluaci�n continua
		// Recibe: Nota del alumno en la evaluaci�n continua
		//         (nota_ev_cont)
		// Devuelve: -
		// PRE: 0 <= nota_ev_cont <= 10
		/*******************************************************************/
		void SetNotaEvaluacionContinua(double nota_ev_cont) {
			
			nota_evaluacion_continua = 	nota_ev_cont;
		}
		
		/*******************************************************************/
		// M�todo: GetNombre()
		// Descripci�n: Devuelve el nombre del alumno
		// Recibe: -
		// Devuelve: Nombre del alumno (nombre)
		/*******************************************************************/
		string GetNombre() {
			
			return nombre;
		}
		
		/*******************************************************************/
		// M�todo: GetApellido1()
		// Descripci�n: Devuelve el primer apellido del alumno
		// Recibe: -
		// Devuelve: Primer apellido del alumno (apellido1)
		/*******************************************************************/
		string GetApellidos() {
			
			return apellidos;	
		}
		
		/*******************************************************************/
		// M�todo: GetDni()
		// Descripci�n: Devuelve el DNI del alumno
		// Recibe: -
		// Devuelve: DNI del alumno (dni)
		/*******************************************************************/
		string GetDni() {
			
			return dni;	
		}
		
		/*******************************************************************/
		// M�todo: GetNotaExamenTeoria()
		// Descripci�n: Devuelve la nota del alumno en el examen de teor�a
		// Recibe: -
		// Devuelve: Nota del alumno en el examen de teor�a 
		//           (nota_examen_teoria)
		/*******************************************************************/
		double GetNotaExamenTeoria() {
			
			return nota_examen_teoria;
		}
		
		/*******************************************************************/
		// M�todo: GetNotaExamenPractico1()
		// Descripci�n: Devuelve la nota del alumno en el primer examen 
		//              pr�ctico
		// Recibe: -
		// Devuelve: Nota del alumno en el primer examen pr�ctico
		//           (nota_examen_practico1)
		/*******************************************************************/
		double GetNotaExamenPractico1() {
			
			return nota_examen_practico1;
		}
		
		/*******************************************************************/
		// M�todo: GetNotaExamenPractico2()
		// Descripci�n: Devuelve la nota del alumno en el segundo examen 
		//              pr�ctico
		// Recibe: -
		// Devuelve: Nota del alumno en el segundo examen pr�ctico
		//           (nota_examen_practico2)
		/*******************************************************************/
		double GetNotaExamenPractico2() {
			
			return nota_examen_practico2;
		}
		
		/*******************************************************************/
		// M�todo: GetNotaEvaluacionContinua()
		// Descripci�n: Devuelve la nota del alumno en la evaluaci�n continua
		// Recibe: -
		// Devuelve: Nota del alumno en la evaluaci�n continua
		//           (nota_evaluacion_continua)
		/*******************************************************************/
		double GetNotaEvaluacionContinua() {
			
			return nota_evaluacion_continua;
		}
		
		/*******************************************************************/
		// M�todo: GetMinimaNotaParaMedia()
		// Descripci�n: Devuelve la nota m�nima que hay que obtener en el
		//              examen de teor�a para que se le haga media al alumno
		// Recibe: -
		// Devuelve: Nota m�nima que hay que obtener en el examen de teor�a 
		//           para que se le haga media al alumno
		//           (NOTA_MINIMA_PARA_MEDIA)
		/*******************************************************************/
		double GetMinimaNotaParaMedia() {
			
			return NOTA_MINIMA_PARA_MEDIA;
		}
		
		/*******************************************************************/
		// M�todo: CalcularNotaFinal()
		// Descripci�n: Devuelve la nota final del alumno en la asignatura
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
		// M�todo: ExamenTeoriaSuspenso()
		// Descripci�n: Comprueba si el alumno ha suspendido el examen de
		//              teor�a
		// Recibe: -
		// Devuelve: True (1) si el alumno ha suspendido el examen de teor�a
		//           y False (0) si no
		/*******************************************************************/
		bool ExamenTeoriaSuspenso() {
			
			bool examen_teoria_suspenso = (nota_examen_teoria < 5.0);	
			
			return examen_teoria_suspenso;
		}
		
		/*******************************************************************/
		// M�todo: ExamenPractico1Suspenso()
		// Descripci�n: Comprueba si el alumno ha suspendido el primer
		//              examen pr�ctico
		// Recibe: -
		// Devuelve: True (1) si el alumno ha suspendido el primer examen
		//           pr�ctico y False (0) si no
		/*******************************************************************/
		bool ExamenPractico1Suspenso() {
			
			bool examen_practico1_suspenso = (nota_examen_practico1 < 5.0);	
			
			return examen_practico1_suspenso;
		}
		
		/*******************************************************************/
		// M�todo: ExamenPractico2Suspenso()
		// Descripci�n: Comprueba si el alumno ha suspendido el segundo
		//              examen pr�ctico
		// Recibe: -
		// Devuelve: True (1) si el alumno ha suspendido el segundo examen
		//           pr�ctico y False (0) si no
		/*******************************************************************/
		bool ExamenPractico2Suspenso() {
			
			bool examen_practico2_suspenso = (nota_examen_practico2 < 5.0);	
			
			return examen_practico2_suspenso;
		}
		
		/*******************************************************************/
		// M�todo: EvContinuaSuspensa()
		// Descripci�n: Comprueba si el alumno ha suspendido la evaluaci�n
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
		// M�todo: MostrarNotasSuspensas()
		// Descripci�n: Devuelve un mensaje con las notas de las partes de la
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
		// M�todo: ToString()
		// Descripci�n: Compone un string con todos los datos y notas de
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
		
		static const int TAMANIO = 100;		// N�mero m�ximo de alumnos que
											// puede haber en el grupo
		AlumnoFP vector_alumnos[TAMANIO];
		
		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_alumnos;           		// N�mero de alumnos del grupo
				
	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Grupo_AlumnosFP() : total_alumnos(0) { }
				
		/*******************************************************************/
		// M�todo: TotalAlumnos()
		// Descripci�n: Devuelve el n�mero de alumnos del grupo
		// Recibe: -
		// Devuelve: N�mero de alumnos del grupo (total_alumnos)
		/*******************************************************************/
		int TotalAlumnos() {
			
			return total_alumnos;
		}
		
		/*******************************************************************/
		// M�todo: Capacidad()
		// Descripci�n: Devuelve el n�mero m�ximo de alumnos que puede haber 
		//              en el grupo
		// Recibe: -
		// Devuelve: N�mero m�ximo de alumnos que puede haber en el grupo 
		//           (TAMANIO)
		/*******************************************************************/
		int Capacidad() {
			
			return TAMANIO;
		}
		
		/*******************************************************************/
		// M�todo: EliminaTodos()
		// Descripci�n: "Vac�a" completamente el vector de alumnos
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaTodos() {
			
			total_alumnos = 0;
		}
		
		/*******************************************************************/
		// M�todo: Aniade()
		// Descripci�n: A�ade un nuevo alumno al final del vector de alumnos. 
		//              La adici�n se realiza si hay alguna casilla disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nuevo alumno a a�adir al final del vector de alumnos (nuevo)
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
		// M�todo: Elemento()
		// Descripci�n: Devuelve el alumno que se encuentra la casilla 
		//              "indice" del vector de alumnos
		// Recibe: �ndice de la casilla del alumno a devolver (indice)
		// Devuelve: Alumno almacenado en la casilla "indice" del vector 
		//           de alumnos
		// PRE: 0 <= indice < total_alumnos
		/*******************************************************************/
		AlumnoFP Elemento(int indice) {
			
			return vector_alumnos[indice];
		}
		
		/*******************************************************************/
		// M�todo: Modifica()
		// Descripci�n: Cambia el alumno de la casilla "indice" por otro
		//              alumno dado en "nuevo". El tama�o del vector de 
		//              alumnos no cambia
		// Recibe: �ndice de la casilla del alumno a cambiar (indice)
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
		// M�todo: Elimina()
		// Descripci�n: Eliminar el alumno de la posici�n dada por "indice"
		//              en el vector de alumnos.
		//              Realiza un borrado f�sico (desplazamiento 
		//              y sustituci�n)
		// Recibe: �ndice de la casilla del alumno a eliminar (indice)
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
		// M�todo: Inserta()
		// Descripci�n: Inserta el alumno "nuevo" en el vector de alumnos justo
		//              en la posici�n dada por "indice". Desplaza todos los 
		//              alumnos una posici�n a la derecha antes de copiar en 
		//              "indice" el alumno "nuevo"
		// Recibe: �ndice de la casilla del alumno a insertar (indice),
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
		// M�todo: PosicionMinimoEntre()
		// Descripci�n: Devuelve la posici�n en el vector de alumnos del
		//              elemento m�nimo que se encuentra entre "izda" y "dcha"
		// Recibe: Extremos del rango de casillas en las cuales queremos 
		//         encontrar la posici�n del elemento m�nimo (izda, dcha).
		// Devuelve: Posici�n en la secuencia del elemento m�nimo 
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
		// M�todo: OrdenaAlumnos()
		// Descripci�n: Ordena el grupo de alumnos mediante el algoritmo
		//              de ordenaci�n por selecci�n
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
		// M�todo: ToString()
		// Descripci�n: Compone un string con todos los alumnos que pertenecen
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
		// M�todo: IntercambiaComponentesEnPosiciones()
		// Descripci�n: Intercambia los alumnos situadas en las casillas
		//              "pos_izda" y "pos_dcha" del vector de alumnos
		// Recibe: �ndice de las casillas  a intercambiar del vector de alumnos
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
// Funci�n: DNICorrecto()
// Descripci�n: Comprueba si una cadena es un DNI
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
// Funci�n: LeeDNI()
// Descripci�n: Lee un DNI
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
// Funci�n principal
/***************************************************************************/
int main() {
	
    cout.setf(ios::fixed);        // Notaci�n de punto fijo para los reales
    cout.setf(ios::showpoint);    // Mostrar siempre decimales 
    
    // Declaraci�n de constantes
    
    const string FINALIZAR = "FIN";
    
    // Declaraci�n de variables y objetos
    
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
    
    // C�lculos
    
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
