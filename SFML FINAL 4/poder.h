#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Poder {
private:
	int danio;
	Texture m_textura;
	Sprite m_sprite;

public:
	virtual void actualizar();
	virtual void dibujar(RenderWindow &w);
};