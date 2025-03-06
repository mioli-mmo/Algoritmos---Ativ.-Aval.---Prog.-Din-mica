#include <iostream>
#include <vector>

struct Livro {
	int preco;
	int paginas;
};

int max_paginas(int orcamento, std::vector<Livro> &livros, int n) {
  
    if (n == 0 || orcamento == 0) // casos de base: chegou ao fim da lista || fim do orçamento
        return 0;

	// [n-1] = livro atual
    if (livros[n-1].preco > orcamento) //  se o livro atual for caro demais, ignore-o
        return max_paginas(orcamento, livros, n - 1);

	// ramifica: a) não compra o livro; b) compra o livro.
	// Depois escolhe o maior valor entre os dois retornos
    return std::max(max_paginas(orcamento, livros, n - 1), // não compra
   		   livros[n-1].paginas + max_paginas(orcamento - livros[n-1].preco, livros, n - 1)); // compra
}

int main() {
	int n;
	int orcamento;
	std::cin >> n >> orcamento;
    std::vector<Livro> livros(n);
    
    for (int i = 0; i < n; i++) { // recebe dados dos livros
    	std::cin >> livros[i].preco >> livros[i].paginas;
    }

    std::cout << max_paginas(orcamento, livros, n) << std::endl;
    return 0;
}

