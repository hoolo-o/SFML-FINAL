#include "nubes.h"

Nubes::Nubes(Vector2f pos, Texture* T_nube, Texture* T_rayo)
{
	m_pos = pos;
	m_textura_nube = T_nube;
	m_textura_rayo = T_rayo;
	m_sprite_nube.setTexture(*m_textura_nube);
}
void Nubes::dibujar(RenderWindow& w)
{
	w.draw(m_sprite_nube);
}

void Nubes::actualizar()
{
}
