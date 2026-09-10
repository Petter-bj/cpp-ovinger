# Oppgave 2: Hva vill skje med strcpy på nullptr?

`strcpy` prøver å kopiere teksten til adressen `line` peker på.
Siden `line` er `nullptr` (adresse 0x0), peker den ikke på noe gyldig minne.
Programmet får **segmentation fault** fordi operativsystemet nekter
å skrive til en ugyldig adresse.
