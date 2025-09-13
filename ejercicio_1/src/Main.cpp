#include <iostream>
#include <cstring>
#include <vector>

#include "include/io_files/Lectura.h"


int main() {

    char archivo[] = "../src/files/input/batallas.txt";
    io::leerBatalla(archivo);   // Simula la batalla leida del archivo
    io::leerTorneo("../src/files/input/torneo.txt"); // Simula el torneo leido del archivo
}