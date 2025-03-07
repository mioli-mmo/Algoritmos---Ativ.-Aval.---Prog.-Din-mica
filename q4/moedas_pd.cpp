#include <iostream>
#include <vector>

int moedas_pd(std::vector<int> &c, int n, int v) {

    std::vector<std::vector<int>> pd(n + 1, std::vector<int>(v + 1, 0));
    // vetor com (n+1) linhas e cada coluna tem um vetor(v+1) preenchido com 0

    pd[0][0] = 1; // há apenas uma forma de fazer 0 com 0 moedas
    for (int i = 1; i <= n; i++) { // itera pelas moedas
        for (int j = 0; j <= v; j++) { // itera pelos valores de 0 a v
            pd[i][j] += pd[i - 1][j]; // opção sem usar moeda atual

            if ((j - c[i - 1]) >= 0) { // se for possível subtrair moeda do valor:
                pd[i][j] += pd[i][j - c[i - 1]]; // opção usando moeda atual
            }
        }
    }
    return pd[n][v];
}

int main() {
	int n;
	int v;
	std::cin >> n >> v;
	
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> c[i];
    }
    
    std::cout << moedas_pd(c, n, v) << std::endl;
    return 0;
}
