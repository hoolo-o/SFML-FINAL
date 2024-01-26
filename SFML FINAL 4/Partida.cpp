#include "Partida.h"

Partida::Partida() : p1(2, 1, 20, 1, "Jugador 1")
{
	T->loadFromFile("imagenes/enemigo.png");
	T_coin->loadFromFile("Imagenes/moneda.png");
	m1.generarMapa();
	m1.SpawnE();
	m1.mostrarMapa();
	m1.Combinar();
	m1.Decoracion();
	ve1 = EsqueletosBordes(num_esq, T, m1.getCampo());
	piedras = m1.getPiedras();
	T1.setNombre(p1.getNomnbre());
}

void Partida::actualizar(Juego& j)
{
	T1.actualizar(ve1, contador_ronda, p1.GetVida(), p1.getMonedas());
	p1.actualizar();
	if (ve1.size() == 0) {
		//sumar esqueletos por ronda
		num_esq += 2;
		ve1 = EsqueletosBordes(num_esq, T, m1.getCampo());
		contador_ronda++;
	}
	for (int x = 0;x < ve1.size();x++) {

		ve1[x].perseguirJugador(p1.verPosicion() - Vector2f(10.0f, 0.0f));
		
		for (int Col = 0; Col < ve1.size();Col++) {
			if (ColisionCirculo(ve1[x].getHitBox(), ve1[Col].getHitBox())) {
				//verifica colision esqueletos y corrije
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
			//verifica danio a jugador
			p1.danio(ve1[x].getDanio());
			cout << "vida: " << p1.GetVida() << endl;
		}
		if (ve1[x].muerto()) {
			//verifica si esqueletos estan muertos y elimina
			moneda coin(ve1[x].verPosicion(), T_coin, ve1[x].getValorEsqueleto());
			ve1.erase(ve1.begin() + x);
			vm1.push_back(coin);
		}
		


		if (p1.GetVida() <= 0) {
			//////funcion carga puntajes
			j.cambiarEscena(new menu);
		}
	}

	for (int x = 0; x < vm1.size(); x++) {
		if (ColisionCirculo(vm1[x].getHitbox(), p1.getHitbox_me())) {
			p1.sumMoneda(vm1[x].getValor());
			vm1.erase(vm1.begin() + x);
		}
	}
	T1.actualizar2(p1.getHitbox_me().getPosition()+Vector2f(-5.0f,-20.0f));

	for (int i = 0; i < ve1.size();i++) {
		for (int j = 0;j < lanzadas.size();j++) {
			if (lanzadas[j].coliss(ve1[i].getHitBox())){
				cout << "si" << endl;
			}
		}
	}
}

void Partida::dibujar(RenderWindow& w)
{
		w.clear(Color::Green);
		m1.dibujar(w);
		for (moneda m : vm1) {
			m.dibujar(w);
		}
		p1.dibujar(w);
		for (Esqueleto e1 : ve1) {
			e1.dibujar(w);
		}
		T1.dibujar(w);
}
//si