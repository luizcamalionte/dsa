#include <iostream>
#include <vector>


//Busca binária em um array
int busca_binaria_array(const int dados[], int tamanho, int valor){
    int inicio = 0;
    int fim = tamanho - 1;

    //Enquanto ainda houver elementos no intervalo de busca ...
    while (inicio <= fim){
        // calcula o índice do elemento central
        // Observação: evitar overflow
        int meio = inicio + (fim - inicio) / 2;

        if (dados[meio] == valor){
            return meio;
        } else if (dados[meio] < valor) {
            // O valor procurado é maior, então busca na metade da direita
            inicio = meio + 1;
        } else {
            // Busca na metade da esquerda
            fim = meio - 1;
        }
    }

    // o intervalo de dados acabou sem encontrar o valor
    return -1;   
}


int busca_binaria_vector(const std::vector<int>& dados, int valor){
    int inicio = 0;
    int fim = static_cast<int>(dados.size() - 1);

    while (inicio <= fim){
        int meio = inicio + (fim - inicio) / 2;

        if (dados[meio] == valor){
            return meio;
        } else if (dados[meio] < valor){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}


int main(){
    int numeros_array[] = {2, 5, 8, 12, 16, 23, 38};
    std::vector<int> numeros_vector = {2, 5, 8, 12, 16, 23, 38};

    int tamanho_array = sizeof(numeros_array) / sizeof(numeros_array[0]);
    int valor_procurado = 5;

    int resultado_array = 
        busca_binaria_array(numeros_array, tamanho_array, valor_procurado);
    
    int resultado_vector = 
        busca_binaria_vector(numeros_vector, valor_procurado);

    std::cout << "Array - encontrado no índice: " << resultado_array << '\n';
    std::cout << "Vector - encontrado no índice: " << resultado_vector << '\n';

    return 0;
}