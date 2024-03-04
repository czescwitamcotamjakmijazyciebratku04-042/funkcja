#include <iostream>
#include "wyszukaj.hpp"

using namespace std;

const int SIZE = 10;

int main() {
    int t[SIZE];
    srand(time(0)); 

    for (int i = 0; i < SIZE; ++i) {
        t[i] = rand() % 100 + 1; 
    }

    srtbabelkowe(t, SIZE);

    int t2[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        t2[i] = rand() % 100 + 1;
    }
    srtprzezscalanie(t2, 0, SIZE - 1);
    cout << "Sortowanie przez scalanie: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << t2[i] << " ";
    }
    cout << endl;

    int t3[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        t3[i] = rand() % 100 + 1;
    }
    srtszybkie(t3, 0, SIZE - 1);
    cout << "Sortowanie szybkie: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << t3[i] << " ";
    }
    cout << endl;

    int t4[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        t4[i] = rand() % 100 + 1;
    }
    srtprzezwstawianie(t4, SIZE);

    int t5[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        t5[i] = rand() % 100 + 1;
    }
    srtkoktajlowe(t5, SIZE);
    
    int klucz = 42; 

    cout << "Wyszukiwanie Liniowe: " << wyszukajliniowe(t, SIZE, klucz) << endl;
    cout << "Wyszukiwanie Liniowe z Wartownikiem: " << wyszukajliniowewartownik(t, SIZE, klucz) << endl;
    cout << "Wyszukiwanie Skokowe: " << wyszukajskokowe(t3, SIZE, klucz) << endl;
    cout << "Wyszukiwanie Binarne: " << wyszukajbinarne(t3, 0, SIZE - 1, klucz) << endl;
    cout << "Wyszukiwanie Interpolacyjne: " << wyszukajinterpolacyjne(t3, SIZE, klucz) << endl;
    
    return 0;
}