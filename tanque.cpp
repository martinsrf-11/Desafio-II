#include "Tanque.h"

Tanque::Tanque(double capacidadTotal, double capacidadDisponible, std::string categoriaCombustible)
    : capacidadTotal(capacidadTotal), capacidadDisponible(capacidadDisponible), categoriaCombustible(categoriaCombustible) {}

void Tanque::actualizarCapacidad(double cantidad) {
    capacidadDisponible -= cantidad; // Actualiza la capacidad disponible
}

bool Tanque::verificarFugas() {
    // Implementar la lógica para verificar fugas
    return false; // Placeholder
}

