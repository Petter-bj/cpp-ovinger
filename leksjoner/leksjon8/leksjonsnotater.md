# Leksjon 8 Templates
Se på en spesiell teknikk (template)
gjør at vi kan lage kode som er anvedielig til mange formål.
STL er et eksempel klassebiblotek med mange nyttige klasser.
Kan lage klasser somm fungerer uavhengig av hvilken dataype.

### Funksjonstemplate
Lage funksjon som template.

Sortere tabell. Samme algorytme uansett datatype.
Eneste krav er at dataene har en innbyrdes rekkeefølge
dette er slik at man kan sortere det etter noe.

Sorteringsalgoritme
finner minste elemnt og plasserer det førstm deretter finner vi nest minste og plasserer det som nummer to.

koden:

```
template <typename Type>
void sort(Type &data) {
  for (size_t i = 0; i < data.size(); ++i) {
    int smallest = i;
    for (size_t j = i + 1; j < data.size(); ++j) {
      if (data[j] < data[smallest])
        smallest = j;
    }
    auto help = data[i];
    data[i] = data[smallest];
    data[smallest] = help;
  }
}
```

Denne koden finner smallest lager en help variabel til lagring av data[i] som blir brukt til slutt for å ta plassen til der data[smallest] orginalt var så når index 0 har fått plass går man videre til neste index sånn fortsetter den helt til den har gått gjennom listen.

Kan da kalle på sort() som en valing funksjon

Viktig å bruke riktig type når du kaller funksjonen.

Templates er en måte å lage polymorfe funksjoner altså funksjoner som oppfører forskjellig avhengig av hvordan de brukes.

