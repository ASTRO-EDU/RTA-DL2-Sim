# RTA-DL2-Sim
Il tool RTA-DL2-Sim è un software per la simulazione dei parametri di Hillas caratterizzanti un evento Cherenkov.
Il software riceve due input:
  1. randomNumTelescope;
  2. eventsNumber.

Se randomNumTelescope è settato a "0" verrà simulato un solo telescopio, se randomNumTelescope è settato ad "1" viene simulato un numero di telescopi casuale maggiore di 2 e minore di 10.
L'input eventsNumber specifica il numero di eventi che si vuole simulare.
In output il software fornisce un file json per ogni evento simulato, per ogni evento sono presenti i parametri di Hillas per ogni telescopio simulato.
Il tool dipende dalla libreria RTAlib, per tanto per il corretto funzionamento del software sarà indispensabile esportare la variabile d'ambiente RTA:
  export RTALIB=/path/to/library/RTAlib/


### Esempio 1
Per utilizzare il simulatore digitare:
  ./bin/dl2Sim 0 2

Dove:
  0: indica che si intende simulare un solo telescopio;
  2: indica il numero di eventi che si intende simulare.

### Esempio 2
  ./bin/dl2Sim 1 2

Dove:
  1: indica che si intende simulare un numero casuale di telescopi;
  2: indica il numero di eventi che si intende simulare;

## Compilazione
* export DEBUG=1  (Se si vuole compilare il modalità DEBUG)
* export MULTITHREAD=1  (Se si vuole compilare con supporto multithreading)
* make
