# Regular Expressions:

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



### Problem Set

Jabber ID https://codeforces.com/contest/21/problem/A 

* https://ideone.com/ct6Dky

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
