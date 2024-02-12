/*
	Ejercicio 15: Programa que, dado un fichero con los resultados
					  de los partidos de "n" equipos, muestra las
					puntuaciones de cada equipo.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAXIMA_LONGITUD = 100;

/*
	Clase en la que cada objeto de ella representa una
	liga de "n" equipos.
*/
class Liga{
   private:
      vector <vector<char> > partidos; // Partidos de la liga
   
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
      Liga();
      
      /*
			Constructor de la clase.
			
			Parametros: numero_equipos (int).
			
			Devuelve: -
		*/	
      Liga(int numero_equipos);
      
      /*
			Funcion que establece el resultado de un partido
			entre dos equipos de la liga..
			
			Parametros: equipo1 (int), equipo2 (int), resultado (int).
			
			Devuelve: -
		*/	
      void NuevoResultado(int equipo1, int equipo2, char resultado);
      
      /*
			Funcion que calcula las puntuaciones de cada equipo de la
			liga.
			
			Parametros: -
			
			Devuelve: -
		*/	
      vector<int> CalcularPuntuaciones();
};

/*
	Clase sin datos miembro que lee los datos de los resultados de los
	equipos y construye el objeto liga.
*/
class GeneradorLiga{
   public:
   	/*
			Funcion que lee los datos de los resultados de los equipos
			de la liga.
			
			Parametros: -
			
			Devuelve: -
		*/	
      Liga Leer();
};

void ImprimeResultados(vector<int> vector);

int main(){
	GeneradorLiga generador;
   Liga liga = generador.Leer();
    
   vector<int> puntuaciones = liga.CalcularPuntuaciones();
   ImprimeResultados(puntuaciones);
   
   cout << endl << endl;
   system("pause");
}

Liga::Liga(){
}

Liga::Liga(int numero_equipos){
   partidos.resize(numero_equipos);
    
   for(int i = 0; i < partidos.size(); i++)
      partidos[i].resize(numero_equipos);
}

void Liga::NuevoResultado(int equipo1, int equipo2, char resultado){
   if(equipo1 < partidos.size() && equipo2 < partidos.size())
      partidos[equipo1][equipo2] = resultado;
}

vector<int> Liga::CalcularPuntuaciones(){
   vector<int> puntos(partidos.size(), 0);
    
   for(int i = 0; i < partidos.size(); i++)
      for(int j = 0; j < partidos[i].size(); j++)
         if(i != j){
            if(partidos[i][j] == '1')
               puntos[i] += 3;
				else if(partidos[i][j] == '2')
               puntos[j] += 3;
				else{
            	puntos[i] += 1;
               puntos[j] += 1;
            }
         }
    
   return puntos;
}

Liga GeneradorLiga::Leer(){
   int numero_equipos, equipo1, equipo2;
   int partidos;
   char resultado;
    
   cin >> numero_equipos;
    
   Liga liga(numero_equipos);
    
   partidos = numero_equipos * (numero_equipos - 1);
   
   for(int i = 0; i < partidos; i++){
      cin >> equipo1;
      
      cin >> equipo2;
      
      cin >> resultado;
      
      liga.NuevoResultado(equipo1, equipo2, resultado);
   }
    
   return liga;
}

void ImprimeResultados(vector<int> vector){
   for(int i = 0; i < vector.size(); i++)
   	cout << "\n El equipo " << i + 1 << " tiene " << vector[i] << " puntos." << endl;
}
