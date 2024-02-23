#pragma once

/**
 * @brief Clase base abstracta para manejar la visibilidad de los objetos.
 */
class DelegadoVisibilidad
{
public:
    virtual ~DelegadoVisibilidad()
    {
    } // Destructor virtual

    virtual void dibuja() = 0;
};

class Invisible : public DelegadoVisibilidad
{
public:
    void dibuja() override;
};

class Visible : public DelegadoVisibilidad
{
public:
    void dibuja() override;
};
