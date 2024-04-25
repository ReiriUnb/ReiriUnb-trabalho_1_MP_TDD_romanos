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
// Esta função converte uma string de caracteres romanos em um nun decimal
int romanos_para_decimal(const std::string& num_romano) {
        return algarismo_romano_unico(num_romano[0]);
}
// wesley