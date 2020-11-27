/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: felipelinzhao
 *
 * Created on November 27, 2020, 12:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Persona.h"

using namespace std;

string cifradocesar_adelante(string, int, int, int);
string cifradocesar_atras(string, int, int, int);

int main(int argc, char** argv) {
    vector<Persona*> lista_persona;
    int menu;
    cout << "1. Registrarse\n2. Ingresar\n3. Salir\n";
    cout << "Ingrese la opcion: ";
    cin >> menu;
    while (menu != 3) {
        switch (menu) {
            case 1:
            {
                cout << "*REGISTRO*" << endl;
                string nombre, apellido, pass;
                int llave;

                cout << "Ingrese su nombre:" << endl;
                cin >> nombre;

                cout << "Ingrese su apellido:" << endl;
                cin >> apellido;

                cout << "Ingrese su contraseña:" << endl;
                cin >> pass;

                llave = rand() % 1 + 15;

                Persona* p = new Persona(nombre, apellido, pass, llave);

                lista_persona.push_back(p);

                break;
            }
            case 2:
            {
                string login_name, login_contra;

                cout << "*LOGIN*" << endl;

                cout << "Ingrese su nombre:" << endl;
                cin >> login_name;

                cout << "Ingrese su contraseña:" << endl;
                cin >> login_contra;


                for (int i = 0; i < lista_persona.size(); i++) {

                    if (lista_persona.at(i)->getNombre() == login_name && lista_persona.at(i)->getPass() == login_contra) {
                        int menu;
                        cout << "1. Enviar mensaje\n2. Ver mensaje\n3. Ver mi llave\n4. Salir\n";
                        cout << "Ingrese la opcion: ";
                        cin >> menu;
                        while (menu != 4) {
                            switch (menu) {
                                case 1:
                                {

                                    break;
                                }
                                default:
                                {
                                    cout << "No existe esa opcion\n";
                                    break;
                                }
                            }
                        }
                    } else {
                        cout << "Ingreso mal el nombre o la contraseña" << endl;
                    }
                }

                break;
            }
            default:
            {
                cout << "No existe esa opcion\n";
                break;
            }
        }

        cout << "1. Registrarse\n2. Ingresar\n3. Salir\n";
        cout << "Ingrese la opcion: ";
        cin >> menu;

    }




}

string cifradocesar_adelante(string texto, int desplazamiento, int tamanio, int aux) {
    for (int i = 0; i < tamanio; i++) {
        aux = texto[i];
        aux = aux + desplazamiento;
        texto[i] = aux;
    }

    return texto;
}

string cifradocesar_atras(string texto, int desplazamiento, int tamanio, int aux) {
    for (int i = 0; i < tamanio; i++) {
        aux = texto[i];
        aux = aux - desplazamiento;
        texto[i] = aux;
    }

    return texto;

}



