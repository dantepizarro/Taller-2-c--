#pragma once
#include <string>

class NodoDecision {
public:
    int pregunta = 0;
    std::string textoSi;
    std::string textoNo;
    std:: string servicio;
    NodoDecision* si;
    NodoDecision* no;

    NodoDecision(std::string servicio) : pregunta(0), servicio(servicio), si(nullptr), no(nullptr) {}

    NodoDecision(int pregunta, std::string textoSi, std::string textoNo, NodoDecision* si, NodoDecision* no) : pregunta(pregunta), textoSi(textoSi), textoNo(textoNo), si(si), no(no) {}

    ~NodoDecision(){
        delete si;
        delete no;
    }
};