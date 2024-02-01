#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Nubes {
private:

	Texture* m_textura_nube;
	Texture* m_textura_rayo;
	Sprite m_sprite_nube;
	Sprite m_sprite_rayo;
	Vector2f m_pos;
	Clock m_reloj;
	int danio;
	int movimiento;

public:

	Nubes(Vector2f pos, Texture* T_nube, Texture* T_rayo);
	void dibujar(RenderWindow& w);
	void actualizar();


	Nubes() = default;
};