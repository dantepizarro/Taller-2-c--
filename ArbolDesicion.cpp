#include "ArbolDesicion.hpp"
#include <iostream>

using namespace std;

ArbolDecision::ArbolDecision() : raiz(nullptr) {}

ArbolDecision::~ArbolDecision() {
    delete raiz;
}

bool ArbolDesicion::responder(int pregunta, const Paciente& p){
    switch(pregunta){
        case 1: return p.getEdad() < 14;
        case 2: return p.getTrauma();
        case 3: return p.getRequiereCirugia();
        case 4: return p.getSintomasNeurologicos();
        case 5: {
            string tipo = p.getTipoDolor();
            for()
            //Revisa para tipoDolor, claude tiro una wea rara
        }
        case 6:
            return p.getTemperatura() >= 38.5 || p.getDolor() >= 8 || p.getPresionArterial() < 90 || p.getPresionArterial() > 180;
        case 7: return p.getDiasHospitalizacion() >= 2;

    }
    return false;
}

void ArbolDecision::construir(){
    delete raiz;

    NodoDecision* hospitalizacion = new NodoDecision(7,"DiasHospitalizacion >= 2", "DiasHospitalizacion < 2", new NodoDecision("Hospitalizacoin"), new NodoDecision("Medicina General"));

    NodoDecision* urgencia = new NodoDecision(6, "Temperatura >= 38.5, Dolor >= 8 o Presion critica", "Temperatura < 38.5, Dolor < 8 y presion normal", new NodoDecision("Urgencias"),hospitalizacion);

    NodoDecision* pecho = new NodoDecision(5,"TipoDolor == pecho", "TipoDolor != pecho", new NodoDecision("Cardiologia"), urgencia);

    NodoDecision* neurologico = new NodoDecision(4, "SintomasNeurologicos == 1", "SintomasNeurologicos == 0", new NodoDecision("Neurologia"), pecho);

    NodoDecision* cirugia = new NodoDecision(3, "RequiereCirugia == 1", "RequiereCIrugia == 0", new NodoDecision("Cirugia"), new NodoDecision("Traumatologia"));

    NodoDecision* trauma = new NodoDecision(2, "Trauma == 1", "Trauma == 0", cirugia, neurologico);

    raiz = new NodoDecision(1, "Edad < 14", "Edad >= 14", new NodoDecision("Pediatria"), trauma);
}

string ArbolDecision::evaluar(const Paciente& p, string% ruta){
    ruta = "";
    if(raiz == nullptr){
        return "Sin Asignar";
    }

    NodoDecision* actual = raiz;
    while(actual->pregunta != 0){
        if(!ruta.empty()){
            ruta += "->";
        }
        if(responder(actual->pregunta, p)){
            ruta += actual->textoSi;
            actual = actual ->no;
        }else {
            ruta += actual->textoNo;
            actual = actual->no;
        }

        
    }

    return actual->servicio;
}

void ArbolDecision::imprimirNodo(NodoDecision* nodo, int nivel){
    for(int i = 0; i < nivel; i++){
        cout << " ";
    }
    if(nodo->pregunta == 0){
        cout << nodo->servicio << endl;
    }else{
        cout << nodo->textoSi << "?" << endl;
    }
}

void ArbolDecision::RecorrerPreorden(NodoDecision* nodo, int nivel){
    if(nodo == nullptr) return;
    imprimirNodo(nodo, nivel);
    RecorrerPreorden(nodo->si, nivel +1);
    RecorrerPreorden(nodo->no, nivel +1);
}

void ArbolDecision::RecorrerInorden(NodoDecision* nodo, int nivel){
    if(nodo == nullptr) return;
    RecorrerInorden(nodo->si, nivel + 1);
    imprimirNodo(nodo, nivel);
    RecorrerInorden(nodo->no, nivel + 1);
}

void ArbolDecision::RecorrerPostorden(NodoDecision* nodo, int nivel){
    if(nodo == nullptr) return;
    RecorrerPostorden(nodo->si, nivel + 1);
    RecorrerPostorden(nodo->no, nivel + 1);
    imprimirNodo(nodo,nivel);
}

void ArbolDecision::mostrarPreorden(){
    cout << "Recorrido preorden" << endl;
    RecorrerPreorden(raiz, 0);
}

void ArbolDecision::mostrarInorden(){
    cout << "Recorrido inorden" << endl;
    RecorrerInorden(rai<,0);
}

void ArbolDecision::mostrarPostOrden(){
    cout << "Recorrido postorden" << endl;
    RecorrerPostorden(raiz,0);
}
