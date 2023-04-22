#ifndef MAT_HPP
#define MAT_HPP
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <cstdio>
using namespace std;

class Matriz
{
  private:
    int nummat;
    int tammat;
    static int casas;
    static int vida;
    static int vida2;
    static int itens2;
    static int itens;
    static int perigo;
    static int ntimes;
    static int abc;
    
  public:
    Matriz();

    int seecasas();
    int seeperigo();
    int seeitens();
    int seevida();
    int sabc();
    void Readfile();
    int Tam();
    int Quant();
    void OpenMatrix();
    int WalkMatrix(int **mtrx, int im, int jm, int rsize, int n);
    int NotVisited();
    void Output();
    void remove();
};
#endif