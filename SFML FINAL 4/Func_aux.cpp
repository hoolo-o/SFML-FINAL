#include "Func_aux.h"
#include <iostream>


std::vector<Esqueleto> EsqueletosBordes(int cantidad, sf::Texture* TE, char* mapa)
{
    std::vector<Esqueleto> esqueletos;

    int ancho = 75;
    int alto = 44;

    for (int An = 0; An < ancho; An++) {
        for (int Al = 0; Al < alto; Al++) {

            if (*(mapa + An * 44 + Al) == 'X') {
                sf::Vector2f posini = { An * 16.0f, Al * 16.0f };
                if (probabilidad(20) and esqueletos.size()<cantidad) {
                    std::cout << "X ";
                    Esqueleto esqts(1, 15, 20, 1.0f, posini, TE);
                    esqts.setVelocidadAleatoria(0.4f, 1.0f);
                    esqueletos.push_back(esqts);
                }
            }

        }
    }
    return esqueletos;
}

bool probabilidad(int prob)
{
    int aleatorio = std::rand() % 100;
    return aleatorio < prob;
}

bool Colision(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
    return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
    std::cout << "HIT" << std::endl;
}

bool ColisionCirculo(const CircleShape& circulo1, const CircleShape& circulo2) {
    sf::Vector2f cent1 = circulo1.getPosition() + Vector2f(circulo1.getRadius(), circulo1.getRadius());
    sf::Vector2f cent2 = circulo2.getPosition() + Vector2f(circulo2.getRadius(), circulo2.getRadius());
    float distan = sqrt(std::pow(cent2.x - cent1.x, 2) + pow(cent2.y - cent1.y, 2));
    return distan <= circulo1.getRadius() + circulo2.getRadius();
}

Vector2f calcularOffset(const CircleShape& circle1, const CircleShape& circle2, float velocidad) {
    // Obtener las posiciones de los círculos
    Vector2f pos1 = circle1.getPosition();
    Vector2f pos2 = circle2.getPosition();

    // Calcular la distancia entre los centros de los círculos
    float distancia = sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2));

    // Calcular la suma de los radios de los círculos
    float sumaRadios = circle1.getRadius() + circle2.getRadius();

    // Verificar si hay colisión
    if (distancia < sumaRadios) {
        // Calcular el vector de separación (offset)
        Vector2f offset = pos2 - pos1;
        float magnitud = sqrt(offset.x * offset.x + offset.y * offset.y);

        // Normalizar el vector y escalarlo para que la distancia sea igual a la suma de los radios
        offset = offset / magnitud * (sumaRadios - distancia);

        // Aplicar el offset de manera progresiva
        offset *= velocidad;

        return offset;
    }

    // No hay colisión, devolver un vector nulo
    return Vector2f(0.f, 0.f);
}
