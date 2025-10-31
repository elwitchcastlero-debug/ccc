cmake_minimum_required(VERSION 3.10)
project(carrito_compras)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)


add_library(Producto src/Producto.cpp)
add_library(ItemCarrito src/ItemCarrito.cpp)
add_library(CarritoCompras src/CarritoCompras.cpp)

target_link_libraries (ItemCarrito Producto)
target_link_libraries (CarritoCompras ItemCarrito Producto)

add_executable(sistemaCarritoCompras src/Usuario.cpp)
target_link_libraries(sistemaCarritoCompras Producto ItemCarrito CarritoCompras)

