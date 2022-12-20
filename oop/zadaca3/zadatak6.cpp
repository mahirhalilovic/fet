/* Napisati funkciju map koja uzima listu integer-a kao prvi argument te funkciju transformacije kao
drugi argument. Map treba nazad da vrati novi instancu liste integer-a koja sadrži elemente
proslijeđene liste transformirane kroz predicate funkciju. Kako treba da izgleda tip drugog argumenta
funkcije map?
Primjer:
Input list: [7, 2, -4, 5, 0, 6, 3]
Funkcija: [](int n) { return n * 2 + 1; }
Output: [15, 5, -7, 11, 1, 13, 7]

Nakon implementacije funkcije map za listu integer-a, odraditi implementaciju i za listu proizvoljnog
tipa podataka te implementaciju za proizvoljan tip kontejnera. */

#include <iostream>
#include <list>
#include <functional>

std::list<int> map(std::list<int> l, std::function<int(int)> f) {

    std::list<int> result;

    for(auto k : l)
        result.push_back(f(k));

    return result;
}

template<typename T>
std::list<T> map(std::list<T> l, std::function<T(T)> f) {

    std::list<T> result;

    for(auto k : l)
        result.push_back(f(k));

    return result;
}

template<typename T>
T map(T l, std::function<typename T::value_type(typename T::value_type)> f) {

    T result;

    for(auto k : l)
        result.push_back(f(k));

    return result;
}

int main() {

    std::list<double> input{7, 2, -4, 5, 0, 6, 3};
    std::list<double> res = map(input, [](double n) { return n * 2 + 1; });

    for(auto k : res)
        std::cout << k << std::endl;

    return 0;
}