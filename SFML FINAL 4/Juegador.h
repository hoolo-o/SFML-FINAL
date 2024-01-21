#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Jugador {
private:
	Texture m_textura;
	Sprite m_sprite;
	Clock m_clock;
	Time delay;
	Keyboard::Key izq, der, arr, abj, atac, take;

	bool izquierda;

	CircleShape hitbox;

	float m_vel;
	float m_vel_atac;
	float m_vida;
	float m_danio;

public:
	Jugador();
	Jugador(float vel, float vel_atac, float vida, float danio);
	void actualizar();
	void dibujar(RenderWindow &w);
	Vector2f verPosicion();
	Sprite getSprite();
	bool atacando();
	float getVelAtaque();
	void ReicioReloj();
	float tiempoPasado();
	float getDanio();
	CircleShape getHitBox();
};