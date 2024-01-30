#pragma once
/////////////////////terminar mapa///////////////////////////
#include <iostream>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>

class Mapa {
private:
    struct BiomaInfo {
        char tipo;
        int x;
        int y;
    };
    const int ancho = 75;
    const int alto = 44;
    char campo[75][44];
    BiomaInfo biomaInfo[3];
    sf::RenderTexture comb;
    sf::RenderTexture combDec;
    sf::RenderTexture combSpawn;
    sf::Sprite mapa;
    sf::Sprite deco;
    sf::Sprite spawn;
    sf::CircleShape piedra;
    std::vector<sf::CircleShape> hitbox_piedras;
public:
    Mapa() {
        //creacion de semilla aleatoria para distribuir en el mapa los biomas de forma heterogenea
        std::random_device rd;
        //semilla
        std::mt19937 gen(rd());
        //distribuir en el mapa los biomas de forma heterogenea
        std::uniform_int_distribution<int> distribX(0, ancho - 1);
        std::uniform_int_distribution<int> distribY(0, alto - 1);

        for (int i = 0; i < 3; i++) {
            biomaInfo[i] = { static_cast<char>('A' + i), distribX(gen), distribY(gen) };
        }
        piedra.setFillColor(sf::Color::Black);
        piedra.setRadius(12);
    }

    void dibujar(RenderWindow &w) {
        w.draw(mapa);
    }

    void generarMapa() {
        //generacion textura voronoi a partir de la ubicacion de los biomas
        for (int i = 0; i < ancho; i++) {
            for (int j = 0; j < alto; j++) {
                char mas_cercano = '.';
                int dist = 99999;

                for (int z = 0; z < sizeof(biomaInfo) / sizeof(biomaInfo[0]); z++) {
                    int xdiff = biomaInfo[z].x - i;
                    int ydiff = biomaInfo[z].y - j;
                    int cdist = xdiff * xdiff + ydiff * ydiff;

                    if (cdist < dist) {
                        mas_cercano = biomaInfo[z].tipo;
                        dist = cdist;
                    }
                }

                campo[i][j] = mas_cercano;
            }
        }
        std::cout << "mapa generado" << std::endl;
    }

    void mostrarMapa() {
        //muestra de mapa letras en consola
        for (int i = 0; i < ancho; i++) {
            for (int j = 0; j < alto; j++) {
                std::cout << campo[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void Combinar() {
        //acomodar sprites de los biomas dependiendo la la letra A B C X
        //crea textura en blanco
        comb.create(ancho * 32, alto * 32);
        std::cout << "combinacion" << std::endl;                
        sf::Sprite SpriteTiles;
        sf::Texture tiles;
        SpriteTiles.setTexture(tiles);
        tiles.loadFromFile("imagenes/GRASS+.png");
        for (int An = 0; An < ancho; An++) {
            for (int Al = 0; Al < alto; Al++) {
                switch (campo[An][Al]) {
                case 'A':
                    SpriteTiles.setTextureRect(sf::IntRect(64, 0, 16, 16));
                    SpriteTiles.setPosition(An * 16.0f, Al * 16.0f);
                    //agrega el nuevo tile a la textura 'comb'
                    comb.draw(SpriteTiles);
                    std::cout << "A ";
                    break;
                case 'B':
                    SpriteTiles.setTextureRect(sf::IntRect(0, 32, 16, 16));
                    SpriteTiles.setPosition(An * 16.0f, Al * 16.0f);
                    comb.draw(SpriteTiles);
                    std::cout << "B ";
                    break;
                case 'C':
                    SpriteTiles.setTextureRect(sf::IntRect(0, 64, 16, 16));
                    SpriteTiles.setPosition(An * 16.0f, Al * 16.0f);
                    comb.draw(SpriteTiles);
                    std::cout << "C ";
                    break;
                case 'X':
                        SpriteTiles.setTextureRect(sf::IntRect(6 * 16, 3 * 16, 16, 16));
                        SpriteTiles.setPosition(An * 16.0f, Al * 16.0f);
                        comb.draw(SpriteTiles);
                    break;
                }
            }
            std::cout << std::endl;
        }
        //guarda los cambios de la textura al finalizar
        comb.display();
        //asigna un sprite a la textura
        sf::Sprite combiSprite(comb.getTexture());
        mapa = combiSprite;
    }

    void Decoracion() {
        //crea nueva textura en blanco
        combDec.create(ancho * 32, alto * 32);
        sf::Sprite SpriteTiles;
        sf::Texture tiles;
        SpriteTiles.setTexture(tiles);
        tiles.loadFromFile("imagenes/GRASS+.png");
        sf::Sprite SpriteTiles2;
        sf::Texture tiles2;
        SpriteTiles2.setTexture(tiles2);
        tiles2.loadFromFile("imagenes/Free-2D-RPG-Desert-Tileset3-720x480-PhotoRoom.png-PhotoRoom.png");
        for (int An = 0; An < ancho; An++) {
            for (int Al = 0; Al < alto; Al++) {
                switch (campo[An][Al]) {
                case 'A':
                    //campo arbustos
                    if (probabilidad(10)) {
                        SpriteTiles.setTextureRect(sf::IntRect(10*16,11*16, 16, 16));
                        SpriteTiles.setPosition(An * 16.0f, Al * 16.0f);
                        comb.draw(SpriteTiles);
                    }
                    break;
                case 'B':
                    //desierto
                    if (probabilidad(3)) {
                        SpriteTiles.setTextureRect(sf::IntRect(7*16, 12*16, 16, 16));
                        SpriteTiles.setPosition(An * 16.0f, Al * 16.0f);
                        comb.draw(SpriteTiles);
                    }
                    else if (probabilidad(1)) {
                        SpriteTiles2.setTextureRect(sf::IntRect(375, 241, 40, 50));
                        SpriteTiles2.setPosition(An * 16.0f, Al * 16.0f);
                        SpriteTiles2.setScale(rand() % 2 ? -1 : 1, 1);
                        comb.draw(SpriteTiles2);
                    }

                    break;
                case 'C':
                    //campo piedras
                    if (probabilidad(4)) {
                        SpriteTiles.setTextureRect(sf::IntRect(5*16, 13*16, 16, 16));
                        SpriteTiles.setPosition(An * 16.0f, Al * 16.0f);
                        SpriteTiles.setScale(rand() % 2 ? -1 : 1, 1);
                        piedra.setPosition(SpriteTiles.getPosition());
                        hitbox_piedras.push_back(piedra);
                        comb.draw(SpriteTiles);
                    }
                    break;
                case 'X':
                    if (probabilidad(15)) {
                        SpriteTiles.setTextureRect(sf::IntRect(10 * 16, 13 * 16, 16, 16));
                        SpriteTiles.setPosition(An * 16.0f, Al * 16.0f);
                        comb.draw(SpriteTiles);
                    }
                    else if (probabilidad(10)) {
                        SpriteTiles.setTextureRect(sf::IntRect(3 * 16, 13 * 16, 16, 16));
                        SpriteTiles.setPosition(An * 16.0f, Al * 16.0f);
                        comb.draw(SpriteTiles);
                    }
                    break;
                }
            }
            std::cout << std::endl;
        }
        comb.display();

        sf::Sprite combiSprite(combDec.getTexture());
    }

    void SpawnE() {
        int filas = 75;
        int columnas = 44;
        int tamanio_circulo = 5;
        //generacion de semilla aleatoria dependiendo la fecha actual
        srand(static_cast<unsigned int>(time(0)));

        int centroFila = rand() % (filas - 2 * tamanio_circulo) + tamanio_circulo;
        int centroColumna = rand() % (columnas - 2 * tamanio_circulo) + tamanio_circulo;
        //dibujo circulo  de X
        for (int i = -tamanio_circulo; i <= tamanio_circulo; ++i) {
            for (int j = -tamanio_circulo; j <= tamanio_circulo; ++j) {
                if (i * i + j * j <= tamanio_circulo * tamanio_circulo) {
                    campo[centroFila + i][centroColumna + j] = 'X';
                }
            }
        }
    }

    bool probabilidad(int prob) {
        int aleatorio = std::rand() % 100;
        return aleatorio < prob;
    }

    sf::Sprite getMapa() {
        Combinar();
        return mapa;
    }
    
    char* getCampo() {
        return &campo[0][0];
    }

    std::vector<sf::CircleShape> getPiedras() {
        return hitbox_piedras;
    }
};

