#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Esqueleto {
private:
	Texture* m_textura;
	Sprite m_sprite;
	Clock m_clock;
	Vector2f m_pos;

	CircleShape hitbox;

	Sprite SpriteEsqueleto;

	int Valor = 5;

	float m_vel;
	float m_vel_atac;
	float m_vida;
	int m_danio;
public:
	Esqueleto(float vel, float vel_atac, float vida, int danio, Vector2f pos, Texture* TE);
	void actualizar();
	void dibujar(RenderWindow& w);
	Vector2f verPosicion();
	void CambiarSpriteDireccion(int pos);
	void perseguirJugador(const sf::Vector2f& posicionJugador);
	void setVelocidadAleatoria(float minVel, float maxVel);
	void Danio(int damage);
	bool muerto();
	Sprite getSprite();
	float getVida();
	CircleShape getHitBox();
	Vector2f EvitarSuperPos(sf::CircleShape C);
	void mover(sf::Vector2f correccion);
	Vector2f getHitBox_Pos();
	int getDanio();
	int getValorEsqueleto();
};