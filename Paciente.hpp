#pragma once
#include <iostream>
#include <string>

using namespace std;

class Paciente {
private:
    string id;
    string nombre;
    int edad;
    float temperatura;
    int presionArterial;
    int dolor;
    string tipoDolor;
    int trauma;                  
    int sintomasNeurologicos;    
    int requiereCirugia;         
    int diasHospitalizacion;
    string servicio;             

public:
   
    Paciente(string id, string nombre, int edad, float temperatura, 
             int presionArterial, int dolor, string tipoDolor, 
             int trauma, int sintomasNeurologicos, int requiereCirugia, 
             int diasHospitalizacion);

    ~Paciente();

    // Getters
    string getId() const;
    string getNombre() const;
    int getEdad() const;
    float getTemperatura() const;
    int getPresionArterial() const;
    int getDolor() const;
    string getTipoDolor() const;
    int getTrauma() const;
    int getSintomasNeurologicos() const;
    int getRequiereCirugia() const;
    int getDiasHospitalizacion() const;
    string getServicio() const;

    // Setter
    void setServicio(const string& nuevoServicio);

    // Visualizacion
    void mostrar() const;
};


