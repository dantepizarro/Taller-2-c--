#include "Persona.hpp"
#include <iostream>
using namespace std;

Persona::Persona(string nombre, int edad) : nombre(nombre), edad(edad) {}

Persona::~Persona() {}

string Persona::getNombre() {
    return nombre;
}

int Persona::getEdad() {
    return edad;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::mostrar() {
    cout << "Nombre: " << nombre << " | Edad: " << edad << endl;
}
