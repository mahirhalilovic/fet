/* Modifikovati funkciju predicate iz prethodnog zadatka tako da tretira iznimke koje se mogu javiti
iz predicate funkcije. Ukoliko predicate funkcija baci iznimku potrebno je vratiti nazad
identičnu kolekciju onoj koja je proslijeđena putem iteratora. Za listu brojeva:
15,20,25,-10,-75,100,-255,430,200
u kombinaciji sa sljedećom predicate lambdom za poziv partition:
[](int num) { if (num > 400) throw 5; return num > 0; }
program treba da ispiše kolekciju identičnu originalnoj. */

#include <iostream>
#include <iterator>
#include <list>
#include <functional>

std::list<int> parni_neparni(std::list<int>::const_iterator begin, std::list<int>::const_iterator end, std::function<bool(int)> f) {

    std::list<int> result;
    auto temp = begin;

    while(begin != end) {

        try{
            if(f(*begin))
                result.push_front(*begin);
            else
                result.push_back(*begin);

            begin++;
        } catch(int) {

            result.clear();

            while(temp != end) {

                result.push_back(*temp);
                temp++;
            }

            return result;
        }
    }

    return result;
}

int main() {

    std::list<int> nums{15,20,25,-10,-75,100,-255,430,200};

    auto predicate = [] (int num) {

        if (num > 400)
            throw 5;
        
        return num > 0;
    };

    std::list<int> res = parni_neparni(nums.cbegin(), nums.cend(), predicate);

    for(auto k : res)
        std::cout << k << std::endl;

    return 0;
}