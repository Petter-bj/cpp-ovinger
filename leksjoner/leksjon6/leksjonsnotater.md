# Leksjon 6: Funksjonsobjekter og trådobjekter

#include <functional>

Lar deg skrive ting som dette: 
function<int<int,int> add = [](int a, int b) {
        return a + b;
    }; 

hvorfor gjøre dette? Visst du har noe som skjer i en klasse, men du vil ikke at klassen selv skal bestemme hva som skjer videre.
Da gir klassen et funksjonsobjekt som den kaller når ting skjer, og du kobler på den oppførelsen du vil ha fra utsiden.

Dette gir mye mening med foreksemepel chessboard klasses som vi egentlig bare vil skal holde seg til logikk.


## Trådprogrammering 
```#include <thread>```

opretting av tråd eksemepl
thread a_thread([] {
    cout << from a_thread << endl;
  });

****join() Main venter til trpden er ferdig eks: a_thread.join(); tråd-objektet kan da ikke dø før den er ferfig 

detach() Tråden kjlrer videre alene, uavhengig. Tråd objektet kan dø men tråden overlever

Man kan la tråden eie dataen den trenger via smart pointers som fanges by value.
Med shared_ptr holdes objektet i live av en referansetelling. Hver eier øker telleren og først når siste eier forsvinner slettes den.
Kna også bruke unique_ptr visst en tråd skal eie og kanskje overta. Men visst flere tråder skal dele og ingen vet hvem som avslutter færst shared_ptr



### Mutex

om flere tråder jobber med des amem ressursene, må en passe på at de ikke endrer og leser fra variablene eller objektene samtidig.

static mutex message_mutex: // we can declare the mutex as static if not needed elsewhere
lock_guard<mutex> lock(message_mutex); // The message_mutex is locked upon construction of lock, and
// the mutex is unlocked when lock is destroyed at the end of scope,
// including when an exception is thrown


### Asynkron tjeneste

Av og til kan det v@re ønskelig å sende oppgaver til en asynkron tjeneste i stedet for å jobbe med tråder manyelt.
Boost.Asio lar deg styre antall tråder som blir brukt.

I stedet for å håndtere tråder manuelt med ekst thread / join / detach. lager man en arbeidstjeneste.
Eks
````
Workers workers(4);
workers.service.post([] {
    cout << "task A" << endl;
});
````
Byggeklosser man har 
io_context   : den lager en oppgavekø en event loop
post(lambda)    : legger en oppgave i køen, returnerer umiddelbart
Worker-tråder   : kjører service.run()  i løkke
stop() stopper loopen og koiner workerne

Man kan bruke det med parallellkserkng eks Workers workers(4) som er fire tråder som deler arbeidet
Eller man kan bruke den sekvenielt med en tråd Workesrs workers(1)

