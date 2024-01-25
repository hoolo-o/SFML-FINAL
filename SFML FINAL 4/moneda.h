#pragma once
#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "Func_aux.h"
#include <iostream>

using namespace sf;
class moneda {
private:
	int m_valor;
	Sprite m_sprite;
	Texture* m_textura;
	CircleShape m_hitbox;
	Vector2f m_pos;
	Clock m_clock;
public:
	moneda(Vector2f pos, Texture *T_coin, int valor);
	void dibujar(RenderWindow& w);
	void actualizar();
	CircleShape getHitbox();
	int getValor();
};