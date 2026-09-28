### Leksjon 2 Pointers and references

Peker er en variabel som kan inneholde adressen til en annen variabel

En stjerne i variabeldefinisjonen markerer at vi snakker om en peker

eks int *pointer

& forran en variabel henter ut adressen til det bak &

*pointer for å vise verdier pointeren peker på ' * = gå til adressen'

Tabeller og adreser visst vi bare skriver table(navnet på tabellen) så får vi adressen til første elementet i tabellen 

eks int *pointer = table;
er det sammes som int *pointer = &table[0];


## const og pekere


const char* p (peker til konstant data)
Så pekeren kan endre seg men ikke dataen.
Altså adressen pekeren peker til.

char* const p (KONSTANT peker)
altså dataen kan endre seg men ikke pekeren. Altså innholdet på adressen kan endres men ikke adressen pekeren peker til.


const char* const (begge delere konstant) ingenting kan endres

## Aritmetikk på, og sammenlikning av pekere

multiplikasjon og divisjon av adresser gir ikke mening så dermed er det bare noen få aritmetiske operasjoner som fungerer.

pointer + n hopper n elementer fremover
pointer - n hopper n elemter bakover 
pointer2 - pointer1 avstand mellom to pekere (antall elementer)
pointer1 == pointer2  Sjekk om samme adresse?
pointer 1 > pointer 2 hvem peker lengst frem i minne


p++ endrer posisjonene på pekeren

god regel å la alle pekere initieres til 0 + c++11 kan vi bruke nullptr

