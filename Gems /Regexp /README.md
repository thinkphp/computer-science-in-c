# Regular Expressions:

Expresiile regulate în C++ sunt disponibile începând cu C++11 prin biblioteca `<regex>`. Iată elementele fundamentale:

```cpp
#include <regex>
#include <string>
#include <iostream>

int main() {
    // Declararea unui regex
    std::regex pattern("text|pattern");
    
    // Verificarea potrivirii unui string
    std::string text = "Acesta este un text de test";
    if(std::regex_search(text, pattern)) {
        std::cout << "Pattern-ul a fost găsit!\n";
    }
}
```

Operatori de bază în regex:
1. `.` - potrivește orice caracter individual
2. `^` - începutul stringului 
3. `$` - sfârșitul stringului
4. `*` - 0 sau mai multe apariții
5. `+` - 1 sau mai multe apariții
6. `?` - 0 sau 1 apariție
7. `[abc]` - potrivește oricare dintre caracterele din paranteze
8. `[^abc]` - potrivește orice caracter în afară de cele din paranteze

Iată un exemplu mai complex:

```cpp
#include <regex>
#include <string>
#include <iostream>

int main() {
    // Pattern pentru email
    std::regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    
    std::string email = "test@example.com";
    
    if(std::regex_match(email, email_pattern)) {
        std::cout << "Email valid!\n";
    }
    
    // Găsirea și înlocuirea textului
    std::string text = "Contactați-mă la email@example.com sau alt.email@domain.ro";
    std::string result = std::regex_replace(text, email_pattern, "[EMAIL]");
    
    std::cout << "Text modificat: " << result << "\n";
    
    // Iterarea prin toate potrivirile
    std::sregex_iterator it(text.begin(), text.end(), email_pattern);
    std::sregex_iterator end;
    
    while(it != end) {
        std::cout << "Email găsit: " << it->str() << "\n";
        ++it;
    }
}
```

Funcții importante pentru lucrul cu regex:
- `regex_match()` - verifică dacă întregul string se potrivește cu pattern-ul
- `regex_search()` - caută o potrivire în string
- `regex_replace()` - înlocuiește potrivirile găsite
- `sregex_iterator` - iterează prin toate potrivirile

Sfaturi pentru utilizare:
1. Folosiți raw string literals (R"()") pentru pattern-uri complexe pentru a evita escape-ul caracterelor
2. Tratați excepțiile `regex_error` care pot apărea la compilarea pattern-urilor invalide
3. Testați pattern-urile pe cazuri limită
4. Aveți grijă la performanță - operațiile regex pot fi costisitoare pentru pattern-uri complexe

Prima expresie: `[A-Za-z0-9_]{1,16}@[A-Za-z0-9_.]{1,32}(/[A-Za-z0-9_]{1,16})?`

Aceasta se împarte în:
1. `[A-Za-z0-9_]{1,16}` - Prima parte (înainte de @):
   - Permite litere mari și mici, cifre și underscore
   - Trebuie să aibă între 1 și 16 caractere
   
2. `@` - Simbolul @ obligatoriu

3. `[A-Za-z0-9_.]{1,32}` - A doua parte (după @):
   - Permite litere, cifre, underscore și punct
   - Trebuie să aibă între 1 și 32 caractere

4. `(/[A-Za-z0-9_]{1,16})?` - Partea opțională finală:
   - Începe cu /
   - Urmată de 1-16 caractere alfanumerice sau underscore
   - `?` face întreaga secțiune opțională

A doua expresie: `[A-Za-z0-9_]{1,16}@[A-Za-z0-9_]{1,16}(.[A-Za-z0-9_]{1,16})*(/[A-Za-z0-9_]{1,16})?`

Diferențele principale:
1. Prima parte este identică

2. După @ structura este diferită:
   - `[A-Za-z0-9_]{1,16}` - Prima secțiune permite doar caractere alfanumerice și underscore
   - `(.[A-Za-z0-9_]{1,16})*` - Permite multiple subdomenii separate prin punct
     - Fiecare subdomeniu poate avea 1-16 caractere
     - `*` permite 0 sau mai multe astfel de subdomenii

3. Partea finală cu "/" este identică cu prima expresie

Exemple valide pentru prima expresie:
```
user@domain.com
user123@subdomain.domain.com/path
```

Exemple valide pentru a doua expresie:
```
user@domain.com
user@domain.subdomain.com
user@domain/path
```

Principala diferență este că a doua expresie:
- Este mai strictă în structura domeniului
- Permite explicit multiple subdomenii
- Tratează punctele ca separatori expliciti între părțile domeniului

Prima expresie este mai permisivă cu poziționarea punctelor în partea de domeniu, în timp ce a doua este mai structurată dar poate fi mai restrictivă.


```
// C++ program to demonstrate working of regex_match()
#include <iostream>
#include <regex>
 
using namespace std;
int main()
{
	string a = "GeeksForGeeks";
 
	// Here b is an object of regex (regular expression)
	regex b("(Geek)(.*)"); // Geek followed by any character
 
	// regex_match function matches string a against regex b
	if ( regex_match(a, b) )
		cout << "String 'a' matches regular expression 'b' \n";
 
	// regex_match function for matching a range in string 
	// against regex b
	if ( regex_match(a.begin(), a.end(), b) )
		cout << "String 'a' matches with regular expression "
				"'b' in the range from 0 to string end\n";
 
	return 0;
}
 
```

### Problem Set

 - Jabber ID https://codeforces.com/contest/21/problem/A  https://ideone.com/ct6Dky
