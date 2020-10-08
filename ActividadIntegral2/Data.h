// =================================================================
//
// File: dato.h
// Author: Andrea Piñeiro Cavazos
// Description: Clase data, que va a ser un objeto con los datos 
// del nombre de la persona y el número de cuponeras adquiridas.
// Linked List
//
// =================================================================

#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream> 
using namespace std;

class Data {
	private:
		string nombre;
		int num_cuponeras;
		int stringToInt(string);

	public:
		Data();
		Data(string, string);
		string get_nombre() {return nombre;}
		int get_cuponeras() {return num_cuponeras;}
		void set_nombre(string nom) {nombre = nom;}
		void set_cuponeras(int cup) {num_cuponeras += cup;}
		bool operator<(Data);
		bool operator==(int);
		string toString();
};

// Constructor vacío
Data::Data(){
	nombre = "";
	num_cuponeras = 0;
}

// Recibe nombre y cupones, y crea el objeto
Data::Data(string nom, string cup){
	nombre = nom;
	num_cuponeras = stringToInt(cup);
}

// Esta función convierte una string a entero
int Data::stringToInt(string i){
	int x;
	x = stoi(i);
	return x;
}

// Sobrecarga de operador <, que sera usado en la lista ligada
bool Data::operator<(Data d){
	if (num_cuponeras < d.num_cuponeras){
		return true;
	} else {
		return false;
	}
}

// Sobrecarga de operador ==, que sera usado en la lista ligada
bool Data::operator==(int cup){
	if (num_cuponeras == cup){
		return true;
	} else {
		return false;
	}
}

// Ayuda a desplegar la información del objeto, nombre y cuponeras.
string Data::toString(){
	stringstream aux;
	aux << nombre << " " << num_cuponeras << " ";
	return aux.str();
}


#endif /* DATA_H */
