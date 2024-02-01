#pragma once
#include <SFML/Graphics.hpp>
#include "piedra.h"
#include "Esqueleto.h"
#include "Func_aux.h"
using namespace std;
using namespace sf;

class Pedrero{
private:
	Texture* m_textura;
	Sprite m_sprite;
	Clock m_clock;
	CircleShape m_hitbox_max;
	CircleShape m_hitbox_mid;
	CircleShape m_hitbox_min;
	CircleShape m_hitbox;

	Vector2f m_pos;

	float m_vel;
	float m_vel_atac;
	float m_vida;
	int m_danio;

	bool puede_atacar;

public:
	Pedrero(float vel, float vel_atac, float vida, int danio, Vector2f pos, Texture* TE);
	void dibujar(RenderWindow &w);
	void actualizar(Vector2f pos_p, CircleShape hitbox_p1);
	void perseguirJugador(const Vector2f& posicionJugador);
	void CambiarSpriteDireccion(int pos);
	Pedrero() = default;
};