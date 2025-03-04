#include <iostream>
#include <vector>
#include <climits>

int troco_memo_rec(int i, int v, std::vector<int> &c, std::vector<std::vector<int>> &memo) {

    if (v == 0) return 0; // caso de base, valor-alvo == 0
    if (v <0 || i == c.size()) return INT_MAX; // caso de base, não conseguimos formar o valor
    
    if (memo[i][v]!=-1) return memo[i][v]; // se já calculamos resultado, retorne-o
    
    int usar = INT_MAX; // por padrão, define como impossível de formar valor, muda caso prove o contrário
    
    usar = troco_memo_rec(i, v-c[i], c, memo); // caminho USAR: inclui moeda, subtrai do valor v
    if (usar != INT_MAX) usar++; // se foi possível usar moeda, adiciona 1 moeda
    
    int naoUsar = troco_memo_rec(i+1, v, c, memo); // caminho NAOUSAR: ignora moeda e passa para a próxima
    
    return memo[i][v] = std::min(usar, naoUsar); // escolhe a melhor opção entre os dois caminhos
}

int troco_memo(std::vector<int> &c, int v) { // função inicial
    std::vector<std::vector<int>> memo(c.size(), std::vector<int>(v+1, -1)); // cria vetor 2D para armazenar resultados e preenche tudo com -1 (não calculado)
    int resp = troco_memo_rec(0, v, c, memo); // resp = resultado da chamada recursiva
    
    if (resp != INT_MAX) {
    	return resp; // retorna resp caso seja possível formar valor v
    } else {
    	return -1; // -1 caso contrário
    }
    
}

int main() {
	
	int n;
	int v;
	
	std::cin >> n;
	std::vector<int> c(n);
	
	for (int i = 0; i < n; i++) {
		std::cin >> c[i]; 
	}
	
	std::cin >> v;
	
	std::cout << troco_memo(c, v) << std::endl;

	return 0;
}	
