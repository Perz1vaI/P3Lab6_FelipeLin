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

char cifradocesar_adelante(char, int);
char cifradocesar_atras(char, int);
string recursivo(string, int, int);
string recursivo_revez(string, int, int);

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

                llave = rand() % 4 + 1;

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
                int persona_selec;

                for (int i = 0; i < lista_persona.size(); i++) {

                    if (lista_persona.at(i)->getNombre() == login_name && lista_persona.at(i)->getPass() == login_contra) {
                        persona_selec = i;
                        int menu;
                        cout << "1. Enviar mensaje\n2. Ver mensaje\n3. Ver mi llave\n4. Salir\n";
                        cout << "Ingrese la opcion: ";
                        cin >> menu;
                        while (menu != 4) {
                            switch (menu) {
                                case 1:
                                {
                                    int persona_enviar;

                                    cout << "*ENVIAR MENSAJE*" << endl;

                                    for (int i = 0; i < lista_persona.size(); i++) {
                                        cout << i << "." << lista_persona[persona_selec]->getNombre() << endl;
                                    }

                                    cout << "Ingrese el numero de la persona que quiere enviar: " << endl;
                                    cin >> persona_enviar;

                                    string mensaje;
                                    cout << "Ingrese el mensaje que quiere codificar: " << endl;
                                    cin >> mensaje;

                                    string mensaje_codificado;

                                    mensaje_codificado = recursivo(mensaje, lista_persona[persona_selec]->getLlave(), 0);

                                    lista_persona[persona_enviar]->addMensaje(mensaje_codificado);



                                    break;
                                }
                                case 2:
                                {
                                    cout << "*VER MENSAJES*" << endl;

                                    for (int i = 0; i < lista_persona.size(); i++) {
                                        cout << i + 1 << ". De: " << lista_persona[persona_selec]->getNombre() << " ";
                                        for (int i = 0; i < lista_persona[persona_selec]->getLista().size(); i++) {
                                            cout << lista_persona[persona_selec]->getLista().at(i);
                                        }
                                        cout << endl;
                                    }
                                    int selec_mensaje;
                                    cout << "Seleccione el mensaje: " << endl;
                                    cin >> selec_mensaje;

                                    string mensaje_decodificado;


                                    mensaje_decodificado = recursivo(lista_persona[selec_mensaje]->getLista().at(0), lista_persona[selec_mensaje]->getLlave(), 0);

                                    cout << "El mensaje decodificado: " << endl;
                                    cout << "[TEXT]:" << mensaje_decodificado << endl;



                                    break;
                                }
                                case 3:
                                {
                                    cout << "*VER MI LLAVE*" << endl;

                                    cout << lista_persona[persona_selec]->getNombre() << " su llave es " << lista_persona[persona_selec]->getLlave() << endl;

                                    break;
                                }
                                default:
                                {
                                    cout << "No existe esa opcion\n";
                                    break;
                                }
                            }
                            cout << "1. Enviar mensaje\n2. Ver mensaje\n3. Ver mi llave\n4. Salir\n";
                            cout << "Ingrese la opcion: ";
                            cin >> menu;
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

string recursivo(string msj, int llave, int contador_llave) {

    bool cambio = false;
    if (llave == 0) {
        return msj;
    } else {
        for (int i = 0; i < msj.size(); i += llave) {

            if (!cambio) {
                for (int j = 0; j < llave; j++) {
                    msj[contador_llave] = cifradocesar_adelante(msj[contador_llave], llave);
                    contador_llave++;
                }
                cambio = true;


            } else {
                for (int j = 0; j < llave; j++) {
                    msj[contador_llave] = cifradocesar_atras(msj[contador_llave], llave);
                    contador_llave++;
                }

                cambio = false;
            }

        }

        recursivo(msj, llave - 1, contador_llave);
    }
    return msj;
}

string recursivo_revez(string msj, int llave, int contador_llave) {

    bool cambio = false;
    if (llave == 0) {
        return msj;
    } else {
        for (int i = 0; i < msj.size(); i += llave) {

            if (!cambio) {
                for (int j = 0; j < llave; j++) {
                    msj[contador_llave] = cifradocesar_atras(msj[contador_llave], llave);
                    contador_llave++;
                }
                cambio = true;


            } else {
                for (int j = 0; j < llave; j++) {
                    msj[contador_llave] = cifradocesar_adelante(msj[contador_llave], llave);
                    contador_llave++;

                }

                cambio = false;
            }

        }

        recursivo(msj, llave - 1, contador_llave);
    }
    return msj;
}

char cifradocesar_adelante(char texto, int desplazamiento) {
    int aux;
    aux = texto;
    aux = aux + desplazamiento;
    texto = aux;

    return texto;

}

char cifradocesar_atras(char texto, int desplazamiento) {
    int aux;
    aux = texto;
    aux = aux - desplazamiento;
    texto = aux;

    return texto;

}



