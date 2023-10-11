#include <iostream>
#include "robos.hpp"
#include "randnumber.hpp"
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

const int TAM = 10;

ofstream arquivo;

class FabricaDeRobos
{
private:
    Robo linhadeproducao[TAM];
    int capacidade = TAM;
    int quantidadeatual = 0;

public:
    FabricaDeRobos() {}

    ~FabricaDeRobos(){
        cout << "Até mais! Volte sempre" << endl;
    }

    void produzirRobo()
    {
        string n, est, s;
        int choice;
        string ano = "2023";
        string tipo;

        if (quantidadeatual < capacidade)
        {
            cout << "Qual nome deseja dar para seu robo?" << endl;
            cin >> n;
            cout << "Escolha o tipo de dança:\n1. Rockeiro Maluko\n2. Romantiko\n3. Balada\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                est = "Rockeiro Maluko";
                tipo = "01";
                break;
            case 2:
                est = "Romantiko";
                tipo = "02";
                break;
            case 3:
                est = "Balada";
                tipo = "03";
                break;
            default:
                cout << "Estilo nao reconhecido" << endl;
                break;
            }

            cout << "\nRobo sendo produzido...\n";

            string rand_num = to_string(convertToASCII(n));
            // a função convertToASCII soma os valores ascii dos dois primeiros caracteres de cada robo, para que a geração de numeros seriais seja mais "aleatorio"

            s = ano + tipo + rand_num;
            // o numero serial é composto pelo ano de produção + o tipo de dança (01, 02, ou 03) + um numero aleatorio formado a partir dos dois primeiros caracteres do nome do robo

            Robo meu_robo(n, est, s);

            linhadeproducao[quantidadeatual] = meu_robo;

            quantidadeatual++;

            arquivo.open("Robos.csv", ios::app);

            if (arquivo.is_open())
            {
                arquivo << linhadeproducao[quantidadeatual - 1].nome_robo() << "," << linhadeproducao[quantidadeatual - 1].estilo_robo() << "," << linhadeproducao[quantidadeatual - 1].serial() << endl;
            }

            arquivo.close();

            cout << "\nRobo produzido com sucesso!\n";
            cout << "Nome: " << linhadeproducao[quantidadeatual - 1].nome_robo() << endl;
            cout << "Estilo: " << linhadeproducao[quantidadeatual - 1].estilo_robo() << endl;
            cout << "Numero de serie: " << linhadeproducao[quantidadeatual - 1].serial() << " (lembre-se desse numero!)" << endl;
        }
        else
        {
            cout << "A linha de produção esgotou!" << endl;
        }
    }

    void desativarRobo()
    {
        int serial;
        int contador = 0;

        Robo desativado;
        if (quantidadeatual > 0)
        {
            cout << "Qual robo deseja desativar?" << endl;
            cout << "Insira o código serial do robo: ";
            cin >> serial;
            for (int i = 0; i < quantidadeatual; i++)
            {
                if (linhadeproducao[i].serial() == to_string(serial))
                {
                    linhadeproducao[i] = linhadeproducao[i + 1];
                    linhadeproducao[i + 1] = desativado;
                }
                if (linhadeproducao[i].nome_robo() == desativado.nome_robo() and linhadeproducao[i].serial() == desativado.serial())
                {
                    linhadeproducao[i] = linhadeproducao[i + 1];
                    linhadeproducao[i + 1] = desativado;
                }
            }
            for (int j = 0; j < quantidadeatual; j++)
            {
                if (linhadeproducao[j].nome_robo() != desativado.nome_robo() and linhadeproducao[j].serial() != desativado.serial())
                {
                    contador++;
                }
            }
            quantidadeatual = contador;
            cout << "Robo desativado com sucesso!" << endl;
        }
        else
        {
            cout << "Voce ainda nao tem nenhum robo para desativar!" << endl;
        }
    }

    void buscarRobo()
    {
        cout << "Lista atual de robos: " << endl;
        for (int i = 0; i < quantidadeatual; i++)
        {
            cout << "[" << i + 1 << "]: " << linhadeproducao[i].nome_robo() << ", " << linhadeproducao[i].estilo_robo() << ", " << linhadeproducao[i].serial() << endl;
        }
    }

    void fazerRoboDancar()
    {
        string nome;
        if (quantidadeatual > 0)
        {
            cout << "Qual robo deseja fazer dançar?" << endl;

            for (int i = 0; i < quantidadeatual; i++)
            {
                if (linhadeproducao[i].nome_robo() != "Desativado")
                {
                    cout << i + 1 << " - " << linhadeproducao[i].nome_robo() << endl;
                }
            }

            cout << "Digite o nome do robo: ";
            cin >> nome;

            for (int j = 0; j < quantidadeatual; j++)
            {
                if (linhadeproducao[j].nome_robo() == nome)
                {
                    if (linhadeproducao[j].estilo_robo() == "Balada")
                    {
                        cout << "!!!! Tuts tuts tuts tuts !!!!!" << endl;
                    }
                    else if (linhadeproducao[j].estilo_robo() == "Rockeiro Maluko")
                    {
                        cout << "ROCK N ROLL!!! *solo de guitarra super interessante*" << endl;
                    }
                    else if (linhadeproducao[j].estilo_robo() == "Romantiko")
                    {
                        cout << "<3 Never gonna give you up" << endl;
                        cout << "Never gonna let you down" << endl;
                        cout << "Never gonna run around and desert you" << endl;
                        cout << "Never gonna make you cry" << endl;
                        cout << "Never gonna say goodbye" << endl;
                        cout << "Never gonna tell a lie and hurt you <3" << endl;
                    }
                }
            }
        }
        else
        {
            cout << "Como eu vou consultar robos se voce não criou nenhum? Crie seu robo e tente novamente." << endl;
        }
    }
};