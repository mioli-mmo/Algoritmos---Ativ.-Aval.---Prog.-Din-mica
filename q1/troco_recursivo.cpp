#include <iostream>
#include <vector>
#include <climits>

int troco_recursivo(std::vector<int> &c, int n, int v)
{
    if (v == 0) // caso de base = valor alcançada || valor == 0
        return 0;
    
    int resp = INT_MAX; // caso de base = v < 0
    
    for (int i = 0; i < n; i = i + 1) // itera por todas as moedas
    {
        if (c[i] <= v) // inclui moeda atual caso não seja maior que v
        {
            int conta = troco_recursivo(c, n, v - c[i]); // chamada recursiva incluindo moeda
            if ( (conta != INT_MAX) && (conta + 1 < resp) ) // se conta atual < conta resp, substitua
                resp = conta + 1;
        }
    }
    
    if (resp == INT_MAX)
        return -1;
    else
        return resp;
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
	
	std::cout << troco_recursivo(c, n, v) << std::endl;

	return 0;
}	
