#include "nubes.h"
#include <iostream>
#include <random>
#include "Func_aux.h"

Nubes::Nubes(Vector2f pos, Texture* T_nube, Texture* T_rayo, Texture* T_efect)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	float abajo = 1.0f;
	float arriba = 3.0f;

	std::uniform_real_distribution<float> distrib(abajo, arriba);
	vel = distrib(gen);
	m_pos = pos;
	m_textura_nube = T_nube;
	m_textura_rayo = T_rayo;
	m_hitbox_rayo.setSize(Vector2f(130, 50));
	m_hitbox_rayo.setFillColor(Color::Magenta);
	m_hitbox_rayo.setPosition(pos+Vector2f(40,120));
	m_efecto.setSize(Vector2f(1200, 700));
	m_efecto.setTexture(T_efect);
	m_sprite_nube.setPosition(pos);
	m_sprite_nube.setTexture(*m_textura_nube);
	m_sprite_rayo.setPosition(pos+Vector2f(45,80));
	m_sprite_rayo.setTexture(*m_textura_rayo);
	m_sprite_rayo.scale(2.3f, 2.3f);
	danio = 1;
}

void Nubes::dibujar(RenderWindow& w)
{
	if (probabilidad(6)) {
		if (probabilidad(50)) {
			m_sprite_rayo.setScale(-2.3, 2.3);
			m_sprite_rayo.move(100,0);
		}
		if (probabilidad(10)) {
			w.draw(m_efecto);
		}
		//w.draw(m_hitbox_rayo);
		w.draw(m_sprite_rayo);
	}
	w.draw(m_sprite_nube);
}


void Nubes::actualizar()
{
	m_sprite_nube.move(vel, 0.f);
	m_sprite_rayo.move(vel, 0.f);
	m_hitbox_rayo.setPosition(m_sprite_rayo.getPosition()+Vector2f(0.f,50));
}

bool Nubes::borrar()
{
	return m_sprite_nube.getPosition().x > 1200;
}

int Nubes::getDanio()
{
	return danio;
}

RectangleShape Nubes::getHitbox()
{
	return m_hitbox_rayo;
}
