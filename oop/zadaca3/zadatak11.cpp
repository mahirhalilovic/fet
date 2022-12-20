/* Implementirati klase Radnik i BazaRadnika koja implementira bazu radnika i omogućava:
● Unos pojedinačnog radnika u bazu. Baza ne dozvoljava unos dva radnika istog imena.
Ukoliko se pokuša unijeti isti radnik dva puta, metod generira iznimku tipa domain_error.
● Brisanje radnika određenog imena iz baze. Metod za brisanje kao rezultat vraća uspješnost
operacije.
● Unos i ispis kompletne baze pomoću objekata tipa istream i ostream.
● Računanje prosječne plate i starosti radnika.

Klasu testirati sljedećim glavnim programom:
#include “Radnik.hpp”
#include “Baza.hpp”
#include <iostream>
int main() {
BazaRadnika b1;
b1.ucitaj(std::cin);
if(b1.izbrisi_radnika(“Alen”)) {
std::cout << “Alen izbrisan” << std::endl;
} else {
std::cout << “Brisanje nije moguce!” << std::endl
}
std::cout << “U bazi su: “ << std::endl;
b1.ispisi(std::cout);
std::cout<<“Prosjek plata je: “<<b1.prosjek_plata()<<std::endl;
std::cout<<“Prosjek godina je: “<<b1.prosjek_godina()<<std::endl;
return 0;
}
Na linku je prikazan poziv izvršnog file-a sa navedenom main funkcijom. */