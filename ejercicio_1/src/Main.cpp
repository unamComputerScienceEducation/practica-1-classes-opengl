#include <iostream>
#include <cstring>
#include <vector>

#include "../include/io_files/Lectura.h"

/* Metodo principal */
int main() {
    // Leemos los archivos de batalla y torneo
    char batalla[] = "../files/input/batallas.txt";
    io::leerBatalla(batalla);   // Simula la batalla leida del archivo
    char torneo[] = "../files/input/torneo.txt";
    io::leerTorneo(torneo); // Simula el torneo leido del archivo
}