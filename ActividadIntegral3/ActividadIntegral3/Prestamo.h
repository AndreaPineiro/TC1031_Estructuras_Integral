// =================================================================
//
// File: prestamo.h
// Author: Andrea Pineiro Cavazos
// Description: Clase prestamo, que va a ser un objeto con los datos 
// de los prestamos, con el nombre de la persona, la fecha en la que
// se hizo el prestamo, la cantidad de articulos y el nombre
//
// =================================================================

#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>
#include <iostream> 
using namespace std;

class Prestamo {
	private:
		string nombre;
		string fecha;
		int cantidad;
		string equipo_entrenamiento;
		int stringToInt(string);

	public:
		Prestamo();
		Prestamo(string, string, string, string);
		string get_nombre() {return nombre;}
		string get_fecha() {return fecha;}
		int get_cantidad() {return cantidad;}
		string get_equipo() {return equipo_entrenamiento;}
		void set_nombre(string nom) {nombre = nom;}
		void set_fecha(string fec) {fecha = fec;}
		void set_cantidad(int cant) {cantidad = cant;}
		void set_equipo(string equip) {equipo_entrenamiento = equip;}
		bool operator<(Prestamo);
		bool operator==(string);
		string toString();
};

// Constructor vacio
Prestamo::Prestamo(){
	nombre = "";
	fecha = "";
	cantidad = 0;
	equipo_entrenamiento = "";
}

// Recibe nombre, fecha, cantidad, y equipo, y crea el objeto
Prestamo::Prestamo(string nom, string fech, string cant, string equip){
	nombre = nom;
	fecha = fech;
	cantidad = stringToInt(cant);
	equipo_entrenamiento = equip;
}

// Esta funcion convierte una string a entero
int Prestamo::stringToInt(string i){
	int x;
	x = stoi(i);
	return x;
}

// Sobrecarga de operador <, que sera usado en la lista ligada
bool Prestamo::operator<(Prestamo d){
	if (equipo_entrenamiento < d.equipo_entrenamiento){
		return true;
	} else {
		return false;
	}
}

// Sobrecarga de operador ==, que sera usado en la lista ligada
bool Prestamo::operator==(string equipo){
	if (equipo_entrenamiento == equipo){
		return true;
	} else {
		return false;
	}
}

// Ayuda a desplegar la informacion del objeto, nombre, fecha, cantidad
// y el nombre del equipo de entrenamiento.
string Prestamo::toString(){
	stringstream aux;
	aux << nombre << " " << fecha << " " << cantidad << " " << equipo_entrenamiento;
	return aux.str();
}


#endif /* PRESTAMO_H */
