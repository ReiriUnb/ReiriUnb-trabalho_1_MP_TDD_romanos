#include "romanos.hpp"
#include <string>

// Esta função para converte caractere romano em um nun decimal
int algarismo_romano_unico(char algarismo) 
{
  // Os  if para verificar qual é o caractere e retornamos o valor certo
  if (algarismo == 'I')
    return 1;
  if (algarismo == 'V')
    return 5;
  if (algarismo == 'X')
    return 10;
  if (algarismo == 'L')
    return 50;
  if (algarismo == 'C')
    return 100;
  if (algarismo == 'D')
    return 500;
  if (algarismo == 'M')
    return 1000;
  // Se o caractere não for um algarismo romano valido, retornamos -1
  return -1;
}

// Esta função verifica se um algarismo romano menor está aparecendo corretamente antes de um algarismo maior
bool eh_subtracao_valida(char menor, char maior) {
    if (menor == 'I') {
        return maior == 'V' || maior == 'X';
    } else if (menor == 'X') {
        return maior == 'L' || maior == 'C';
    } else if (menor == 'C') {
        return maior == 'D' || maior == 'M';
    }
    return false;
}

// Esta função converte uma string de caracteres romanos em um nun decimal
int romanos_para_decimal(const std::string& num_romano) {
    int total = 0;
    int valor_atual = 0;
    int valor_anterior = 0;

    for (int i = num_romano.length() - 1; i >= 0; --i) {
        valor_atual = algarismo_romano_unico(num_romano[i]);

        // Se algarismo_romano_unico retornar -1, retornamos -1
        if (valor_atual == -1) {
            return -1;
        }

        // Se o valor atual for maior ou igual ao valor anterior, nos o add ao total
        if (valor_atual >= valor_anterior) {
            total += valor_atual;
        } else {
            // Se não for uma subtração valida, retornamos -1
            if (!eh_subtracao_valida(num_romano[i], num_romano[i+1])) {
                return -1;
            }
            // Se o valor atual for menor que o valor anterior, nós o subtraimos do total
            total -= valor_atual;
        }

        // Atualizamos o valor anterior para a proxima iteração
        valor_anterior = valor_atual;
    }

    // Retornamos a soma total
    return total;
}
// wesley