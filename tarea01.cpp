#include <iostream>

template <class T>
struct ASC {
    bool operator ()(T a, T b) {
        return a > b;
    }
};

template <class T>
struct DES {
    bool operator ()(T a, T b) {
        return a < b;
    }
};

template <class T, class O, int N = 10>
class ListaOrd {
    int tam;
    int elem;
    O opera;
    T arr[N];

public:

    ListaOrd() {
        tam = N;
        elem = 0;
    }

    bool add(T x) {
        if (elem > N) { return 0; }

        T* p = arr;
        T* q = arr + elem;
        for (; (p < q) &&  (opera(x, *p)); p++) {}
        if (x == *p) { return 0; }

        while (p < q) {
            *q = *(q - 1);
            q--;
        }

        *p = x;
        elem++;

        return 1;
    }

    bool del(T x) {
        T* p = arr;
        T* q = arr + elem;
        for (; (p < q) && (opera(x, *p)); p++) {}
        if (x == *p) { 
            while (p < q) {
                *p = *(p + 1);
                p++;
            }

            elem--;
            return 1;
        }
        else { return 0; }
        
    }

    void print() {
        T* q = arr + elem;
        for (T* p = arr; p < q; p++) {
            std::cout << *p << " -> ";
        }

        std::cout << " " << std::endl;
    }


};

int main()
{
    ListaOrd<int, DES<int>> milista;

    milista.add(2);
    milista.print();
    milista.add(9);
    milista.print();
    milista.add(1);
    milista.print();
    milista.add(3);
    milista.print();
    milista.add(4);
    milista.print();
    milista.add(0);
    milista.print();
    milista.add(6);
    milista.print();
    milista.del(0);
    milista.print();


    return 0;
}
