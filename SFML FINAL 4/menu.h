#pragma once
#include <SFML/Graphics.hpp>
#include "Escena.h"
#include "Juego.h"
#include "Func_aux.h"
#include "Mapa.h"
using namespace sf;


class menu : public Escena {
private:
	RectangleShape b_Jugar;
	RectangleShape ver_puntos;
	RectangleShape intro_nombre;
	Texture fondo;
	Sprite s_fondo;
	std::string aux;
	std::vector<UsuarioInfo> v;
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