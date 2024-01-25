#include "moneda.h"

moneda::moneda(Vector2f pos, Texture*T_coin, int valor)
{
	m_valor = valor;
	m_pos = pos;
	m_textura = T_coin;
	m_sprite.setPosition(m_pos-Vector2f(6.0f,0.0f));
	m_sprite.setTexture(*m_textura);
	m_sprite.setScale(0.5f,0.5f);
	m_hitbox.setPosition(m_pos);
	m_hitbox.setFillColor(Color::Yellow);
	m_hitbox.setRadius(7);
}

void moneda::dibujar(RenderWindow&w)
{
	//w.draw(m_hitbox);
	w.draw(m_sprite);
}

void moneda::actualizar()
{

}

CircleShape moneda::getHitbox()
{
	return m_hitbox;
}

int moneda::getValor()
{
	return m_valor;
}
