#include "no.h"

namespace bry
{

    No::No():dados(0),proximo(0)
    {
    }

    No::No(int dados):dados(dados),proximo(0)
    {
    }

    void No::setDados(int newDados)
    {
        dados = newDados;
    }

    void No::setProximo(No *newProximo)
    {
        proximo = newProximo;
    }

    QString No::toString()const
    {
        return "|"+QString::number(dados)+"|->";
    }
}

