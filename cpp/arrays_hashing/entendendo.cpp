#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <functional>

    int main() {
        // Definindo o mapa de frequências
        std::unordered_map<int, int> count_map = {
            {3, 1},
            {2, 2},
            {-1, 2},
            {1, 1},
            {4, 1}
        };

        // Definindo o comparador personalizado
        auto comp = [&count_map](int n1, int n2) {
            return count_map[n1] > count_map[n2];
        };

    // Definindo a priority_queue com o comparador personalizado
    std::priority_queue<int, std::vector<int>, decltype(comp)> heap(comp);

    // Inserindo as chaves do mapa na priority_queue
    int k = 2;
    for (const auto& pair : count_map) {
        heap.push(pair.first);
        if(heap.size() > k) heap.pop();
    }

    // Extraindo e exibindo os elementos da priority_queue
    while (!heap.empty()) {
        int top = heap.top();
        std::cout << "Elemento: " << top << ", Frequência: " << count_map[top] << std::endl;
        heap.pop();
    }

    return 0;
}

