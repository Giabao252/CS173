"""

@Authors: Ethan Tecson and Bao Luu
@Description: This program takes the textfile 'input.txt' and prints out all the words in the textfile 
              in lowercase, sorted alphabetically,and then prompts the user to enter one of the listed 
              words. Then, the program will output every sentence that contains the input word along 
              with where that sentence appears in the text file.
@Date: 2023/01/25
@Updated: 2023/01/26

"""

import string

####################################################################


def data_parsing():
    """  
    This function prompts the user to enter a textfile name and 
    then opens and reads the textfile. The textfile information
    is then assigned to the variable name 'text'

        Parameters:
            none

        Return:
            text - the textfile data unedited 
    """
    # Prompt user to enter filename to be opened and read
    file_name = input('Enter Filename: ')
    with open(file_name) as f:
        text = f.read()
    return text


# Global variable assigned so the original text is stored somewhere
text = data_parsing()

####################################################################


def word_list():
    """  
    This function will output all the words in the file 
    in lowercase and sorted alphabetically

        Parameters:
            none

        Return:
            none
    """

    # Use for loop to remove periods so there are no repetitions in list_of_words
    for word in text:
        if word == '.':
            text_without_punct = text.replace(word, " ")

    # Split, lower (so we do not have to worry about capitalization), and then sort text alphabetically
    # New variable 'text_modified' is created so we do not affect original textfile data
    text_modified = text_without_punct.lower().split()
    text_modified.sort()

    # Create empty list and append word into list without repetitions
    list_of_words = list()
    for word in text_modified:
        if word not in list_of_words:
            list_of_words.append(word)

    # Print list of words in textfile sorted alphatically without repetitions
    print('List of Words in Text: ')
    for word in list_of_words:
        print(word)

#####################################################################


def sentence_sorter():
    """  
    This function prompts the user to enter a word from the list_of_words
    which will then print every sentence the word is in along with the 
    sentence's place in the textfile based on its numberly order

        Parameters:
            none

        Return:
            none
    """

    # All the sentences will be stored in the 'sentences' variable by splitting on periods
    sentences = text.split('.')

    # A second variable 'word_check' will be created which is lowercased and split on spaces
    # so the words can be individually identified
    word_check = text.lower().split()

    # Prompt users to enter the keyword
    keyword = str(input('Enter a word: '))

    # If statement to check if the entered word is a word in the textfile
    # If not, then an error string will be printed
    if keyword not in word_check:
        print('Error: \n word is not found in textfile')

    # Otherwise the program will continue
    else:
        print(f'{keyword} appears in:')

    # Check which of the sentences have the input keyword.
    # If yes, append those to a new list
        for sentence in sentences:
            sentences_with_word = list()
            if keyword in sentence.lower():
                sentences_with_word.append(sentence)

                # How we identify which number sentence 'sentences_with_word' is
                for items in sentences_with_word:
                    for i in range(len(sentences) - 1):
                        if sentences[i] == items:
                            print(i+1, items)

#####################################################################


def main():
    """  
    This function will be the caller of all the functions to 
    bring the program together

        Parameters:
            none

        Return:
            none
    """
    word_list()
    sentence_sorter()


#####################################################################
main()
