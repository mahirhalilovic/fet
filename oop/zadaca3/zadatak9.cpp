/* Napisati generičku funkciju jednako koja poredi sekvence [od1, do1) i [od2, do2), pri čemu se
pretpostavlja da sekvence imaju isti broj elemenata. Funkcija vraća vrijednost true ukoliko su svi
elementi obje sekvence isti, u suprotnom vraća netačnu vrijednost. Funkcija uzima tri parametra - prva
dva označavaju početak i kraj prve sekvence, a treći parametar označava početak druge sekvence.
Napomena: iteratori koji operiraju na sekvencama mogu biti različitog tipa.
Koristeći funkciju jednako, napisati program koji učitava riječi koje korisnik unosi sa tastature i
ispisuje svaku riječ koju identificira kao palindrom. Palindrom je riječ koja ima isto značenje bez
obzira da li se čita sa lijeva na desno ili obrnuto. */

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

template<typename T>
bool jednako(T begin, T end, T sub) {

    while(begin != end) {

        if(*begin != *sub)
            return false;

        begin++;
        sub++;
    }

    return true;
}

int main() {

    std::string rijec1, rijec2;

    while(std::cin >> rijec1) {

        rijec2 = rijec1;
        reverse(rijec2.begin(), rijec2.end());

        if(jednako(rijec1.begin(), rijec1.end(), rijec2.begin()))
            std::cout << "Palindrom: " << rijec1 << std::endl;
    }

    return 0;
}