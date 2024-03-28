#pragma once
#include <iostream>

template <class T>
class IndirectSortClass
{
public:
    static int Sort_Shell(T** A, int n);
    static int Sort_Pyramidal(T** A, int n);
    static bool Indirect_Sort_Check(T** A, int n);
private:
    static void sift(T** A, int i, int m, int& COUNT);
};

template <class T>
int IndirectSortClass<T>::Sort_Shell(T** A, int n)
{
    int i, j, h, COUNT = 0;
    for (h = 1; h <= n / 9; h = h * 3 + 1);
    while (h >= 1) {
        for (i = h; i < n; i++)
            for (j = i - h; COUNT++, j >= 0 && *A[j] > *A[j + h]; j -= h) { // Подсчет каждого сравнения
                std::swap(A[j], A[j + h]);
            }
        h = (h - 1) / 3;
    }
    return COUNT;
}

template <class T>
int IndirectSortClass<T>::Sort_Pyramidal(T** A, int n)
{
    int i, m, COUNT = 0;
    // построение пирамиды
    for (i = n / 2; i >= 0; i--)
        sift(A, i, n - 1, COUNT);
    // сортировка массива
    for (m = n - 1; m >= 1; m--)
    {
        std::swap(A[0], A[m]);
        sift(A, 0, m - 1, COUNT);
    }
    return COUNT;
}

template <class T>
void IndirectSortClass<T>::sift(T** A, int i, int m, int& COUNT)
{
    int j = i, k = i * 2 + 1;	 // k - левый сын
    while (k <= m)
    {
        COUNT += 2; // За цикл происходит 2 сравнения
        if (k < m && *A[k] < *A[k + 1]) k++; // k - больший сын
        if (*A[j] < *A[k])
        {
            std::swap(A[j], A[k]); j = k; k = k * 2 + 1;
        }
        else break;
    }
}

template <class T>
bool IndirectSortClass<T>::Indirect_Sort_Check(T** A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (*A[i] <= *A[i + 1]);
        else return false;
    }
    return true;
}
