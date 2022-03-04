from cs50 import get_string

number = get_string("Number: ")

reverse_number = number[::-1]
even = reverse_number[::2]
odd = reverse_number[1::2]

sum_do = 0
for c in odd:
    do = int(c) * 2  # double_c = do
    a = int((do / 10) + (do % 10))
    sum_do += a

sum_even = 0
for c in even:
    sum_even += int(c)

total_sum = int(sum_do + sum_even)
print(number[0])

if total_sum % 10 == 0:
    if (len(number) == 15 and (number[:2] in ["34", "37"])):
        print("AMEX")
    elif (len(number) == 16 and number[:2] in ["51", "52", "53", "54", "55"]):
        print("MASTERCARD")
    elif ((len(number) == 13 or len(number) == 16) and number[0] in ["4"]):
        print("VISA")
    else:
        print("INVALID")

else:
    print("INVALID")

