#include "../include/Producto.h"
#include <sstream>
#include <iomanip>
using namespace std;

Producto::Producto(string n, float p, int c)
    : nombre(n), precio(p), cantidad(c) {}

vector<string> Producto::productoDetalles() const {
    vector<string> prod;
    prod.push_back(nombre);
    ostringstream oss;
    oss << fixed << setprecision(2) << precio;
    prod.push_back(oss.str());
    prod.push_back(to_string(cantidad));
    return prod;
}

string Producto::getNombre() const {
    return nombre;
}

float Producto::getPrecio() const {
    return precio;
}

int Producto::getCantidad() const {
    return cantidad;
}

void Producto::setCantidad(int c) {
    cantidad = c;
}
