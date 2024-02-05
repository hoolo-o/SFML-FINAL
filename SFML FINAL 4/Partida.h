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
#include "vendedor.h"
#include "poder.h"
#include "esqueleto_distancia.h"
#include "nubes.h"

using namespace sf;
using namespace std;

struct hitBordes {
	RectangleShape arriba;
	RectangleShape abajo;
	RectangleShape izquierda;
	RectangleShape derecha;

	hitBordes() {
		arriba.setFillColor(Color::Green);
		arriba.setPosition(300, 300);
		arriba.setScale(1200, 20);
	}
	void dibujar(RenderWindow& w) {
		w.draw(arriba);
	}
};

class Partida : public Escena {
private:
	Jugador p1;
	Vendedor vende;
	Mapa m1;
	Sprite m1S;
	Clock reloj;
	String m_name;
	Keyboard::Key uno, dos, tres, cuatro, cinco, seis;

	hitBordes BORDS;

	Clock reloj2;

	Clock reloj_fps;
	float delta;
	float fps;
	Time pasado;

	Pedrero pedro;
	Texture bordes;
	Sprite Sbordes;
	Texture* T = new Texture();
	Texture* T_coin = new Texture();
	Texture* T_nube = new Texture();
	Texture* T_rayo = new Texture();
	Texture* T_efect = new Texture();
	Texture T_controles;
	Sprite controles;
	vector<Esqueleto> ve1;
	vector<moneda> vm1;
	vector<CircleShape> piedras;
	vector<piedra> lanzadas;
	vector<Nubes> v_nube;
	int num_esq = 2;
	Vector2f ajuste;
	Textos T1;
	int Puntos = 0;
	int contador_ronda = 1;
	menu menu1;
	bool aux, aux2, aux3, auxA;
	bool a = true;
public:
	Partida(String name);
	void actualizar(Juego& j) override;
	void dibujar(RenderWindow& w)override;
	void CargarPuntajes(string getNombre, int getMonedas, int getKills);
	~Partida();
};