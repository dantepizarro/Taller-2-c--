#pragma once
#include <iostream>

using namespace std;

class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad);
    virtual ~Persona();

    string getNombre() ;
    int getEdad() ;

    void setNombre(string nombre);
    void setEdad(int edad);

    virtual void mostrar();

};