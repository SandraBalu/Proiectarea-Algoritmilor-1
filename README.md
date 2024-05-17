# Tema 1 PA
Balu Sandra

## Alimentare Servere

Implementarea solutiei se bazeaza pe funcria findOptimalPower, care calculeaza 
puterea optima de alimentare pentru servere. Se calcueaza limitarile 
intervalului in care curentul optim poate varia (minimul dintre diferentele 
puterii de calcul si pragurile de alimentare si minimul sumei dintre cele 2).
Calculam apoi, punctul median între limita maxima de supra-alimentare si cea de
sub-alimentare, optimizand astfel puterea minima a serverului cel mai afectat.
Apoi iteram prin lista de servere pentru a calcula puterea minima posibila la 
acest nivel de curent, si determinam puterea sistemului.

Complexitatea temporala: O(N)
Complexitatea spatiala: O(N)

## Colorare

Soltia acestei probleme utilizeaza exponentierea rapida pentru a calcula
numarul de moduri de colorare a sectiunilor consecutive de dreptunghiuri, si
o abordare iterativa pentru a combina rezultatele sectiunilor individuale 
intr-un total global. Exista patru cazuri posibile bazate pe orientarile 
secventelor curente si anterioare (orizontal-orizontal, vertical-vertical,
orizontal-vertical, vertical-orizontal), fiecare cu o formula specifica pentru
calculul numarului de aranjamente valide.

Complexitatea temporala: O(N * logk)
Complexitatea spatiala: O(1)

## Compresie

Implementarea solutiei urmareste sa calculeze lungimea maxima a unui subsir
identic ce poate fi obținut din A si B determinand secvente consecutive cu sume
egale în ambele siruri. Daca cele 2 siruri au sume identice, subsirul se va 
putea calcul, altfel un astfel de subsir nu exista. Daca totusi acesta 
exista, se itereaza prin ambele siruri simultan incercand sa formam elemente 
egale, iar cand se determina se trece la urmatorul.

Complexitatea temporala: O(N + M)
Complexitatea spatiala: O(N + M)

## Criptat

Implementarea solutiei exploreaza fiecare litera posibila ca litera dominanta,
construind cea mai lunga parola posibila pentru fiecare caz si selectand 
lungimea maxima obtinuta pentru o parola care are numarul de aparitii ale 
literei doinante mai mare decat jumatate din lungimea totala. Utilizeaza o 
structura pentru sortarea cuvintelor pe baza "greutatii" fiecarei litere in
cuvinte. Greutatea unui cuvant este definita ca raportul dintre frecventa 
literei vizate în cuvant si lungimea totala a cuvantului.

Complexitatea temporala: O(N * max(26, max_size_word))
Complexitatea spatiala: O(N)

## Oferta

Solutia utilizeaza programare dinamica pentru a calcula costul minim de 
achizitie al produselor, considerand ofertele disponibile. Pentru fiecare 
produs, evaluam costul minim folosind produsul singur, in grup cu produsul
anterior, sau in grup cu doua produse anterioare.

Complexitatea temporala: O(N)
Complexitatea spatiala: O(N)