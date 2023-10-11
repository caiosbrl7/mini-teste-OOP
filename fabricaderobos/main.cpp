#include "fabricaderobos.hpp"
#include <iostream>
#include <fstream>

int main()
{
    int opcao;

    FabricaDeRobos fabrica;

    while (true)
    {
        system("cls");
        cout << "Bem-vindo a fábrica de robôs!" << endl;
        cout << "O que deseja fazer?" << endl;
        cout << "1. Produzir Robô." << endl;
        cout << "2. Desativar Robô." << endl;
        cout << "3. Buscar Robô." << endl;
        cout << "4. Fazer Robô dançar" << endl;
        cout << "0. Ir embora." << endl
             << endl;
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            fabrica.produzirRobo();
            cin.get();
            break;
        case 2:
            fabrica.desativarRobo();
            cin.get();
            break;
        case 3:
            fabrica.buscarRobo();
            cin.get();
            break;
        case 4:
            fabrica.fazerRoboDancar();
            cin.get();
            break;
        case 0:
            return 0;
        }
        cout << "\n\nAperte ENTER para continuar..." << endl;
        cin.get();
    }
}