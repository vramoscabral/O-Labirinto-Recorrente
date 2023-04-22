#include <iostream>
#include "mat.hpp"
using namespace std;

int main() {
  Matriz m;

  m.Readfile();
  m.OpenMatrix();
  m.Output();
  m.remove();
  
  cout << "\n---- RESULTADO FINAL DO JOGO----" << endl;
  if (m.sabc()==1)
    cout << "Encerrado pois o total de vidas chegou a 0\n" << endl;
  else if (m.sabc()==2)
  {
    cout << "Encerrado pois nao tinha mais possibilidade de pegar itens" << endl;
    cout << "Restavam " << m.seevida() << " vida(s)\n" << endl;
  }
  else
  {
    cout << "Encerrado pois o personagem ficou cercado por paredes" << endl;
    cout << "Restavam " << m.seevida() << " vida(s)\n" << endl;
  }
  cout << "Total de casas percorridas: " << m.seecasas() << endl;
  cout << "Total de itens consumidos: " << m.seeitens() << endl;
  cout << "Casas que não foram exploradas: " << m.NotVisited() << endl;
  cout << "Total de perigos enfrentados: " << m.seeperigo() << endl;
  
  return 0;
}