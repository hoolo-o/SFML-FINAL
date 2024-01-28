#include "ventana_vendedor.h"

ventana::ventana()
{
	m_textura.loadFromFile("Imagenes/plano.png");
	m_sprite.setTexture(m_textura);
	m_sprite.setPosition(50, 100);
}

void ventana::actualizar()
{

}

void ventana::dibujar(RenderWindow& w)
{
	w.draw(m_sprite);
}
