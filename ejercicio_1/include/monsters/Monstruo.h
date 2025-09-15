/**
 * @file Monstruo.h
 * @brief Clase abstracta para los monstruos
 */

#ifndef MONSTRUO_H
#define MONSTRUO_H

#include <string>

namespace monster{

    /**
     * @brief Clase abstracta para los monstruos
     */
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
        /**
         * @brief Constructor con parametros
         * @param nombre Nombre del monstruo
         * @param fuerza Fuerza del monstruo
         * @param agilidad Agilidad del monstruo
         * @param inteligencia Inteligencia del monstruo
         */
        Monstruo(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            m_nombre {nombre}
            , m_fuerza {fuerza}
            , m_agilidad {agilidad}
            , m_inteligencia {inteligencia}
        {

        }

        /**
         * @brief Establece el nombre del monstruo
         * @param nombre Nombre del monstruo
         */
        void setNombre(const std::string& nombre) { m_nombre = nombre; }

        /**
         * @brief Obtiene el nombre del monstruo
         * @return Nombre del monstruo
         */
        const std::string& getNombre() const { return m_nombre; }

        /**
         * @brief Establece la fuerza del monstruo
         * @param fuerza Fuerza del monstruo
         */
        void setFuerza(const int& fuerza) { m_fuerza = fuerza; }

        /**
         * @brief Obtiene la fuerza del monstruo
         * @return Fuerza del monstruo
         */
        const int& getFuerza() const { return m_fuerza; }

        /**
         * @brief Establece la agilidad del monstruo
         * @param agilidad Agilidad del monstruo
         */
        void setAgilidad(const int& agilidad) { m_agilidad = agilidad; }

        /**
         * @brief Obtiene la agilidad del monstruo
         * @return Agilidad del monstruo
         */
        const int& getAgilidad() const { return m_agilidad; }

        /**
         * @brief Establece la inteligencia del monstruo
         * @param inteligencia Inteligencia del monstruo
         */
        void setInteligencia(const int& inteligencia) { m_inteligencia = inteligencia; }

        /**
         * @brief Obtiene la inteligencia del monstruo
         * @return Inteligencia del monstruo
         */
        const int& getInteligencia() const { return m_inteligencia; }

        /**
         * @brief Método virtual para obtener el tipo de monstruo
         * @return Tipo de monstruo (Orco, Troll, Vampiro, Dragon, Hechicero, Esqueleto, etc.)
         * Se sobreescribe en las clases derivadas
         */
        virtual std::string tipoMonstruo() const = 0;
    };
    
};
#endif // MONSTRUO_H
