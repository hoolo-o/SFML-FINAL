#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <iostream>

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
			Eventos(e);
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

void Juego::Eventos(sf::Event& event) {
	if (event.type == sf::Event::TextEntered) {
		if (event.text.unicode < 128) {
			nombre += static_cast<char>(event.text.unicode);
		}
	}
}

String Juego::getNombre()
{
	return nombre;
}
