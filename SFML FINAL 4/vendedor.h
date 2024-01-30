#pragma once
#include "Func_aux.h"
#include <SFML/Graphics.hpp>
#include "ventana_vendedor.h"
using namespace std;
using namespace sf;

class Vendedor {
private:
	Texture m_textura;
	Sprite m_sprite;
	CircleShape m_hitbox;
	Clock m_reloj;
	bool aparecer;
	bool mostrar_ventana;
	int aux;
	float movimiento;
	Keyboard::Key uno, dos, tres, cuatro, cinco, seis;
	ventana v1;
public:
	Vendedor();
	void setMonedas(int coins);
	void actualizar(bool ver);
	void dibujar(RenderWindow &w);
	void mostrarse_switch();
	CircleShape getHitbox();
	bool ventana_abierta();
};