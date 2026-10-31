/*
Exercício:

Usando stack, crie um algoritmo que verifique
se uma expressão é ou não balanceada.

Exemplo:
 (a + b)  -> balanceada
 (a + B)) -> não balanceada
 ((a + b * c) -> não balanceada
*/

#include <iostream>
#include <stack>
#include <string>


bool parenteses_balanceados(const std::string &expreassao){
    //Recebe uma expressão e retorna true se os parenteses estiverem balanceados.

    std::stack<char> pilha;
    
    //Percorrer cada caractere
    for (char c : expreassao){
        if (c == '('){
            pilha.push(c);
        }
        else if (c == ')'){
            if (pilha.empty()){
                return false;
            }

            pilha.pop();
        }
    }

    return pilha.empty();
}


int main(){
    std::string expressao = "((a + b)) * c";

    if (parenteses_balanceados(expressao)){
        std::cout << "Expressão Balanceada";
    }
    else{
        std::cout << "Expressão Não Balanceada";
    }

    return 0;
}