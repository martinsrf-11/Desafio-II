#ifndef SURTIDOR_H
#define SURTIDOR_H

#include <string>

class Surtidor {
private:
    std::string codigo;
    std::string modelo;
    static const int tiposCombustible = 3;
    double preciosCombustible[tiposCombustible];
    double ventasCombustible[tiposCombustible];
public:
    Surtidor(const std::string& codigo, const std::string& modelo);
    void consultarHistorico();
    bool verificarFugas();
    std::string getCodigo() const;
    void realizarVenta(int);
    void setPrecio(int tipoCombustible, double precio);
    double getVentasPorCombustible(int tipoCombustible) const;
};

#endif // SURTIDOR_H
