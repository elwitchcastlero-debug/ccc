#ifndef ITEM_CARRITO_H
#define ITEM_CARRITO_H

#include <string>
#include <vector>
#include "Producto.h"

class ItemCarrito {
private:
    Producto product;
    int cantidad;

public:
    // Constructor
    ItemCarrito(Producto p, int c);

    // Método para obtener detalles del item
    std::vector<std::string> detallesItem();

    // Getters
    std::string getName() const;
    float getPrice() const;   // ✅ Debe ser const
    int getCant() const;

    // Setter
    void setCant(int c);
};

#endif
