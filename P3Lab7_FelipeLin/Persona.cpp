#include "Persona.h"

Persona::Persona(string nombre, string apellido,string contra,int llave) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->contra = contra;
	this->llave = llave;

}

string Persona::getNombre(){
	return nombre;
}

string Persona::getLlave(){
	return nombre;
}

string Persona::getPass(){
	return nombre;
}

vector<string> Persona::getLista(){
	return Lista_Mensaje;
}

Persona::Persona(const Persona& orig) {
}

Persona::~Persona() {
}

