import csv
from sys import argv
from cs50 import get_string



if len(argv) != 3:
    print("Useage: python dna.py database/large.csv sequence.txt")
    exit(1)

csv_file = open(argv[1],"r")
reader = csv.DictReader(csv_file)
strs = reader.fieldnames[1:]

stands = []
persons = {}
for ind,row in reader:
    if ind == 0:
        strand = [strand for strand in row.strip().split(",")][1:]
    else:
        curr_row = row.strip().split(",")
        persons[curr_row[0]] = [line(x) for x in curr_row[1:]]


with open(argv[2],"r") as txt_file:
     sample = txt_file.read()
     print(len(sample))


print(strand)
print(persons)