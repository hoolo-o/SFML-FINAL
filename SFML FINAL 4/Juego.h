#pragma once
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class Juego {
public:
	Juego(Escena* e);
	void jugar();
	~Juego();
	void cambiarEscena(Escena* nueva_escena);
	Event* getEvent();
private:
	Event e;
	RenderWindow m_win;
	Escena* m_esc, * m_prox = nullptr;
};