// =================================================================
//
// File: main.cpp
// Author: Andrea Pineiro Cavazos
// Description: Este proyecto agrega a una lista ligada los datos
// acerca del equipo de entrenamiento prestado a los clientes del 
// gimnasio Black Bull Fitness en la cuarentena. 
//
// =================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dlist.h"
#include "heap.h"
#include "Prestamo.h"
#include "Equipo.h"

using namespace std;


// Esta funcion escribe los resultados en un nuevo archivo .txt,
// recibe la lista y dos indices, el inicial y final.
void TxtDatos(DList<Prestamo> d, int ini, int fin){
	ofstream file("Datos.txt");
	for (int i = ini; i < fin; i++){
		file << (d.get_obj(i)).toString() << endl;
	}
	file.close();
}

int main(){
	// Declaramos variables
	DList<Prestamo> dlist;
	//SplayTree<Equipo> my_splay;
	string equipo_busqueda;
	int posInicial, posFinal;
	//int inicio, fin;
	int pos1, pos2, cant;
	string nombre;
	
	// Leemos la informacion del archivo de texto dentro de la carpeta
	// con esto creamos un objeto y lo agregamos a la lista doble.
	string line;
    ifstream lee;
    lee.open("Prestamos.csv");
    
 	// El objeto que creamos es prestamo, con el nombre de la persona a 
 	// la que se presto, la fecha, la cantidad de elementos, y el nombre
 	// del equipo de entrenamiento.
    while(lee.good()){
    	string nombre;
    	string fecha;
    	string cantidad;
    	string equipo_entrenamiento;

    	getline(lee, nombre, ',');
    	getline(lee, fecha, ',');
    	getline(lee, cantidad, ',');
    	getline(lee, equipo_entrenamiento, '\n');

    	
    	Prestamo prest(nombre, fecha, cantidad, equipo_entrenamiento);
    	dlist.add(prest);
    }

    // Usamos Insertion Sort para ordenar la informacion con respecto al numero de cuponeras
	dlist.ordenaSeleccion();

    
    // Creamos un heap que va a tener objetos tipo Equipo, que tienen
    // el nombre del equipo y la cantidad de elementos prestados.
    Heap<Equipo> heap(dlist.size);

	cout << endl << "Andrea Pineiro Cavazos A01705681" << endl;
	int opcion = 0;
	// Se presentan 4 opciones al usuario
	while (opcion < 4 && opcion > -1){
		posInicial= 0;
		posFinal = 0;
		cout << "\t\t\tOpciones:\t\t\t" << endl;
		cout << "1. Ver los datos ordenados" << endl;
		cout << "2. Buscar por nombre de equipo" << endl;
		cout << "3. Obtener equipo mas prestado" << endl;
		cout << "4. Salir" << endl;
		cin >> opcion;
		cout << endl;

		switch (opcion) {
			// En la opcion 1 en el .txt se despliega toda la informacion ordenada por objeto
			// en orden alfabetico
			case 1:
				TxtDatos(dlist, 0, dlist.size);
				cout << "Los datos se encuentran en el archivo Datos.txt\n\n";
			break;

			// En la opcion dos permite al usuario ingresar un valor de inicio y un valor de fin , 
			// y escribe en el .txt todos los datos dentro de ese rango.
			case 2:
				cout << "Introduce el nombre del equipo: ";
				cin.ignore();
				getline(cin, equipo_busqueda);
			
				// Obtenemos los indices de la posicion inicial y final
				//cout << "PRUEBA 1" << endl;
    			posInicial = dlist.findFirst(equipo_busqueda);
    			//cout << "PRUEBA 2" << endl;
    			posFinal = dlist.findLast(equipo_busqueda);
    			//cout << "PRUEBA 3" << endl;
    			//cout << posInicial << " " << posFinal << endl;
    			cout << endl;

    			if (posInicial == -1 || posFinal == -1){
    				cout << "Este objeto no existe" << endl;
    			} else {
    				TxtDatos(dlist, posInicial, posFinal);
    				cout << "Los datos se encuentran en el archivo Datos.txt\n\n";
    			}
    		break;

    		// La opcion 3 obtiene el objeto con mas piezas prestadas
    		// y lo saca del arbol, para que el usuario pueda ver la siguiente
    		case 3:
    			// Llenamos el heap con los objetos Equipo, para esto tenemos 
	  			// 2 posiciones. La primera sirve para obtener el nombre del 
	  			// equipo de la posicion inicial, mientras el elemento de la pos2
			  	// tenga el mismo nombre de equipo de entrenamiento, vamos a sumar
			  	// a la cantidad el numero de piezas que se prestaron. 
			    pos1 = 0;
				while (pos1 < dlist.size){
			    	pos2 = pos1 + 1;
			    	// Buscamos l nombre del equipo de la cantidad inicial
			    	nombre = dlist.get_obj(pos1).get_equipo();
			    	// Inicializamos la cantidad con la del objeto en la pos1
			    	cant = dlist.get_obj(pos1).get_cantidad();
			    	// Mientras sean el mismo equipo de entrenamiento sumamos la cantidad
			    	while (dlist.get_obj(pos2).get_equipo() == nombre){
			    		cant += dlist.get_obj(pos2).get_cantidad();
			    		pos2++;
			    	}
			    	// Creamos un objeto equipo con estos datos
			    	Equipo equipo (nombre, cant);
			    	heap.push(equipo); // Lo agregamos al heap
			    	pos1 = pos2; // La pos1 ahora es la pos 2
			    }

			    // Esta opcion nos permite obtener el elemento con mayor objetos prestados
    			int conti = 1;
    			while (conti == 1){
	    			if (heap.empty()){
						cout << "Ya no hay mas objetos";
						continue;
					} 
					while (heap.top().get_nombre() == ""){
						heap.pop();
					}
					// Imprime el objeto y lo borra 
					cout << heap.top().toString() << endl;
					heap.pop();

					cout << "1 para ver el siguiente elemento, 0 para salir: " << endl;
					cin >> conti;
					cout << endl;
	    		}

			break;
		}
		
		if (opcion > 4 || opcion < -1){
			cout << "Opcion invalida" << endl;
		}
	}
	cout << "Gracias" << endl;
}

/*
	Prueba 1 : Opcion 1. Ver datos ordenados
		
	ESTO SE ENCUENTRA EN UN ARCHIVO, "DATOS.TXT"

	Resultado:
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Abmat
		Pablo Manuel Gayosso Chavez 19/3/2020 1 Abmat
		Raul Duran Soto 19/3/2020 1 Abmat
		Vianney Alberto Melo Rios 31/3/2020 2 Abmat
		Mario Villarreal Mares 31/03/20 1 Abmat
		Marco Antonio Banos Rubio 31/03/20 2 Abmat
		Linnet Pasquel  31/03/20 1 Abmat
		Carla Guzman Illescas 31/03/20 1 Abmat
		Ivan Oyervides Vega 31/03/20 1 Abmat
		Claudia Camacho Carregio 06/04/20 1 Abmat
		Celinn Mirell Gutierrez Rodriguez 15/04/20 1 Abmat
		Jose Manuel Gachuz Moreno 22/03/20 1 Aros
		Fernando Ramirez Leon  08/05/20 1 Banco
		Mayra Anay Avila Martinez 27/04/20 1 Barra 25 lbs
		Julio Cornejo 22/07/20 1 Barra 25 lbs
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Barra 30 lbs
		Jose Daniel PŽrez Nunez 20/04/20 1 Barra 30 lbs
		Sandra Karina Tapia Navarrete 19/06/20 1 Barra 30 lbs
		Diego Alberto Ramirez Ceron 02/05/20 1 Barra 35 lbs
		Claudia Camacho Carregio 29/05/20 1 Barra 35 lbs
		Raul Duran Soto 19/3/2020 1 Barra 45 lbs
		Claudia Camacho Carregio 29/05/20 1 Barra 45 lbs
		Marco Antonio Banos Rubio 04/06/20 1 Barra 45 lbs
		Jose Manuel Gachuz Moreno 19/6/2020 1 Barra 45 lbs
		Vianney Alberto Melo Rios 24/06/20 2 Barra 45 lbs
		Orlando Jair Lopez Santiago 19/3/2020 1 Caja
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Caja
		Claudia Camacho Carregio 06/04/20 2 Caja
		Carla Guzman Illescas 20/05/20 1 Caja
		Pablo Manuel Gayosso Chavez 19/3/2020 1 Caja
		Daniel Morales Castillo 18/04/20 1 Cuerda
		Raul Duran Soto 19/3/2020 2 Disco 10 lbs
		Elba Zuzely Vizcaya Barrera 19/3/2020 2 Disco 10 lbs
		Jose Daniel PŽrez Nunez 20/04/20 2 Disco 10 lbs
		Mayra Anay Avila Martinez 27/04/20 2 Disco 10 lbs
		Diego Alberto Ramirez Ceron 02/05/20 2 Disco 10 lbs
		Melissa Azpeitia Hernandez 21/05/20 2 Disco 10 lbs
		Claudia Camacho Carregio 29/05/20 4 Disco 10 lbs
		Marco Antonio Banos Rubio 04/06/20 2 Disco 10 lbs
		Jose Manuel Gachuz Moreno 19/6/2020 2 Disco 10 lbs
		Sandra Karina Tapia Navarrete 19/06/20 2 Disco 10 lbs
		Vianney Alberto Melo Rios 24/06/20 4 Disco 10 lbs
		Julio Cornejo 22/07/20 1 Disco 10 lbs
		Elba Zuzely Vizcaya Barrera 19/3/2020 2 Disco 15 lbs
		Jose Daniel PŽrez Nunez 20/04/20 2 Disco 15 lbs
		Mayra Anay Avila Martinez 27/04/20 2 Disco 15 lbs
		Diego Alberto Ramirez Ceron 02/05/20 2 Disco 15 lbs
		Marco Antonio Banos Rubio 04/06/20 2 Disco 15 lbs
		Sandra Karina Tapia Navarrete 19/06/20 2 Disco 15 lbs
		Vianney Alberto Melo Rios 24/06/20 2 Disco 15 lbs
		Elba Zuzely Vizcaya Barrera 19/3/2020 2 Disco 25 lbs
		Diego Alberto Ramirez Ceron 02/05/20 2 Disco 25 lbs
		Melissa Azpeitia Hernandez 21/05/20 2 Disco 25 lbs
		Claudia Camacho Carregio 29/05/20 4 Disco 25 lbs
		Claudia Camacho Carregio 29/05/20 4 Disco 25 lbs
		Jose Manuel Gachuz Moreno 19/6/2020 2 Disco 25 lbs
		Jose Manuel Gachuz Moreno 19/6/2020 2 Disco 25 lbs
		Vianney Alberto Melo Rios 24/06/20 2 Disco 25 lbs
		Raul Duran Soto 19/3/2020 2 Disco 25 lbs
		Julio Cornejo 22/07/20 1 Disco 25 lbs
		Vianney Alberto Melo Rios 24/06/20 2 Disco 35 lbs
		Vianney Alberto Melo Rios 24/06/20 2 Disco 45 lbs
		Elba Zuzely Vizcaya Barrera 19/3/2020 2 Disco metal 2.5 kg
		Marco Antonio Banos Rubio 04/06/20 2 Disco metal 2.5 kg
		Jose Manuel Gachuz Moreno 19/6/2020 2 Disco metal 2.5 kg
		Elba Zuzely Vizcaya Barrera 19/3/2020 2 Disco metal 2.5 kg
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Dumbbell 10 lbs
		Raul Duran Soto 19/3/2020 1 Dumbbell 20 lbs
		Selma Janett Calleja Carrillo 22/04/20 1 Dumbbell 20 lbs
		Orlando Jair Lopez Santiago 19/3/2020 1 Dumbbell 20 lbs
		Maria Concepcion Avila Martinez 19/3/2020 1 Dumbbell 20 lbs
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Dumbbell 20 lbs
		Claudia Camacho Carregio 06/04/20 1 Dumbbell 30 lbs
		Vianney Alberto Melo Rios 19/3/2020 1 Dumbbell 30 lbs
		Celinn Mirell Gutierrez Rodriguez 15/04/20 1 Dumbbell 30 lbs
		Pablo Manuel Gayosso Chavez 19/3/2020 1 Dumbbell 30 lbs
		Mario Villarreal Mares 20/3/2020 1 Dumbbell 35 lbs
		Raul Duran Soto 19/3/2020 1 Dumbbell 35 lbs
		Marco Antonio Banos Rubio 31/03/20 1 Dumbbell 35 lbs
		Maria Concepcion Avila Martinez 22/05/20 1 Dumbbell 35 lbs
		Pablo Manuel Gayosso Chavez 19/3/2020 1 Dumbbell 35 lbs
		Carla Guzman Illescas 31/03/20 1 Dumbbell 35 lbs
		Linnet Pasquel  31/03/20 1 Dumbbell 35 lbs
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Dumbbell 35 lbs
		Daniel Morales Castillo 18/04/20 1 Dumbbell 40 lbs
		Ivan Oyervides Vega 31/03/20 1 Dumbbell 40 lbs
		Jalil Aparicio Cortazar 19/3/2020 1 Dumbbell 50 lbs
		Claudia Camacho Carregio 06/04/20 1 Dumbbell 50 lbs
		Vianney Alberto Melo Rios 19/3/2020 1 Dumbbell 50 lbs
		Pablo Manuel Gayosso Chavez 19/3/2020 1 Dumbbell 50 lbs
		Raul Duran Soto 19/3/2020 1 Dumbbell 50 lbs
		Marco Antonio Lozada Copca 20/3/2020 1 Dumbbell 50 lbs
		Angeles Zeydel Olivares 23/07/20 1 Kettlebell 10 lbs
		Sandra Karina Tapia Navarrete 22/05/20 1 Kettlebell 18 lbs
		Julio Cesar Hernandez Velasco 22/06/20 1 Kettlebell 18 lbs
		Berenice Alfaro Ponce 29/07/20 1 Kettlebell 18 lbs
		Selma Janett Calleja Carrillo 22/04/20 1 Kettlebell 22 lbs
		Marco Antonio Banos Rubio 31/03/20 1 Kettlebell 22 lbs
		Fernando Ramirez Leon  08/05/20 2 Kettlebell 22 lbs
		Sandra Karina Tapia Navarrete 22/05/20 1 Kettlebell 35 lbs
		Sandra Karina Tapia Navarrete 22/05/20 1 Kettlebell 35 lbs
		Diego Alberto Ramirez Ceron 02/05/20 1 Kettlebell 35 lbs
		Marco Antonio Lozada Copca 20/03/20 1 Kettlebell 35 lbs
		Maria Esther Hernandez Diaz 22/06/20 1 Kettlebell 35 lbs
		Sean 23/06/20 1 Kettlebell 35 lbs
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Kettlebell 35 lbs
		Gaston Ceron 22/3/2020 1 Kettlebell 35 lbs
		Raul Duran Soto 19/3/2020 1 Kettlebell 35 lbs
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Kettlebell 50 lbs
		Berenice Alfaro Ponce 29/07/20 1 Kettlebell 50 lbs
		Pablo Manuel Gayosso Chavez 19/3/2020 3 Liga chica
		Vianney Alberto Melo Rios 31/3/2020 2 Liga chica
		Carla Guzman Illescas 31/03/20 1 Liga chica
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Liga chica
		Linnet Pasquel  31/03/20 1 Liga chica
		Raul Duran Soto 19/3/2020 1 Liga grande
		Ivan Oyervides Vega 31/03/20 1 Liga grande
		Pablo Manuel Gayosso Chavez 19/3/2020 1 Liga grande
		Marco Antonio Banos Rubio 31/03/20 1 Liga grande
		Mario Villarreal Mares 31/03/20 1 Liga grande
		Jalil Aparicio Cortazar 19/3/2020 1 Liga grande
		Claudia Camacho Carregio 29/05/20 4 Seguro
		Vianney Alberto Melo Rios 24/06/20 4 Seguro
		Elba Zuzely Vizcaya Barrera 19/3/2020 2 Seguro
		Mayra Anay Avila Martinez 27/04/20 4 Seguro
		Julio Cornejo 22/07/20 2 Seguro
		Sandra Karina Tapia Navarrete 19/06/20 2 Seguro
		Jose Manuel Gachuz Moreno 19/6/2020 2 Seguro
		Marco Antonio Banos Rubio 04/06/20 2 Seguro
		Orlando Jair Lopez Santiago 19/3/2020 2 Soporte hook
		Pablo Manuel Gayosso Chavez 19/3/2020 4 Tapete
		Carla Guzman Illescas 31/03/20 1 Tapete
		Orlando Jair Lopez Santiago 19/3/2020 1 Tapete
		Celinn Mirell Gutierrez Rodriguez 15/04/20 1 Tapete
		Angeles Zeydel Olivares 23/07/20 3 Tapete
		Marco Antonio Banos Rubio 31/03/20 1 Tapete
		Mario Villarreal Mares 31/3/2020 1 Tapete
		Raul Duran Soto 19/3/2020 1 Tapete



Prueba 2 : Opcion 3. Obtener equipo mas prestado
		
		"Disco 10 lbs 27"
		"1 para ver el siguiente elemento, 0 para salir: "

		1

		"Disco 25 lbs 23"
		"1 para ver el siguiente elemento, 0 para salir: "

		1

		"Seguro 22"
		"1 para ver el siguiente elemento, 0 para salir: "

		1

		"Disco 15 lbs 14"
		"1 para ver el siguiente elemento, 0 para salir: "

		1

		"Abmat 13"
		"1 para ver el siguiente elemento, 0 para salir: "

		0


Prueba 3 : Opcion 2. Buscar por rango
	Valor inicial: 2 // Out of range
	Valor final: 2 // Out of range

	Resultado: 
		Elba Zuzely Vizcaya Barrera 19/3/2020 1 Abmat
		Pablo Manuel Gayosso Chavez 19/3/2020 1 Abmat
		Raul Duran Soto 19/3/2020 1 Abmat
		Vianney Alberto Melo Rios 31/3/2020 2 Abmat
		Mario Villarreal Mares 31/03/20 1 Abmat
		Marco Antonio Banos Rubio 31/03/20 2 Abmat
		Linnet Pasquel  31/03/20 1 Abmat
		Carla Guzman Illescas 31/03/20 1 Abmat
		Ivan Oyervides Vega 31/03/20 1 Abmat
		Claudia Camacho Carregio 06/04/20 1 Abmat


*/
