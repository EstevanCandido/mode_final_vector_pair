#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

int moda_pares_validos(std::vector<std::pair<int, double>> pares) {
    // Cria um vetor para armazenar os pares que atendem à condição de diferença menor que 2.5
    std::vector<std::pair<int, double>> pares_validos;
    // Adiciona o primeiro par do vetor
    //pares_validos.push_back(pares[0]);

    // Verifica a diferença entre cada segundo elemento (T2) e armazena apenas os pares que atendem à condição
    for (int i = 1; i < pares.size(); i++) {
        if (std::abs(pares[i].second - pares[i-1].second) < 2.5) {
            pares_validos.push_back(pares[i]);
        }
    }

    // Verifica se há pares válidos para calcular a moda
    if (pares_validos.empty()) {
        return -1;
    }

    // Cria um mapa para contar as ocorrências de cada primeiro elemento (T1) dos pares válidos
    std::map<int, int> contador;
    for (auto par : pares_validos) {
        contador[par.first]++;
    }

    // Encontra a moda do primeiro elemento (T1) dos pares válidos
    int moda = 0;
    int max_ocorrencias = 0;
    for (auto it = contador.begin(); it != contador.end(); it++) {
        if (it->second > max_ocorrencias) {
            moda = it->first;
            max_ocorrencias = it->second;
        }
    }

    return moda;
}


int main() {
    std::vector<std::pair<int, double>> pares = {{1, 3.56},
                                                 {3, 5.56},
                                                 {3, 6.56},
                                                 {3, 8.34}, 
                                                 {2, 9.56}, 
                                                 {2, 12.30}, 
                                                 {2, 13.66}, 
                                                 {2, 14.52}, 
                                                 {2, 15.56}, 
                                                 {2, 16.28}, 
                                                 {3, 170.45},
                                                 {3, 180.45},
                                                 {3, 190.50},
                                                 {3, 200.50},
                                                 {3, 210.50},
                                                 {3, 220.50},
                                                 {3, 230.50},
                                                 {3, 240.50},
                                                 {3, 250.50},
                                                 {3, 260.50},
                                                 {3, 270.50},
                                                 {3, 280.50},
                                                 {3, 290.45},
                                                 {3, 300.45},
                                                 {3, 310.45},
                                                 {3, 320.50},
                                                 {3, 330.50},
                                                 {3, 34.50},
                                                 {4, 350.50},
                                                 {4, 360.50},
                                                 {4, 370.50},
                                                 {4, 380.50},
                                                 {4, 390.50},
                                                 {4, 400.50},
                                                 {4, 410.50},
                                                 {4, 420.45},
                                                 {4, 430.45},
                                                 {4, 440.45},
                                                 {4, 450.50},
                                                 {4, 460.50},
                                                 {4, 470.50},
                                                 {4, 480.50},
                                                 {4, 490.50},
                                                 {4, 500.50},
                                                 {4, 510.50},
                                                 {4, 515.50},
                                                 {4, 518.50},
                                                 {4, 520.50},
                                                 {4, 525.45},
                                                 {5, 56.56},
                                                 {5, 57.50},
                                                 {5, 58.50},
                                                 {5, 59.50},
                                                 {6, 60.45},
                                                 {6, 60.90},
                                                 {6, 56.56},
                                                 {6, 57.50},
                                                 {6, 58.50},
                                                 {6, 59.50},
                                                 {6, 60.45},
                                                 {6, 60.90},
                                                 {5, 61.56}};

  for (const auto& par : pares) 
  {
    std::cout << "(" << par.first << ", " << par.second << ")" << std::endl;
  }

    int moda = moda_pares_validos(pares);
    std::cout << "Moda: " << moda << std::endl;
    return 0;
}
