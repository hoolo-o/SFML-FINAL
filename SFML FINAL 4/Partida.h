#pragma once
#include <vector>
#include "Jugador.h"
#include "Escena.h"
#include "Mapa.h"
#include "Esqueleto.h"
#include "Func_aux.h"
#include "Textos.h"
#include "menu.h"
#include "Juego.h"
#include "moneda.h"
using namespace sf;
using namespace std;

class Partida : public Escena {
private:
	Jugador p1;
	Mapa m1;
	Sprite m1S;
	Texture* T = new Texture();
	Texture* T_coin = new Texture();
	vector<Esqueleto> ve1;
	vector<moneda> vm1;
	int num_esq = 20;
	Vector2f ajuste;
	Textos T1;
	int Puntos = 0;
	int contador_ronda = 1;
	menu menu1;
public:
	Partida();
	void actualizar(Juego& j) override;
	void dibujar(RenderWindow& w)override;
};