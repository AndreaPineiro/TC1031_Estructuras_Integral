// =================================================================
//
// File: main.cpp
// Author: Andrea Pineiro Cavazos
// Description: Este proyecto agrega a una lista ligada los datos
// acerca de los atletas inscritos en el gimnasio Black Bull Fitness
// y el numero de cumponeras que han comprado
//
// =================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dlist.h"
#include "Data.h"

using namespace std;


// Esta funcion escribe los resultados en un nuevo archivo .txt,
// recibe la lista y dos indices, el inicial y final.
void TxtDatos(DList<Data> d, int ini, int fin){
	ofstream file("Datos.txt");
	for (int i = ini; i < fin; i++){
		file << (d.get_obj(i)).toString() << endl;
	}
	file.close();
}

int main(){
	// Declaramos variables
	DList<Data> dlist;
	int numInicial, numFinal;
	int posInicial, posFinal;
	
	// Leemos la informacion del archivo de texto dentro de la carpeta
	// con esto creamos un objeto y lo agregamos a la lista doble.
	string line;
    ifstream lee;
    lee.open("Cuponeras.csv");
    
    while(lee.good()){
    	string nombre;
    	string cuponera;

    	getline(lee, nombre, ',');
    	getline(lee, cuponera, '\n');

    	Data dat(nombre, cuponera);
    	dlist.add(dat);
    }

    // Usamos Insertion Sort para ordenar la informacion con respecto al numero de cuponeras
	dlist.ordenaSeleccion();

	cout << endl << "Andrea Pineiro Cavazos A01705681" << endl;
	int opcion = 0;
	// Se presentan 3 opciones al usuario
	while (opcion != 3){
		cout << "\t\t\tOpciones:\t\t\t" << endl;
		cout << "1. Ver los datos ordenados" << endl;
		cout << "2. Buscar por rango" << endl;
		cout << "3. Salir" << endl;
		cin >> opcion;
		cout << endl;

		// En la opcion 1 en el .txt se despliega toda la informacion ordenada por numero de cuponeras
		if (opcion == 1){
			TxtDatos(dlist, 0, dlist.size);
			cout << "Los datos se encuentran en Datos.txt\n\n";

		// En la opcion dos permite al usuario ingresar un valor de inicio y un valor de fin , 
		// y escribe en el .txt todos los datos dentro de ese rango.
		} else if (opcion == 2){


			cout << "Introduce el valor inicial: ";
			cin >> numInicial;

			cout << "Introduce el valor final: ";
			cin >> numFinal;
			
			// Obtenemos los indices de la posicion inicial y final
    		posInicial = dlist.findFirst(numInicial);
    		posFinal = dlist.findLast(numFinal);
    		cout << endl;

    		// Si el valor inicial es mayor al ultimo valor se encuentra fuera del limite
    		if (numInicial > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
        		cout << "Las fechas exceden el limite. \n" << endl;
    		}
    		
    		// Si el valor final es menor al primer valor se encuentra debajo del limite
    		else if(numFinal < (dlist.get_obj(0)).get_cuponeras()){
        		cout << "Las fechas estan por debajo del limite. \n" << endl;
    		}

    		else {
    			// Si el primer numero no se encuentra, el primer indice sera 0
    			if (numInicial < (dlist.get_obj(0)).get_cuponeras()){
    				posInicial = 0;
    			}

    			// Si el segundo numero no se encuentra el ultimo indice sera el final.
    			if (numFinal > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    				posFinal = dlist.size - 1;
    			}

    			TxtDatos(dlist, posInicial, posFinal);
    			cout << "Los datos se encuentran en Datos.txt\n\n";
    		}
    		

		// La opcion 3 saca al usuario
		} else if (opcion == 3){
			cout << "Gracias" << endl;
			break;

		// Si el usuario ingresa otro numero el sistema muestra error
		} else {
			cout << "Opcion invalida" << endl;
		}
	}

}

/*
	Prueba 1 : Opcion 1. Ver datos ordenados
	Resultado:
		Crisalida Yohel Ramirez Rodriguez 1 
		Gabriela Barranco Mendoza 1 
		Gloria Griselda Pedrizuela Arenal 1 
		Jose Daniel Perez Nunez 1 
		Jesus Octavio Olivares Gonzalez 1 
		Jorge Alberto Gonzalez Melendez 1 
		Jorge Armando Paz Estrada 1 
		Marco Antonio Dominguez Lopez 1 
		Martha Guerrero Olvera 1 
		Mitzi Yael Porras Perez 1 
		Navil Marlen Acosta Olvera 1 
		Naydelin Ruiz Hernandez 1 
		Oscar Nashiel Gonzalez Lara 1 
		Regina Rojas Crespo 1 
		Suriel Martinez Serrano 1 
		Zaira Omana Sanchez 1 
		Magali Citlalli Reyes Garcia 2 
		Maria de los Angeles Villanueva Espinosa 2 
		﻿Angel Zaid Cruz Olivarez 2 
		Naoli Alfaro Ponce 2 
		Danya Omana Sanchez 2 
		Angeles Zeydel Olivares Hidalgo 2 
		Juan Francisco Bello Jardines  2 
		Julio Cesar Hernandez Velasco 2 
		Rodrigo Osvaldo Cortes Montiel 2 
		Sergio Rogelio Perez Ramirez  2 
		Valerio Ivan Islas Charolet 2 
		Luis David Cruz Olivarez 2 
		Mario Villarreal Mares  3 
		Berenice Alfaro Ponce  3 
		Luba Miriam Laski Covarrubias 4 
		Axel Ishac Licona Calderon 4 
		Maria Esther Hernandez Diaz 4 


Prueba 2 : Opcion 2. Buscar por rango
	Valor inicial: -1 // Out of range
	Valor final: 2

	Resultado: 
		Crisalida Yohel Ramirez Rodriguez 1 
		Gabriela Barranco Mendoza 1 
		Gloria Griselda Pedrizuela Arenal 1 
		Jose Daniel Perez Nunez 1 
		Jesus Octavio Olivares Gonzalez 1 
		Jorge Alberto Gonzalez Melendez 1 
		Jorge Armando Paz Estrada 1 
		Marco Antonio Dominguez Lopez 1 
		Martha Guerrero Olvera 1 
		Mitzi Yael Porras Perez 1 
		Navil Marlen Acosta Olvera 1 
		Naydelin Ruiz Hernandez 1 
		Oscar Nashiel Gonzalez Lara 1 
		Regina Rojas Crespo 1 
		Suriel Martinez Serrano 1 
		Zaira Omana Sanchez 1 
		Magali Citlalli Reyes Garcia 2 
		Maria de los Angeles Villanueva Espinosa 2 
		﻿Angel Zaid Cruz Olivarez 2 
		Naoli Alfaro Ponce 2 
		Danya Omana Sanchez 2 
		Angeles Zeydel Olivares Hidalgo 2 
		Juan Francisco Bello Jardines  2 
		Julio Cesar Hernandez Velasco 2 
		Rodrigo Osvaldo Cortes Montiel 2 
		Sergio Rogelio Perez Ramirez  2 
		Valerio Ivan Islas Charolet 2 

Prueba 3 : Opcion 2. Buscar por rango
	Valor inicial: 2 // Out of range
	Valor final: 2 // Out of range

	Resultado: 
		Magali Citlalli Reyes Garcia 2 
		Maria de los Angeles Villanueva Espinosa 2 
		﻿Angel Zaid Cruz Olivarez 2 
		Naoli Alfaro Ponce 2 
		Danya Omana Sanchez 2 
		Angeles Zeydel Olivares Hidalgo 2 
		Juan Francisco Bello Jardines  2 
		Julio Cesar Hernandez Velasco 2 
		Rodrigo Osvaldo Cortes Montiel 2 
		Sergio Rogelio Perez Ramirez  2 
		Valerio Ivan Islas Charolet 2 

*/
