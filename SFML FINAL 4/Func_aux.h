#pragma once
#include "Esqueleto.h"
#include <fstream>
#include <sstream>
#include "vector"
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "nubes.h"

struct UsuarioInfo
{
	string usuario;
	int kills;
	int puntos;
};

struct direccion {
	bool arriba;
	bool abajo;
	bool izquierda;
	bool derecha;
};
vector<Nubes> NubesBordes(int cantidad, sf::Texture* TN, sf::Texture* TR, sf::Texture* TE);
std::vector<Esqueleto> EsqueletosBordes(int cantidad, sf::Texture* TE, char* mapa);
bool probabilidad(int prob);
bool Colision(const Sprite& sprite1, const Sprite& sprite2);
bool ColisionCirculo(const CircleShape& circle1, const CircleShape& circle2);
Vector2f resolverColision(const CircleShape& cir1, const CircleShape& cir2);
bool mouse(Vector2f mousePos, RectangleShape& rect);
void hilo_tiempo(Clock& reloj, Time esperar);
bool temporizador(float tiempo);
bool ColisionCirRect(const sf::RectangleShape& rec, const sf::CircleShape& cir);
vector<UsuarioInfo> cargarDatosDesdeArchivo();
void actualizarArchivo( UsuarioInfo nuevoUsuario);
bool compararPorKills(const UsuarioInfo& a, const UsuarioInfo& b);