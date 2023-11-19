cmake_minimum_required(VERSION 3.26)
project(Cpp_Test)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp_Test main.cpp
        Empresa.cpp
        Empresa.h
        RUT.cpp
        RUT.h
        Patente.cpp
        Patente.h
        Fecha.cpp
        Fecha.h
        Funciones.h
        Funciones.cpp
        patentesComerciales.txt
        Heap.h  # Agrega el archivo aquí
)

# Copiar el archivo patentesComerciales.txt al directorio de compilación
configure_file(patentesComerciales.txt patentesComerciales.txt COPYONLY)
