#include <iostream>
#include <vector>

struct Livro {
	int preco;
	int paginas;
};

void imprime_tabela(std::vector<std::vector<int>> &pd, int n, int orcamento) {

    std::cout << "Tabela:\n";
    
    std::cout << "   ";
    for (int j = 0; j < orcamento; j++) { // imprime  de 0 até orçamento
        std::cout << j << "\t";
    }
    std::cout << orcamento << "\n";

    for (int i = 0; i < n; i++) { // imprime de 0 até n (qtd. de livros)
        std::cout << i << "  ";
        for (int j = 0; j <= orcamento; j++) {
            std::cout << pd[i][j] << "\t"; // imprime valores calculados
        }
        std::cout << "\n";
    }
}


int max_paginas_pd(int orcamento, std::vector<Livro> &livros, std::vector<std::vector<int>> &pd) {
    int n = livros.size();

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
	std::vector<std::vector<int>> pd(n + 1, std::vector<int>(orcamento + 1)); // cria a tabela
    std::vector<Livro> livros(n);
    
    for (int i = 0; i < n; i++) { // recebe dados dos livros
    	std::cin >> livros[i].preco >> livros[i].paginas;
    }

    std::cout << "\n" << "Maior qtd. de páginas: " << max_paginas_pd(orcamento, livros, pd) << std::endl;
    imprime_tabela(pd, n + 1, orcamento + 1);
    
    return 0;
}
