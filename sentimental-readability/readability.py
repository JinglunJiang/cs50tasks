# TODO
from cs50 import get_string


def count_letters(text):
    letter_number = 0
    for char in text:
        char = char.lower()
        if char.isalpha():
            letter_number += 1
    return letter_number


def count_words(text):
    word_number = 1
    for char in text:
        if char.isspace():
            word_number += 1
    return word_number


def count_sentences(text):
    sentence_number = 0
    for char in text:
        if char in ['.', '?', '!']:
            sentence_number += 1
    return sentence_number


def main():
    text = get_string("Text: ")
    letter_number = count_letters(text)
    word_number = count_words(text)
    sentence_number = count_sentences(text)
    index = 0.0588 * (letter_number / word_number) * 100 - 0.296 * (sentence_number / word_number) * 100 - 15.8
    index = round(index)
    if index <= 1:
        print("Before Grade 1")
    elif index < 16:
        print(f"Grade {index}")
    else:
        print("Grade 16+")


main()