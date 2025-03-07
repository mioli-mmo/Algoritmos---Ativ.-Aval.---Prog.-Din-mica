#include <iostream>
#include <vector>

struct Livro {
	int preco;
	int paginas;
};

int max_paginas_pd(int orcamento, std::vector<Livro> &livros) {
    int n = livros.size();
    std::vector<std::vector<int>> pd(n + 1, std::vector<int>(orcamento + 1)); // cria um vetor 2D:
    																		  // livros x orçamento

    for (int i = 0; i <= n; i++) { // itera livros
        for (int j = 0; j <= orcamento; j++) { // itera orçamento
            if (i == 0 || j == 0) { // casos de base
                pd[i][j] = 0;
            }
            else if (livros[i - 1].preco <= j) { // se for possível comprar o livro:				// max entre:
                pd[i][j] = std::max(livros[i - 1].paginas + pd[i - 1][j - livros[i - 1].preco], // compra o livro
															// e subtrai preço
                           pd[i - 1][j]);
			}												// ou valor armazenado
            else {
                pd[i][j] = pd[i - 1][j]; // se não pode comprar livro, copia valor anterior
            }
        }
    }
    return pd[n][orcamento]; // resultado final está no final da matriz
}

int main() {
	int n;
	int orcamento;
	std::cin >> n >> orcamento;
    std::vector<Livro> livros(n);
    
    for (int i = 0; i < n; i++) { // recebe dados dos livros
    	std::cin >> livros[i].preco >> livros[i].paginas;
    }

    std::cout << max_paginas_pd(orcamento, livros) << std::endl;
    return 0;
}
