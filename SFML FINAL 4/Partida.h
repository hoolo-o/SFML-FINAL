#pragma once
#include <vector>
#include "Juegador.h"
#include "Escena.h"
#include "Mapa.h"
#include "Esqueleto.h"
#include "Func_aux.h"
using namespace sf;
using namespace std;

class Partida : public Escena {
private:
	Jugador p1;
	Mapa m1;
	Sprite m1S;
	Texture* T = new sf::Texture();
	vector<Esqueleto> ve1;
public:
	Partida();
	void actualizar(Juego& j) override;
	void dibujar(RenderWindow& w)override;
};