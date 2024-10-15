Un alt algoritm de criptografie, de dificultate medie, care este predat la universități precum Princeton sau Cambridge este **Algoritmul RSA** (Rivest–Shamir–Adleman), unul dintre cele mai utilizate și importante algoritme de criptare cu cheie publică.

### Despre RSA:
- **RSA** este un algoritm asimetric de criptare, ceea ce înseamnă că utilizează două chei: o cheie publică pentru criptare și o cheie privată pentru decriptare.
- Securitatea algoritmului se bazează pe dificultatea factorizării numerelor foarte mari, în special a produselor a doi factori primi mari.

### Pașii algoritmului:
1. **Generarea cheilor**:
   - Se aleg doi numere prime mari \( p \) și \( q \).
   - Se calculează \( n = p \times q \) și \( \phi(n) = (p-1) \times (q-1) \).
   - Se alege un număr întreg \( e \) astfel încât \( 1 < e < \phi(n) \) și \( e \) să fie coprim cu \( \phi(n) \).
   - Se calculează cheia privată \( d \) astfel încât \( e \times d \equiv 1 \, (\text{mod} \, \phi(n)) \).
   
2. **Criptare**:
   - Mesajul \( M \) este transformat într-un număr întreg mai mic decât \( n \).
   - Mesajul criptat \( C \) este obținut prin formula: \( C = M^e \mod n \).

3. **Decriptare**:
   - Mesajul criptat \( C \) este decriptat cu cheia privată \( d \) folosind formula: \( M = C^d \mod n \).

### Exemple de aplicare:
- RSA este utilizat pe scară largă în securizarea comunicațiilor pe internet, inclusiv în protocoale precum SSL/TLS și pentru semnături digitale.

Acest algoritm este predat în cursuri de criptografie la universități de top deoarece îmbină concepte fundamentale din teoria numerelor și oferă un nivel ridicat de securitate practică.

Dacă dorești o implementare a acestui algoritm sau explicații detaliate pe anumite aspecte, spune-mi!
