import pickle
from datetime import date

def edit_file(path):
    with open(path, 'ab') as writeFile:
        customers = []
        numb = int(input("How many customers you want to add? - "))
        for i in range(numb):
            cust = customer_fill()
            customers.append(cust)
            print()
        for cust in customers:
            pickle.dump(cust, writeFile)

def create_file(path):
    with open(path, 'wb') as writeFile:
        customers = []
        numb = int(input("How many customers you want to add? - "))
        for i in range(numb):
            cust = customer_fill()
            customers.append(cust)
            print()
        for cust in customers:
            pickle.dump(cust, writeFile)

def write_file_data_in_list(path):
    customers = []
    with open(path, 'rb') as readFile:
        readFile.seek(0, 2)
        end = readFile.tell()
        readFile.seek(0, 0)
        while readFile.tell() != end:
            cust = pickle.load(readFile)
            customers.append(cust)
    return customers

def out_file_data(path):
    customers = write_file_data_in_list(path)
    for cust in customers:
        customer_out(cust)

def make_second_customers_list(path, secPath, anotherPath):
    customers =  write_file_data_in_list(path)
    with open(secPath, 'wb') as writeSecFile:
        with open(anotherPath, 'wb') as writeAnotherFile:
            for cust in customers:
                if is_second_cust(cust):
                    pickle.dump(cust, writeSecFile)
                else:
                    pickle.dump(cust, writeAnotherFile)

def delet_old_customers(path):
    customers = []
    customers = list_without_old_cust(path)
    with open(path, 'wb') as writeFile:
        for cust in customers:
            pickle.dump(cust, writeFile)





def customer_fill():
    customer ={'secondname' : input("Write secondname of castomer: "),
               'lastVisit' : date_fill("last visit"),
               'nextVisit' : date_fill("next visit")}
    return customer

def date_fill(dateName):
    print("Write date of", dateName , "like dd.mm.yyyy")
    str = input()
    str = str.split('.')
    date ={'day' : int(str[0]),
           'month' : int(str[1]),
           'year' : int(str[2])}
    while date['day'] < 1 or date['day'] > 31 or date['month'] < 1 or date['month'] > 12 or date['year'] < 1:
        print("You write incorect date! Please, check your date and write again.")
        str = input("Write date of", dateName , "like dd.mm.yyyy")
        str = str.split('.')
        date['day'] = str[0]
        date['month'] = str[1]
        date['year'] = str[2]
    return date

def date_out(date):
    if date['day'] >= 1 and date['day'] < 10:
        print('0' + str(date['day']) + '.', end = '')
    else:
        print(date['day'], end = '')
    if date['month'] >= 1 and date['month'] < 10:
        print('0' + str(date['month']) + '.', end = '')
    else:
       print(date['month'], end = '')
    print(date['year'], end=' ')

def customer_out(cust):
    print(cust['secondname'], end =' '),
    date_out(cust['lastVisit'])
    date_out(cust['nextVisit'])
    print()

def list_without_old_cust(path):
    customers = []
    customers = write_file_data_in_list(path)
    i = 0
    for cust in customers:
        if is_old_cust(cust):
            customers.pop(i)
        else:
            i += 1
    return customers

def is_second_cust(cust):
    local_time = date.today()
    chek = False
    if cust['lastVisit']['month'] == local_time.month:
        if local_time.day - cust['lastVisit']['day'] <= 10:
            chek = True
    elif local_time.month - cust['lastVisit']['month'] == 1:
        if cust['lastVisit']['month'] == 2:
            if 28 - cust['lastVisit']['day'] + local_time.day <= 10:
                chek = True
        elif cust['lastVisit']['month'] == 1 or cust['lastVisit']['month'] == 3 or cust['lastVisit']['month'] == 5 or cust['lastVisit']['month'] == 7 or cust['lastVisit']['month'] == 8 or cust['lastVisit']['month'] == 10 or cust['lastVisit']['month'] == 12:
            if 31 - cust['lastVisit']['day'] + local_time.day <= 10:
                chek = True
        else:
            if 30 - cust['lastVisit']['day'] + local_time.day <= 10:
                chek = True
    return chek

def is_old_cust(cust):
    local_time = date.today()
    chek = False
    if cust['nextVisit']['year'] < local_time.year:
        chek = True
    elif cust['nextVisit']['year'] == local_time.year:
        if cust['nextVisit']['month'] < local_time.month:
            chek = True
        elif cust['nextVisit']['month'] == local_time.month:
            if cust['nextVisit']['day'] < local_time.day:
                chek = True
    return chek
