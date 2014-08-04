#
# A dead simple python that generates a file.out with randomly integers between -1024 and +1024 without duplicates.
# I use it when sorting something in c++
#
# Usage:
#
# python genvec 10
#
# ->[9,8,7,6,5,4,3,2,1,0]
#

from random import randint
import sys

def pick( n ):

    #an array of integers pick up arbirtarily
    taken = []

    #for each i in range 0...n execute
    for i in range(0, n):

        #get a random integer.
        num = randint(-1024,1024)

        #check whether the random number is taken or not.
        while num in taken: 

              #if taken get another one
              num = randint(-1024,1024)

        #append to the taken list
        taken.append(num)

    #finally return the taken list
    return taken

def writeToFile( n ):

    #get a handler for this file
    f = open('file.in','w')
  
    #get the numbers
    randoms = pick(n)

    #write them into the file.out
    f.write("{}\n".format(n)) 

    for i in range(0, n):

        f.write(str(randoms[i])+" ")
 
    #close the connection with the output file
    f.close()

    #display on screen
    print randoms 

if __name__ == "__main__":

     if len(sys.argv) != 2:

        print"Usage: python gen 17"

        sys.exit()  

     n = int(sys.argv[1])  
 
     writeToFile( n )
