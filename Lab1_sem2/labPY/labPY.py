from Function import*

path = "Text.txt"
pathNew = "NewText.txt"

fileStr = []

choice = int(input("You want to edit or overwrite the file?\n1 - edit\n2 - owerwrite\n"))
if choice == 1:
    edit_file(path)
elif choice == 2:
    create_file(path)
else:
    print("You enter the wrong number!")
    exit(0)
fileStr = text_sort(path, fileStr)
count_sym(fileStr, pathNew)
print("New text:\n")
text_out(pathNew)

