#pragma once
#include <SFML/Graphics.hpp>
#include "Escena.h"
#include "Juego.h"
using namespace sf;

class menu : public Escena {
private:
	RectangleShape b_Jugar;
	RectangleShape b_ver_puntos;
	RectangleShape intro_nombre;
	Event e;
	Clock fj;
	String aux2;
	Text jugar;
	Text puntos;
	Text nombre;
	Font fuente;
public:
	menu();
	void dibujar(RenderWindow& w) override;
	void actualizar(Juego& j) override;
};