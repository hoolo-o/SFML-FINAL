#pragma once
#include <vector>
#include "Jugador.h"
#include "Escena.h"
#include "Mapa.h"
#include "Esqueleto.h"
#include "Func_aux.h"
#include "Textos.h"
using namespace sf;
using namespace std;

class Partida : public Escena {
private:
	Jugador p1;
	Mapa m1;
	Sprite m1S;
	Texture* T = new sf::Texture();
	vector<Esqueleto> ve1;
	int num_esq = 20;
	Vector2f ajuste;
	TextHandler T1;
	int Puntos = 0;
	int contador_ronda = 1;
public:
	Partida();
	void actualizar(Juego& j) override;
	void dibujar(RenderWindow& w)override;
};