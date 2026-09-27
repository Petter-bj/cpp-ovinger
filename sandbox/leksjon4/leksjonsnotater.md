# Leksjon 4 Konteinere og lambda

STL er c++ sitt bilotek for å håndtere data-konteinere.
Leksjon konsentrerer seg im vektorer som den mest brukte konteineren.

Bruken handler til en viss grad av hva vi putter inn i konteineren

## STL = Standard Template Libary
Bibloteket består av tre deler:

### Konteinere

Typen container sier hvordan data er organisert.
De viktigste er vector, unordered_set og unordered_map. (De tre er pensum)

En vektor (ikke matte vektor) ligner en tabell. Laget slik at vi ikke trenger å tenke på at den kan bli overfylt.
Visst den blir full, utvider den seg selv.

Ligner ArrayList fra java. Men i java blir kjøretiden mye dårligere når man går fra lavnivå tabell til ArrayList.
I c++ er det ingen forskjell på om man bruker en lavnivå tabell eller vector.
vector goated

### Iterator
Lar oss forflytte oss fra element til element i kontaineren

### Algoritmer
Gjør noe med datainnholdet i en konteiner. Brukes med #include <algorithm>
Vi sender inn iterator som argumenter til algoritmene.
Eksempel sort() eller find()

## Bruk av kontaineren vektor

opretting = vector<datatype> navn;

visst du har en vektor kalt navn så kan man bruke numbers.emplace_back(number); for å legge inn det nye tallet bakerst

kan bruke capacity() på vektoren. For å se kapasitenten til vektoren for å se hvor mange elementer den har satt av minne til.

kan å bestemme kapasitente med navn.reserve(10) som vil reservere plass til minst 10 elementer.

for vektorerer kan man tilordene vektor verdier på begge sider av tilordningstegnet "="

visst size = 3 på en vektor kan man ikke kjøre navn[3] = 50; dette vil feile siden det ikke er et tredje element.
Visst du vil legge inn et nytt element bakerst kan man bruke navn.emplace_back(50);

## Vektor fylt med objekter

vector<objektet> objektene;
ikke noe særlig mere enn det visst du kjører objektene.emplace_back() så vet den parameterene til objektet så du bare fyller de inn i rekkefølgen til objektet.


## iteratorer
Bindeledd mellom konteinerne og algoritmene

Nesten alle kontainere har medlemsfunksjonene begin() og end(). Funskjonene begin() returnerer en iterator til første element i konteineren
Dette gjør det mulig å skrive løkker slik:

for (auto it = objekter.begin(); it != surface.end(); ++it);

merk ++it for å slippe å gi kompilatoren to verdier.

for (auto it = surfaces.begin(); it != surfaces.end(); ++it)
cout << it->name << " areal: " << it->get_area() << endl;
 
^^ løkke eksempel der man istedenfor å skrive(it*).name så bruker man pil operatoren.

## Algoritmen sort

Eksempel bruk
sort(numbers.begin(), numbers.end());
sort(first, last);
Sort vil da sortere nummerene i vektoren fra høy til lav.
sort kan også brukes for å sortere spesifike elementer av en container
Kan kjøre sort(numbers.begin() + 1, sort numbers.end()-2)

Kan også sortere objekter men må definere en funksjon som definerer hvordan vi vil ha den sortert
eksempel sort(objekt.begin(), objekt.end(), compare) 
i eksempelet så vil compare da være en bool som tar eksempel arealet til en flate og samnenligner det og kan da si at visst den returnerer True så vil sort tolke det som at det skal plaseres før det den sammenlignes med.

Ok bare glem det du kan lage en anonym funkjson (lambda funskjon) slik
sort(surfaces.begin(), surfaces.end(), [](const Surface &a, const Surface &b) {
return a.get_area() < b.get_area();
});



## Anonyme funksjoner
Tok med anonyme funksjoner (lambda funksjon) visste eksempel i forrige men. Her kommer mere om det.
eksmepl fra hans kode:
button.signal_clicked().connect([this]() {
label.set_text("Button clicked");
});

[this] fanger oekeren til det gjeldende Window objektet slik at funskjonen kan bruke medlemene som label i dette eksempelet
Objektet kopieres ikke lambdaen får tilgang til det gjennom this pekeren

Så man kan bruke lamda som reaksjon på en hendelse og så fange this for å bruke datamldemmene til objektet inen i lamdaen

