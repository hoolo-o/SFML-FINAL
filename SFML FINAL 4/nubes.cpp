#include "nubes.h"
#include <iostream>
#include <random>
#include "Func_aux.h"

Nubes::Nubes(Vector2f pos, Texture* T_nube, Texture* T_rayo, Texture* T_efect)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	float lower_bound = 1.0f;
	float upper_bound = 3.0f;

	std::uniform_real_distribution<float> distribution(lower_bound, upper_bound);
	vel = distribution(gen);
	m_pos = pos;
	m_textura_nube = T_nube;
	m_textura_rayo = T_rayo;
	m_efecto.setSize(Vector2f(1200, 700));
	m_efecto.setTexture(T_efect);
	m_sprite_nube.setPosition(pos);
	m_sprite_nube.setTexture(*m_textura_nube);
	m_sprite_rayo.setPosition(pos+Vector2f(45,80));
	m_sprite_rayo.setTexture(*m_textura_rayo);
	m_sprite_rayo.scale(2.3f, 2.3f);
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
		w.draw(m_sprite_rayo);
	}
	w.draw(m_sprite_nube);
}


void Nubes::actualizar()
{
	m_sprite_nube.move(vel, 0.f);
	m_sprite_rayo.move(vel, 0.f);
}

bool Nubes::borrar()
{
	return m_sprite_nube.getPosition().x > 1200;
}
