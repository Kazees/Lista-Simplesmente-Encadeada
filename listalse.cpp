#include "listalse.h"

namespace bry
{
    ListaLSE::ListaLSE():inicio(0),quantidadeElementos(0)
    {
    }

    void ListaLSE::inserirInicio(int dados)
    {
        try
        {
            No *novoNo=new No(dados);

            novoNo->setProximo(inicio);
            inicio=novoNo;
            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    void ListaLSE::inserirFinal(int dados)
    {
        try
        {
            if(estaVazia())
            {
                inserirInicio(dados);
                return;
            }

            No *novoNo=new No(dados);

            /*if(estaVazia())
            {
                inicio=novoNo;
                quantidadeElementos++;
                return;
            }*/

            No *atual=inicio;

            while(atual->getProximo()!=0)
            {
                atual=atual->getProximo();
            }

            atual->setProximo(novoNo);
            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    void ListaLSE::inserirPosicao(int dados,int posicao)
    {
        try
        {
            if(posicao<0||posicao>quantidadeElementos)
            {
                throw QString("Posição inválida.");
            }

            if(posicao==0)
            {
                inserirInicio(dados);
                return;
            }

            if(posicao==quantidadeElementos-1)
            {
                inserirFinal(dados);
                return;
            }

            No *novoNo=new No(dados);
            No *atual=inicio;

            for(int i=0;i<posicao-1;i++)
            {
                atual=atual->getProximo();
            }

            novoNo->setProximo(atual->getProximo());
            atual->setProximo(novoNo);
            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    int ListaLSE::acessarInicio()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        return inicio->getDados();
    }

    int ListaLSE::acessarFinal()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        No *atual=inicio;

        while(atual->getProximo()!=0)
        {
            atual=atual->getProximo();
        }

        return atual->getDados();
    }

    int ListaLSE::acessarPosicao(int posicao)const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(posicao<0||posicao>=quantidadeElementos)
        {
            throw QString("Posição inválida.");
        }

        No *atual=inicio;

        for(int i=0;i<posicao;i++)
        {
            atual=atual->getProximo();
        }

        return atual->getDados();
    }

    void ListaLSE::retirarInicio()
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        No *pAux=inicio;

        inicio=inicio->getProximo(); //ou inicio->setProximo(pAux->getProximo());
        quantidadeElementos--;

        delete pAux;
    }

    void ListaLSE::retirarFinal()
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(quantidadeElementos==1)
        {
            delete inicio;
            inicio=0;
            quantidadeElementos=0;
            return;
        }

        No *final=inicio;
        No *penultimo=0;

        while(final->getProximo()!=0)
        {
            penultimo=final;
            final=final->getProximo();
        }

        penultimo->setProximo(0);
        quantidadeElementos--;

        delete final;
    }

    void ListaLSE::retirarPosicao(int posicao)
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(posicao<0||posicao>=quantidadeElementos)
        {
            throw QString("Posição inválida.");
        }

        if(posicao==0)
        {
            retirarInicio();
            return;
        }

        if(posicao==quantidadeElementos-1)
        {
            retirarFinal();
            return;
        }

        No *final=inicio;
        No *penultimo=0;
        int cont=0;

        while(cont<posicao)
        {
            penultimo=final;
            final=final->getProximo();
            cont++;
        }

        penultimo->setProximo(final->getProximo());
        quantidadeElementos--;

        delete final;
    }

    void ListaLSE::inserirOrdenadoCrescente(int dados)
    {
        try
        {
            if(estaVazia())
            {
                inserirInicio(dados);
                return;
            }

            No *atual=inicio;
            No *novoNo=new No(dados);

            if(novoNo->getDados()<=atual->getDados())
            {
                novoNo->setProximo(inicio);
                inicio=novoNo;
            }

            else
            {
                atual=inicio;

                while(atual->getProximo() && novoNo->getDados()>atual->getProximo()->getDados())
                {
                    atual=atual->getProximo();
                }

                novoNo->setProximo(atual->getProximo());
                atual->setProximo(novoNo);
            }

            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    void ListaLSE::inserirOrdenadoDescrescente(int dados)
    {
        try
        {
            if(estaVazia())
            {
                inserirInicio(dados);
                return;
            }

            No *atual=inicio;
            No *novoNo=new No(dados);

            if(novoNo->getDados()>atual->getDados())
            {
                novoNo->setProximo(inicio);
                inicio=novoNo;
            }

            else
            {
                atual=inicio;

                while(atual->getProximo() && novoNo->getDados()<atual->getProximo()->getDados())
                {
                    atual=atual->getProximo();
                }

                novoNo->setProximo(atual->getProximo());
                atual->setProximo(novoNo);
            }

            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    QString ListaLSE::toString()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        bry::No *pAux=inicio;
        QString saida="Dados da lista: ";

        for(int i=0;i<quantidadeElementos;i++)
        {
            saida+=pAux->toString();
            pAux=pAux->getProximo();
        }

        return saida;
    }
}
