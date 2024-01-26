#include "piedra.h"
#include <iostream>



piedra::piedra(Vector2f pos, Vector2f direc, Texture* T_piedra)
{
	danio = 2;
	m_sprite.setPosition(pos);
	m_sprite.setTexture(*T_piedra);
	m_sprite.setScale(0.4, 0.4f);
	m_vel = direc;
	tiempo_vida = 2.5f;
	m_hitbox.setPosition(pos+Vector2f(0.0f,10.0f));
	m_hitbox.setOrigin(2, 2);
	m_hitbox.setRadius(5);
	m_hitbox.setFillColor(Color::Black);
	m_clock.restart();
}
void piedra::actualizar()
{
	m_hitbox.move(m_vel);
	m_sprite.move(m_vel);
}
void piedra::dibujar(RenderWindow& w)
{
	w.draw(m_hitbox);
	w.draw(m_sprite);
}

Vector2f piedra::getPos()
{
	return m_hitbox.getPosition();
}

bool piedra::verificarTiempo()
{
	return m_clock.getElapsedTime() >= seconds(tiempo_vida);
}

CircleShape piedra::getHitbox()
{
	return m_hitbox;
}

int piedra::getDanio()
{
	return danio;
}

bool piedra::coliss(CircleShape otro)
{
	std::cout << "otro si" << std::endl;
	sf::Vector2f cent1 = otro.getPosition() + Vector2f(otro.getRadius(), otro.getRadius());
	sf::Vector2f cent2 = this->getPos() + Vector2f(this->getHitbox().getRadius(), this->getHitbox().getRadius());
	//distancia
	float distan = sqrt(std::pow(cent2.x - cent1.x, 2) + pow(cent2.y - cent1.y, 2));
	//verificar colision
	return distan <= otro.getRadius() + this->getHitbox().getRadius();
}
