#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class piedra {
private:
	Sprite m_sprite;
	Texture m_textura;
	CircleShape m_hitbox;
	Vector2f m_vel;
	int danio;
public:
	piedra(Vector2f pos, Vector2f direc, Texture * T_piedra);
	void actualizar();
	void dibujar(RenderWindow &w);
	Vector2f getPos();
};