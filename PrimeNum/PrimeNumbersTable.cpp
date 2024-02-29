//
//  PrimeNumbersTable.cpp
//
//
//  Created by Mick Maciel on 27/02/2024.
//

#include "PrimeNumbersTable.hpp"

#ifndef PrimeNumbersTable_hpp

class PrimeNumbersTable {

public:
  PrimeNumbersTable(unsigned long sizeTable);
  ~PrimeNumbersTable();
  
  void init(); // Deve ser executado no inicio de main()!
  unsigned long readTable();
  unsigned long readTable(unsigned long index); // sobrecarga para admitir
                                                // escolha aleatória do índice
  void writeTable(
      unsigned long primeNumber);
  bool isItFull();

private:
  void clearTable();
  void indexTableInit();
  unsigned long sizeTable;
  unsigned long *table; // tamanho do array será determinado na instaciacao
  unsigned long indexReadTable; // R: por via de dúvidas, usemos tabelas grandes
  unsigned long indexWriteTable;

}; // end class PrimeNumberTable

#endif

//--------------------------------------------------------------------------

PrimeNumbersTable::PrimeNumbersTable (unsigned long sizeTable) //Construtor
  : sizeTable(sizeTable)
{
  table = new unsigned long[sizeTable]; //aloca memoria para a tabela
}


PrimeNumbersTable::~PrimeNumbersTable() {   //Destrutor
  delete[] table; // desaloca memoria
}

//--------------------------------------------------------------------------
// Prepara a tabela para o armazenamento dos numeros primos informados
void PrimeNumbersTable::init() {

  clearTable();
  indexTableInit(); // Volta a posicao inicial da tabela
}

//--------------------------------------------------------------------------
// Retorna o valor da tabela na posicao indexReadTable
// Incremeta o indexReadTable para proxima posicao
unsigned long PrimeNumbersTable::readTable() {

  if (indexReadTable >= sizeTable)
    return 0;
  return table[indexReadTable++]; // R: usa indexReadTable, depois incrementa
}

//--------------------------------------------------------------------------
// Retorna o valor da tabela na posicao passada por index
// Atribui index a indexReadTable
unsigned long PrimeNumbersTable::readTable(unsigned long index) {

  indexReadTable = index;
  readTable();
}

//--------------------------------------------------------------------------
// Armazena um valor na tabela na posicao indexWriteTable
void PrimeNumbersTable::writeTable(unsigned long primeNumber) {

  if (indexWriteTable >= sizeTable)
    return;
  table[indexWriteTable] = primeNumber;
  indexWriteTable++;
}

//--------------------------------------------------------------------------
bool PrimeNumbersTable::isItFull() {

  return (indexWriteTable >= sizeTable);
}

//--------------------------------------------------------------------------
void PrimeNumbersTable::clearTable() {

  unsigned long index;
  for (index = 0; index < sizeTable; index++)
    table[index] = 0; // Limpa dado na posição atual da tabela
}

//--------------------------------------------------------------------------
void PrimeNumbersTable::indexTableInit() {

  indexReadTable = indexWriteTable = 0;
}
