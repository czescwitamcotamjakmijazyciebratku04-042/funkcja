#ifndef KOD_HPP
#define KOD_HPP

void srtbabelkowe(int arr[], int size);
void srtprzezscalanie(int arr[], int left, int right);
void srtszybkie(int arr[], int left, int right);
void srtprzezwstawianie(int arr[], int size);
void srtkoktajlowe(int arr[], int size);

int wyszukajliniowe(int arr[], int size, int klucz);
int wyszukajliniowewartownik(int arr[], int size, int klucz);
int wyszukajskokowe(int arr[], int size, int klucz);
int wyszukajbinarne(int arr[], int left, int right, int klucz);
int wyszukajinterpolacyjne(int arr[], int size, int klucz);

#endif