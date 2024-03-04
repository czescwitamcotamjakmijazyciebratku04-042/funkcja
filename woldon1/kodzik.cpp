#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include "wyszukaj.hpp"

using namespace std;

void srtbabelkowe(int arr[], int size) {
    cout << "Sortowanie bąbelkowe: ";
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void srtprzezscalanie(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        srtprzezscalanie(arr, left, middle);
        srtprzezscalanie(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void srtszybkie(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[left];
        int i = left, j = right;

        while (i <= j) {
            while (arr[i] < pivot) ++i;
            while (arr[j] > pivot) --j;
            if (i <= j) {
                swap(arr[i], arr[j]);
                ++i;
                --j;
            }
        }

        if (left < j) srtszybkie(arr, left, j);
        if (i < right) srtszybkie(arr, i, right);
    }
}

void srtprzezwstawianie(int arr[], int size) {
    cout << "Sortowanie przez wstawianie: ";
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void srtkoktajlowe(int arr[], int size) {
    cout << "Sortowanie koktajlowe: ";
    bool swapped = true;
    int start = 0;
    int end = size - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int wyszukajliniowe(int arr[], int size, int klucz) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == klucz) return i;
    }
    return -1;
}

int wyszukajliniowewartownik(int arr[], int size, int klucz) {
    arr[size] = klucz;
    int i = 0;
    while (arr[i] != klucz) {
        ++i;
    }
    if (i < size) {
        return i;
    }
    return -1;
}

int wyszukajskokowe(int arr[], int size, int klucz) {
    int krok = sqrt(size);
    int poprzedni = 0;
    while (arr[min(krok, size) - 1] < klucz) {
        poprzedni = krok;
        krok += sqrt(size);
        if (poprzedni >= size) return -1;
    }
    while (arr[poprzedni] < klucz) {
        ++poprzedni;
        if (poprzedni == min(krok, size)) return -1;
    }
    if (arr[poprzedni] == klucz) return poprzedni;
    return -1;
}

int wyszukajbinarne(int arr[], int left, int right, int klucz) {
    if (right >= left) {
        int srodek = left + (right - left) / 2;
        if (arr[srodek] == klucz) return srodek;
        if (arr[srodek] > klucz) return wyszukajbinarne(arr, left, srodek - 1, klucz);
        return wyszukajbinarne(arr, srodek + 1, right, klucz);
    }
    return -1;
}

int wyszukajinterpolacyjne(int arr[], int size, int klucz) {
    int niski = 0, wysoki = size - 1;
    while (niski <= wysoki && klucz >= arr[niski] && klucz <= arr[wysoki]) {
        if (niski == wysoki) {
            if (arr[niski] == klucz) return niski;
            return -1;
        }
        int pozycja = niski + ((double)(wysoki - niski) / (arr[wysoki] - arr[niski])) * (klucz - arr[niski]) / (double)(wysoki - niski);
        if (arr[pozycja] == klucz) return pozycja;
        if (arr[pozycja] < klucz) niski = pozycja + 1;
        else wysoki = pozycja - 1;
    }
    return -1;
}