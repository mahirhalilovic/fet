/* Napisati funkciju find_if() koja prima dva iteratora begin i end i predicate funkciju koja definira uslov pod kojim pretrazujemo elemente u kontejneru.
Funkcija vraca end iterator ukoliko element nije pronađen, u suprotnom vraca iterator na element koji je pronađen.
Funkcija treba imati mogucnost da radi sa sto vecim brojem različitih tipova. Tipovi koji moraju biti podržani su: int, float, double i std::string.
Elemente vektora kao i vrijednost koju pretražujemo unosimo sa ulaza.
Napisati program koji testira ovu funkciju. Napisati sto veci broj funkcija (Poželjno deklaracije i definicije funkcija razdvojiti u odvojene hpp i cpp fajlove).
Obratiti paznju na nacin proslijedjivanja argumenata u funkcije. */

#include <iostream>
#include <vector>
#include <list>
#include <functional>

template <typename T>
T find_if(T begin, T end, std::function<bool(typename T::value_type)> f) {

    while(begin != end) {

        if(f(*begin))
            return begin;

        begin++;
    }

    return end;
}

int main() {

    std::vector<int> l{};
    int k;

    //std::cout << "Unesite elemente vektora:" << std::endl;

   /* do{

        std::cin >> k;
        l.push_back(k);
    }while(k != 0);*/

    while(std::cin >> k) {
        l.push_back(k);
    }

    std::cout << "Trazena vrijednost: ";
    std::cin >> k;

    auto lambda = [k] (int a) {return a == k;};
    auto it = find_if(l.begin(), l.end(), lambda);

    std::cout << *it;

    return 0;
}