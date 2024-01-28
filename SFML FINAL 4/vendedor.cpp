#include "vendedor.h"
#include <iostream>

Vendedor::Vendedor()
{
	uno = Keyboard::Num1;
	dos = Keyboard::Num2;
	tres = Keyboard::Num3;
	cuatro = Keyboard::Num4;
	cinco = Keyboard::Num5;
	seis = Keyboard::Num6;

	m_hitbox.setRadius(30);
	m_hitbox.setFillColor(Color::White);

	m_textura.loadFromFile("Imagenes/vendedor.png");
	m_sprite.setTexture(m_textura);

	m_sprite.setTextureRect(IntRect(1, 1, 50, 50));
	m_sprite.setPosition(-15, -15);
	m_sprite.setScale(-1, 1);
	m_sprite.setOrigin(25,25);
	aparecer = false;
	mostrar_ventana = false;
}

void Vendedor::actualizar(bool ver)
{
	if (aparecer and movimiento < 6) {
		m_sprite.setScale(-1, 1);
		movimiento += 0.1;
		m_sprite.move(movimiento, movimiento);
	}
	if (aparecer == false and movimiento > 0) {
		m_sprite.setScale(1, 1);
		movimiento -=0.1;
		m_sprite.move(-movimiento, -movimiento);
	}
	m_hitbox.setPosition(m_sprite.getPosition());
	mostrar_ventana = ver;
}

void Vendedor::dibujar(RenderWindow& w)
{
	w.draw(m_hitbox);
	w.draw(m_sprite);
	if (mostrar_ventana) {
		v1.dibujar(w);
	}
}

void Vendedor::mostrarse_switch()
{
	aparecer = !aparecer;
}

CircleShape Vendedor::getHitbox()
{
	return m_hitbox;
}

