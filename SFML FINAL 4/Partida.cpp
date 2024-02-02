#include "Partida.h"

Partida::Partida() : p1(2, 0.5f, 20, 1, "Jugador 1")
{
	
	uno = Keyboard::Num1;
	dos = Keyboard::Num2;
	tres = Keyboard::Num3;
	cuatro = Keyboard::Num4;
	cinco = Keyboard::Num5;
	seis = Keyboard::Num6;
	T->loadFromFile("imagenes/enemigo.png");
	T_coin->loadFromFile("Imagenes/moneda.png");
	T_rayo->loadFromFile("Imagenes/rayo.png");
	T_efect->loadFromFile("Imagenes/klipartz.com.png");
	m1.generarMapa();
	m1.SpawnE();
	m1.mostrarMapa();
	m1.Combinar();
	m1.Decoracion();

	Pedrero p(0.2, 0.2, 1, 1, Vector2f(200, 200), T);
	pedro = p;
	T_nube->loadFromFile("Imagenes/nube.png");
	v_nube = NubesBordes(3, T_nube, T_rayo, T_efect);

	bordes.loadFromFile("Imagenes/bordes4.png");
	Sbordes.setTexture(bordes);
	Sbordes.setColor(Color(180,180,180,180));
	ve1 = EsqueletosBordes(num_esq, T, m1.getCampo());
	piedras = m1.getPiedras();
	T1.setNombre(p1.getNomnbre());
	aux = true;
	aux2 = true;
	aux3 = true;
}

void Partida::actualizar(Juego& j)
{
	//compra poderes
	for (int x = 0; x < v_nube.size();x++) {
		v_nube[x].actualizar();
	}
	if (vende.ventana_abierta() and Keyboard::isKeyPressed(uno) and p1.getMonedas()>=p1.pasarValor1() and aux2) {
		p1.poder1swith();
		p1.sumMoneda(-p1.pasarValor1());
		aux2 = false;
	}
	if (vende.ventana_abierta() and Keyboard::isKeyPressed(dos) and p1.getMonedas() >= p1.pasarValor2() and aux3) {
		p1.poder2swith();
		p1.sumMoneda(-p1.pasarValor2());
		aux3 = false;
	}
	vende.setMonedas(p1.getMonedas());

	for (int x = 0;x < ve1.size();x++) {
		if (ColisionCirculo(*p1.pasarHit1(), *ve1[x].getHitBox())) {
			ajuste = resolverColision(*ve1[x].getHitBox(), *p1.pasarHit1());
			ve1[x].mover(-ajuste);
		}
	}
	
	pasado = reloj_fps.restart();
	vende.actualizar(ColisionCirculo(p1.getHitbox_me(),vende.getHitbox()));
	T1.actualizar(ve1, contador_ronda, p1.GetVida(), p1.getMonedas(), fps);
	p1.actualizar();

	if (ve1.size() == 0 and aux) {
		reloj.restart();
		aux = false; vende.mostrarse_switch(); 
	}
	if (ve1.size() == 0 and reloj.getElapsedTime().asSeconds()>=10) {
		//sumar esqueletos por ronda
		vende.mostrarse_switch();
		num_esq += 2;
		ve1 = EsqueletosBordes(num_esq, T, m1.getCampo());
		v_nube = NubesBordes(8, T_nube, T_rayo, T_efect);
		contador_ronda++;
		aux = true;
	}
	for (int x = 0; x < v_nube.size();x++) {
		if (ColisionCirRect(v_nube[x].getHitbox(), p1.getHitbox_me()) and reloj2.getElapsedTime().asMilliseconds()>rand()%1000){
			p1.danio(v_nube[x].getDanio());
			reloj2.restart();
		}
		if (v_nube[x].borrar()) {
			v_nube.erase(v_nube.begin() + x);
			cout << "nube: " << x << endl;
		}
	}
	for (int x = 0;x < ve1.size();x++) {

		ve1[x].perseguirJugador(p1.verPosicion() - Vector2f(10.0f, 0.0f));
		
		for (int Col = 0; Col < ve1.size();Col++) {
			if (ColisionCirculo(*ve1[x].getHitBox(), *ve1[Col].getHitBox())) {
				//verifica colision esqueletos y corrije
				ajuste = resolverColision(*ve1[x].getHitBox(), *ve1[Col].getHitBox());
				ve1[x].mover(ajuste);
				ve1[Col].mover(-ajuste);
			}
		}
		if (ColisionCirculo(p1.getHitBox(), *ve1[x].getHitBox()) and p1.atacando()) {
			cout << "Hit a " << x << endl;
			ve1[x].Danio(p1.getDanio());
			ve1[x].retroceso(p1.verPosicion());
			T1.actualizar3(ve1[x].getHitBox_Pos());
			p1.ya_ataco();
		}
		
		if (ColisionCirculo(p1.getHitbox_me(), *ve1[x].getHitBox()) and ve1[x].get_puede_atacar()) {
			//verifica danio a jugador
			p1.danio(ve1[x].getDanio());
			ve1[x].ya_ataco();
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
		for (int j = 0;j < p1.getPiedras().size();j++) {
			if (ColisionCirculo(*ve1[i].getHitBox(), p1.getPiedras()[j].getHitbox())) {
				cout << "si" << endl;
				ve1[i].Danio(p1.getPiedras()[j].getDanio());
				T1.actualizar3(ve1[i].verPosicion());
				p1.getPiedras().erase(p1.getPiedras().begin() + j);
			}
		}
	}
	for (int x = 0; x < v_nube.size();x++) {
		for (int y = 0;y < ve1.size(); y++) {
			if (ColisionCirRect(v_nube[x].getHitbox(), *ve1[y].getHitBox())) {
				ve1[y].mejorar();
			}
		}
	}
	delta = pasado.asSeconds();
	fps = 1.0f / delta;
	
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
		vende.dibujar(w);
		for (Nubes n : v_nube) {
			n.dibujar(w);
		}
		w.draw(Sbordes);
		//BORDS.dibujar(w);
		T1.dibujar(w);
}
Partida::~Partida()
{
	delete T;
	delete T_coin;
	delete T_nube;
	delete T_rayo;
	delete T_efect;
}
//si