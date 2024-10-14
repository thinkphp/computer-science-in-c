# Theory of Computability and Complexity Course Outline

## Course Introduction

Welcome to the Theory of Computability and Complexity course at Oxford University. I'm [Your Name], your instructor for this term. As a [Your Position] with expertise in [Your Specific Areas of Research/Interest], I'm excited to guide you through this fascinating exploration of the fundamental limits and capabilities of computation.

## Key Definitions

Before we delve into the course content, let's establish two core concepts that will frame our studies:

1. **Computability**: Computability theory deals with the question of what can be computed. It explores the fundamental capabilities and limitations of abstract computing devices, regardless of practical constraints like time or memory. A problem is considered computable if there exists an algorithm that can solve it in a finite number of steps.

2. **Complexity**: Computational complexity theory focuses on the question of how efficiently a problem can be solved. It classifies computational problems based on their inherent difficulty and the resources (primarily time and space) required to solve them. Complexity theory helps us understand not just what is computable, but what is feasibly computable with realistic constraints.

Throughout this course, we'll explore these concepts in depth, seeing how they interrelate and inform our understanding of computation at its most fundamental level.

## Course Description
This course introduces the fundamental concepts of computability theory and computational complexity, exploring the limits of what can be computed, the nature of computation itself, and the efficiency of computational processes. Suitable for advanced undergraduate or postgraduate students at Oxford University.

## Course Objectives
By the end of this course, students will be able to:
1. Understand and apply key concepts in computability theory and computational complexity
2. Analyze and construct formal models of computation
3. Prove fundamental theorems in computability and complexity theory
4. Recognize and describe the limitations of computational models
5. Classify problems according to their computational complexity
6. Understand the relationships between different complexity classes

## Prerequisites
- Discrete Mathematics
- Introduction to Algorithms
- Basic knowledge of formal logic

## Weekly Topics

### Week 1: Introduction to Computability Theory
- Historical context and motivation
- Informal notion of algorithms
- Introduction to formal models of computation

### Week 2-3: Turing Machines
- Definition and examples
- Programming techniques for Turing machines
- Variants of Turing machines
- The Church-Turing thesis

### Week 4: Decidability
- Decidable languages
- The halting problem
- Reduction technique

### Week 5: Turing Reducibility and Computability
- Oracle Turing machines
- Turing reducibility
- Computable functions

### Week 6: Recursively Enumerable Languages
- Definition and properties
- Relationship to decidable languages
- Rice's theorem

### Week 7: Introduction to Computational Complexity
- Motivation and importance of efficiency in computation
- Time complexity
  - Big O notation
  - Time complexity classes (P, NP, EXP)
- Space complexity
  - Space complexity classes (L, PSPACE)

### Week 8: Complexity Classes and Problem Types
- Detailed exploration of complexity classes:
  - P: Problems solvable in polynomial time
  - NP: Problems verifiable in polynomial time
  - NP-hard: Problems at least as hard as NP problems
  - NP-complete: Problems that are both NP and NP-hard
  - PSPACE: Problems solvable using polynomial space
  - EXP: Problems solvable in exponential time
- Relationships between classes (e.g., P ⊆ NP ⊆ PSPACE ⊆ EXP)
- Examples of problems in each class
- Introduction to the P vs NP problem

### Week 9: NP-Completeness and Reductions
- Formal definition of NP-completeness
- Cook-Levin theorem and the significance of SAT
- Reduction techniques for proving NP-completeness
- Examples of NP-complete problems:
  - Boolean Satisfiability (SAT)
  - Traveling Salesman Problem
  - Graph Coloring
  - Subset Sum
- Coping with NP-hardness: approximation algorithms and heuristics

### Week 10: Advanced Topics in Complexity and Computability
- Beyond NP: Introduction to the polynomial hierarchy
- Probabilistic complexity classes (e.g., BPP, RP, ZPP)
- Brief introduction to quantum complexity classes (e.g., BQP)
- Average-case complexity
- Parameterized complexity
- Recursion theorem
- Undecidability in logic (Gödel's incompleteness theorems)
- Connections between computability and complexity theory
- Open problems in the field

## Assessment
- Weekly problem sets (25%)
- Midterm exam (25%)
- Final project (20%)
- Final exam (30%)

## Recommended Textbooks
1. Sipser, M. (2012). Introduction to the Theory of Computation. Cengage Learning.
2. Arora, S., & Barak, B. (2009). Computational Complexity: A Modern Approach. Cambridge University Press.
3. Hopcroft, J. E., Motwani, R., & Ullman, J. D. (2006). Introduction to Automata Theory, Languages, and Computation. Pearson.
4. Cooper, S. B. (2003). Computability Theory. Chapman and Hall/CRC.

## Additional Resources
- Complexity Zoo: An online wiki cataloging complexity classes
- Research papers from leading conferences (STOC, FOCS, ICALP)
- Online lectures from Coursera, edX, or MIT OpenCourseWare on advanced topics
- Garey, M. R., & Johnson, D. S. (1979). Computers and Intractability: A Guide to the Theory of NP-Completeness. W. H. Freeman.
# ___________________-

# Teoria Complexității

## Descrierea cursului
Acest curs se concentrează pe teoria complexității algoritmilor, explorând modul în care sunt evaluați și clasificați algoritmii în funcție de utilizarea resurselor, cum ar fi timpul și spațiul. Studenții vor învăța concepte fundamentale în analiza algoritmilor și vor explora aplicații practice ale teoriei complexității.

## Obiectivele Cursului
- Înțelegerea conceptelor fundamentale ale complexității algoritmilor.
- Analizarea algoritmilor din perspectiva complexității de timp și spațiu.
- Distincția între clasele de complexitate, cum ar fi P, NP și NP-complete.
- Examinarea subiectelor avansate, inclusiv algoritmii de aproximare și algoritmii randomizați.

## Structura Cursului

### Modulul 1: Introducere în Teoria Complexității
1. Importanța teoriei complexității în informatică
2. Definiții și concepte de bază
3. Notarea Big O și analiză asimptotică
4. Relația dintre computabilitate și complexitate

### Modulul 2: Analiza Eficienței Algoritmilor
1. Complexitatea de timp și spațiu
2. Cazuri: cel mai bun, mediu și cel mai rău
3. Compromisuri și optimizări
4. Tehnici de analiză pentru algoritmi recursivi și iterativi

### Modulul 3: Clasele de Complexitate
1. Clasele P, NP, NP-complete și NP-hard
2. Reduceri și completitudine
3. Problema P vs. NP
4. Implicații practice ale NP-completitudinii

### Modulul 4: Complexitate Avansată
1. PSPACE, EXPTIME și alte clase de complexitate
2. Ierarhii ale claselor de complexitate
3. Relații între clase
4. Teorema Cook-Levin și implicațiile sale

### Modulul 5: Algoritmi de Aproximare și Heuristici
1. Algoritmi pentru probleme intractabile
2. Raționamente de aproximare
3. Studii de caz: Problema călătorului vânzător, problema rucsacului
4. Tehnici de proiectare pentru algoritmi de aproximare

### Modulul 6: Algoritmi Randomizați și Paraleli
1. Introducerea algoritmilor probabilistici
2. Complexitatea în computația paralelă
3. Algoritmi Monte Carlo și Las Vegas
4. Clasa BPP și relația sa cu P și NP

### Modulul 7: Aplicații ale Teoriei Complexității
1. Rezolvarea problemelor din lumea reală
2. Criptografie și securitate
3. Perspective asupra calculului cuantic
4. Implicații în inteligența artificială și machine learning

## Metode de Evaluare
1. Teme săptămânale cu exerciții teoretice și demonstrații
2. Examen parțial focalizat pe analiza complexității
3. Proiect final: studenții aleg o lucrare de cercetare recentă în teoria complexității pentru a o prezenta și analiza critic
4. Examen final acoperind întregul material al cursului

## Resurse Recomandate
1. Sipser, M. "Introduction to the Theory of Computation"
2. Arora, S. și Barak, B. "Computational Complexity: A Modern Approach"
3. Papadimitriou, C. H. "Computational Complexity"
4. Articole de cercetare din conferințe recente STOC, FOCS și ICALP
5. Cursuri online de pe platforme precum Coursera și MIT OpenCourseWare
6. Website-ul Complexity Zoo pentru explorarea claselor de complexitate

### Books
- "Introduction to Algorithms" de Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest și Clifford Stein

- "Introduction to the Theory of Computation" de Michael Sipser
- "Algorithm Design" de Jon Kleinberg și Éva Tardos
- "The Design and Analysis of Algorithms" de Dexter C. Kozen
- "The Nature of Computation" de Cristopher Moore și Stephan Mertens
- "Introduction to the theory of complexity" Daniel Pierre Bovet Pierluigi Crescenzi

### References:
https://math.mit.edu/~sipser/

https://plato.stanford.edu/entries/computability/
