#include "../include/CarritoCompras.h"
#include <iostream>
using namespace std;

CarritoCompras::CarritoCompras(vector<ItemCarrito> i)
    : items(i) {}

void CarritoCompras::agregarItem(const ItemCarrito& item) {
    items.push_back(item);
}

void CarritoCompras::quitarItem(const ItemCarrito& item) {
    bool encontrado = false;
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == item.getName()) {
            if (it->getCant() <= item.getCant()) {
                items.erase(it);
            } else {
                int nuevaCant = it->getCant() - item.getCant();
                it->setCant(nuevaCant);
            }
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
        cout << "Item no encontrado." << endl;
}

float CarritoCompras::calcularTotal() const {  // 🔽 también minúscula
    float total = 0.0;
    for (const auto& it : items) {
        total += it.getPrice() * it.getCant();
    }
    return total;
}

vector<ItemCarrito> CarritoCompras::carrito() const {
    return items;
}

void CarritoCompras::mostrarCarrito() const {
    cout << "\n--- Carrito de Compras ---" << endl;
    for (const auto& item : items) {
        cout << item.getName()
             << " | Cantidad: " << item.getCant()
             << " | Precio: $" << item.getPrice()
             << " | Subtotal: $" << item.getPrice() * item.getCant()
             << endl;
    }
    cout << "Total: $" << calcularTotal() << endl; // 🔽 también minúscula
}
