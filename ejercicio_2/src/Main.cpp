#include "../include/App.h"
#include <vector>


// Vertices del ejemplo, se puede modificar para cambiar la figura o incluir mas c:
std::vector<float> m_vertices = {
    -1.0f,  1.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,
    0.0f,  1.0f, 0.0f,

    1.0f, -1.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, -1.0f, 0.0f
};
// Colores del ejemplo, de igual forma se puede modificar
std::vector<float> m_colors = {
    1.0f,  0.0f, 0.0f,
    0.0f,  1.0f, 0.0f,
    0.0f,  0.0f, 1.0f,

    1.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 1.0f
};

/* Metodo principal */
int main() {
    // Creamos la aplicacion
    opengl::App app;
    // Establecemos los vertices y colores a usar
    app.setVertices(m_vertices);
    app.setColors(m_colors);
    // Disfrute :DD
    return app.run();
}