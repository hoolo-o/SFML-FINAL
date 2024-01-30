#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class ventana {
private:
	//vector<poderes> v_pod;
	Texture m_textura;
	Sprite m_sprite;
	Font m_font;
	Text Texto1;

public:
	ventana();
	void actualizar(int monedas);
	void dibujar(RenderWindow& w);
};