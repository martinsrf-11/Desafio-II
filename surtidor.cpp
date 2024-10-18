#include "Surtidor.h"
#include <iostream>

Surtidor::Surtidor(const std::string& codigo, const std::string& modelo)
    : codigo(codigo), modelo(modelo) {}

void Surtidor::consultarHistorico() {
    std::cout << "Consultando histórico de ventas del surtidor " << codigo << "...\n";
    // Implementar lógica para consultar el histórico
}

bool Surtidor::verificarFugas() {
    // Implementar lógica para verificar fugas
    return false; // Por ahora, devolvemos falso
}

std::string Surtidor::getCodigo() const {
    return codigo;
}
void Surtidor::realizarVenta(int litros) {
    std::cout << "Venta registrada: " << litros << " litros en el surtidor " << codigo << "\n";
}
void Surtidor::setPrecio(int tipoCombustible, double precio) {
    if (tipoCombustible >= 0 && tipoCombustible < tiposCombustible) {
        preciosCombustible[tipoCombustible] = precio;
    }
}

double Surtidor::getVentasPorCombustible(int tipoCombustible) const {
    if (tipoCombustible >= 0 && tipoCombustible < tiposCombustible) {
        return ventasCombustible[tipoCombustible];
    }
    return 0.0;  // Si el tipo de combustible no es válido
}


