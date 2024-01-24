#include "Partida.h"

Partida::Partida() : p1(2, 1, 20, 1)
{
	T->loadFromFile("imagenes/enemigo.png");
	m1.generarMapa();
	m1.SpawnE();
	m1.mostrarMapa();
	m1.Combinar();
	m1.Decoracion();
	ve1 = EsqueletosBordes(num_esq, T, m1.getCampo());
}

void Partida::actualizar(Juego& j)
{
	T1.actualizar(ve1, contador_ronda, p1.GetVida(), Puntos);

	p1.actualizar();
	if (ve1.size() == 0) {
		num_esq += 2;
		ve1 = EsqueletosBordes(num_esq, T, m1.getCampo());
		contador_ronda++;
	}
	for (int x = 0;x < ve1.size();x++) {
		
		ve1[x].perseguirJugador(p1.verPosicion() - Vector2f(10.0f, 0.0f));
		
		for (int Col = 0; Col < ve1.size();Col++) {
			if (ColisionCirculo(ve1[x].getHitBox(), ve1[Col].getHitBox())) {
				ajuste = resolverColision(ve1[x].getHitBox(), ve1[Col].getHitBox());
				ve1[x].mover(ajuste);
				ve1[Col].mover(-ajuste);
			}
		}
		if (ColisionCirculo(p1.getHitBox(), ve1[x].getHitBox()) and p1.atacando()) {
			cout << "Hit a " << x << endl;
			ve1[x].Danio(p1.getDanio());
		}
		if (ColisionCirculo(p1.getHitbox_me(), ve1[x].getHitBox())) {
			p1.danio(ve1[x].getDanio());
			cout << "vida: " << p1.GetVida() << endl;
		}
		if (ve1[x].muerto()) {
			Puntos += ve1[x].getValorEsqueleto();
			ve1.erase(ve1.begin() + x);
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
		T1.dibujar(w);
}
//si