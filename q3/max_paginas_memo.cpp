#include <iostream>
#include <vector>

struct Livro {
	int preco;
	int paginas;
};

// função recursiva que preenche a tabela e divide entre comprar/ não comprar
int max_paginas_rec(int orcamento, std::vector<Livro> &livros, int index, std::vector<std::vector<int>> &memo) {
  
    if (index < 0) // caso de base: chegou ao fim da lista
        return 0;
        
    if (memo[index][orcamento] != -1) // se valor já foi calculado, retorne-o
    return memo[index][orcamento];

	if (livros[index].preco > orcamento) { // se o livro atual for caro demais, ignore-o
        memo[index][orcamento] = max_paginas_rec(orcamento, livros, index - 1, memo);
    } else {
        memo[index][orcamento] = std::max( // armazena em memo o máximo dentre os dois abaixo:
        livros[index].paginas + max_paginas_rec(orcamento - livros[index].preco, livros, index - 1, memo),
		max_paginas_rec(orcamento, livros, index - 1, memo)
		);
	}
	return memo[index][orcamento]; // retorne o valor encontrado
}
	
int max_paginas_memo(int orcamento, std::vector<Livro> &livros) { // função inicial
	int n = livros.size();
	std::vector<std::vector<int>> memo(n, std::vector<int>(orcamento + 1, -1)); // cria vetor para armazernar 
																				// resultados já calculados
	return max_paginas_rec(orcamento, livros, n - 1, memo); // chama a função recursiva
}

int main() {
	int n;
	int orcamento;
	std::cin >> n >> orcamento;
    std::vector<Livro> livros(n);
    
    for (int i = 0; i < n; i++) { // recebe dados dos livros
    	std::cin >> livros[i].preco >> livros[i].paginas;
    }

    std::cout << max_paginas_memo(orcamento, livros) << std::endl;
    return 0;
}

