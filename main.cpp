#include <iostream>
#include <vector>
#include "loja.hpp"

int organizaPrateleira(int qtd_rolos);
int colocaRolos(std::vector<int> rolos);

int main() {
    // Quantidade de testes
    int N = 0;
    std::cin >> N;

    for (int num_teste = 0; num_teste < N; num_teste++) {
        // Quantidade de rolos
        int R = 0;
        std::cin >> R;

        int qtd_rolos_prateleira = organizaPrateleira(R);
        std::cout << qtd_rolos_prateleira << std::endl;
    }
}

// Preenche o vetor de rolos e retorna a quantidade máxima
int organizaPrateleira(int qtd_rolos) {
    std::vector<int> rolos(qtd_rolos);

    for (int i = 0; i < qtd_rolos; i++) {
        int preco_rolo = 0;
        std::cin >> preco_rolo;

        rolos[i] = preco_rolo;
    }

    return colocaRolos(rolos);
}

// Calcula a quantidade máxima de rolos que podem ser dispostos na prateleira
int colocaRolos(std::vector<int> rolos) {
    int quantidade = rolos.size(), quantidade_max = 1;
    std::vector<int> cache_crescente(quantidade, 1), cache_decrescente(quantidade, 1);

    for (int i = quantidade-1; i >= 0; i--) {
        for (int j = i+1; j < quantidade; j++) {         
            if (rolos[i] < rolos[j]) 
                cache_crescente[i] = std::max(cache_crescente[i], cache_crescente[j] + 1);

            if (rolos[i] > rolos[j]) 
                cache_decrescente[i] = std::max(cache_decrescente[i], cache_decrescente[j] + 1);

            quantidade_max = std::max(quantidade_max, cache_crescente[i] + cache_decrescente[i] - 1);
        }
    }

    return quantidade_max;
}