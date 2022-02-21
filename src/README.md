Project 1: Tokenizer
====================
# Objective

My objective for the first lab project is to build a tokenizer that maintains a history. Tokenizing is the process of dividing a string into tokens by some delimeter. My tokenizer should maintain a history. A user should be able to view and recall a certain history item by using a command similar to ’!2’. This would then use the string whatever is in position 2 as input and tokenize.

# Challenges

The first to that I had to do was creating a UI that would echo whatever the user wirites in the terminal. For this I used a while loop. I saved the first character of the input in a variable called 'c', then printed charcater by character until it reached the End Of File. This while loop was inside an infinite while loop so they could type as many phrases as they wanted. 

The second milestone of my project was to define several of the functions declared and described (but not defined) in tokenizer.h:

1. int space_char(char c); // true if c is a tab or space, and not zero <br/>Here all I did was make an if statement that returns 1 if a character is a space, ' ', or a tab, '\t', 0 otherwise.
    
2. int non_space_char(char c); // true if c not a tab or space, and not zero <br/>Here all I did was make an if statement that returns 1 if a character is NOT a space, ' ', and NOT a tab, '\t', 0 otherwise.

3. char *word_start(char *s); // * to first (non-space) char in first word in s <br/>I tackled this challenge by creating a while loop that moves the pointer of a string to the first non-sopace character of the string. Then returns the pointer at the new position.

4. `char *word_terminator(char *word); // * to char after end of word <br/>This one is also a while loop but doing the opposite. Is going to move the string pointer to the first space character and then return the new end of the word.

5. int count_words(char *s); // the number of words in s <br/>On this one I first started with moving the pointer to the start of the string. Then, I did a while loop, where if the end or start of a new word is not '\0' add 1 to a count variable. After getting at the end of the string we return the number of words.

6. char *copy_str(char *inStr, short len); // return a pointer to a (terminated) copy of inStr <br/>For this one I first had to allocate the memeory for the word I am going to copy, so I saved it in a new char pointer. Then in a for loop, I copy whatever is in the *inStr pointer into the new variable pointer. Then we move both pointers to the next address, until we reach the length of the string. At the end I added a '\0' to the end of the string and returned the string copy.

