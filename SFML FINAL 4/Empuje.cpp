#include "Empuje.h"
#include <iostream>

Empuje::Empuje()
{
	m_textura->loadFromFile("Imagenes/EMPUJE_EFECTO.png");
	usar = Keyboard::Num1;
	m_hitbox1.setRadius(3);
	m_hitbox1.setFillColor(Color::White);
	m_hitbox1.setOrigin(0,-15);
	m_hitbox1.setTexture(m_textura, false);
	expandir = 0.1;
	valor_monedas = 100;
	puede_usarse = true;
	aux = true;
}

void Empuje::actualizar(Vector2f pos)
{
	if (Keyboard::isKeyPressed(usar) and puede_usarse) {
		aux2 = true;
	}
	if (puede_usarse and aux2) {
		if (aux) {
			cout << "primer paso" << endl;
			m_reloj.restart();
			aux = false;
		}
		m_hitbox1.setPosition(pos);
		cout << expandir << endl;
		m_hitbox1.setRadius(expandir);
		m_hitbox1.setPosition(m_hitbox1.getPosition().x - expandir, m_hitbox1.getPosition().y - expandir);
		if (expandir < 140) {
			expandir += 3.0f;
		}
		else {
			puede_usarse = false;
			aux2 = false;
			m_hitbox1.setRadius(0);
			expandir = 0;
			m_reloj.restart();
		}
	}
	if (m_reloj.getElapsedTime() >= seconds(5)) {
		puede_usarse = true;
	}

}

void Empuje::dibujar(RenderWindow& w)
{
	w.draw(m_hitbox1);
}

CircleShape* Empuje::getHitbox()
{
	return &m_hitbox1;
}

int Empuje::getValor()
{
	return valor_monedas;
}
