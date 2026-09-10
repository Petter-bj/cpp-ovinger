# Oppgave 3: Finn feil i programbiten

**1. Buffer overflow:** `text[5]` har plass til 4 tegn. `cin >> text` skriver uten
grensesjekk for lang input går utenfor arrayet. Kan dermed overskrive annen data i minnet.

**2. Out of bounds:** Hvis teksten ikke inneholder 'e', stopper ikke løkken.
`pointer` løper forbi `text` og leser/skriver tilfeldig minne.

**3. Dataødeleggelse:** `*pointer = search_for` overskriver tegnene med 'e'
under søket. Originalteksten ødelegges.
