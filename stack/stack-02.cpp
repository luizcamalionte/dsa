#include <iostream>
#include <stack>


int main(){
    std::stack<int> pilha;

    pilha.push(10);
    pilha.push(20);

    //Verificar o tamanho stack na memória, com 2 elementos
    std::cout << sizeof(pilha) << " bytes\n";
    
    std::cout << "Topo: " << pilha.top();

    while (!pilha.empty())
    {
        std::cout << "Topo: " << pilha.top() << '\n';
        pilha.pop();
    }
    
    //Verificar o tamanho stack vazia na memória
    std::cout << sizeof(pilha) << " bytes\n";

    return 0;
}