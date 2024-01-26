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
                if (probabilidad(50) and esqueletos.size()<cantidad) {
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
    //posicion circulos
    sf::Vector2f cent1 = circulo1.getPosition() + Vector2f(circulo1.getRadius(), circulo1.getRadius());
    sf::Vector2f cent2 = circulo2.getPosition() + Vector2f(circulo2.getRadius(), circulo2.getRadius());
    //distancia
    float distan = sqrt(std::pow(cent2.x - cent1.x, 2) + pow(cent2.y - cent1.y, 2));
    //verificar colision
    return distan <= circulo1.getRadius() + circulo2.getRadius();
}

Vector2f resolverColision(const CircleShape& cir1, const CircleShape& cir2) {
    //calculo superposicion
    float Superpos = cir1.getRadius() + cir2.getRadius() - sqrt(pow(cir1.getPosition().x - cir2.getPosition().x, 2) +
        pow(cir1.getPosition().y - cir2.getPosition().y, 2));
    //calculo angulos entre centros ciruclos
    float angulo = atan2(cir1.getPosition().y - cir2.getPosition().y, cir1.getPosition().x - cir2.getPosition().x);
    //calculo desplazamiento
    float moverX = Superpos * cos(angulo) / 2.0f;
    float moverY = Superpos * sin(angulo) / 2.0f;
    return Vector2f(moverX, moverY);
}

bool mouse(Vector2f mousePos, RectangleShape& rect) {
    return mousePos.x > rect.getPosition().x &&
        mousePos.x < rect.getPosition().x + rect.getSize().x &&
        mousePos.y > rect.getPosition().y &&
        mousePos.y < rect.getPosition().y + rect.getSize().y;
}

void hilo_tiempo(Clock& reloj, Time esperar) {
    while (reloj.getElapsedTime() < esperar) {

    }
}

bool temporizador(float tiempo)
{
    sleep(seconds(tiempo));
    return true;
}
