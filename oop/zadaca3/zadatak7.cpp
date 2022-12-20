/* Napisati funkciju reduce koja uzima listu integer-a kao prvi argument, funkciju koju će koristiti da
elemente kontejnera svede na jedan element te početnu vrijednost date akumulacije. Reduce treba da
elemente proslijeđenog kontejnera svede na 1 element koristeći funkciju koja je proslijeđena kao
argument. Kako treba da izgleda tip drugog argumenta funkcije reduce?
Primjer:
Input list: [11, 4, 5, 12, 6, 8, 9]
Funkcija: [](int a, int b) { return a + b + 1; }
Start: -12
Output: 50
Nakon implementacije funkcije reduce za listu integer-a, odraditi implementaciju i za listu
proizvoljnog tipa podataka te implementaciju za proizvoljan tip kontejnera. */

#include <iostream>
#include <list>
#include <functional>

int reduce(std::list<int> l, std::function<int(int, int)> f, int initial = 0) {

    for(auto k : l)
        initial = f(initial, k);

    return initial;
}

template<typename T>
T reduce(std::list<T> l, std::function<T(T, T)> f, T initial = 0) {

    for(auto k : l)
        initial = f(initial, k);

    return initial;
}

template<typename T>
typename T::type_value reduce(T l, std::function<typename T::type_value(typename T::type_value, typename T::type_value)> f, typename T::type_value initial = 0) {

    for(auto k : l)
        initial = f(initial, k);

    return initial;
}

int main() {

    std::list<double> input{11, 4, 5, 12, 6, 8, 9};

    double result = reduce<double>(input, [](double a, double b) { return a + b + 1; }, -12);

    std::cout << result;

    return 0;
}