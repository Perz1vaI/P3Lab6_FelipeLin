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

int main(int argc, char** argv) {
    vector<Persona> lista_persona;
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

                Persona p(nombre, apellido, pass, llave);

                lista_persona.push_back(p);

                cout << "nombre:: " << lista_persona.at(0).getNombre() << endl;
                cout << "pass:: " << lista_persona.at(0).getPass() << endl;
                cout << "llave:: " << lista_persona.at(0).getLlave() << endl;






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


                cout << " tamanio : " << lista_persona.size() << endl;
                for (int i = 0; i < lista_persona.size(); i++) {
                    cout << "i=" << i << endl;
                    cout << "nombre: " << lista_persona.at(i).getNombre() << endl;
                    cout << "contra: " << lista_persona.at(i).getPass() << endl;
                    if (lista_persona.at(i).getNombre() == login_name && lista_persona.at(i).getPass() == login_contra) {
                        int menu;
                        cout << "1. Enviar mensaje\n2. Ver mensaje\n3. Ver mi llave\n4. Salir\n";
                        cout << "Ingrese la opcion: ";
                        cin >> menu;
                        while (menu != 4) {
                            switch (menu) {
                                case 1:
                                {
                                    cout << "si entras aqui sos el puto amo";

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

