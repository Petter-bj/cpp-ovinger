### Leksjon 3 objektorientert programmering i C++ 

Konsterer seg om detaljene rundt programmering av en enkelt klasse men også sammerbeid mellom objekter og arv av klasser.

Objekt en modell av en ting som problemområdet vårt handler om.

Et objekt kan modellere noe konkret som en stol, bord en person eller en buss.
Et objekt ar ansvar for å kunne en del ting om seg selv.

Et objekt har en tilstand. Som kan endres etterhvert som ting skjer.

Objekter har attributter eks nummer.

Atferden til et objekt er gitt som mengden av operasjoner som objektet kan utføre.

Innkapsling (encapsulation) egenskap ved objekter. Oplysninger om hvordan et objekt løser en oppgvae er gjemt inne i objektet

Klientobjektet trenger ikke vite noe om hvordan tjenerobjektet løser oppgaven are at den løses.

En klasse er en beskrivelse av en mngde objekter osm har det itl felles at har samme attributtene og samme atferd.

vanlig å dele opp koden der klassedeklarsjone ligger i hpp fil

i header filen valing å ta med '#pragma once' for å ungå redeklarering dersom samme header fil inkluders flere ganger

const etter funksjonsnavnet sier at den funksjonenen endrer ikke data

set funksjoner uten const endrer data eks: void set_length(double length);  // IKKE const — den endrer!

const string & -- hvorfor? string (kopi) tregt &string raskere men kan endres.

sub klasser er også i c++