/* Napisati funkciju parni_neparni koja uzima dva iteratora na početak i kraj kontejnera
std::list<int> kao argumente te nazad vraća novi std::list<int> kontejner takav da su
svi parni članovi na lijevoj strani, a svi neparni na desnoj strani kolekcije. Funkcija ne treba
modifikovati elemente proslijeđene kolekcije na koje iteratori pokazuju. */

#include <iostream>
#include <iterator>
#include <list>

std::list<int> parni_neparni(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) {

    std::list<int> result;

    while(begin != end) {

        if(*begin % 2 == 0)
            result.push_front(*begin);
        else
            result.push_back(*begin);

        begin++;
    }

    return result;
}

int main() {

    std::list<int> nums{15,20,25,-10,-75,100,-255,430,200};
    std::list<int> res = parni_neparni(nums.cbegin(), nums.cend());

    for(auto k : res)
        std::cout << k << std::endl;

    return 0;
}