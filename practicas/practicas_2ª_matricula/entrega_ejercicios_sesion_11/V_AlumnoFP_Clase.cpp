/*
	Relación de ejercicios 5

	Ejercicio 17: Programa que lee los datos y del alumno, calcula su 
	              nota final en FP y en caso de haber obtenido una nota 
				  inferior a 5 en alguna de las partes, indica la nota obtenida
				  en dicha parte.
	              
	Entradas: Datos del alumno (nombre_alumno, apellido1_alumno, dni_alumno),
	          Notas del alumno (nota_exm_teoria, nota_exm_pract1, 
			                    nota_exm_pract2, nota_ev_cont).
	Salidas: Nota final del alumno (nota_final),
	         Nota de aquellas partes que el alumno ha suspendido.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

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
// Clase AlumnoFP: permite representar las notas de un alumno de la
//                 asignatura "Fundamentos de Programación"
/***************************************************************************/
class AlumnoFP {
	
	private:
		
		string nombre;		// Nombre del alumno
		string apellido1;	// Primer apellido del alumno
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

		/*******************************************************************/
		// Constructor con parámetros
		// PRE: 0 <= nota_exm_teoria <= 10
		//      0 <= nota_exm_pract1 <= 10
		//      0 <= nota_exm_pract2 <= 10
		//      0 <= nota_ev_cont <= 10
		/*******************************************************************/
		AlumnoFP(string nombre_alumno, string apellido1_alumno, 
		         string dni_alumno, double nota_exm_teoria, 
				 double nota_exm_pract1, double nota_exm_pract2,
				 double nota_ev_cont)
				:  nombre(nombre_alumno), apellido1(apellido1_alumno),
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
		void SetApellido1(string apellido1_alumno) {
			
			apellido1 = apellido1_alumno;
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
		string GetApellido1() {
			
			return apellido1;	
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
		// Método: CalcularNotaFinal()
		// Descripción: Devuelve la nota final del alumno en la asignatura
		// Recibe: -
		// Devuelve: Nota final del alumno en la asignatura (nota_final)
		/*******************************************************************/
		double CalcularNotaFinal() {
			
			double nota_final;
			
			if(nota_examen_teoria >= 4)
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
};

// Ponderación del examen de teoría = 60 %
const double AlumnoFP::PORCENTAJE_EXM_TEORIA = 0.6;
// Ponderación del primer examen práctico = 10 %
const double AlumnoFP::PORCENTAJE_EXM_PRACT1 = 0.1;
// Ponderación del segundo examen práctico = 20 %
const double AlumnoFP::PORCENTAJE_EXM_PRACT2 = 0.2;
// Ponderación de la evaluación continua = 10 %
const double AlumnoFP::PORCENTAJE_EV_CONT = 0.1;

/*******************************************************************/
// Función: EsReal()
// Descripción: Comprueba si una cadena es un número real
// Recibe: Cadena a comprobar si es un número real (cadena)
// Devuelve: True (1) si "cadena" es un número real y False (0) si 
//           no lo es
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

/*******************************************************************/
// Función: LeeReal()
// Descripción: Lee un número real
// Recibe: Texto que etiqueta la lectura (titulo)
// Devuelve: Número real (numero)
/*******************************************************************/
double LeeReal(string titulo) {
	
	string numero;
	
	do {
		
		cout << titulo;
		getline(cin, numero);
		
	}while( !EsReal(numero) );
	
	return ( stod(numero) ); 
}

/*******************************************************************/
// Función: LeeRealEnRango()
// Descripción: Lee un número real dentro del rango ["menor" , "mayor"]
// Recibe: Texto que etiqueta la lectura (titulo),
//         Valor mínimo del rango (menor),
//		   Valor máximo del rango (mayor)
// Devuelve: Número real dentro del rango (numero)
/*******************************************************************/
double LeeRealEnRango(string titulo, double menor, double mayor) {
	
	double numero; 
	
	do {
		numero = LeeReal(titulo);		
	}while( (numero < menor) || (numero > mayor) );
	
	return numero;	
}

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
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Declaración de variables
	
	string nombre_alumno, apellido1_alumno, dni_alumno;
	double nota_exm_teoria, nota_exm_pract1, nota_exm_pract2, nota_ev_cont;
	
	// Entradas de datos
	
	cout << " Introduzca el nombre del alumno: ";
	getline(cin, nombre_alumno);
	
	cout << " Introduzca el primer apellido del alumno: ";
	getline(cin, apellido1_alumno);
	
	dni_alumno = LeeDNI(" Introduzca el DNI del alumno: ");

	nota_exm_teoria = LeeRealEnRango
	                  (" Introduzca la nota del examen de teoria: ", 0, 10);
	                  
	nota_exm_pract1 = LeeRealEnRango
	                  (" Introduzca la nota del examen practico 1: ", 0, 10);
	  
  	nota_exm_pract2 = LeeRealEnRango
                  	  (" Introduzca la nota del examen practico 2: ", 0, 10);  
						
  	nota_ev_cont = LeeRealEnRango
                  	  (" Introduzca la nota de la evaluacion continua: ", 
					   0, 10); 
	
	// Cálculos
	
	ManipuladorString m(nombre_alumno);
	m.EliminaSeparadoresInicialesyFinales();
	nombre_alumno = m.GetCadena();
	
	m.SetCadena(apellido1_alumno);
	m.EliminaSeparadoresInicialesyFinales();
	apellido1_alumno = m.GetCadena();   
	
	// Declaración de un objeto de la clase AlumnoFP
	
	AlumnoFP alumno(nombre_alumno, apellido1_alumno, dni_alumno, 
	                nota_exm_teoria, nota_exm_pract1, nota_exm_pract2,
					nota_ev_cont);
					
	double nota_final = alumno.CalcularNotaFinal();
	
	// Salidas
	
	cout << endl;
	cout << " Nota final del alumno " << alumno.GetNombre() << " "
	     << alumno.GetApellido1() << ": " << setprecision(3) << nota_final;
	
	cout << endl << endl;
	cout << " Partes suspensas del alumno: ";
	cout << endl << endl;
	cout << alumno.MostrarNotasSuspensas();
	cout << endl << endl;
	
	return 0;
}
