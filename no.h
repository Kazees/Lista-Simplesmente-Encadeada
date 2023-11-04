#ifndef NO_H
#define NO_H
#include <QString>

namespace bry
{
    class No
    {
    private:
        int dados;
        No *proximo;

    public:
        No();
        No(int dados);

        int getDados() const {return dados;}
        No *getProximo() const {return proximo;}

        void setDados(int newDados);
        void setProximo(No *newProximo);

        QString toString()const;
    };
}



#endif // NO_H
