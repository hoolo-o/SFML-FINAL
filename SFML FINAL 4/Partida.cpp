#include "Partida.h"

Partida::Partida() : p1(2, 1, 1, 1)
{
	T->loadFromFile("C:/Users/ccpro/OneDrive/Escritorio/imagenes/enemigo.png");
	m1.generarMapa();
	m1.SpawnE();
	m1.mostrarMapa();
	m1.Combinar();
	m1.Decoracion();
	ve1 = EsqueletosBordes(10, T, m1.getCampo());
}

void Partida::actualizar(Juego& j)
{
	p1.actualizar();
	for (int x = 0;x < ve1.size();x++) {
		ve1[x].perseguirJugador(p1.verPosicion());
		if (ColisionCirculo(p1.getHitBox(),ve1[x].getHitBox()) and p1.atacando()) {
			cout << "Hit a " << x << endl;
			ve1[x].Danio(p1.getDanio());
		}
		if (ve1[x].muerto()) {
			ve1.erase(ve1.begin()+x);
		}
	}
}

void Partida::dibujar(RenderWindow& w)
{
	w.clear(Color::Green);
	m1.dibujar(w);
	p1.dibujar(w);
	for (Esqueleto e1 : ve1) {
		e1.dibujar(w);
	}
}
