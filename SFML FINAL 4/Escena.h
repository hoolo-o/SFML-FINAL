#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Juego;
class Escena {
public:
	virtual void actualizar(Juego& j) = 0;
	virtual void dibujar(RenderWindow&) = 0;
};