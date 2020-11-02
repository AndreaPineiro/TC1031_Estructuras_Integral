// =================================================================
//
// File: Equipo.h
// Author: Andrea Pineiro Cavazos
// Description: Clase equipo, que va a ser un objeto con los datos 
// del nombre del equipo de entrenamiento, ej. cuerda, y la cantidad
// que se encuentra prestada 
//
// =================================================================
#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include <iostream> 
using namespace std;

class Equipo {
	private:
		string nombre;
		int cant_prestada;
		int stringToInt(string);
	public:
		Equipo();
		Equipo(string, string);
		Equipo (string, int);
		string get_nombre() {return nombre;}
		int get_cant() {return cant_prestada;}
		void set_nombre(string nom) {nombre = nom;}
		void set_cant(int cant) {cant_prestada = cant;}
		bool operator<(Equipo);
		bool operator>(Equipo);
		void operator+(int);
		bool operator==(Equipo);
		string toString();
};

// Constructor vacio
Equipo::Equipo(){
	nombre = "";
	cant_prestada = 1;
}

// Recibe nombre y cantidad, y crea el objeto. Este recibe string
Equipo::Equipo(string nom, string cant){
	nombre = nom;
	cant_prestada = stringToInt(cant);
}

// Recibe nombre y cantidad, y crea el objeto. La cantidad es int
Equipo::Equipo(string nom, int cant){
	nombre = nom;
	cant_prestada = cant;
}

// Esta funcion convierte una string a entero
int Equipo::stringToInt(string i){
	int x;
	x = stoi(i);
	return x;
}

// Sobrecarga de operador <, que sera usado en el heap
bool Equipo::operator<(Equipo e){
	if (cant_prestada < e.cant_prestada) {
		return true;
	} else {
		return false;
	}
}

// Sobrecarga de operador >, que sera usado en el heap
bool Equipo::operator>(Equipo e){
	if (cant_prestada > e.cant_prestada){
		return true;
	} else {
		return false;
	}
}

// Sobrecarga de operador +
void Equipo::operator+(int val){
	cant_prestada += val;
}

// Sobrecarga de operador ==, que sera usado en el heap
bool Equipo::operator==(Equipo e){
	if (cant_prestada == e.cant_prestada){
		return true;
	} else {
		return false;
	}
}

// Ayuda a desplegar la informacion del objeto, nombre y cantidad.
string Equipo::toString() {
	stringstream aux;
	aux << nombre << ": " << cant_prestada << endl;
	return aux.str();
}


#endif /* EQUIPO_H */