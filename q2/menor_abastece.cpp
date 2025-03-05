#include <iostream>
#include <vector>
#include <climits>

struct Posto { // struct para armazernar info dos postos
    int distancia;
    int tempo;
};

int menor_abastece(std::vector<Posto> &postos, int distanciaTotal) { // recebe lista de postos e distância total
    int n = postos.size();
    std::vector<int> tempoMin(n + 2, INT_MAX); // armazena os tempos para alcançar cada ponto (+2 para incluir C1 e C2 como pontos)
    
    postos.insert(postos.begin(), {0, 0}); // C1: ponto inicial (distância 0 e tempo 0)
    postos.push_back({distanciaTotal, 0}); // C2: ponto final (distância total e tempo 0)
    
    tempoMin[0] = 0; // tempo para chegar a C1 é 0
    
    for (int i = 0; i < postos.size(); i++) { // itera pelos postos (ponto de partida)
        if (tempoMin[i] == INT_MAX) continue; // Se tempoMin de i for invalido, é inacessível, então pula
        
        for (int j = i + 1; j < postos.size() && (postos[j].distancia - postos[i].distancia) <= 100; j++) { // itera pelos postos depois de i enquanto houver postos && enquanto a distância for acessível (<= 100 km)
            int novoTempo = tempoMin[i] + postos[j].tempo; // novoTempo é o tempo acumulado até i + tempo até o próximo posto acessível
            if (novoTempo < tempoMin[j]) { // se novoTempo for melhor que o tempo até j armazenado, substitui
                tempoMin[j] = novoTempo;
            }
        }
    }
    
    return tempoMin[n + 1]; // Retorna o menor tempo acumulado para chegar ao fim do trajeto
}

int main() {
    int n, distanciaTotal;
    std::cin >> distanciaTotal;
    std::cin >> n; // qtd de postos
    std::vector<Posto> postos(n);
    
    for (int i = 0; i < n; i++) { // Recebe info dos postos (distância e tempo para cada posto)
    							  // a distância deve ser em ordem crescente; ex.: p1 (100,12), p2(120,10),
    							  // p3(180,15) ...
        std::cin >> postos[i].distancia >> postos[i].tempo;
    }
    
    std::cout << menor_abastece(postos, distanciaTotal) << " min" << std::endl;
    
    return 0;
}

