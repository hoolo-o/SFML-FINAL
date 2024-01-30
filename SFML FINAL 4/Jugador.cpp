#include "Jugador.h"
#include "piedra.h"
#include "Teleport.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class piedra;
Jugador::Jugador(float vel, float vel_atac, int vida, float danio, String nombre)
{
	poder1, poder2, poder3, poder4, poder5, poder6 = false;

	m_textura.loadFromFile("imagenes/Player.png");
	m_sprite.setTexture(m_textura);
	m_sprite.setTextureRect(IntRect(1,1,31,31));
	m_sprite.setScale(1.5f,1.5f);
	m_sprite.setPosition(500, 400);
	m_vel = vel;
	m_vel_atac = vel_atac;
	m_vida = vida;
	m_danio = danio;
	m_nombre = nombre;

	monedas = 250;
	puede_lanzar = true;
	puede_atacar = true;

	izq = Keyboard::A;
	der = Keyboard::D;
	arr = Keyboard::W;
	abj = Keyboard::S;
	atac = Keyboard::L;
	take = Keyboard::M;
	lanz = Keyboard::K;

	hitbox.setRadius(10);
	hitbox.setFillColor(Color::Blue);
	hitbox_me.setRadius(10);
	hitbox_me.setFillColor(Color::Green);
	T_piedra->loadFromFile("Imagenes/piedra.png");
	m_sprite.setOrigin(15.5, 0);
}

Sprite Jugador::getSprite() {
	return m_sprite;
}

void Jugador::actualizar()
{
	//verificar teclas de forma constante
	//mover jugador y cambiar textura
	//definir posicion de gitbox/ataque segun movimiento
	if (poder1) {
		empuj.actualizar(this->verPosicion());
	}
	if (poder2) {
		tport.setDirec(direc);
		tport.actualizar(this->hitbox_me.getPosition()+Vector2f(8.f,15.f));
		m_sprite.move(tport.getOffset());
	}

	if (m_clock3.getElapsedTime() >= seconds(m_vel_atac)) {
		puede_atacar = true;
	}

	if (m_clock.getElapsedTime().asSeconds() < 0.2f) {
		return;
	}
	if (direc.izquierda) {
		m_sprite.setTextureRect(IntRect(4 * 31, 0, 31, 31));
	}
	else {
		m_sprite.setTextureRect(IntRect(1, 1, 31, 31));
	}
	hitbox_me.setPosition(this->verPosicion()-Vector2f(16,-16));
	hitbox.setPosition(0, 0);
	if (Keyboard::isKeyPressed(izq)) {
		direc.derecha = false;
		direc.abajo = false;
		direc.arriba = false;
		direc.izquierda = true;
		m_sprite.move(-m_vel, 0.0);
		m_sprite.setScale(1.5f, 1.5f);
		m_sprite.setTextureRect(IntRect(4*31, 0, 31, 31));
		if (Keyboard::isKeyPressed(izq) and Keyboard::isKeyPressed(atac)) {
			hitbox.setPosition(this->verPosicion()+Vector2f(-34,15));
		}
	}
	if (Keyboard::isKeyPressed(der)) {
		direc.derecha = true;
		direc.abajo = false;
		direc.arriba = false;
		direc.izquierda = false;
		m_sprite.move(m_vel, 0.0);
		m_sprite.setScale(1.5f, 1.5f);
		m_sprite.setTextureRect(IntRect(1, 1, 31, 31));
		if (Keyboard::isKeyPressed(der) and Keyboard::isKeyPressed(atac)) {
			hitbox.setPosition(this->verPosicion() + Vector2f(18, 15));
		}
	}
	if (Keyboard::isKeyPressed(arr)) {
		direc.derecha = false;
		direc.abajo = false;
		direc.arriba = true;
		direc.izquierda = false;
		m_sprite.move(0.0, -m_vel);
		if (Keyboard::isKeyPressed(arr) and Keyboard::isKeyPressed(atac)) {
			hitbox.setPosition(this->verPosicion() + Vector2f(-7, -13));
		}
	}
	if (Keyboard::isKeyPressed(abj)) {
		direc.derecha = false;
		direc.abajo = true;
		direc.arriba = false;
		direc.izquierda = false;
		m_sprite.move(0.0, m_vel);
		if (Keyboard::isKeyPressed(abj) and Keyboard::isKeyPressed(atac)) {
			hitbox.setPosition(this->verPosicion() + Vector2f(-7, 40));
		}
	}
	if (Keyboard::isKeyPressed(atac) and puede_atacar) {
		m_clock.restart();
			m_sprite.setScale(1.5f, 1.5f);
			m_sprite.setTextureRect(IntRect(2, 3.2 * 31, 31, 31));
			if (direc.izquierda) {
				m_sprite.setScale(-1.5f, 1.5f);
				hitbox.setPosition(this->verPosicion() + Vector2f(-34, 15));
			}else{
			hitbox.setPosition(this->verPosicion() + Vector2f(18, 15));
			}
		}
	if (m_clock2.getElapsedTime() >= seconds(m_vel_atac))
		puede_lanzar = true;
	if (Keyboard::isKeyPressed(lanz) and puede_lanzar) {
		generar_piedra(T_piedra);
		m_clock2.restart();
		puede_lanzar = false;
	}
	for (int x = 0; x < ps.size();x++) {
		ps[x].actualizar();
		if (ps[x].verificarTiempo()) {
			ps.erase(ps.begin() + x);
		}
	}
	}

void Jugador::dibujar(RenderWindow& w)
{
	w.draw(m_sprite);
	for (int x = 0; x < ps.size();x++) {
		ps[x].dibujar(w);
	}
	if (poder1) {
		empuj.dibujar(w);
	}
	if (poder2) {
		tport.dibujar(w);
	}
	//w.draw(hitbox);
	//w.draw(hitbox_me);
}

Vector2f Jugador::verPosicion()
{
	return m_sprite.getPosition();
}

bool Jugador::atacando() {
	return (Keyboard::isKeyPressed(atac));
}

float Jugador::getVelAtaque() {
	return m_vel_atac;
}

void Jugador::ReicioReloj() {
	m_clock.restart();
}

float Jugador::tiempoPasado() {
	return m_clock.getElapsedTime().asSeconds();
}

int Jugador::getDanio() {
	return m_danio;
}

CircleShape Jugador::getHitBox() {
	return hitbox;
}

int Jugador::GetVida() {
	return m_vida;
}

void Jugador::danio(int Danio) {
	m_vida = m_vida - Danio;
}

CircleShape Jugador::getHitbox_me() {
	return hitbox_me;
}

void Jugador::sumMoneda(int moneda)
{
	monedas += moneda;
}

int Jugador::getMonedas()
{
	return monedas;
}

piedra Jugador::generar_piedra(Texture* T_piedra)
{
	Vector2f d;
	if(direc.arriba){
		d={ 0.0f,-2.9f };
	}
	if (direc.abajo) {
		d = { 0.0f, 2.9f };
	}
	if (direc.derecha) {
		d = { 2.9f, 0.0 };
	}
	if (direc.izquierda) {
		d={ -2.9f, 0.0f };
	}

	piedra p(hitbox_me.getPosition(), d, T_piedra);
	ps.push_back(p);
	return p;
}

std::vector<piedra>& Jugador::getPiedras()
{
	return ps;
}

string Jugador::getNomnbre()
{
	return m_nombre;
}

void Jugador::ya_ataco()
{
	puede_atacar = false;
	m_clock3.restart();
}


//
void Jugador::poder1swith()
{
	poder1 = !poder1;
}
CircleShape* Jugador::pasarHit1()
{
	return empuj.getHitbox();
}
int Jugador::pasarValor1()
{
	return empuj.getValor();
}
//
void Jugador::poder2swith()
{
	poder2 = !poder2;
}
int Jugador::pasarValor2() {
	return tport.getValor();
}
//
void Jugador::poder3swith()
{
	poder3 = !poder3;
}
void Jugador::poder4swith()
{
	poder4 = !poder4;
}
void Jugador::poder5swith()
{
	poder5 = !poder5;
}
void Jugador::poder6swith()
{
	poder6 = !poder6;
}




