#pragma once
#include "Esqueleto.h"
#include "vector"
#include <cstdlib>
#include <SFML/Graphics.hpp>
std::vector<Esqueleto> EsqueletosBordes(int cantidad, sf::Texture* TE, char* mapa);

bool probabilidad(int prob);
bool Colision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);