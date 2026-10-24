/*
Queue (fila) - Usa o conceito de FIFO (First In Firt Out).

Operações básicas:
  push() - adicionar valor
  front() - consulta o primeiro valor
  pop() - remove o primeiro valor
  empty() - verifica se a fila está vazia
  size() - verifica o tamanho da fila

*/

#include <iostream>
#include <queue>


int main(){
    std::queue<int> fila;

    fila.push(1);
    fila.push(2);
    fila.push(3);
    fila.push(4);
    fila.push(5);
    fila.push(6);

    std::cout << "Primeiro da fila: " << fila.front() << '\n';

    fila.pop();
    std::cout << "Primeiro da fila após o pop: " << fila.front() << '\n';
    std::cout << "Quantidade de elementos: " << fila.size() << '\n';

    std::cout << "Repetição com fila: " << '\n';
    while (!fila.empty()){
        std::cout << "Elemento: " << fila.front() << '\n';
        fila.pop();
    }

    return 0;
}