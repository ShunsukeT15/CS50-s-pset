from cs50 import get_string


def main():
    text = get_string("Text: ")
    count_letters = 0
    count_sentences = 0
    count_words = 1

    for x in text:
        if letter_end(x):
            count_letters += 1
        if sentence_end(x):
            count_sentences += 1
        if word_end(x):
            count_words += 1

    L = 100 * count_letters / count_words
    S = 100 * count_sentences / count_words
    index = (0.0588 * L) - (0.296 * S) - 15.8

    index = round(index)

    l = count_letters
    s = count_sentences
    w = count_words

    print("L={}, S={}".format(L, S))
    print("letters={},sentences={},words={}".format(l, s, w))

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Grade {}" .format(index))


def letter_end(x):
    return x.isalpha()


def sentence_end(x):
    scounter = 0
    if x == "." or x == "!" or x == "?":
        scounter += 1
    return scounter


def word_end(x):
    wcounter = 0
    if x == " ":
        wcounter += 1
    return wcounter


main()