#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include "Esqueleto.h"
using namespace sf;
using namespace std;
class Textos {
private:
	stringstream ss1;
	Clock m_clock1;
	Text Texto1;
	Text Texto2;
	Text Texto3;
	Text Texto4;
	Text Texto5;
	Font fuente;
	bool aux;
public:
	Textos() {
		aux = false;

		fuente.loadFromFile("Recursos/OstrichSans-Black.otf");
		Texto1.setPosition(10.0f, 10.0f);
		Texto1.setFont(fuente);
		Texto1.setCharacterSize(25);
		Texto1.setFillColor(Color::Black);
		Texto1.setOutlineColor(Color::White);
		Texto1.setOutlineThickness(1);

		Texto2.setFont(fuente);
		Texto2.setCharacterSize(10);
		Texto2.setLetterSpacing(2.0f);
		Texto2.setFillColor(Color::Black);
		Texto2.setOutlineColor(Color::White);
		Texto2.setOutlineThickness(0.5f);

		Texto3.setString("HIT");
		Texto3.setFont(fuente);
		Texto3.setCharacterSize(15);
		Texto3.setLetterSpacing(1.5f);
		Texto3.setFillColor(Color::Red);
		Texto3.setOutlineColor(Color::Black);
		Texto3.setOutlineThickness(0.4f);

		Texto4.setString("HIT");
		Texto4.setFont(fuente);
		Texto4.setCharacterSize(15);
		Texto4.setLetterSpacing(1.5f);
		Texto4.setFillColor(Color::Red);
		Texto4.setOutlineColor(Color::Black);
		Texto4.setOutlineThickness(0.4f);
		Texto4.setPosition(500, 500);

		Texto5.setString("VUELVE!!");
		Texto5.setFont(fuente);
		Texto5.setCharacterSize(50);
		Texto5.setLetterSpacing(1.5f);
		Texto5.setFillColor(Color::Red);
		Texto5.setOutlineColor(Color::Black);
		Texto5.setOutlineThickness(0.4f);
		Texto5.setPosition(500, 350);

	}

	void dibujar(RenderWindow &w) {
		w.draw(Texto1);
		w.draw(Texto2);
		if (m_clock1.getElapsedTime() < seconds(0.5)) {
			w.draw(Texto3);
		}
		if (aux) {
			w.draw(Texto5);
		}
		aux = false;
	}
	void actualizar(std::vector<Esqueleto> v, int contador_ronda, int vida_p1, int monedas, int fps) {
		ss1.str("");
		ss1 << "Enemigos: " << v.size() << "   Ronda: " << contador_ronda << "  Vida: " << vida_p1 << "  Monedas: " << monedas << "                                                                                         FPS: " << fps;
		Texto1.setString(ss1.str());
	}

	void setNombre(String nombre) {
		Texto2.setString(nombre);
	}
	void actualizar2(Vector2f pos) {
		Texto2.setPosition(pos);
		if (pos.x > 1200 or pos.y > 700 or pos.x < 0 or pos.y<0) {
			aux = true;
		}
	}
	void actualizar3(Vector2f pos) {
		m_clock1.restart();
		Texto3.setPosition(pos);
		
	}
	void actualizar4(char tiempo) {
		Texto4.setString(tiempo);
	}
};