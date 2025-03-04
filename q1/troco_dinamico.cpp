#include <iostream>
#include <vector>
#include <climits>

int troco_dinamico(std::vector<int> &c, int n, int v)
{
    if (v == 0) // caso de base
        return 0;
   	std:: vector<int> solucoes(v+1); // vetor que armazena resultados; o tamanho é baseado em v
    solucoes[0] = 0; // para formar v = 0, precisamos de 0 moedas

    for (int i = 1; i <= v; i++)
        solucoes[i] = INT_MAX; // por padrão, indica um valor impssível; é alterado caso se prove o contrário

    for (int i = 1; i <= v; i++) // itera valores de 1 até v
    {
        for (int j = 0; j < n; j++) // itera pelas moedas
        {
            if (c[j] <= i)// verifica se pode usar moeda atual
            {
                int conta = solucoes[i - c[j]]; 
                if (conta != INT_MAX && conta + 1 < solucoes[i]) // se a conta atual for menor, adicone em solucoes[i]
                    solucoes[i] = conta + 1;
            }
        }
    }

    if (solucoes[v] == INT_MAX)
        return -1;
    else
        return solucoes[v];
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
	
	std::cout << troco_dinamico(c, n, v) << std::endl;

	return 0;
}	
