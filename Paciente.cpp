#include "Paciente.hpp"
#include <iostream>

using namespace std;

Paciente::Paciente(string id, string Nombre, int edad, float Temperatura, int presionArterial, int Dolor, string TipoDolor, int Trauma, int SintomasNeurologicos, int RequiereCirugia, int diasHospitalizacion) {
    this->id = id;
    this->nombre = Nombre;
    this->edad = edad;
    this->temperatura
     = Temperatura;
    this->presionArterial = presionArterial;
    this->dolor = Dolor;
    this->tipoDolor = TipoDolor;
    this->trauma = Trauma;
    this->sintomasNeurologicos = SintomasNeurologicos;
    this->requiereCirugia = RequiereCirugia;
    this->diasHospitalizacion = diasHospitalizacion;
    this->servicio = "Sin Asignar";
}

Paciente::~Paciente() {}

string Paciente::getId() const {
    return id;
}

string Paciente::getNombre() const {
    return nombre;
}

int Paciente::getEdad() const {
    return edad;
}

float Paciente::getTemperatura() const {
    return temperatura;
}

int Paciente::getPresionArterial() const {
    return presionArterial;
}

int Paciente::getDolor() const {
    return dolor;
}

string Paciente::getTipoDolor() const {
    return tipoDolor;
}

int Paciente::getTrauma() const {
    return trauma;
}

int Paciente::getSintomasNeurologicos() const {
    return sintomasNeurologicos;
}

int Paciente::getRequiereCirugia() const {
    return requiereCirugia;
}

int Paciente::getDiasHospitalizacion() const {
    return diasHospitalizacion;
}

string Paciente::getServicio() const {
    return servicio;
}

void Paciente::setServicio(const string& nuevoServicio) {
    servicio = nuevoServicio;
}

void Paciente::mostrar() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Temperatura: " << temperatura << endl;
    cout << "Dolor: " << dolor << endl;
    cout << "TipoDolor: " << tipoDolor << endl;
    cout << "Trauma: " << trauma << endl;
    cout << "SintomasNeurologicos: " << sintomasNeurologicos << endl;
    cout << "RequiereCirugia: " << requiereCirugia << endl;
    cout << "DiasHospitalizacion: " << diasHospitalizacion << endl;
}


