#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Persona{
public:
	Persona();

	Persona(const Persona& orig);
	virtual ~Persona();

	Persona(string,string,string,int);
	string getNombre();
    int getLlave();
	string getPass();
	vector<string> getLista();
	void addMensaje(string);


private:
	string nombre;
	string apellido;
	string contra;
	int llave;
	vector <string> Lista_Mensaje;
};

#endif /* PERSONA_H */
