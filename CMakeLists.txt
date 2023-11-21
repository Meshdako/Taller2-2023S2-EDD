cmake_minimum_required(VERSION 3.26)
project(Cpp_Test)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(Cpp_Test src/main.cpp
        src/Empresa.cpp
        include/Empresa.h
        src/RUT.cpp
        include/RUT.h
        src/Patente.cpp
        include/Patente.h
        src/Fecha.cpp
        include/Fecha.h
        include/Funciones.h
        src/Funciones.cpp
        patentesComerciales.txt
        include/Heap.h
)

# Copiar el archivo patentesComerciales.txt al directorio de compilación
configure_file(patentesComerciales.txt patentesComerciales.txt COPYONLY)
