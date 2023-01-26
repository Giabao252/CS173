import string


def data_parsing():
    # Prompt user to enter filename and filename will be read
    file_name = input('Enter Filename: ')
    with open(file_name) as f:
        text = f.read()
    return text


text = data_parsing()


# this function will output all the words in the file in lowercase, sorted alphabetically
def word_list():

    # Use for loop to remove periods so there are no repetitions in list_of_words
    for word in text:
        if word == '.':
            text_without_punct = text.replace(word, " ")

    # Split, lower, and then sort text alphabetically
    text_modified = text_without_punct.lower().split()
    text_modified.sort()

    # Create empty list and append word into list without repetitions
    list_of_words = list()
    for word in text_modified:
        if word not in list_of_words:
            list_of_words.append(word)
    print('List of Words in Text: ')
    for word in list_of_words:
        print(word)


# this sentence will
def sentence_sorter():

    # prompt users to enter the keyword
    keyword = str(input('Enter a word: '))

    # all the sentences will be stored in the SENTENCES list using the split method
    sentences = text.split('.')
    
    print(f'{keyword} appears in:')

    # check which if the sentences have the input keyword.
    # if yes, append those to a new list

    for sentence in sentences:
        sentences_with_word = list()
        if keyword in sentence.lower():
            sentences_with_word.append(sentence)
            for items in sentences_with_word:
                for i in range(len(sentences) - 1):
                    if sentences[i] == items:
                        print(i+1, items)


# main() function will be a caller of all the function we need so we don't have to call them separately
def main():
    word_list()
    sentence_sorter()


# function caller
main()
