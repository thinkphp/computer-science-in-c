Recursion
---------

### Recursive Definitions

One of the basic rules for defining new objects or concepts is that the definition should contain only such terms that
have already been defined or that are obvious. Therefore, an object which is defined in terms of itself is a serious violation
of this rule - vicious circle. On the other hand, there are many programming concepts that define themselves. As it turns out, formal
restrictions imposed on definitions such as existence and uniqueness are satisfied and no violation of the rules takes place.
Such definitions are called recursive definitions and are used primarily to define infinite sets. When define sets, it is 
innefficient. Thus, a more efficient efficient way has to be devised to determine if an object belongs to a set.

A recursive definition consists of two parts. In the first part, called the anchor or ground case, the basic elements that are
the building blocks of all elements of the set are listed. In the second part, rules are given that allow for the construction of new
objects out the basic elements or objects that have already been constructed. These rules are applied again and again to generate new objects. For
example, to construct the set of natural numbers, one basic element, 0 is singled out, and the operation of incrementing by 1 is given as:

       1. 0 belongs to N
       2. if n belongs to N, then (n + 1) belongs to N     
       3. there are no other objects in the set N
        
According to these rules, the set of natural numbers N consists of the following items: 0, 0 + 1, 0 + 1 + 1, etc 


### References

https://www.cs.princeton.edu/courses/archive/fall13/cos126/lectures/07-Recursion.pdf

https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1206/lectures/intro-to-recursion/

https://web.mit.edu/6.005/www/fa15/classes/10-recursion/

### Practice

https://www.pbinfo.ro/probleme/categorii/82/recursivitate-subprograme-recursive

https://www.pbinfo.ro/probleme/categorii/83/recursivitate-probleme-diverse

