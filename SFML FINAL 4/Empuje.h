#pragma once
#include "poder.h"
class Empuje : public Poder {
private:
	Texture *m_textura = new Texture();
	Sprite m_sprite;
	CircleShape m_hitbox1;
	Clock m_reloj;
	float expandir;
	bool puede_usarse;
	bool aux;
	bool aux2;
	int valor_monedas;
	Keyboard::Key usar;
public:
	Empuje();
	void actualizar(Vector2f pos) override;
	void dibujar(RenderWindow& w) override;
	CircleShape getHitbox();
};