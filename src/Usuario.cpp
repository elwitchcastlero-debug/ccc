#include <iostream>
#include <vector>
#include "../include/Producto.h"
#include "../include/ItemCarrito.h"
#include "../include/CarritoCompras.h"
using namespace std;

class Usuario {
    string nombre;
    int id;
    CarritoCompras carrito_compras;

public:
    Usuario(string n, int i) : nombre(n), id(i) {}

    void mostrarInfo() const {
        cout << "\nUsuario: " << nombre << " (ID: " << id << ")" << endl;
    }

    void agregarCompra(const ItemCarrito& item) {
        carrito_compras.agregarItem(item);
    }

    void quitarCompra(const ItemCarrito& item) {
        carrito_compras.quitarItem(item);
    }

    void mostrarCompras() const {
        cout << "\n--- Compras de " << nombre << " ---" << endl;
        for (const auto& item : carrito_compras.carrito()) {
            cout << item.getName()
                 << " | Cantidad: " << item.getCant()
                 << " | Precio: $" << item.getPrice()
                 << " | Subtotal: $" << item.getPrice() * item.getCant()
                 << endl;
        }
        cout << "Total gastado: $" << carrito_compras.calcularTotal() << endl;
    }

    float gasto() const {
        return carrito_compras.calcularTotal();
    }
};

// --------------------- MAIN ---------------------
int main() {
    Usuario user("Andrés", 1013459);
    user.mostrarInfo();

    // Productos disponibles
    Producto p1("Queso", 35.92, 8);
    Producto p2("Papa", 12.20, 15);
    Producto p3("Pan", 5.50, 10);
    Producto p4("Leche", 9.99, 5);
    Producto p5("Café", 25.30, 4);

    // Crear items del carrito
    ItemCarrito i1(p1, 3);
    ItemCarrito i2(p2, 5);
    ItemCarrito i3(p3, 2);
    ItemCarrito i4(p4, 1);
    ItemCarrito i5(p5, 2);

    // Crear carrito y agregar items
    CarritoCompras carrito;
    carrito.agregarItem(i1);
    carrito.agregarItem(i2);
    carrito.agregarItem(i3);
    carrito.agregarItem(i4);
    carrito.agregarItem(i5);

    // Mostrar el carrito del usuario
    carrito.mostrarCarrito();

    cout << "\nQuitando 1 producto (Papa x5)..." << endl;
    carrito.quitarItem(i2);

    cout << "\nCarrito actualizado:" << endl;
    carrito.mostrarCarrito();

    // Asociar carrito al usuario (solo demostrativo)
    cout << "\nResumen final de compras:" << endl;
    user.mostrarCompras();

    return 0;
}
