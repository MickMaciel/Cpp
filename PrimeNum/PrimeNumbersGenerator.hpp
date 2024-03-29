//
//  PrimeNumbersGenerator.hpp
//
//
//  Created by Mick Maciel on 27/02/2024.
//

#include "main.hpp"
#include "PrimeNumbersTable.hpp"

#ifndef PrimeNumbersGenerator_hpp
#define PrimeNumbersGenerator_hpp

/*
===========================================================================
gera numeros primos usando forca bruta
tem como parametro inputLimit
R
*/
class PrimeNumbersGenerator {
public:
  bool isPrime(int number) const;
  void generate(PrimeNumbersTable *primeTable, unsigned int inputLimit);
};

#endif /* PrimeNumbersGenerator_hpp */
