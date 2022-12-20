/* Napisati funkciju koja prima std::vector<int> kao prvi argument, te vektor funkcija koje će biti
primijenjene nad svakim elementom u vektoru. Ukoliko element ne zadovolji kriterije svih predicate
funkcija, u tom slučaju taj element zamijeniti sa defaultnim trećim argumentom kojeg funkcija prima
koji ima vrijednost -1. Ukoliko bilo koja predicate funkcija vrati false, taj element zamijeniti sa
defaultnim argumentom.
Funkcija ima sljedeci potpis:
typedef std::vector<std::function<bool(int)>> Funkcije;
void default_if_not_all(std::vector<int>&, Funkcije, int def=-1); */

#include <iostream>
#include <vector>
#include <functional>

typedef std::vector<std::function<bool(int)>> Funkcije;

void default_if_not_all(std::vector<int> &v, Funkcije f, int def = -1) {

    for(auto &e : v)
        for(auto p : f)
            if(p(e) == false)
                e = def;
}

int main() {

    Funkcije f = {[](int a){return a % 2;}, [](int a){return a > 0;}, [](int a){return a < 5;}};

    std::vector<int> v{7, 4, 2, 1, 5, 8};

    default_if_not_all(v, f);

    for(auto k : v)
        std::cout << k << std::endl;

    return 0;
}