#include <iostream>
#include <stack>


int main(){
    std::stack<int> pilha;

    pilha.push(10);
    pilha.push(20);
    
    std::cout << "Topo: " << pilha.top();

    while (!pilha.empty())
    {
        std::cout << "Topo: " << pilha.top() << '\n';
        pilha.pop();
    }
    
    //TODO: Verificar o tamanho real da stack na memória
    return 0;
}