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
	Text Texto1;
	Font fuente;
public:
	Textos() {
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
	void actualizar(std::vector<Esqueleto> v, int contador_ronda, int vida_p1, int Puntos) {
		ss1.str("");
		ss1 << "Enemigos: " << v.size() << "   Ronda: " << contador_ronda << "  Vida: " << vida_p1 << "  Puntaje: " << Puntos;
		Texto1.setString(ss1.str());
	}
};