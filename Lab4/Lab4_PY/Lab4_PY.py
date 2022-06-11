from Function import*

m = int(input("Enter size of int array - "))
n = int(input("Enter size of real array - "))

arr1 = makeIntVec(m)
arr2 = makeRealVec(n)

print("Intenger array")
printVec(arr1)
print("Real array")
printVec(arr2)

print("Sum of first intenger = ", findFirstNumSum(arr1))
print("Sum of last real = ", findLastNumSum(arr2))