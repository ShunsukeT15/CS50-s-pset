from cs50 import get_float

while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        coins = [25, 10, 5, 1]
        cents = round(dollars * 100)

        counter = 0

        for i in coins:
            counter += int(cents / i)
            cents = cents % i

        print(counter)
        break