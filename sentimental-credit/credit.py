# TODO

def card_validity(n):
    sum = 0
    is_second = False
    while n > 0:
        digit = n % 10
        if is_second:
            digit = digit * 2
            if digit > 9:
                digit = (digit // 10) + (digit % 10)
        sum = sum + digit
        is_second = not is_second
        n = n // 10
    return sum % 10 == 0


def main():
    n = int(input("Number: "))
    num = len(str(n))
    if num == 15:
        first_two_digits = n // 10000000000000
        if first_two_digits == 34 or first_two_digits == 37:
            if card_validity(n):
                print("AMEX")
            else:
                print("INVALID")
        else:
            print("INVALID")
    elif num == 13:
        first_digit = n // 1000000000000
        if first_digit == 4:
            if card_validity(n):
                print("VISA")
            else:
                print("INVALID")
        else:
            print("INVALID")
    elif num == 16:
        first_digit = n // 1000000000000000
        first_two_digits = n // 100000000000000
        if first_digit == 4:
            if card_validity(n):
                print("VISA")
            else:
                print("INVALID")
        elif first_two_digits == 51 or first_two_digits == 52 or first_two_digits == 53 or first_two_digits == 54 or first_two_digits == 55:
            if card_validity(n):
                print("MASTERCARD")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()