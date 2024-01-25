#include "piedra.h"


piedra::piedra(Vector2f pos, Vector2f direc, Texture* T_piedra)
{
	m_sprite.setPosition(pos);
	m_sprite.setTexture(*T_piedra);
	
	m_hitbox.setPosition(pos);
	m_hitbox.setOrigin(2, 2);
	m_hitbox.setRadius(2);
	m_hitbox.setFillColor(Color::Cyan);

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
