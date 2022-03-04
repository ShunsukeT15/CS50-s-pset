import csv
from sys import argv
from cs50 import get_string


if len(argv) != 3:
    print("Useage: python dna.py database/large.csv sequence.txt")
    exit(1)

strands = []
with open(argv[1],"r") as csv_file:
    reader = csv.DictReader(csv_file)
    strs = reader.fieldnames[1:]
    refc = [row for row in reader]
    for row in reader:
        print(row)

with open(argv[2],"r") as txt_file:
     sample = txt_file.read()
     sample_length = len(sample)


print(strs.strip(","))
print(f"ref_csv={refc}")
print(f"strs={strs}")
print(f"stcount={stcount}")

count = {k:0 for k in refc[0][1::]}

for key in count.keys():
    local_count = 0
    i = 0
    while i < len(sample):
        step = 1
        flag = False
        repeat_end = i + len(key)
        if repeat_end < len(sample) and key == sample[i:repeat_end]:
            local_count += 1
            step = len(key)
        elif local_count > count[key]:
            count[key] = local_count
            local_count = 0
        i += step

max_count =[str(v) for _, v in count.items()]

for r in ref[1::]:
    if r[1::] == max_count:
        print(row[0])
        break
    elif r == ref[-1]:
        print("No match")
