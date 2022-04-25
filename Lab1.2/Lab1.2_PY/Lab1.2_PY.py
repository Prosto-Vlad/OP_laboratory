from PYFileWork import*


path = "Path.txt"
SecPath = "SecondCustomers.txt"
AnotherPath = "AnotherCustomers.txt"

print("You want to edit or overwrite the file?\n1 - edit\n2 - owerwrite")
choice = int(input())
while choice < 1 or choice > 2:
    print("You enter the wrong number! Please enter 1 or 2")
    choice = int(input())
if choice == 1:
    edit_file(path)
else:
    create_file(path)
out_file_data(path)
print()

delet_old_customers(path)
print("Customers list without old customers")
out_file_data(path)
print()

make_second_customers_list(path,SecPath,AnotherPath)
print("Second customers list")
out_file_data(SecPath)
print()
print("Another customers list")
out_file_data(AnotherPath)
print()


