#include <cstring>
namespace funcoes
{

    template <class T>
    void trocar(T &a, T &b)
    { /* troca valores de a e b entre si */
        T clone;
        clone = a;
        a = b;
        b = clone;
    }

    template <class T>
    T maximo(const T a, const T b)
    {/* retorna maior entre a e b */
        int maior = (b > a) ? b : a;
        return maior;
    }

    template <class T>
    T minimo(const T a, const T b)
    { /* retorna menor entre a e b */
        int min = (b < a) ? b : a;
        return min;
    }

    template <>
    const char *maximo(const char *a, const char *b)
    { /* retorna maior entre a e b */
        const char *maximo = (strcmp(a, b) < 0) ? a : b;
        return maximo;
    }

    template <>
    const char *minimo(const char *a, const char *b)
    { /* retorna menor entre a e b */
        const char *min = (strcmp(a, b) > 0) ? a : b;
        return min;
    }

}