#include <iostream>
#include <vector>

int moedas_rec(std::vector<int> &c, int n, int v) {
  
    if (v == 0) { // caso de base: alcançou valor
    return 1;
    }

    if (v < 0 || n == 0) { // casos de base: estourou valor ou não alcançou valor
    return 0;
    }

    return moedas_rec(c, n, v - c[n - 1]) + // inclui moeda na contagem
            moedas_rec(c, n - 1, v);		// não inclui
}


int main() {
	int n;
    int v;	
    std::cin >> n >> v;
    
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> c[i];
    }
    
    std::cout << moedas_rec(c, n, v) << std::endl;
    
    return 0;
}
