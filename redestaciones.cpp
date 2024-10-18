#include "RedEstaciones.h"
#include <iostream>

RedEstaciones::RedEstaciones() {
    numEstaciones = 0;
    maxEstaciones = 100;
    estaciones = new EstacionDeServicio*[maxEstaciones];
}

RedEstaciones::~RedEstaciones() {
    for (int i = 0; i < numEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;
}

void RedEstaciones::agregarEstacion(EstacionDeServicio* estacion) {
    if (numEstaciones < maxEstaciones) {
        estaciones[numEstaciones++] = estacion; // Agregar la estación y aumentar el conteo
        std::cout << "Estacion agregada con exito.\n";
    } else {
        std::cout << "No se pueden agregar mas estaciones.\n";
    }
}

void RedEstaciones::eliminarEstacion(const std::string& codigo) {
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i]->getCodigo() == codigo) {
            delete estaciones[i]; // Liberar la memoria de la estación
            for (int j = i; j < numEstaciones - 1; ++j) {
                estaciones[j] = estaciones[j + 1]; // Desplazar los elementos
            }
            --numEstaciones; // Reducir el conteo
            std::cout << "Estación eliminada.\n";
            return;
        }
    }
    std::cout << "Estación no encontrada.\n";
}

EstacionDeServicio* RedEstaciones::buscarEstacion(const std::string& codigo) {
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i]->getCodigo() == codigo) {
            return estaciones[i]; // Retornar la estación encontrada
        }
    }
    return nullptr; // Retornar nullptr si no se encuentra
}

Surtidor* RedEstaciones::buscarSurtidor(const std::string& codigo) {
    for (int i = 0; i < numEstaciones; ++i) {
        Surtidor* surtidor = estaciones[i]->buscarSurtidor(codigo);
        if (surtidor) {
            return surtidor; // Retornar el surtidor encontrado
        }
    }
    return nullptr; // Retornar nullptr si no se encuentra
}

void RedEstaciones::mostrarEstaciones() const {
    if (numEstaciones == 0) {
        std::cout << "No hay estaciones inscritas.\n";
    } else {
        std::cout << "--- Lista de Estaciones ---\n";
        for (int i = 0; i < numEstaciones; ++i) {
            std::cout << "--- Estacion " << (i + 1) << " ---";
            std::cout << "Nombre de estación: " << estaciones[i]->getNombre() << "\n";
            std::cout << "Código de estación: " << estaciones[i]->getCodigo() << "\n";
            std::cout << "Gerente de estación: " << estaciones[i]->getGerente() << "\n";
            std::cout << "Región de estación: " << estaciones[i]->getRegion() << "\n";
            std::cout << "Ubicación de estación: " << estaciones[i]->getUbicacion() << "\n";
        }
    }
}
