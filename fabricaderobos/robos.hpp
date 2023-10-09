#include <iostream>

using namespace std;

class Robo{
private:
  string nome;
  string estiloDeDanca;
  string numeroDeSerie;

public:
  Robo(string name, string style, string num){
    this->nome = name;
    this->estiloDeDanca = style;
    this->numeroDeSerie = num;
  }

  Robo(){
  }

  string nome_robo(){
    return this->nome;
  }
  string estilo_robo(){
    return this->estiloDeDanca;
  }
  string serial(){
    return this->numeroDeSerie;
  }
};