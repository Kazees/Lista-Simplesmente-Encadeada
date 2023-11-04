#ifndef LISTALLSE_H
#define LISTALLSE_H
#include <QString>
#include <no.h>

namespace bry
{
    class ListaLSE
    {
    private:
        No *inicio;
        int quantidadeElementos;

    public:
        ListaLSE();
        ~ListaLSE();

        int getQuantidadeElementos()const {return quantidadeElementos;}

        bool estaVazia()const {return quantidadeElementos==0;} //ou inicio==0
        void inserirInicio(int dados);
        void inserirFinal(int dados);
        void inserirPosicao(int dados,int posicao);

        int acessarInicio()const;
        int acessarFinal()const;
        int acessarPosicao(int posicao)const;

        void retirarInicio();
        void retirarFinal();
        void retirarPosicao(int posicao);

        void inserirOrdenadoCrescente(int dados);
        void inserirOrdenadoDescrescente(int dados);

        QString toString()const;
    };
}

#endif // LISTALLSE_H
