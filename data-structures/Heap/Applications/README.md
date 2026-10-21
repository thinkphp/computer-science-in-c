# Heap Data Structure Applications

Bună întrebare — heap-ul e una dintre cele mai versatile structuri din informatică. Iată principalele aplicații, grupate pe categorii:

## 1. Algoritmi pe grafuri (probabil cele mai importante)

- **Algoritmul lui Dijkstra** — găsirea celor mai scurte drumuri. La fiecare pas extragi nodul cu distanța minimă dintr-un minHeap → complexitate **O((V+E) log V)** în loc de O(V²).
- **Algoritmul lui Prim** — arbore parțial de cost minim (MST). Extragi mereu muchia de cost minim disponibilă.
- **Algoritmul lui A\*** (drumuri în jocuri / hărți) — frontieră explorată ținută într-un heap ordonat după `f = g + h`.

Fără heap, acești algoritmi ar fi mult mai lenți pe grafuri rare.

## 2. Probleme de selecție (top-k, mediană)

- **Top K elemente** dintr-un flux de N numere: păstrezi un heap de dimensiune k → **O(N log k)** în loc de O(N log N) prin sortare.
  - Top K cele mai mari → minHeap de dimensiune k
  - Top K cele mai mici → maxHeap de dimensiune k
- **Mediaiană dintr-un flux** (median of running stream): două heap-uri — un maxHeap pentru jumătatea inferioară și un minHeap pentru cea superioară → fiecare inserare **O(log n)**, mediana în O(1). Clasică problemă de interviu!

## 3. Planificare și simulare

- **Task scheduling** în sistemele de operare (procese după prioritate).
- **Simulare cu evenimente discrete**: evenimentele viitoare ținute într-un minHeap ordonat după timp — se extrage mereu următorul eveniment. Se folosește în simulatoare de rețele, jocuri, sisteme reale.

## 4. Comprimare de date

- **Codificarea Huffman** — construiești arborele de prefix optim unind repetat cele două noduri cu frecvența minimă, exact ca într-un minHeap.

## 5. Fuziune de date ordonate (k-way merge)

- Ai **k liste sortate** și vrei să le interclasezi: un minHeap de k elemente (câte unul din fiecare listă) → **O(N log k)**, folosit la sortarea externă (fișiere mai mari decât memoria) și la `merge` în MapReduce.

## 6. Alte aplicații utile

- **Scheduling în Greedy algorithms**: de exemplu, problema planificării job-urilor pentru profit maxim (Job Sequencing).
- **Găsirea celui mai apropiat punct / k-NN**: heap pentru a ține cei mai apropiați k vecini.
- **`heapq` în Python** are chiar funcții dedicate: `nlargest`, `nsmallest`.

## De ce heap peste alternative?

Regula generală: când ai nevoie **repetat** de minimul/maximul curent, în timp ce vin elemente noi sau se modifică unele, heap-ul oferă O(log n) — mai bun ca un array nesortat (O(n) la căutare) și mai flexibil ca un array sortat (O(n) la inserare).

**Pe scurt:** Dijkstra/Prim/A*, top-k, mediană din flux, Huffman, scheduling, simulare de evenimente, k-way merge — cam oriunde apare formula „extrage repetat extremul". Heap sort și coada cu priorități sunt doar cele două fețe cele mai cunoscute ale aceluiași mecanism.
