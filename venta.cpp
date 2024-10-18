#include "Venta.h"

Venta::Venta(std::string fecha, std::string hora, double cantidadLitros, std::string categoriaCombustible, std::string metodoPago, std::string documentoCliente)
    : fecha(fecha), hora(hora), cantidadLitros(cantidadLitros), categoriaCombustible(categoriaCombustible), metodoPago(metodoPago), documentoCliente(documentoCliente) {}

double Venta::calcularMonto() {
    // Implementar la lógica para calcular el monto de la venta
    return 0.0; // Placeholder
}
