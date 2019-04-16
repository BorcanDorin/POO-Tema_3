# POO-Tema_3

## Precizari generale
 * Puteti folosi STL si ce considerati ca e nevoie insa pentru temele care presupun structuri de date, folosirea STL pentru exact structura de date din cerinta ar circumventa scopului temei.
 * Cele mai multe cerinte sunt partiale, lasand la latitudinea voastra cum alegeti anumite elemente concrete pentru a ilustra cat mai bine competentele voastre de OOP.
 * In cazul in care o cerinta este neclara si nu reusiti sa o clarificati singuri, spuneti pe grup, sau discutam la laborator
 * 1p in plus pentru folosirea de templateuri
 * 1p in plus pentru un design pattern implementat
 * Incercati sa utilizati cat mai multe cunostinte de POO pe care le-ati dobandit pana acum si incercati sa implementati totul cum trebuie (cu constructori de copiere, operator=, alocare dinamica, fara memory leakuri, etc)


## Atelier auto: 
Exista mai multe categorii de vehicule (motocicleta, bicicleta, automobil) care pot sosi la un garaj pentru a descoperi ce probleme tehnice au si a obtine un deviz de reparatii. Fiecare vehicul poate avea probleme din diferite categorii: frane, directie, noxe, motor, caroserie. Nu toate vehiculele pot avea toate tipurile de probleme. Fiecare tip de problema are o solutie tehnica ce presupune un anumit consum de materiale (de diferite tipuri) si un anumit efort uman (in ore-om). Fiecare material are un cost la fel ca si ora-om de efort uman. Pentru fiecare vehicul ce soseste in garaj trebuie calculat devizul estimativ.

### Precizari:

 * Tipurile de probleme vor include cel putin: 
   + Frane:
     - placute uzate (fata/spate la un auto/moto),
     - discuri uzate (oricare din 4 la un auto, oricare din 2 la moto), 
     - lant tocit (bicicleta), 
     - lant lipsa (bicicleta), 
     - defectiune capitala; 
   + Motor: 
     - Nivel ulei scazut (la moto si auto), 
     - carburator murdar (la auto), 
     - motor topit (la moto si auto); 
   + Directie: 
     - ghidon stramb (bicicleta, moto), 
     - roata stramba (toate), 
     - defectiune capitala (toate); 
   + Noxe: 
     - Vehiculul arde ulei (moto si auto), 
     - Vehiculul este anterior anului 2000 (moto si auto); 
   + Caroserie (auto): 
     - Caroserie corodata de rugina, 
     - Caroserie stramba (aripi stanga/dreapta, fata/spate, bara, capota) - foarte stramba sau asa-si-asa (pe fiecare componenta in parte).
 * Solutiile presupun un consum de materiale. Materialele sunt toate la bucata. Placutele de frana de pe spate difera de cele de pe fata. Placutele de frana sunt aferente fiecarei roti. Nivel ulei scazut, motor topit si vehiculul arde ulei toate presupun schimb de ulei.
 * Fiecare problema are o solutie (mai putin defectiunea capitala). Pot exista tipuri de materiale comune mai multor solutii. Toate solutii consuma suruburi (minim 5).
 * Vehiculul suporta operatiuni de traumatizare (e.g. Uzeaza discul de frana de pe spate dreapta sau Incepe sa arzi ulei).
 * Vehiculul odata conectat la tester (in atelier) se va putea autodiagnostica verificand fiecare componenta a sa si returnand lista de probleme.
