#include "esqueleto_distancia.h"

Pedrero::Pedrero(float vel, float vel_atac, float vida, int danio, Vector2f pos, Texture* TE)
{
	m_textura = TE;
    m_vel = vel;
    m_vel_atac = vel_atac;
    m_vida = vida;
    m_danio = danio;


    m_sprite.setTexture(*TE);
    m_sprite.setPosition(m_pos);
    m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    m_sprite.scale(0.7f, 0.7f);

    m_hitbox_mid.setFillColor(Color::White);
    m_hitbox_mid.setRadius(120);

    m_hitbox_max.setFillColor(Color::Green);
    m_hitbox_max.setRadius(200);
    
    m_hitbox_min.setFillColor(Color::Red);
    m_hitbox_min.setRadius(40);


}

void Pedrero::dibujar(RenderWindow& w)
{
    w.draw(m_hitbox_max);
    w.draw(m_hitbox_mid);
    w.draw(m_hitbox_min);
    w.draw(m_sprite);
}

void Pedrero::actualizar(Vector2f pos_p, CircleShape hitbox_p1)
{
    if (!ColisionCirculo(hitbox_p1, m_hitbox_max) and not ColisionCirculo(hitbox_p1, m_hitbox_mid)) {
        perseguirJugador(pos_p);
    }
    else {

    }
}

void Pedrero::CambiarSpriteDireccion(int pos) {
    //modifica sprite dependiendo las coordenadas del jugador
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
    m_sprite.setTextureRect(sf::IntRect(coordX * 64, coordY * 64, 64, 64));
}


void Pedrero::perseguirJugador(const sf::Vector2f& posicionJugador) {
    if (m_clock.getElapsedTime() >= seconds(m_vel_atac)) {
        puede_atacar = true;
    }
    //llama a funcion anterior y modifica la pos persiguiendo al jugador
    sf::Vector2f direccion = posicionJugador - m_sprite.getPosition();
    //normalizar vector
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
    m_sprite.move(direccion * m_vel);
    //posiciona hitbox sobre el esqueleto
    m_hitbox.setPosition(m_sprite.getPosition() - Vector2f(-10.0f, -10.0f));
    m_hitbox_max.setPosition(m_sprite.getPosition()-Vector2f(185,185));
    m_hitbox_mid.setPosition(m_sprite.getPosition()-Vector2f(100,100));
    m_hitbox_min.setPosition(m_sprite.getPosition()-Vector2f(15,15));
}
