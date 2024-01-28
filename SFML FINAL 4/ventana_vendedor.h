#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class ventana {
private:
	//vector<poderes> v_pod;
	Texture m_textura;
	Sprite m_sprite;

public:
	ventana();
	void actualizar();
	void dibujar(RenderWindow& w);
};