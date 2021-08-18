def readPoly():
    return([1,2,3,4], 3)
 
def writePoly(coef, degree):
    print(f"P(x) = {coef[0]}x^0", end = "")
    for i in range(1, degree + 1):
        print(f" + {coef[i]}x^{i}", end = "")
    print()
 
def valuePoly(coef, degree, x):
    aux = 1
    value = coef[0]
    for i in range(1, degree+1):
        aux *= x
        value += aux * coef[i]
    return value
 
def derivatePoly(coef, degree):
    for i in range(0, degree):
        coef[i] = coef[i+1] * (i + 1)
    degree -= 1
    return [coef,degree]
 
def main():
    coef, degree = readPoly()
    writePoly(coef, degree)
    coef, degree = derivatePoly(coef, degree)
    writePoly(coef, degree)
    x = float(input("x = "))
    print(f"P'({x}) = ", valuePoly(coef, degree, x))
main()
