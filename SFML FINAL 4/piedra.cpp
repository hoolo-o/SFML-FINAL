#include "piedra.h"



piedra::piedra(Vector2f pos, Vector2f direc, Texture* T_piedra)
{
	m_sprite.setPosition(pos);
	m_sprite.setTexture(*T_piedra);
	m_sprite.setScale(0.4, 0.4f);
	m_vel = direc;
	tiempo_vida = 2.5f;
	m_hitbox.setPosition(pos+Vector2f(0.0f,10.0f));
	m_hitbox.setOrigin(2, 2);
	m_hitbox.setRadius(2);
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
	//w.draw(m_hitbox);
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
