/*
 *  Created on: 22/11/2020
 *      Author: Andrea Pineiro Cavazos
 *
 *  Programa que contiene los casos de prueba para 
 *  los préstamos de equipo en el gimnasio Black Bull Fitness
 *  
 *  Casos de prueba incluidos al final
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dlist.h"
#include "heap.h"
#include "Prestamo.h"
#include "Equipo.h"

using namespace std;

int main(){
	DList<Prestamo> dlist;
	//SplayTree<Equipo> my_splay;
	string equipo_busqueda;
	int posInicial, posFinal;
	//int inicio, fin;
	int pos1, pos2, cant;
	string nombre;
	string ans = "";
	string prueba = "";
	
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
    lee.close();

    // Usamos Insertion Sort para ordenar la informacion con respecto al numero de cuponeras
	dlist.ordenaSeleccion();

    
    // Creamos un heap que va a tener objetos tipo Equipo, que tienen
    // el nombre del equipo y la cantidad de elementos prestados.
    Heap<Equipo> heap(dlist.size);

 	cout << endl << "\t\tAndrea Pineiro Cavazos A01705681\t\t" << endl;
	cout << "\t\t\tPRESTAMOS BBFIT HOME\t\t\t" << endl << endl;
	
	// Se prueba la opción 1, para mostrar los datos ordenados por
	// fecha.
	cout << "PRUEBA 1: DATOS ORDENADOS EN EL TXT" << endl;
	
	stringstream aux1;
	stringstream aux2;

	// Leemos el archivo con la respuesta correcta y lo guardamos en 
	// una string.
	ifstream arch ("OrdenadoForTest.txt");
	if (arch.is_open()){
		 while (getline(arch, line)){
			if (line[0] != ','){
				aux1 << line << "\n";
				//ans.push_back(line);;
			}
		} 
		arch.close();
	}
	else {
		cout << "Unable to open file";
	}
	ans = aux1.str();

	
	for (int i = 0; i < dlist.size; i++){
		aux2 << (dlist.get_obj(i)).toString() << "\n";
	}	
	prueba = aux2.str();

    cout << "\t\t1 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


    stringstream aux;
    // Se prueba la opción 2 de Buscar por nombre de equipo
	aux.str("");
	cout << endl << "PRUEBA 2: BUSCAR POR NOMBRE DE EQUIPO";
	equipo_busqueda = "Abmat";
	cout << endl;
	cout << "\tNombre = Abmat\t\t" << endl;

	ans = "Elba Zuzely Vizcaya Barrera 19/3/2020 1 Abmat  Pablo Manuel Gayosso Chavez 19/3/2020 1 Abmat  Raul Duran Soto 19/3/2020 1 Abmat  Vianney Alberto Melo Rios 31/3/2020 2 Abmat  Mario Villarreal Mares 31/03/20 1 Abmat  Marco Antonio Banos Rubio 31/03/20 2 Abmat  Linnet Pasquel  31/03/20 1 Abmat  Carla Guzman Illescas 31/03/20 1 Abmat  Ivan Oyervides Vega 31/03/20 1 Abmat  Claudia Camacho Carregio 06/04/20 1 Abmat  Celinn Mirell Gutierrez Rodriguez 15/04/20 1 Abmat  ";

	// Obtenemos los indices de la posicion inicial y final
    posInicial = dlist.findFirst(equipo_busqueda);
    posFinal = dlist.findLast(equipo_busqueda);
    
    if (posInicial == -1 || posFinal == -1){
    	cout << "Este objeto no existe" << endl;
    } else {
		for (int i = posInicial; i < posFinal; i++){
			aux << dlist.get_obj(i).toString() << "  ";
		}					
    }

    prueba = aux.str();

	cout << "\t\t2 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";



	// Se prueba la opción 2 de Buscar por nombre de equipo
	aux.str("");
	cout << endl << "PRUEBA 3: BUSCAR POR NOMBRE DE EQUIPO";
	equipo_busqueda = "Caja";
	cout << endl;
	cout << "\tNombre = Caja\t\t" << endl;

	ans = "Orlando Jair Lopez Santiago 19/3/2020 1 Caja  Elba Zuzely Vizcaya Barrera 19/3/2020 1 Caja  Claudia Camacho Carregio 06/04/20 2 Caja  Carla Guzman Illescas 20/05/20 1 Caja  Pablo Manuel Gayosso Chavez 19/3/2020 1 Caja  ";

	// Obtenemos los indices de la posicion inicial y final
    posInicial = dlist.findFirst(equipo_busqueda);
    posFinal = dlist.findLast(equipo_busqueda);
    
    if (posInicial == -1 || posFinal == -1){
    	cout << "Este objeto no existe" << endl;
    } else {
		for (int i = posInicial; i < posFinal; i++){
			aux << dlist.get_obj(i).toString() << "  ";
		}					
    }

    prueba = aux.str();

	cout << "\t\t3 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";

	

	// Se prueba la opción 2 de Buscar por nombre de equipo
	aux.str("");
	cout << endl << "PRUEBA 4: BUSCAR POR NOMBRE DE EQUIPO";
	equipo_busqueda = "Disco 10 lbs";
	cout << endl;
	cout << "\tNombre = Disco 10 lbs\t\t" << endl;

	ans = "Raul Duran Soto 19/3/2020 2 Disco 10 lbs  Elba Zuzely Vizcaya Barrera 19/3/2020 2 Disco 10 lbs  Jose Daniel Perez Nunez 20/04/20 2 Disco 10 lbs  Mayra Anay Avila Martinez 27/04/20 2 Disco 10 lbs  Diego Alberto Ramirez Ceron 02/05/20 2 Disco 10 lbs  Melissa Azpeitia Hernandez 21/05/20 2 Disco 10 lbs  Claudia Camacho Carregio 29/05/20 4 Disco 10 lbs  Marco Antonio Banos Rubio 04/06/20 2 Disco 10 lbs  Jose Manuel Gachuz Moreno 19/6/2020 2 Disco 10 lbs  Sandra Karina Tapia Navarrete 19/06/20 2 Disco 10 lbs  Vianney Alberto Melo Rios 24/06/20 4 Disco 10 lbs  Julio Cornejo 22/07/20 1 Disco 10 lbs  ";

	// Obtenemos los indices de la posicion inicial y final
    posInicial = dlist.findFirst(equipo_busqueda);
    posFinal = dlist.findLast(equipo_busqueda);
    
    if (posInicial == -1 || posFinal == -1){
    	cout << "Este objeto no existe" << endl;
    } else {
		for (int i = posInicial; i < posFinal; i++){
			aux << dlist.get_obj(i).toString() << "  ";
		}					
    }

    prueba = aux.str();

	cout << "\t\t4 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


	// Se prueba la opción 3 Obtener equipo mas prestado
	cout << endl << "PRUEBA 5: OBTENER EQUIPO MAS PRESTADO";
	cout << endl;

	aux.str("");
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

	for (int i = 0; i < 6; i++){
		if (heap.empty()){
			cout << "Ya no hay mas objetos";
			continue;
		} 
		while (heap.top().get_nombre() == ""){
			heap.pop();
		}
		// Imprime el objeto y lo borra 
		aux << heap.top().toString();
		heap.pop();
		//cout << endl;
	}
	prueba = aux.str();

	ans = "Disco 25 lbs: 23\nSeguro: 22\nDisco 15 lbs: 14\nAbmat: 13\nTapete: 13\n";

	cout << prueba << endl;

	cout << "\t\t5 " << (ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";
}