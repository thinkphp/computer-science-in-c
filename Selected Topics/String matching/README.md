# String Matching

Naive string matching, also known as the brute-force string matching algorithm, is the most straightforward approach to finding a pattern within a text. Let's discuss it in more detail.


1. Basic Concept:
   The algorithm simply slides the pattern over the text one by one and checks for a match at each position.

2. Algorithm Steps:
   a. Start at the beginning of the text.
   b. Compare each character of the pattern with the corresponding character in the text.
   c. If all characters match, a pattern is found.
   d. If a mismatch is found or after a full match, slide the pattern one position to the right.
   e. Repeat until the end of the text is reached.

3. Time Complexity:
   - Worst case: O(nm), where n is the length of the text and m is the length of the pattern.
   - This occurs when there are many partial matches or when the pattern and text are similar.

4. Space Complexity:
   - O(1), as it only needs a constant amount of additional space.

5. Advantages:
   - Simple to understand and implement.
   - Works well for small texts or patterns.
   - No preprocessing required.

6. Disadvantages:
   - Inefficient for large texts or patterns.
   - Performs unnecessary comparisons, especially when there are many partial matches.

Here's a simple implementation of naive string matching in C++:

```cpp
#include <iostream>
#include <string>
#include <vector>

std::vector<int> naiveStringMatch(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            matches.push_back(i);
        }
    }

    return matches;
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    
    std::vector<int> matches = naiveStringMatch(text, pattern);
    
    if (matches.empty()) {
        std::cout << "Pattern not found in the text." << std::endl;
    } else {
        std::cout << "Pattern found at positions: ";
        for (int pos : matches) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

This implementation:
1. Iterates through each position in the text.
2. For each position, it compares the pattern with the corresponding substring in the text.
3. If a full match is found, the starting position is added to the `matches` vector.
4. Finally, it returns all positions where the pattern was found.

While naive string matching is not the most efficient for large texts or patterns, it's often sufficient for simple cases and serves as a good starting point for understanding more complex string matching algorithms.



Pentru a fi bine pregătit pentru interviurile de coding și problemele legate de **string matching**, este foarte util să înțelegi și să stăpânești algoritmii menționați (**Knuth-Morris-Pratt**, **Rabin-Karp**, **Z-Algorithm** și **Boyer-Moore**). Aceștia acoperă o gamă largă de abordări și sunt frecvent discutați în contexte academice și practice. Iată o analiză detaliată:

---

### **1. Knuth-Morris-Pratt (KMP)**
- **Ce face**: Elimină comparațiile redundante folosind un tabel de prefix (LPS - Longest Prefix Suffix) pentru a "sări" eficient peste caractere deja potrivite.
- **Relevanță pentru interviu**:  
  - Demonstrează înțelegerea optimizării față de abordarea naive.  
  - Util în probleme care necesită **găsirea unui subșablon într-un text** sau probleme avansate (e.g., cel mai lung prefix/sufix comun).  
  - Complexitate: O(n + m) timp și spațiu.

---

### **2. Rabin-Karp**
- **Ce face**: Folosește un **rolling hash** pentru a compara hash-ul subșirurilor din text cu hash-ul șablonului.
- **Relevanță pentru interviu**:  
  - Ideal pentru a discuta despre **hashing probabilistic** și aplicații precum detectarea plagiatului sau căutarea multiplă de șabloane.  
  - Permite extensii la probleme cu wildcards sau șabloane aproximative.  
  - Complexitate: O(n + m) în medie, dar O(nm) în cel mai rău caz (dacă există coliziuni).

---

### **3. Z-Algorithm**
- **Ce face**: Construiește un array `Z` care indică cel mai lung subșir începând de la fiecare poziție care coincide cu prefixul șirului.
- **Relevanță pentru interviu**:  
  - Simplifică probleme de tipul "găsește toate aparițiile unui șablon" prin concatenarea șablon + text.  
  - Folosit și pentru probleme de **periodicitate** sau **bordare** (e.g., problema celor mai lungi prefix/sufix).  
  - Complexitate: O(n + m) timp și spațiu.

---

### **4. Boyer-Moore**
- **Ce face**: Optimează căutarea comparând șablonul de la dreapta la stânga și folosind două reguli (**bad character** și **good suffix**) pentru a sări peste caractere inutile.
- **Relevanță pentru interviu**:  
  - Eficient în practică pentru texte mari (e.g., motoare de căutare).  
  - Discută compromisuri între teorie și performanță practică.  
  - Complexitate: O(nm) în cel mai rău caz, dar sub-liniar în medie.

---

### **Când sunt suficienți acești algoritmi?**
- **Interviuri**:  
  - Majoritatea problemelor de string matching nu necesită implementarea explicită a acestor algoritmi, dar a le cunoaște teoretic și a ști să explici trade-off-urile este esențial.  
  - Uneori se cer în probleme care par simple dar necesită optimizări (e.g., "găsește toate aparițiile unui șablon într-un text mare").  
- **Cazuri practice**:  
  - KMP și Z-Algorithm sunt utile pentru probleme de tipul LPS (Longest Prefix Suffix).  
  - Rabin-Karp este flexibil pentru șabloane dinamice sau multiple.  
  - Boyer-Moore este preferat în aplicații practice (e.g., `grep`).

---

### **Ce altceva ar trebui să înveți?**
- **Aho-Corasick**: Pentru căutarea **multiplelor șabloane** simultan (folosește un trie și automat finit).  
- **Suffix Trees/Arrays**: Pentru probleme avansate (e.g., cel mai lung subșir comun, repetări).  
- **Automate finite**: Pentru șabloane regulate sau matching cu wildcards.

---

### **Concluzie**
Da, este suficient să stăpânești acești algoritmi, dar asigură-te că:  
1. Înțelegi **cum funcționează** și **de ce sunt eficienți** (nu doar implementarea).  
2. Poți explica **când să folosești fiecare** (e.g., Rabin-Karp pentru multiple patterns, KMP pentru garantat timp liniar).  
3. Exersează aplicarea lor în probleme practice (e.g., [LeetCode](https://leetcode.com/tag/string-matching/)).  

Dacă poți implementa KMP sau Z-Algorithm rapid și discuta trade-off-urile față de alte metode, vei fi foarte bine pregătit!
