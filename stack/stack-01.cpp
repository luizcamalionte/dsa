#include <iostream>
// Permite lançar exceções, como std::overflow_error
#include <stdexcept>


class Pilha {
    /*
    Esta classe modela uma stack, com a seguinte interface:

        - push(valor): adicionar um elemento no topo
        - pop(): remove o elemento do topo
        - top(): consulta o elemento do topo sem removê-lo
        - is_empty(): verifica se a pilha está vazia
        - is_full(): verifica se a pilha atingiu a capacidade total
    */

    private:
        static const int capacidade = 5;
        int dados[capacidade];
        int topo = -1;
    
    public:
        // Métodos de Verificação de estado
        // O "const" depois dos "()" indica que
        // esses métodos consultam a pilha, mas
        // não alteram seu estado.
        bool is_empty() const {
            // Se topo == -1 - A pilha está vazia
            return topo == -1;
        }

        bool is_full() const {
            return topo == capacidade - 1;
        }
        
        void push(int valor) {
            if (is_full()){
                // Informa que não cabe mais elementos na pilha
                throw std::overflow_error("Pilha cheia");
            }

            topo++;
            dados[topo] = valor;
        }

        int top() const{
            if (is_empty()){
                throw std::underflow_error("Pilha vazia");
            }

            return dados[topo];
        }

        void pop(){
            if (is_empty()){
               throw std::underflow_error("Pilha vazia"); 
            }

            // A pilha passa a considerar o elemento anterior como topo
            topo--;
        }
    };


int main(){
    Pilha pilha;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);
    pilha.push(40);
    std::cout << "Topo: " << pilha.top() << '\n';

    pilha.pop();
    std::cout << "Topo: " << pilha.top() << '\n';

    while (!pilha.is_empty()){
        std::cout << "Topo: " << pilha.top() << " | ";
        pilha.pop();
    }

    return 0;
}