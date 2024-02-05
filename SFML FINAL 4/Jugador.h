#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "piedra.h"
#include "Func_aux.h"
#include "poder.h"
#include "Teleport.h"
#include "Empuje.h"

using namespace sf;

class Jugador {
private:
	Texture* T_piedra = new Texture();
	Texture m_textura;
	Sprite m_sprite;
	Clock m_clock;
	Clock m_clock2;
	Clock m_clock3;
	Clock m_clock4;
	Time delay;
	Keyboard::Key izq, der, arr, abj, atac, lanz, take;
	String m_nombre;

	bool poder1;
	Empuje empuj;
	bool poder2;
	Teleport tport;
	bool poder3;
	bool poder4;
	bool poder5;
	bool poder6;

	bool puede_lanzar;
	bool puede_atacar;
	bool lanzar;

	direccion direc;
	std::vector<piedra> ps;

	int monedas;
	int kills;

	RectangleShape danio_w;
	bool mostrar_w_danio;
	CircleShape hitbox;
	CircleShape hitbox_me;

	float m_vel;
	float m_vel_atac;
	int m_vida;
	float m_danio;


public:
	Jugador();
	Jugador(float vel, float vel_atac, int vida, float danio, String nombre);
	void actualizar();
	void dibujar(RenderWindow &w);
	Vector2f verPosicion();
	Sprite getSprite();
	bool atacando();
	float getVelAtaque();
	void ReicioReloj();
	float tiempoPasado();
	int getDanio();
	CircleShape getHitBox();
	int GetVida();
	void danio(int Danio);
	CircleShape getHitbox_me();
	void sumMoneda(int moneda);
	int getMonedas();
	piedra generar_piedra(Texture* T_piedra);
	std::vector<piedra>& getPiedras();
	sf::String getNomnbre();
	void SumKill();
	int getKills();
	void ya_ataco();

	void poder1swith();
	CircleShape* pasarHit1();
	int pasarValor1();

	void poder2swith();
	int pasarValor2();

	void poder3swith();
	void poder4swith();
	void poder5swith();
	void poder6swith();
};