/* Napisati poboljšanu verziju prethodne funkcije takvu da osim iteratora na std::list uzima i
predicate funkciju kao argument (std::function<bool(int)> iz functional
zaglavlja). Funkcija treba da poziva predicate nad svakim članom ulaznog argumenta, te ukoliko
je rezultat predicate poziva tačan, član treba da se nalazi na lijevoj strani, odnosno ukoliko je
netačan na desnoj strani rezultujuće kolekcije. */

#include <iostream>
#include <iterator>
#include <list>
#include <functional>

std::list<int> parni_neparni(std::list<int>::const_iterator begin, std::list<int>::const_iterator end, std::function<bool(int)> f) {

    std::list<int> result;

    while(begin != end) {

        if(f(*begin))
            result.push_front(*begin);
        else
            result.push_back(*begin);

        begin++;
    }

    return result;
}

int main() {

    std::list<int> nums{15,20,25,-10,-75,100,-255,430,200};

    auto predicate = [] (int num) {

        return !(num % 2);
    };

    std::list<int> res = parni_neparni(nums.cbegin(), nums.cend(), predicate);

    for(auto k : res)
        std::cout << k << std::endl;

    return 0;
}