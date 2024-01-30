#include "Juego.h"
#include <SFML/Graphics.hpp>

using namespace sf;
Juego::Juego(Escena* e): m_win(VideoMode(1200, 700), "Final")
{
	m_win.setFramerateLimit(90);
	m_esc = e;
}

void Juego::jugar()
{
	while (m_win.isOpen()) {
		Event e;
		while (m_win.pollEvent(e)) {
			if (e.type == Event::Closed)
				m_win.close();
		}

		m_esc->actualizar(*this);

		m_esc->dibujar(m_win);
		m_win.display();

		if (m_prox) {
			delete m_esc;
			m_esc = m_prox;
			m_prox = nullptr;
		}
	}
}

Juego::~Juego()
{
	delete m_esc;
}

void Juego::cambiarEscena(Escena* nueva_escena)
{
	m_prox = nueva_escena;
}
