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

    void produzirRobo()
    {
        string n, est, s;
        int choice;
        string ano = "2023";
        string tipo;

        if (quantidadeatual <= capacidade)
        {
            cout << "Qual nome deseja dar para seu robo?" << endl;
            cin >> n;
            cout << "Escolha o tipo de dança:\n1. Rockeiro Maluko\n2. Romantiko\n3. Funkeiro\n";
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
                est = "Funkeiro";
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
        Robo desativado("Desativado", "Desativado", to_string(0000));
        int serial;
        int opt;
        cout << "Qual robo deseja desativar?" << endl;
        if (quantidadeatual > 0)
        {
            for (int i = 0; i < quantidadeatual; i++)
            {
                cout << i + 1 << " - " << linhadeproducao[i].nome_robo() << endl;
            }
        }
        else
        {
            cout << "Voce ainda não tem nenhum robo!" << endl;
        }

        cout << "Digite o serial do Robo: ";
        cin >> serial;
        for (int j = 0; j < quantidadeatual; j++)
        {
            if (linhadeproducao[j].serial() == to_string(serial))
            {
                cout << "Deseja realmente desativar o Robo?" << endl;
                cout << "1. Sim" << endl;
                cout << "2. Não" << endl;
                cin >> opt;
                switch (opt)
                {
                case 1:
                    linhadeproducao[j] = desativado;
                    cout << "Robo desativado com sucesso!" << endl;
                    break;
                case 2:
                    cout << "Boa escolha!" << endl;
                    break;
                }
            }
        }
    }

    void buscarRobo()
    {
        int serial;
        cout << "Insira o numero serial do robo para busca-lo: ";
        cin >> serial;
        if (quantidadeatual > 0)
        {
            for (int i = 0; i < quantidadeatual; i++)
            {
                if (linhadeproducao[i].serial() == to_string(serial))
                {
                    cout << "Robo encontrado!" << endl;
                    cout << "Nome: " << linhadeproducao[i].nome_robo() << endl;
                    cout << "Estilo: " << linhadeproducao[i].estilo_robo() << endl;
                    cout << "Numero de serie: " << linhadeproducao[i].serial() << endl;
                }
            }
        }
        else
        {
            cout << "Como eu vou consultar robos se voce não criou nenhum? Crie seu robo e tente novamente." << endl;
        }
    }

    void fazerRoboDancar()
    {
        int serial;
        cout << "Qual robo deseja fazer dançar?" << endl;
        if (quantidadeatual > 0)
        {
            for (int i = 0; i < quantidadeatual; i++)
            {
                if (linhadeproducao[i].nome_robo() != "Desativado")
                {
                    cout << i + 1 << " - " << linhadeproducao[i].nome_robo() << endl;
                }
            }
        }
        else
        {
            cout << "Voce ainda não tem nenhum robo!" << endl;
        }

        cout << "Digite o numero serial do robo: ";
        cin >> serial;

        for (int j = 0; j < quantidadeatual; j++)
        {
            if (linhadeproducao[j].serial() == to_string(serial))
            {
                if (linhadeproducao[j].estilo_robo() == "Funkeiro")
                {
                    cout << "TU TA TA TU TU TA" << endl;
                }
                else if (linhadeproducao[j].estilo_robo() == "Rockeiro Maluko")
                {
                    cout << "IAAAAAAA" << endl;
                }
                else if (linhadeproducao[j].estilo_robo() == "Romantiko")
                {
                    cout << "oh babyyyyy" << endl;
                }
            }
        }
    }
};
