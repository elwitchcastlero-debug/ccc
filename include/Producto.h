#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <vector>

class Producto {
private:
    std::string nombre;
    float precio;
    int cantidad;

public:
    Producto(std::string n, float p, int c);

    std::vector<std::string> productoDetalles() const;
    std::string getNombre() const;
    float getPrecio() const;
    int getCantidad() const;
    void setCantidad(int c);
};

#endif
