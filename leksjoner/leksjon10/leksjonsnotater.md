# Leksjon 10: 3.parts bilioteker

### Programmeringsbibliotek
Et programmeringsbiblotek inneholder ferdigkompilerte implementasjoner av klasser eller funksjoner som kan gjenbrukes av programmer vi skriver.

#### statiske bibliotek
Opprinnelig fantes det kun statiske bibliotek som ble lagt til de kjørbare filene ved kompilering.
Om et bibliotek ble oppdatertm måtte en kompilere alle programmene som brukte biblioteket på nytt.

Det dette betyr er at hvis bilioteket oppdateres, får ikke programmet den nye versjonen. 
Programmet må bygges på nytt for å ta oppdateringen i bruk. (Tungvidnt når mange programmer bruker samme bib)

#### Dynamiske bilbioteker
Program som er linket dynamisk blir bibliotekene bruker lastet ved kjøring av programmet. Hver ganga programmet startes blir nyeste versjon av biblioteket brukt.

Ulempe er at bibliotekene må være installert for å kjøre programmet

#### Kompileringsfiler

eks makefile her kompileres alle ulike programmene/biblotekene i et proj 


#### CMake
enklere måte å lage bygningsfiler.

## Eksempel på 3. parts biblioteker
srd bib til cpp er mindre enn til eks java eller C#.
Vi er derfor avhengig av prosjekter som har implementert klasser og funk som stdbibloteket for cpp mangler.

