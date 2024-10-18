#ifndef ESTACIONDESERVICIO_H
#define ESTACIONDESERVICIO_H

#include "Surtidor.h"
#include <string>

class EstacionDeServicio {
private:
    std::string nombre;
    std::string codigo;
    std::string gerente;
    std::string region;
    std::string ubicacion;
    Surtidor** surtidores;
    int numSurtidores;
    double getVentasTotales() const;
    double ventasRegular;
    double ventasPremium;
    double ventasEcoExtra;
public:
    EstacionDeServicio(const std::string& nombre, const std::string& codigo, const std::string& gerente, const std::string& region, const std::string& ubicacion);
    ~EstacionDeServicio();
    void registrarVenta(double litros, const std::string& tipoCombustible);
    void agregarSurtidor(Surtidor* surtidor);
    void eliminarSurtidor(const std::string& codigo);
    void consultarHistorico();
    bool verificarFugas();
    std::string getCodigo() const;
    Surtidor* buscarSurtidor(const std::string& codigo);
    double ventasTotales;
    std::string getNombre() const;
    std::string getRegion() const;
    std::string getUbicacion() const;
    std::string getGerente() const;
    void calcularVentasPorTipoCombustible();
    void fijarPreciosCombustible(double precioRegular, double precioPremium, double precioEcoExtra);
    void obtenerVentasPorCombustible(double& ventasRegular, double& ventasPremium, double& ventasEcoExtra) const;
};

#endif // ESTACIONDESERVICIO_H
