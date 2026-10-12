# Leksjon 7: Operator overloading

Utvide bruksområdet for de vanlige operatorene. Kan bruke sammenligningsoperatorene til å sammneligne objekter.

## Hva menes operator overloading?
Vi kan ha flere funksjoner med samme navn, bare parameterlisten er forskjellig.

Vi skal se på at vi på tilsvarene måter kan øa samme opertor brukes med forskjellige typer operander.
Dette er allerede kjent ettersom + kan brukes med både heltall og flyttall.
Siden de representeres påvidt forskjellige måter internt i maskinen, vil det for kompilatorene være to helt forskjellige operasjoner.

Operator overloading er nødvending når du skal sammenligne ting innad i en klasse.
Da må du som programerer definere hva operatoren skal brukes til altså gi operatoren en mening for din egen klasse.

aldri == på desimaltall farlig med double

fabs() absoluttverdi fra cmath.

kan oprette compare funksjon men koden ser klossete ut og lagre resultat og sjekke tre verdier hver gang.

````
bool Surface::operator<(const Surface &other) const {
  return (compare(other) < 0);
}
````
Tar å gejnbruker compare bool som returtype.

så siste steg er du nå kan skrive if(surface1 < surdace2)
Nå har man utvidet < til å fungere på Surface-objekter

Stegene er da 1 lag compare(other) så operator<(other) så til sluttt kan du da bruke surface1 < surface2

## Eksempel: klassen Fraction (norsk:brøk)

Oppklaring en binær operator en en operator som tar to operander.
Vi mp alltid ha to operander for å utføre en multiplikasjon.
En unær operator tar kun en operand. En unær operator tar kun en operand pluss og minus er vanligvis binære men kan være unære-
Eks -number er unær da tar du verdien til number og legger til et negativt fortegn.

fraction programmet er et program som bruker operatorene på noen brøker.
Vi ser at vi kan bruke operatorene på akkurat samme måte for brøkene som om det var int eller double.

Lag kopi, endre kopien returner.

```` 
Fraction Fraction::operator*(const Fraction &other) const {
    Fraction fraction = *this;  //lager kopi 
    fraction *= other;  //bruker *= på kopien
    return fraction;    //returnerer den nye kopiem
}
````
+, /, * returnerer et nytt objekt. +=, = og ++ returnerer *this.

hvorfor oprette kopi. For å beholde tallene til utskriften for visst ikke hadde bare fractionen blitt regnet ut og du ville ikke kunne ha skrevet den ut.
Så du skal kunne beregene et nytt resultat uten å ødelegge operandene.

compare kjernen
````
// Returnerer +1 hvis *this > other, 0 hvis like, -1 hvis *this < other
int Fraction::compare(const Fraction &other) const {
    Fraction fraction = *this - other;   // regn ut differansen
    if (fraction.numerator > 0)  return 1;
    else if (fraction.numerator == 0) return 0;
    else return -1;
}
````
