#pragma once
#include "Esqueleto.h"
#include "vector"
#include <cstdlib>
#include <SFML/Graphics.hpp>
std::vector<Esqueleto> EsqueletosBordes(int cantidad, sf::Texture* TE, char* mapa);

bool probabilidad(int prob);
bool Colision(const Sprite& sprite1, const Sprite& sprite2);
bool ColisionCirculo(const CircleShape& circle1, const CircleShape& circle2);