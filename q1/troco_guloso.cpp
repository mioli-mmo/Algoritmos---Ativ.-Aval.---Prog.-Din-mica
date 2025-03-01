#include <iostream>
#include <vector>

int menorTroco(std::vector<int> s, int n, int v) {

	std::vector<int> resp;
	
	// Encontrando valores
	for (int i = n-1; i >= 0; i--) {
		while (v >= s[i]) {
			v -= s[i]; // subtrai valor do alvo
			resp.push_back(s[i]); // inclui valor na resposta
		}
	}
	
	return resp.size();
	
}


int main() {
	std::vector<int> s = {1,2,5,10,20,50,100,200,500};
	int n = 9;
	
	std::cout << menorTroco(s, n, 7) << std::endl;

	return 0;
}
