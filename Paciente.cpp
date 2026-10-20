#include "Paciente.hpp"
#include <iostream>
using namespace std;


Paciente::Paciente(string id, string Nombre, int edad, string TipoDolor, int Dolor, int Trauma, int SintomasNeurogologicos, int RequiereCirugia) {}

Paciente::~Paciente() {}

string Paciente::getID() {
    return id;
}

string Paciente::getNombre() {
    return Nombre;
}

string Paciente::getTipoDolor(){
    return TipoDolor;
}

int Paciente::getEdad(){
    return edad;
}

int Paciente::getDolor(){
    return Dolor;
}

int Paciente::getTrauma(){
    return Trauma;
}

int Paciente::getSintomasNeurologicos(){
    return SintomasNeurologicos;
}

int Paciente::getRequiereCirugia(){
    return RequiereCirugia;
}



