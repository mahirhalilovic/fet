/* Potrebno je implementirati program koji ima mogućnost unosa i evidencije studenata, predmeta i
ocjena. Program treba da podržava operacije dodavanja novih predmeta, dodavanje studenata,
editovanje polja jednog studenta te ispis svih studenata zajedno sa svim ocjenama iz pojedinih
predmeta i prosjekom. Sve ove operacije implementirati korisničkim menijem. Uzeti u obzir da naziv
predmeta i odsjeka na kojem se predmet nalazi može imati više riječi.
Strukture Predmet i Student modelirati kao što je to ispod prikazano:
struct Predmet {
std::string naziv;
std::string odsjek;
};
struct OcjenaIzPredmeta {
int ocjena;
std::list<Predmet>::const_iterator predmet;
};
struct Student {
std::string brojIndeksa;
std::string ime;
std::string prezime;
std::string grad;
std::vector<OcjenaIzPredmeta> ocjene;
};
Iz modela strukture OcjenaIzPredmeta jasno je da je za predmete potrebno koristiti kontejner
tipa std::list. Zašto ne vektor? Šta se sa iteratorima vektora dešava kada se vektor kontejner
proširuje?
Unos novih predmeta treba da bude vrlo jednostavan, od korisnika se traži unos naziva predmeta i
odsjeka. Novi predmet je potrebno dodati na kraj kontejnera tipa std::list<Predmet> osim ako
predmet sa unešenim nazivom već ne postoji. U tom slučaju ispisati grešku korisniku. te se vratiti na
početni meni.
Unos studenta treba da ide u redoslijedu:
1. Indeks (samo jedna riječ). Ukoliko student sa unesenim brojem indeksa već postoji, ispisati
grešku na ekran te se vratiti nazad na početni meni.
2. Ime (može sadržavati više riječi)
3. Prezime (može sadržavati više riječi)
4. Grad (može sadržavati više riječi)
5. Unos ocjena
a. Unos predmeta za koju je ocjena vezana. Ukoliko predmet ne postoji ispisati grešku
na ekran, vratiti se na početni meni i ne dodavati ništa u kolekciju studenata. U
suprotnom kreirati instancu strukture Ocjena iz predmeta čiji iterator pokazuje na
konkretan predmet iz kolekcije.
b. Unos ocjene (moguće vrijednosti od 5 do 10). Ukoliko korisnik unese vrijednost
manju od 5 ili veću od 10 zatražiti ponovni unos ocjene.

Opcija editovanja studenta treba od korisnika da traži unos broja indeksa. Ukoliko student sa tim
brojem indeksa ne postoji, ispisati grešku i vratiti se na početni meni, u suprotnom potrebno je
ponuditi novi meni gdje korisnik može odabrati kakvu operaciju editovanja želi odraditi. Moguće
operacije su:
1. Mijenjanje broja indeksa studenta
2. Mijenjanje imena studenta
3. Mijenjanje prezimena studenta
4. Mijenjanje grada studenta
5. Brisanje svih ocjena
6. Dodavanje novih ocjena
Struktura Student i sve potencijalne funkcije vezane za nju je potrebno izdvojiti u poseban hpp file.
Svu implementaciju ovih funkcija vezanih za studente je potrebno prebaciti u poseban cpp file. */