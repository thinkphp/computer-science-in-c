class Point:
    def __init__(self,x,y):
        self.x = float(x)
        self.y = float(y)
 
class Circle:
    def __init__(self, x, y, R):
        self.O = Point(x,y)
        self.R = float(R)
 
def sqrt(n):
 
    x = n
    y = 1.0
    e = 0.00001
    while x-y>e:
        x = (x + y) / 2
        y = n / x
    return x
 
def sqr(x):
    return x*x
 
def computeDistance(p,p1):
    return sqrt(sqr(p1.x-p.x) + sqr(p1.y-p.y))
 
def belongTo(circle, point):
    if computeDistance(circle.O, point) < circle.R:
        return True
    else:
        return False
 
 
def main():
    n = int(input("Introduceti numarul de cercuri N = "))
    C = []
    print("Introduceti cercurile: ")
    for i in range(1, n+1):
        print("Circle#%d"%i)
        x = float(input("x="))
        y = float(input("y="))
        r = float(input("R="))
        circle = Circle(x,y,r)
        C.append(circle)
 
    for i in C:
        print(i.O.x, i.O.y,i.R)
    print("Introduceti punctul P(x,y)")
    x = float(input("x="))
    y = float(input("y="))
    P = Point(x,y)
 
    for i in range(0, n):
        if belongTo(C[i], P) is True:
           print("The Point(%.3f,%.3f) Belongs To Circle#%d(%.3f,%.3f,%.3f)"%(P.x, P.y, i+1,C[i].O.x, C[i].O.y,C[i].R))
main()
