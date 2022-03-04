import csv
from sys import argv
from cs50 import get_string


if len(argv) != 3:
    print("Useage: python dna.py database/large.csv sequence.txt")
    exit(1)

strs = []
person = {}
csv_file = open(argv[1], "r")
reader = csv.DictReader(csv_file)
for index, row in enumerate(csv_file):
    if index != 0:
        curr_row = row.strip().split(",")
        person[curr_row[0]] = [int(x) for x in curr_row[1:]]
    if index == 0:
        strs = [strs for strs in row.strip().split(",")][1:]

with open(argv[2], "r") as txt_file:
    sample = txt_file.read()
    sample_length = len(sample)

csv_file.close()

last_strs = []
for str in strs:
    i = 0
    max_str = -1
    cur_max = 0
    while i < sample_length:
        cur_window = sample[i:len(str) + i]
        if cur_window == str:
            cur_max += 1
            max_str = max(max_str, cur_max)
            i += len(str)
        else:
            cur_max = 0
            i += 1

    last_strs.append(max_str)

for name, data in person.items():
    if data == last_strs:
        print(name)
        exit(0)

print("No match")