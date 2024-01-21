#include "Juegador.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
Jugador::Jugador(float vel, float vel_atac, float vida, float danio)
{
	m_textura.loadFromFile("C:/Users/ccpro/OneDrive/Escritorio/imagenes/Player.png");
	m_sprite.setTexture(m_textura);
	m_sprite.setTextureRect(IntRect(1,1,31,31));
	m_sprite.setScale(1.5f,1.5f);
	m_sprite.setPosition(500, 400);
	m_vel = vel;
	m_vel_atac = vel_atac;
	m_vida = vida;
	m_danio = danio;

	izq = Keyboard::A;
	der = Keyboard::D;
	arr = Keyboard::W;
	abj = Keyboard::S;
	atac = Keyboard::L;
	take = Keyboard::M;

	hitbox.setRadius(10);
	hitbox.setFillColor(Color::Blue);

}

Sprite Jugador::getSprite() {
	return m_sprite;
}

void Jugador::actualizar()
{
	if (Keyboard::isKeyPressed(izq)) {
		izquierda = true;
		m_sprite.move(-m_vel, 0.0);
		m_sprite.setScale(1.5f, 1.5f);
		m_sprite.setTextureRect(IntRect(4*31, 1, 31, 31));
		if (Keyboard::isKeyPressed(izq) and Keyboard::isKeyPressed(atac)) {
			hitbox.setPosition(this->verPosicion()+Vector2f(-34,15));
		}
	}
	if (Keyboard::isKeyPressed(der)) {
		izquierda = false;
		m_sprite.move(m_vel, 0.0);
		m_sprite.setScale(1.5f, 1.5f);
		m_sprite.setTextureRect(IntRect(1, 1, 31, 31));
		if (Keyboard::isKeyPressed(der) and Keyboard::isKeyPressed(atac)) {
			hitbox.setPosition(this->verPosicion() + Vector2f(18, 15));
		}
	}
	if (Keyboard::isKeyPressed(arr)) {
		m_sprite.move(0.0, -m_vel);
		if (Keyboard::isKeyPressed(arr) and Keyboard::isKeyPressed(atac)) {
			hitbox.setPosition(this->verPosicion() + Vector2f(-7, -13));
		}
	}
	if (Keyboard::isKeyPressed(abj)) {
		m_sprite.move(0.0, m_vel);
		if (Keyboard::isKeyPressed(abj) and Keyboard::isKeyPressed(atac)) {
			hitbox.setPosition(this->verPosicion() + Vector2f(-7, 40));
		}
	}
	if (Keyboard::isKeyPressed(atac)) {
			m_sprite.setScale(1.5f, 1.5f);
			m_sprite.setTextureRect(IntRect(2, 3.2 * 31, 31, 31));
			if (izquierda) {
				m_sprite.setOrigin(15.5, 0);
				m_sprite.setScale(-1.5f, 1.5f);
			}
		}
	}

void Jugador::dibujar(RenderWindow& w)
{
	w.draw(m_sprite);
	w.draw(hitbox);
}

Vector2f Jugador::verPosicion()
{
	return m_sprite.getPosition();
}

bool Jugador::atacando() {
	return Keyboard::isKeyPressed(atac);
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

float Jugador::getDanio() {
	return m_danio;
}

CircleShape Jugador::getHitBox() {
	return hitbox;
}

