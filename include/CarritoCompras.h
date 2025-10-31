#ifndef CARRITO_COMPRAS_H
#define CARRITO_COMPRAS_H

#include <vector>
#include "ItemCarrito.h"

class CarritoCompras {
private:
    std::vector<ItemCarrito> items;

public:
    CarritoCompras(std::vector<ItemCarrito> i = {});

    void agregarItem(const ItemCarrito& item);
    void quitarItem(const ItemCarrito& item);
    float calcularTotal() const;  // 🔽 minúscula
    std::vector<ItemCarrito> carrito() const;
    void mostrarCarrito() const;
};

#endif
