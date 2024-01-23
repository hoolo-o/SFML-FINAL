#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include "Esqueleto.h"
using namespace sf;
using namespace std;
class TextHandler {
private:
	stringstream ss1;
	Text Texto1;
	Font fuente;
public:
	TextHandler() {
		fuente.loadFromFile("Recursos/OstrichSans-Black.otf");
		Texto1.setPosition(10.0f, 10.0f);
		Texto1.setFont(fuente);
		Texto1.setCharacterSize(25);
		Texto1.setFillColor(Color::Black);
		Texto1.setOutlineColor(Color::White);
		Texto1.setOutlineThickness(1);
	}

	void dibujar(RenderWindow &w) {
		w.draw(Texto1);
	}
	void actualizar(std::vector<Esqueleto> v, int contador_ronda, int vida_p1) {
		ss1.str("");
		ss1 << "Enemigos: " << v.size() << "   Ronda: " << contador_ronda << "  Vida: " << vida_p1;
		Texto1.setString(ss1.str());
	}
};