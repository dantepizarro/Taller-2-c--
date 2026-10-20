#pragma once
#include <iostream>
using namespace std;


class Paciente {
private:

    string id,TipoDolor,Nombre;
    int edad,Dolor,Trauma,SintomasNeurologicos,RequiereCirugia;
    float Temperatura;
    

    

public:
    Paciente(string id,string Nombre, int edad, string TipoDolor, int Dolor, int Trauma, int SintomasNeurologicos, int RequiereCirugia);
    ~Paciente();

    string getID();
    string getNombre();
    string getTipoDolor();
    int getEdad();
    int getDolor();
    int getTrauma();
    int getSintomasNeurologicos();
    int getRequiereCirugia();


    
    
};


