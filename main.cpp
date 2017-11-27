#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>

using std:: cout;
using std:: cin;
using std:: vector;

void aleatorio(int &); // Função para definir os números aleatoriamente
bool trocar (int &, int &); // Função para trocar inteiros
bool trocar (double &, double &); // Função para trocar double
void bubblesort (vector <double> &);

bool teste;
int cont;
char resposta;

int main(int argc, char **argv)
{
    srand (time(NULL)); //Redefine os números aleatórios a cada execução
    
    vector <double> meuvetor (0);
    
    teste = true;
    while (teste == true)
    {
        meuvetor.push_back(rand() % 20);
        cout << "A[" << meuvetor.size() << "]: " << meuvetor.back() << "\n \n";
        
        resposta = 'a';
        while (resposta != 's' && resposta != 'n')
        {
            cout << "Deseja entrar com um novo valor? (s/n)\n";
            cin >> resposta;
            cout << "\n";
        }
        
        if (resposta == 's')
            teste = true;
            else teste = false;
    }
    
    cout << "\n";
    
    bubblesort (meuvetor);
    
    cout << "\n";
    
    int vetor_array[meuvetor.size()];
    
    for (int i = 0; i < meuvetor.size(); i++)
        {
            vetor_array[i+1] = meuvetor[meuvetor.size() - 1 - i];
            cout << "B[" << i+1 << "]: " << vetor_array[i+1] << "\n";
        }
    
    cout << "\nApagando o vector com o pop_back\n\n";
    
    while (!meuvetor.empty())
    {
        meuvetor.pop_back();
        for (int i = 0; i < meuvetor.size(); i++)
        {
            
            cout << "A[" << i+1 << "]: " << meuvetor[i] << "\n";
        }
        cout << "\n";
    }
    
    cout << "\n";
    return 0;
}

void bubblesort (vector <double> &vetor)
{
    for (int i = 0; i < vetor.size(); i++) //Loop de repetição para definir os valores das células
    {
        cout << "A[" << i+1 << "]: " << vetor[i] << "\n";
    }

    cout << "\n";

    while (teste == false) //Loop de teste para verificar se o vetor está em ordem (Só precisa executar no mínimo uma vez)
    {
        teste = true;
        for (int i = 0; i < vetor.size() - 1; i++) //Repetição para trocar os valores
        {
            if (trocar(vetor[i], vetor[i+1]))
            {
                cont++;
                teste = false;
            }
        }
    }
        
    cout << "Trocas: " << cont << "\n"; //Informa o número de trocas
    cout << "\n";
    for (int i = 0; i < vetor.size(); i++) //Escreve o vetor
    {
        cout << "A[" << i+1 << "]: " << vetor[i] << "\n";
    }
}

bool trocar (int &x, int &y)
{
    int temp;
    
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
        return true;
    }
    else return false;
}

bool trocar (double &x, double &y)
{
    int temp;
    
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
        return true;
    }
    else return false;
}