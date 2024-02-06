#include "ventana_vendedor.h"

ventana::ventana()
{
	m_textura.loadFromFile("Imagenes/plano_con_poderes.png");
	m_sprite.setTexture(m_textura);
	m_sprite.setPosition(100, 100);

	m_font.loadFromFile("Recursos/OstrichSans-Black.otf");
	Texto1.setPosition(170.0f, 110.0f);
	Texto1.setFont(m_font);
	Texto1.setCharacterSize(25);
	Texto1.setFillColor(Color::White);
	Texto1.setOutlineColor(Color::Yellow);
	Texto1.setOutlineThickness(1);
}

void ventana::actualizar(int monedas)
{
	
	Texto1.setString(to_string(monedas));
}

void ventana::dibujar(RenderWindow& w)
{
	w.draw(m_sprite);
	w.draw(Texto1);
}
