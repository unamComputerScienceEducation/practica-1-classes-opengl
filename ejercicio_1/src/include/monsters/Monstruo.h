#ifndef MONSTRUO_H
#define MONSTRUO_H

#include <string>

namespace monster{

    /* Clase abstracta para monstruos y sus derivados */
    class Monstruo
    {
    private:
        /* Nombre del monstruo */
        std::string m_nombre {};
        /* Fuerza del monstruo */
        int m_fuerza {};
        /* Agilidad del monstruo */
        int m_agilidad {};
        /* Inteligencia del monstruo */
        int m_inteligencia {};

    public:
        /* Constructor por defecto */
        Monstruo()
        {
        }
        /* Constructor con parámetros */
        Monstruo(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            m_nombre {nombre}
            , m_fuerza {fuerza}
            , m_agilidad {agilidad}
            , m_inteligencia {inteligencia}
        {

        }

        /* Getters y Setters de cada atributo */
        void setNombre(const std::string& nombre) { m_nombre = nombre; }

        const std::string& getNombre() const { return m_nombre; }

        void setFuerza(const int& fuerza) { m_fuerza = fuerza; }

        const int& getFuerza() const { return m_fuerza; }

        void setAgilidad(const int& agilidad) { m_agilidad = agilidad; }

        const int& getAgilidad() const { return m_agilidad; }

        void setInteligencia(const int& inteligencia) { m_inteligencia = inteligencia; }

        const int& getInteligencia() const { return m_inteligencia; }

        /* Metodo que nos regresa el tipo de monstruo */
        virtual std::string tipoMonstruo() const = 0; // Se sobreescribe en las clases derivadas
    };
    
};
#endif // MONSTRUO_H
