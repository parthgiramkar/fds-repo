def longest_word(s):
    words = s.split()
    longest = max(words, key=len)
    return longest

def char_frequency(s, char):
    return s.count(char)

def is_palindrome(s):
    return s == s[::-1]

def first_substring_index(s, substring):
    return s.find(substring)

def word_occurrences(s):
    words = s.split()
    word_count = {}
    for word in words:
        word_count[word] = word_count.get(word, 0) + 1
    return word_count

# Input string from the user
input_string = input("Enter a string: ")

# a) Display word with the longest length
longest = longest_word(input_string)
print(f"The word with the longest length is: {longest}")

# b) Determine frequency of occurrence of a particular character
char = input("Enter a character to check its frequency: ")
frequency = char_frequency(input_string, char)
print(f"The character '{char}' occurs {frequency} times.")

# c) Check whether the string is a palindrome
if is_palindrome(input_string):
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")

# d) Display index of first appearance of the substring
substring = input("Enter a substring to find its first appearance: ")
index = first_substring_index(input_string, substring)
if index != -1:
    print(f"The first appearance of the substring is at index: {index}")
else:
    print("The substring was not found.")

# e) Count the occurrences of each word in the string
word_count = word_occurrences(input_string)
print("Occurrences of each word in the string:")
for word, count in word_count.items():
    print(f"{word}: {count}")
