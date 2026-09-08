#include <iostream>

struct DIV {
    bool operator () (int a) {
        return a % 3 == 0;
    }
};

template <class O>
struct util {
    O orden;

    void merge(int* ini, int* mid, int* fin) {
        while (ini < mid && mid < fin) {
            if(*ini > *mid) {
                int i = *mid;
                for (int* p = mid; p > ini; p--) {
                    *p = *(p - 1);
                }
                
                *ini = i;
                mid++;
            }

            ini++;
        }
    }

    void split(int* ini, int* fin) {
        int* ii = ini;

        while (ini < fin) {
            if (orden(*ini)) {
                int i = *ini;
                for (int* p = ini; p > ii; p--) {
                    *p = *(p - 1);
                }

                *ii = i;
                ii++;
            }

            ini++;
        }
    }

    void print(int* ini, int* fin) {
        while (ini < fin) {
            std::cout << *ini << " ";
            ini++;
        }

        std::cout << std::endl;
    }

};

int main()
{
    int arr[10] = { 1, 2, 5, 7, 30, 3, 5, 11, 23, 25 };
    util<DIV> cosa;

    cosa.merge(arr, arr + 5, arr + 10);
    cosa.print(arr, arr + 10);
    cosa.split(arr, arr + 10);
    cosa.print(arr, arr + 10);
}


