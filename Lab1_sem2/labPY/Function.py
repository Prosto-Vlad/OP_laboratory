def count_sym(fileStr, pathNew):
    file = open(pathNew, 'w')
    for i in range(len(fileStr)):
        line = fileStr[i] + ' - ' + str(len(fileStr[i]) - fileStr[i].count(' ')) + '\n'
        file.write(line)
    file.close()

def edit_file(path):
    file = open(path, 'a')
    text_out(path)
    print("Write the new strings. To finish enter ctrl+x")
    while(1):
        line = input()
        if(ord(line[0]) == 24):
            break
        file.write(line + "\n")
    file.close()

def text_sort(path, fileStr):
    file = open(path, 'r')
    fileStr = file.read().split('\n')
    fileStr = list(filter(None, fileStr))

    temp = ""
    for i in range(len(fileStr) - 1):
        for j in range(len(fileStr) - 1):
            if (len(fileStr[j]) - fileStr[j].count(' ') > len(fileStr[j+1]) - fileStr[j+1].count(' ')):
                temp = fileStr[j]
                fileStr[j] = fileStr[j+1]
                fileStr[j+1] = temp

    file.close()
    return fileStr

def create_file(path):
    file = open(path, 'w')
    print("Write the text. To finish enter ctrl+x")
    while(1):
        line = input()
        if(ord(line[0]) == 24):
            break
        file.write(line + "\n")
    file.close()

def text_out(path):
    file = open(path, 'r')
    for line in file:
        print(line)
    file.close()
