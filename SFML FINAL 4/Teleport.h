#pragma once
#include "poder.h"
#include "Func_aux.h"

class Teleport : public Poder {
private:
	Texture m_textura;
	Sprite m_sprite;
	Sprite m_sprite2;
	Clock m_reloj;
	float distancia;
	bool puede_usarse;
	bool aux;
	bool aux2;
	int valor_monedas;
	int movimiento;
	Vector2f offset;
	Keyboard::Key usar;
	direccion d;
public:
	Teleport();
	void setDirec(direccion dir);
	Vector2f getOffset();
	int getValor();
	void actualizar(Vector2f pos) override;
	void dibujar(RenderWindow& w) override;
};