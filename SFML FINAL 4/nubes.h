#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Nubes {
private:

	Texture* m_textura_nube;
	Texture* m_textura_rayo;
	Texture* m_efecto_t;
	Sprite m_sprite_nube;
	Sprite m_sprite_rayo;
	RectangleShape m_hitbox_rayo;
	RectangleShape m_efecto;
	Vector2f m_pos;
	Vector2f aux;
	Clock m_reloj;
	int danio;
	int vel;
	int movimiento;
public:

	Nubes(Vector2f pos, Texture* T_nube, Texture* T_rayo, Texture* T_efect);
	void dibujar(RenderWindow& w);
	void actualizar();
	bool borrar();
	int getDanio();
	RectangleShape getHitbox();

	Nubes() = default;
};