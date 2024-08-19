#include <iostream>
#include "../include/grafo.hpp"

using namespace std;

Grafo::Grafo(int n) : numVertices(n), vertices(nullptr) {
    vertices = new Vertice[numVertices];
}

Grafo::~Grafo() {
    for (int i = 0; i < numVertices; ++i) {
        Aresta* atual = vertices[i].listaArestas;
        while (atual) {
            Aresta* proxima = atual->proximaAresta;
            delete atual;
            atual = proxima;
        }
    }
    delete[] vertices;
}

void Grafo::lerEntrada() {
    for (int i = 0; i < numVertices; ++i) {
        int qtdVizinhos;
        cin >> qtdVizinhos;

        for (int j = 0; j < qtdVizinhos; j++) {
            int adjcVertice;
            cin >> adjcVertice;

            // Adiciona a aresta à lista de arestas do vértice
            vertices[i].listaArestas = new Aresta(adjcVertice, vertices[i].listaArestas);
        }

        int corEscolhida;
        cin >> corEscolhida;
        vertices[i].cor = corEscolhida;
    }
}

bool Grafo::avaliarColoracaoGulosa() {
    for (int i = 0; i < numVertices; i++) {
             Aresta* atual = vertices[i].listaArestas;

            int menorCorVizinho = 0;

            while (atual != nullptr) {
                int indiceVizinho = atual->vizinho;
                int corVizinho = vertices[indiceVizinho].cor;

                if (corVizinho >= 0 && corVizinho < menorCorVizinho) {
                    menorCorVizinho = corVizinho;
                }

                // Avança para o próximo vizinho
                atual = atual->proximaAresta;
            }

            // Verifique se a cor do vértice atual é a menor disponível
            if (vertices[i].cor != menorCorVizinho + 1) {
                return false; 
            }
    }
    return true;
}
Vertice* Grafo::getVertices() {
    return vertices;
}
