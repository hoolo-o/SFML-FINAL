#include "Teleport.h"
#include <iostream>
Teleport::Teleport()
{
	d.abajo, d.arriba, d.derecha, d.izquierda = false;
	m_textura.loadFromFile("Imagenes/efecto_tp.png");
	m_sprite.setTexture(m_textura);
	m_sprite2.setTexture(m_textura);
	m_sprite.setScale(0.5, 0.5);
	m_sprite2.setScale(m_sprite.getScale());
	usar = Keyboard::Num2;
	distancia = 150.f;
	valor_monedas = 100;
	puede_usarse = true;
	aux = true;
	aux2 = true;
}

void Teleport::setDirec(direccion dir)
{
	d = dir;
}

Vector2f Teleport::getOffset()
{
	return offset;
}

int Teleport::getValor()
{
	return valor_monedas;
}

void Teleport::actualizar(Vector2f pos)
{
	offset = { 0.0f,0.0f };

	if (Keyboard::isKeyPressed(usar) and puede_usarse) {
		aux2 = true;

		if (puede_usarse and aux2) {
			if (aux) {
				m_reloj.restart();
				cout << "reset reloj" << endl;
				aux = false;
			}
			m_sprite.setPosition(pos);
			m_sprite2.setPosition(m_sprite.getPosition());
		
			if (d.abajo == true and d.arriba == false and d.derecha == false and d.izquierda == false) {
				offset = { 0.0f,distancia };
				m_sprite.move(0.0f, distancia);
				puede_usarse = false;
				aux2 = false;
			}
			if (d.abajo == false and d.arriba == true and d.derecha == false and d.izquierda == false) {
				offset = { 0.0f, -distancia };
				m_sprite.move(0.0f, -distancia);
				puede_usarse = false;
				aux2 = false;
			}
			if (d.abajo == false and d.arriba == false and d.derecha == true and d.izquierda == false) {
				offset = { distancia, 0.0f };
				m_sprite.move(distancia, 0.0f);
				puede_usarse = false;
				aux2 = false;
			}
			if (d.abajo == false and d.arriba == false and d.derecha == false and d.izquierda == true) {
				offset = { -distancia, 0.0f };
				m_sprite.move(-distancia, 0.0f);
				puede_usarse = false;
				aux2 = false;
			}

		}

	}
	
	m_sprite.setRotation(m_reloj.getElapsedTime().asMilliseconds());
	m_sprite2.setRotation(-m_reloj.getElapsedTime().asMilliseconds());


	if (m_sprite.getScale().x < 0) {
		m_sprite.setScale(m_reloj.getElapsedTime().asSeconds(), m_reloj.getElapsedTime().asSeconds());
		m_sprite2.setScale(-m_sprite.getScale());
	}
	if (m_reloj.getElapsedTime() >= seconds(0.8)) {
		m_sprite.setPosition(-40.f, -40.f);
		m_sprite2.setPosition(-40.f, -40.f);
	}
	if (m_reloj.getElapsedTime() >= seconds(1)) {
		puede_usarse = true;
		aux = true;
	}
}

void Teleport::dibujar(RenderWindow& w)
{
	w.draw(m_sprite);
	w.draw(m_sprite2);
}
