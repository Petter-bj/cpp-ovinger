# Øving 7 teori

### Oppgave 1b)
Forklar hvordan 5 - 3 - fraction1 - 7 - fraction2 blir tolket. Hvilke versjoner av operatoren - blir brukt?

For `-` og generelle operatorer (utenom `=`) gjelder venstre-assosiativitet. Den tar venstre side først, så blir resultatet det nye venstre uttrykket for neste operator.

Så i dette tilfellet vil det starte med:

`5 - 3` bruker den originale versjonen av `-`-operatoren (innebygd for int).

Så får du `2 - fraction1`. Venstre operand er nå en int, ikke et Fraction-objekt, så ingen medlemsfunksjon kan bære den. Derfor brukes ikke-medlemsfunksjonen `Fraction operator-(int integer, const Fraction &other);`

Når det er gjort står man igjen med en fraction, og `nyFraction - 7` tar i bruk medlemsfunksjonen `Fraction operator-(int integer) const;` (venstre operand er brøken, som kommer inn via `this`, og tallet er parameteren).

Til slutt står man igjen med to fractions, og da bruker man medlemsfunksjonen `Fraction operator-(const Fraction &other) const;`
