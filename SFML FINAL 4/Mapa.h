#pragma once
/////////////////////terminar mapa///////////////////////////
#include <iostream>
#include <random>
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
public:
    Mapa() {
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribX(0, ancho - 1);
        std::uniform_int_distribution<int> distribY(0, alto - 1);

        for (int i = 0; i < 3; i++) {
            biomaInfo[i] = { static_cast<char>('A' + i), distribX(gen), distribY(gen) };
        }
    }

    void dibujar(RenderWindow &w) {
        w.draw(mapa);
    }

    void generarMapa() {
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
        for (int i = 0; i < ancho; i++) {
            for (int j = 0; j < alto; j++) {
                std::cout << campo[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void Combinar() {
        comb.create(ancho * 32, alto * 32);
        std::cout << "combinacion" << std::endl;                
        sf::Sprite SpriteTiles;
        sf::Texture tiles;
        SpriteTiles.setTexture(tiles);
        tiles.loadFromFile("C:/Users/ccpro/OneDrive/Escritorio/imagenes/GRASS+.png");
        for (int An = 0; An < ancho; An++) {
            for (int Al = 0; Al < alto; Al++) {
                switch (campo[An][Al]) {
                case 'A':
                    SpriteTiles.setTextureRect(sf::IntRect(64, 0, 16, 16));
                    SpriteTiles.setPosition(An * 16, Al * 16);
                    comb.draw(SpriteTiles);
                    std::cout << "A ";
                    break;
                case 'B':
                    SpriteTiles.setTextureRect(sf::IntRect(0, 32, 16, 16));
                    SpriteTiles.setPosition(An * 16, Al * 16);
                    comb.draw(SpriteTiles);
                    std::cout << "B ";
                    break;
                case 'C':
                    SpriteTiles.setTextureRect(sf::IntRect(0, 64, 16, 16));
                    SpriteTiles.setPosition(An * 16, Al * 16);
                    comb.draw(SpriteTiles);
                    std::cout << "C ";
                    break;
                case 'X':
                        SpriteTiles.setTextureRect(sf::IntRect(6 * 16, 3 * 16, 16, 16));
                        SpriteTiles.setPosition(An * 16, Al * 16);
                        comb.draw(SpriteTiles);
                    break;
                }
            }
            std::cout << std::endl;
        }
        comb.display();

        sf::Sprite combiSprite(comb.getTexture());
        mapa = combiSprite;
    }

    void Decoracion() {
        combDec.create(ancho * 32, alto * 32);
        sf::Sprite SpriteTiles;
        sf::Texture tiles;
        SpriteTiles.setTexture(tiles);
        tiles.loadFromFile("C:/Users/ccpro/OneDrive/Escritorio/imagenes/GRASS+.png");
        sf::Sprite SpriteTiles2;
        sf::Texture tiles2;
        SpriteTiles2.setTexture(tiles2);
        tiles2.loadFromFile("C:/Users/ccpro/OneDrive/Escritorio/imagenes/Free-2D-RPG-Desert-Tileset3-720x480-PhotoRoom.png-PhotoRoom.png");
        for (int An = 0; An < ancho; An++) {
            for (int Al = 0; Al < alto; Al++) {
                switch (campo[An][Al]) {
                case 'A':
                    //campo arbustos
                    if (probabilidad(10)) {
                        SpriteTiles.setTextureRect(sf::IntRect(10*16,11*16, 16, 16));
                        SpriteTiles.setPosition(An * 16, Al * 16);
                        comb.draw(SpriteTiles);
                    }
                    break;
                case 'B':
                    //desierto
                    if (probabilidad(3)) {
                        SpriteTiles.setTextureRect(sf::IntRect(7*16, 12*16, 16, 16));
                        SpriteTiles.setPosition(An * 16, Al * 16);
                        comb.draw(SpriteTiles);
                    }
                    else if (probabilidad(1)) {
                        SpriteTiles2.setTextureRect(sf::IntRect(375, 241, 40, 50));
                        SpriteTiles2.setPosition(An * 16, Al * 16);
                        SpriteTiles2.setScale(rand() % 2 ? -1 : 1, 1);
                        comb.draw(SpriteTiles2);
                    }

                    break;
                case 'C':
                    //campo piedras
                    if (probabilidad(2)) {
                        SpriteTiles.setTextureRect(sf::IntRect(5*16, 13*16, 16, 16));
                        SpriteTiles.setPosition(An * 16, Al * 16);
                        comb.draw(SpriteTiles);
                    }
                    else if (probabilidad(5)) {
                        SpriteTiles.setTextureRect(sf::IntRect(12*16,16 *16, 16, 16));
                        SpriteTiles.setPosition(An * 16, Al * 16);
                        SpriteTiles.setScale(rand() % 2 ? -1 : 1, 1);
                        comb.draw(SpriteTiles);
                    }
                    break;
                case 'X':
                    if (probabilidad(15)) {
                        SpriteTiles.setTextureRect(sf::IntRect(10 * 16, 13 * 16, 16, 16));
                        SpriteTiles.setPosition(An * 16, Al * 16);
                        comb.draw(SpriteTiles);
                    }
                    else if (probabilidad(10)) {
                        SpriteTiles.setTextureRect(sf::IntRect(3 * 16, 13 * 16, 16, 16));
                        SpriteTiles.setPosition(An * 16, Al * 16);
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
        const int FILAS = 75;
        const int COLUMNAS = 44;
        const int TAMANIO_CIRCULO = 5;
        srand(static_cast<unsigned int>(time(0)));
        // Generar coordenadas aleatorias para el centro del círculo
        int centroFila = rand() % (FILAS - 2 * TAMANIO_CIRCULO) + TAMANIO_CIRCULO;
        int centroColumna = rand() % (COLUMNAS - 2 * TAMANIO_CIRCULO) + TAMANIO_CIRCULO;

        // Agregar el círculo a la matriz
        for (int i = -TAMANIO_CIRCULO; i <= TAMANIO_CIRCULO; ++i) {
            for (int j = -TAMANIO_CIRCULO; j <= TAMANIO_CIRCULO; ++j) {
                if (i * i + j * j <= TAMANIO_CIRCULO * TAMANIO_CIRCULO) {
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
};

