# Leksjon 9 STL-algoritmer

Bruk av ulike STL-algoriter

## algoritmer for linært søk
"linært søk: søk i en tabell med å sammenlikne hvert enkelt element med den verdien vi leter etter."

Søk etter enkelverdi bruke find(startverdi,sluttverdi,det vi leter etter)

find_first_of leter etter det første elementet i ett område som er lik et av elementene i et annet område.
find_first_of tar inn fire argumenter en for start posisjon til hvert område og en til slutten av områden til hver av de.

adjacent_find() leter etter de to første naboene som har lik verdi og returnere en iterator til det første elementet i paret.
adjecent_find leter kun i et område og tar inn start og slutt av området

count() teller antall forekomster av noe count(start,slutt,det du teller)

find returnere iteraotr til posisjonen den finner noe på 


## Algoritmer som endre eller flytter på datainnholdet

swap(v1,v2) bytter innholdet i de to vektorene

.rezize()int endrer størrelsen på vektoren altså legger til 0-er der man reziser 

og copy vil kopiere innhold fra start til slutt fra index til den vektoren du velger

swap_ranges() kan brukes for å bytte plassering på områder innad i et ommråde eks bytte index 1-5 med 5-10 slik at det dat blir 5-10 så 1-5 

fill() brukes for å fylle en bestem verdi fra index til en annen index

replace_copy tar inn elementer som skal kopieres hvor de skal skives verdien som skal ertsattes og den nye verdien rezize trengs her fordi replace_copy skriver til eksisterende elementer

reverse_copy start og slutt og hvor det skal skrives så reverserer den det du sendte inn

rotate(start, nytt_første, slutt) tar inn tre iteratorer og flytter elementene i området [start, slutt) slik at nytt_første blir først, mens elementene foran det flyttes bakerst i området.


next_permutation finner neste permutasjon


## Algoritmer på sorterte data
eksempler på algoritmer som foutsetter at data er sortert 

binary_search() sier om et element er i en vektor men ikke hvor.
binary_search(begin,end, tall du leter etter)
kan bruke lower_bound() eller upper_bound() til å finne tallet
lower_bound() gir oss en iterator til første elemnt som er større enn eller lik 17
derfor gir pos-v1.begin oss rett index til vektor v1

så lower bound vil ikke garantere at tallet fines.

upper_bound()  dette er plassen etter alle like verdier 
så visst du ser etter 17 så vil den gi deg første verdi større enn 17

Kan brukes smart til å finne antall av et tall visst man tar lowerbound - upper bound for samme tall

includes sjekker om alle elemente fra område 2 er med i områed 1 returner true eller false

merge() dette fletter sammen elementene og beholder alle
5 argumenter de 4 første angir de to områdene som skal flettes og det siste angir hvor det skal skrives

unique() og end() fjerne dubletter 
unique samler en av hver legger de fremst i vektoren 
den reduserer ikke størrelsen det gjør erase() som kan fjerne ende verdier

set_union() verdier som finnes i en eller begge.

set_intersection() - verdier som finnes i begge

