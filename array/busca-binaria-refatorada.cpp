/*
Busca binária, utilziando uma função genérica com iteradores.
*/

#include <iostream>
#include <vector>


/*
Iterador: representa uma posição dentro de uma sequência (array ou vector)

Essa função exige iteradores de acesso, para iterar tanto o array
quanto o vector.
*/
template <typename Iterator>
int busca_binaria(Iterator inicio_dados, Iterator fim_dados, int valor){
    int quantidade = static_cast<int>(fim_dados - inicio_dados);
    int inicio = 0;
    int fim = quantidade - 1;

    while (inicio <= fim){
        int meio = inicio + (fim - inicio) / 2;
        
        // Para acessar o elemento do meio:
        // inicio_dados + meio -> aponta para a posição desejada
        // Portanto para obter o valor que se encontra na posição,
        // usamos "*".
        int elemento_meio = *(inicio_dados + meio);

        if (elemento_meio == valor){
            return elemento_meio;
        } else if (elemento_meio < valor){
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

    int valor_procurado = 40;

    /*
    Em um array, o nome do array aponta para o primeiro elemento.

    Ex:
        numeros_array + 7 = aponta para a posição depois do último elemento.
    */
   int resultado_array =
        busca_binaria(numeros_array, numeros_array + 7, valor_procurado);

    // begin() aponta para o início.
    // end() aponta para o fim.
    int resultado_vector =
        busca_binaria(
            numeros_vector.begin(),
            numeros_vector.end(),
            valor_procurado
        );
    
    std::cout << "Array: " << resultado_array << '\n';
    std::cout << "Vector: " << resultado_vector << '\n';
}