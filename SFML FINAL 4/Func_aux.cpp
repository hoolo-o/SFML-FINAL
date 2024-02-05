#include "Func_aux.h"
#include <iostream>
#include "nubes.h"
#include <random>


bool compararPorKills(const UsuarioInfo& a, const UsuarioInfo& b) {
    return a.kills > b.kills;
}


std::vector<Esqueleto> EsqueletosBordes(int cantidad, sf::Texture* TE, char* mapa)
{
    std::vector<Esqueleto> esqueletos;

    int ancho = 75;
    int alto = 44;

    for (int An = 0; An < ancho; An++) {
        for (int Al = 0; Al < alto; Al++) {
            if (*(mapa + An * 44 + Al) == 'X') {
                sf::Vector2f posini = { An * 16.0f, Al * 16.0f };
                if (probabilidad(50) and esqueletos.size()<cantidad) {
                    std::cout << "X ";
                    Esqueleto esqts(1, 1, 15, 1.0f, posini, TE);
                    esqts.setVelocidadAleatoria(0.4f, 1.0f);
                    esqueletos.push_back(esqts);
                }
            }
        }
    }
    return esqueletos;
}

bool probabilidad(int prob)
{
    int aleatorio = std::rand() % 100;
    return aleatorio < prob;
}

bool Colision(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
    return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
    std::cout << "HIT" << std::endl;
}

bool ColisionCirculo(const CircleShape& circulo1, const CircleShape& circulo2) {
    //posicion circulos
    sf::Vector2f cent1 = circulo1.getPosition() + Vector2f(circulo1.getRadius(), circulo1.getRadius());
    sf::Vector2f cent2 = circulo2.getPosition() + Vector2f(circulo2.getRadius(), circulo2.getRadius());
    //distancia
    float distan = sqrt(std::pow(cent2.x - cent1.x, 2) + pow(cent2.y - cent1.y, 2));
    //verificar colision
    return distan <= circulo1.getRadius() + circulo2.getRadius();
}

Vector2f resolverColision(const CircleShape& cir1, const CircleShape& cir2) {
    //calculo superposicion
    float Superpos = cir1.getRadius() + cir2.getRadius() - sqrt(pow(cir1.getPosition().x - cir2.getPosition().x, 2) +
        pow(cir1.getPosition().y - cir2.getPosition().y, 2));
    //calculo angulos entre centros ciruclos
    float angulo = atan2(cir1.getPosition().y - cir2.getPosition().y, cir1.getPosition().x - cir2.getPosition().x);
    //calculo desplazamiento
    float moverX = Superpos * cos(angulo) / 2.0f;
    float moverY = Superpos * sin(angulo) / 2.0f;
    return Vector2f(moverX, moverY);
}

bool mouse(Vector2f mousePos, RectangleShape& rect) {
    return mousePos.x > rect.getPosition().x &&
        mousePos.x < rect.getPosition().x + rect.getSize().x &&
        mousePos.y > rect.getPosition().y &&
        mousePos.y < rect.getPosition().y + rect.getSize().y;
}

void hilo_tiempo(Clock& reloj, Time esperar) {
    while (reloj.getElapsedTime() < esperar) {

    }
}

bool temporizador(float tiempo)
{
    sleep(seconds(tiempo));
    return true;
}

std::vector<Nubes> NubesBordes(int cantidad, sf::Texture* TN, sf::Texture* TR, sf::Texture* TE) {
    std::vector<Nubes> Nube;

    std::random_device rd;
    std::mt19937 gen(rd());

    float lower_bound = 0;
    float upper_bound = 700;

    std::uniform_real_distribution<float> distribution(lower_bound, upper_bound);

    float lower_bound2 = 0;
    float upper_bound2 = 700;

    std::uniform_real_distribution<float> distribution2(lower_bound2, upper_bound2);

    for (int i = 0; i < cantidad; i++) {
        float x = distribution2(gen);
        float y = distribution(gen);
        sf::Vector2f CoordNubes = {-x,y};
        Nubes Nubesin(CoordNubes, TN, TR, TE);
        Nube.push_back(Nubesin);
    }
    return Nube;
}

bool ColisionCirRect(const sf::RectangleShape& rect, const sf::CircleShape& cir) {
    // Obtener el centro del círculo
    sf::Vector2f circleCenter(cir.getPosition().x + cir.getRadius(), cir.getPosition().y + cir.getRadius());

    // Calcular la distancia entre el centro del círculo y el rectángulo
    float distX = std::abs(circleCenter.x - rect.getPosition().x - rect.getSize().x / 2.f);
    float distY = std::abs(circleCenter.y - rect.getPosition().y - rect.getSize().y / 2.f);

    // Si la distancia es mayor que la mitad del ancho o la mitad de la altura del rectángulo más el radio del círculo, no hay colisión
    if (distX > rect.getSize().x / 2.f + cir.getRadius() || distY > rect.getSize().y / 2.f + cir.getRadius()) {
        return false;
    }
    return true;
}

vector<UsuarioInfo> cargarDatosDesdeArchivo() {
    vector<UsuarioInfo> usuarios;
    ifstream archivo("Listaa.txt");
    if (archivo.is_open()) {
        UsuarioInfo usuario;
        while (archivo>> usuario.usuario >> usuario.kills >> usuario.puntos) {
            usuarios.push_back(usuario);
        }
        archivo.clear();
        archivo.close();
    }
    for (int x = 0; x < usuarios.size();x++) {
        cout << usuarios[x].usuario << usuarios[x].kills << usuarios[x].puntos << endl;
    }
    return usuarios;
}

void actualizarArchivo( UsuarioInfo nuevoUsuario) {
    vector<UsuarioInfo> usuarios = cargarDatosDesdeArchivo();
    bool usuarioExiste = false;

    for (int x = 0;x < usuarios.size();x++) {
        if (usuarios[x].usuario == nuevoUsuario.usuario) {
            usuarioExiste = true;
            if (nuevoUsuario.kills > usuarios[x].kills) {
                usuarios[x].kills = nuevoUsuario.kills;
                usuarios[x].puntos = nuevoUsuario.puntos;
            }
            break;
        }
    }

    if (!usuarioExiste) {
        usuarios.push_back(nuevoUsuario);
    }

    ofstream archivo("Listaa.txt");
    archivo.clear();
    if (archivo.is_open()) {
        for (UsuarioInfo usuario : usuarios) {
           archivo << usuario.usuario << " " << usuario.kills << " " << usuario.puntos << endl;
        }
        for (int x = 0; x < usuarios.size();x++) {
            cout << usuarios[x].usuario << usuarios[x].kills << usuarios[x].puntos << endl;
        }
        archivo.close();
    }
}
