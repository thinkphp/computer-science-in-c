#
# 8 = 0000 0000 0000 0000 0000 0000 0000 1000
#
# 1 = 0000 0000 0000 0000 0000 0000 0000 0001
#     0000 0000 0000 0000 0000 0000 0000 1000

def main():

    n = 21

    counter = 0

    mask = 1

    for i in range( 0, 32 ):

        if n & (mask<<i):

            counter +=1

    print("Numarul de biti de 1 din reprezentarea interna in cod binar a numarului =", counter)

#main()


def interchimbare():


    a = 8

    b = 5

    print("a = ", a)

    print("b = ", b)

    sau_exclusiv = a ^ b

    a = sau_exclusiv ^ a

    b = sau_exclusiv ^ b

    print("==="*10)

    print("a = ",a)

    print("b = ",b)

    #8 = 0000 1000
    #5 = 0000 0101
  #XOR = 0000 1101
  #      0000 1000
  #      0000 0101 (5)
  #XOR = 0000 1101
  #      0000 0101
  #      0000 1000 (8)

#interchimbare()


def doi_la_putere_n():

    n = 5

    ans = 1

    ans = ans << n

    print(ans)
    # 2^5 =>
    #0000 0001
    #0000 0000

#doi_la_putere_n()


def par_impar():

    #citim numarul N
    n = int(input("N = "))

    #am creat o lista vida
    lista = []

    #am iterat de la 1 la n
    for i in range(1, n + 1):

        #citim un numar natural
        x = int(input("elem="))

        #il adaugam in lista
        lista.append( x )

    #afisez lista noastra creata
    #print(lista)

    mask = 1

    #afisam 1 sau 0 in functie paritatea numarului
    for i in range(0, n):

        if lista[i] & mask:

            print("1", end = " ")

        else:
            
            print("0", end = " ")

par_impar()
