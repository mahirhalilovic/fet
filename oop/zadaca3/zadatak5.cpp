/* Napisati funkciju filter koja uzima listu integer-a kao prvi argument i predicate funkciju kao drugi
argument. Filter treba nazad da vrati novu instancu liste integer-a koja sadrži sve elemente
proslijeđene liste (prvi argument) koji zadovoljavaju datu predicate funkciju. Kako treba da izgleda tip
drugog argumenta funkcije filter?
Primjer:

Input list: [1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10];
Predicate: [](int n) { return n % 2 == 0; }
Output: [8, 4, 0, 2, 6, 10]
Nakon implementacije funkcije filter za listu integer-a, odraditi implementaciju i za listu
proizvoljnog tipa podataka te implementaciju za proizvoljan tip kontejnera. */

#include <iostream>
#include <list>
#include <functional>

std::list<int> filter(std::list<int> l, std::function<bool(int)> f) {

    std::list<int> result;

    for(auto k : l)
        if(f(k))
            result.push_back(k);

    return result;
}

template<typename T>
std::list<T> filter(std::list<T> l, std::function<bool(T)> f) {

    std::list<T> result;

    for(auto k : l)
        if(f(k))
            result.push_back(k);

    return result;
}

template<typename T>
T filter(T l, std::function<bool(typename T::value_type)> f) {

    T result;

    for(auto k : l)
        if(f(k))
            result.push_back(k);

    return result;
}

int main() {

    std::list<double> input{1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10};
    std::list<double> res = filter(input, [](double n) { return n < 5; });

    for(auto k : res)
        std::cout << k << std::endl;

    return 0;
}