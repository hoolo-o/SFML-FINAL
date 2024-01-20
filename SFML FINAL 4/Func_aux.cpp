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
                    Esqueleto esqts(1, 15, 5, 1.0f, posini, TE);
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