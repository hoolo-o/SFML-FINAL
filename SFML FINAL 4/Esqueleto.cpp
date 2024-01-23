#include "Esqueleto.h"


Esqueleto::Esqueleto(float vel, float vel_atac, float vida, int danio, Vector2f pos, Texture*TE)
{
    m_vel = vel;
    m_vel_atac = vel_atac;
    m_vida = vida;
    m_danio = danio;
    m_pos = pos;
    m_textura = TE;
    SpriteEsqueleto.setTexture(*m_textura);
    SpriteEsqueleto.setPosition(m_pos);
    SpriteEsqueleto.setTextureRect(sf::IntRect(0, 0, 64, 64));
    SpriteEsqueleto.scale(0.6f, 0.6f);
    hitbox.setFillColor(Color::Blue);
    hitbox.setRadius(11);
}

void Esqueleto::actualizar()
{
}

void Esqueleto::dibujar(RenderWindow& w)
{
    w.draw(hitbox);
    w.draw(SpriteEsqueleto);
}

Vector2f Esqueleto::verPosicion()
{
	return SpriteEsqueleto.getPosition();
}


void Esqueleto::CambiarSpriteDireccion(int pos) {
    float coordX = 0;
    float coordY = 0;
    if (pos == 3) {
        coordX = 1;
        coordY = 4.0f;
    }
    else if (pos == 1) {
        coordX = 1;
        coordY = 5.0f;
    }
    else if (pos == 2) {
        coordX = 0;
        coordY = 0;
    }
    else if (pos == 0) {
        coordX = 1;
        coordY = 3.0f;
    }
    SpriteEsqueleto.setTextureRect(sf::IntRect(coordX * 64, coordY * 64, 64, 64));

}

void Esqueleto::perseguirJugador(const sf::Vector2f& posicionJugador) {
    sf::Vector2f direccion = posicionJugador - SpriteEsqueleto.getPosition();
    float magnitud = std::sqrt(direccion.x * direccion.x + direccion.y * direccion.y);
    direccion /= magnitud;

    int orientacion = 0; // 0: xy, 1: -xy, 2: -x-y, 3: -yx
    if (direccion.x >= 0 && direccion.y >= 0) {
        orientacion = 0; // xy
    }
    else if (direccion.x < 0 && direccion.y >= 0) {
        orientacion = 1; // -xy
    }
    else if (direccion.x < 0 && direccion.y < 0) {
        orientacion = 2; // -x-y
    }
    else if (direccion.x >= 0 && direccion.y < 0) {
        orientacion = 3; // -yx
    }

    CambiarSpriteDireccion(orientacion);
    SpriteEsqueleto.move(direccion * m_vel);
    hitbox.setPosition(SpriteEsqueleto.getPosition()-Vector2f(-7.0f,-10.0f));
}

void Esqueleto::setVelocidadAleatoria(float minVel, float maxVel) {
    m_vel = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxVel - minVel)) + minVel;
}

void Esqueleto::Danio(int damage)
{
    m_vida = m_vida - damage;
}

bool Esqueleto::muerto()
{
    if (m_vida < 1) {
        return true;
    }
    else {
        return false;
    }
}

Sprite Esqueleto::getSprite()
{
    return SpriteEsqueleto;
}

float Esqueleto::getVida() {
    return m_vida;
}

CircleShape Esqueleto::getHitBox()
{
    return hitbox;
}

Vector2f Esqueleto::EvitarSuperPos(sf::CircleShape C)
{
    Vector2f disV = C.getPosition() - hitbox.getPosition();
    float dis = sqrt(disV.x * disV.x + disV.y * disV.y);
    float radSum = C.getRadius() + hitbox.getRadius();
    if (dis < radSum) {
        return disV - ((disV / dis) * radSum);
    }
}

void Esqueleto::mover(sf::Vector2f correccion)
{
    SpriteEsqueleto.move(correccion);
}

Vector2f Esqueleto::getHitBox_Pos() {
    return hitbox.getPosition();
}

int Esqueleto::getDanio() {
    return m_danio;
}
