#pragma once
#include <SFML/Graphics.hpp>
#include "Escena.h"
using namespace sf;

class menu : public Escena {
private:
	RectangleShape b_Jugar;
	RectangleShape b_ver_puntos;
	RectangleShape intro_nombre;
	Text jugar;
	Text puntos;
	Text nombre;
	Font fuente;
public:
	menu();
	void dibujar(RenderWindow& w) override;
	void actualizar(Juego& j) override;

};