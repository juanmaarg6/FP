/*
	Ejercicio 18: Programa que calcula el area de un
	              poligono convexo.
	              
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <cmath>

using namespace std;

struct TipoPunto{
	double abscisa;
	double ordenada;
};

struct TipoPoligono{
	TipoPunto puntos[100];
	int num_puntos;
};

/*
	Funcion que calcula la distancia entre dos puntos.
	
	Parametros: punto1 (TipoPunto), punto2 (TipoPunto).
	
	Algoritmo:
		Se calcula la diferencia de las abscisas y la diferencia de las
		ordenadas de los dos puntos.
		
		Se eleva al cuadrado cada una de las diferencias.
		
		Se calcula la distancia entre los dos puntos como la raiz cuadrada
		de la suma de ambas diferencias al cuadrado.
				
	Devuelve: distancia (double), es decir, la distancia entre dos puntos.
*/
double DistanciaPuntos(TipoPunto punto1, TipoPunto punto2);

/*
	Funcion que calcula el area de un triangulo a partir de las longitudes
	de sus lados.
	
	Parametros: punto1 (TipoPunto), punto2 (TipoPunto), punto3 (TipoPunto).
	
	Algoritmo:
		Se calcula la longitud de cada lado del triangulo en funcion de las
		coordenadas de los vertices de dicho triangulo.
		
		Se calcula el semiperimetro del triangulo.
		
		Se calcula el area del triangulo mediante la siguiente formula:
			area = sqrt(semiperimetro * (semiperimetro - lado1) * (semiperimetro - lado2) * (semiperimetro - lado3));
	
	Devuelve: area_triangulo (double), es decir, el area del triangulo.
*/
double AreaTriangulo( TipoPunto punto1, TipoPunto punto2, TipoPunto punto3);

/*
	Funcion que calcula el area de un poligono como suma de areas
	de varios triangulos.
	
	Parametros: poligono (TipoPoligono).
	
	Algoritmo:
		Si el poligono es un triangulo, entonces el area del poligono
		es el area de dicho triangulo.
		Si no:
			Se didive el poligono en dos partes: una triangulo T1 
			y otra poligono B.
			
			Se calculan los puntos y el numero de puntos del poligono B.
			
			Se calcula el area del poligono como la suma del area de T1 
			mas el area de B (si B no es un triangulo entonces se le
			aplica a dicho poligono todo este proceso).		
	
	Devuelve: area_poligono (double), es decir, el area del poligono.
*/
double AreaPoligono(TipoPoligono poligono);

int main(){
	TipoPoligono poligono;
	double area_poligono;
	
	int vertice;
	
	/*
		Algoritmo:
		
		El usuario introduce el numero de vertices del poligono
		y las coordenadas de cada vertice.
		
		Se calcula el area del poligono.
		
		Se muestra en pantalla el area del poligono.
	*/
	
	cout << " Introduzca el numero de vertices del poligono: ";
	cin >> poligono.num_puntos;
	
	cout << endl;
	
	if(poligono.num_puntos < 3){
		cout << "\n Error. Un poligono tiene como minimo 3 vertices" << endl << endl;
		exit(-1);
	}

	for(int i = 0; i < poligono.num_puntos; i++){
		vertice = i + 1;
		cout << " Introduzca las coordenadas del vertice " << vertice << ": ";
		cin >> poligono.puntos[i].abscisa >> poligono.puntos[i].ordenada;
	}
	
	area_poligono = AreaPoligono(poligono);
	
	cout << "\n El area del poligono es " << area_poligono << endl << endl;
		
	system("pause");
}

double DistanciaPuntos(TipoPunto punto1, TipoPunto punto2){
	double diferencia_x, diferencia_y;
	double cuadrado_diferencia_x, cuadrado_diferencia_y;
	double distancia;
	
	diferencia_x = abs((punto1.abscisa - punto2.abscisa));
	diferencia_y = abs((punto1.ordenada - punto2.ordenada));
	
	cuadrado_diferencia_x = diferencia_x * diferencia_x;
	cuadrado_diferencia_y = diferencia_y * diferencia_y;

	distancia = sqrt(cuadrado_diferencia_x + cuadrado_diferencia_y);
	
	return distancia;
}

double AreaTriangulo( TipoPunto punto1, TipoPunto punto2, TipoPunto punto3){
	double lado1, lado2, lado3;
	double semiperimetro;
	double area_triangulo;
	
	lado1 = DistanciaPuntos(punto1, punto2);
	lado2 = DistanciaPuntos(punto2, punto3);
	lado3 = DistanciaPuntos(punto3, punto1);
	
	semiperimetro = (lado1 + lado2 + lado3) / 2;
	
	area_triangulo = sqrt(semiperimetro * (semiperimetro - lado1) * (semiperimetro - lado2) * (semiperimetro - lado3));
	
	return area_triangulo;
}

double AreaPoligono(TipoPoligono poligono){
   double area_poligono;
    
   if(poligono.num_puntos == 3)
      area_poligono = AreaTriangulo(poligono.puntos[0], poligono.puntos[1], poligono.puntos[2]);
	
	else{	
      TipoPoligono T1 = {{poligono.puntos[0], poligono.puntos[1], poligono.puntos[2]}, 3};
      TipoPoligono B;
        
      int j = 0;
        
      for(int i = 0; i < poligono.num_puntos; i++){
         if(i != 1){
            B.puntos[j] = poligono.puntos[i];
            j++;
         }
      }
        
      B.num_puntos = j;
        
      area_poligono = AreaPoligono(T1) + AreaPoligono(B);
   }
    
   return area_poligono;
}
