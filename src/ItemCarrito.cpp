#include "../include/ItemCarrito.h"
#include <sstream>
#include <iomanip>
using namespace std;

ItemCarrito::ItemCarrito(Producto p, int c)
    : product(p), cantidad(c) {}

vector<string> ItemCarrito::detallesItem() {
    vector<string> item;
    string name = product.getNombre();
    item.push_back(name);

    int cant = product.getCantidad();
    if (cantidad <= cant && cantidad > 0) {
        item.push_back(to_string(cantidad));
        product.setCantidad(cant - cantidad);
    } else {
        item.push_back(to_string(cant));
        product.setCantidad(0);
    }
    return item;
}

string ItemCarrito::getName() const {
    return product.getNombre();
}

float ItemCarrito::getPrice() const {   // ✅ corregido a const
    return product.getPrecio();
}

int ItemCarrito::getCant() const {
    int cantProd = product.getCantidad();
    if (cantidad <= cantProd && cantidad > 0)
        return cantidad;
    else
        return cantProd;
}

void ItemCarrito::setCant(int c) {
    cantidad = c;
}

