# Totient Function (φ(n))

The Euler's totient function, denoted as φ(n), represents the number of positive integers less than or equal to n that are **coprime with n** (i.e., their greatest common divisor with n is 1).

---

## Properties

1. **For Prime Numbers**  
   If n is a prime number:
   
   φ(n) = n - 1
   
   All numbers less than n are coprime with n.

2. **Multiplicative Property**  
   The totient function is **multiplicative**, meaning:
   
   φ(m · n) = φ(m) · φ(n)
   
   if gcd(m, n) = 1.

3. **General Formula**  
   For any integer n, the totient function can be calculated as:
   
   φ(n) = n · ∏(p|n) (1 - 1/p)
   
   Where p are the prime factors of n.

---

## Example Calculation

For n = 12:  
- Prime factors of 12 are 2 and 3.  
- Using the formula:
  
  φ(12) = 12 · (1 - 1/2) · (1 - 1/3)
  
  φ(12) = 12 · 1/2 · 2/3 = 4
  
- Numbers less than or equal to 12 that are coprime with 12 are: 1, 5, 7, 11.

---

## Applications

1. **Cryptography**  
   - Used in encryption algorithms like **RSA**, where modular arithmetic is essential.

2. **Number Theory**  
   - Helps calculate the order of elements in cyclic groups.
   - Solves problems involving modular inverses and residues.

3. **Diophantine Equations**  
   - Appears in solving equations of the form ax ≡ b (mod n).

---

## Example Table

| n | Prime Factors of n | φ(n) | Numbers Coprime with n |
|---|-------------------|------|----------------------|
| 6 | 2, 3 | 6 · (1 - 1/2) · (1 - 1/3) = 2 | 1, 5 |
| 15 | 3, 5 | 15 · (1 - 1/3) · (1 - 1/5) = 8 | 1, 2, 4, 7, 8, 11, 13, 14 |
| 17 | 17 (prime) | 17 - 1 = 16 | 1, 2, 3, ..., 16 |

---

This document provides an overview of the totient function and its practical applications in number theory and cryptography.

### Problem set
- https://www.infoarena.ro/problema/fractii
 - https://www.pbinfo.ro/probleme/3227/tramvaie
 
### Ideone
- https://ideone.com/thinkphp/eulertotient

### References
- https://www.pbinfo.ro/articole/18882/indicatorul-lui-euler
- https://edu.roalgo.ro/mediu/euler-totient/#calcularea-functiei-pentru-toate-valorile-de-la-1-la-n
- https://ro.wikipedia.org/wiki/Indicatorul_lui_Euler
- https://en.wikipedia.org/wiki/Euler%27s_totient_function
