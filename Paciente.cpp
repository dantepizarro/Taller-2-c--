#include "Paciente.hpp"
#include <iostream>

using namespace std;

Paciente::Paciente(string id, string Nombre, int edad, float Temperatura, 
                   int presionArterial, int Dolor, string TipoDolor, 
                   int Trauma, int SintomasNeurologicos, int RequiereCirugia, 
                   int diasHospitalizacion) {
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

string Paciente::getId() {
    return id;
}

string Paciente::getNombre() {
    return Nombre;
}

int Paciente::getEdad() {
    return edad;
}

float Paciente::getTemperatura() {
    return Temperatura;
}

int Paciente::getPresionArterial() {
    return presionArterial;
}

int Paciente::getDolor() {
    return Dolor;
}

string Paciente::getTipoDolor() {
    return TipoDolor;
}

int Paciente::getTrauma() {
    return Trauma;
}

int Paciente::getSintomasNeurologicos() {
    return SintomasNeurologicos;
}

int Paciente::getRequiereCirugia() {
    return RequiereCirugia;
}

int Paciente::getDiasHospitalizacion() {
    return diasHospitalizacion;
}

string Paciente::getServicio() {
    return servicio;
}

void Paciente::setServicio(string servicio) {
    this->servicio = servicio;
}

void Paciente::mostrar() {
    cout << "ID: " << id
         << " | Nombre: " << Nombre
         << " | Edad: " << edad
         << " | Temp: " << Temperatura << "°C"
         << " | Dolor: " << Dolor << " (" << TipoDolor << ")"
         << " | Servicio: " << servicio << endl;
}



