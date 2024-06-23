OBJECTIVE:

The objective of this code is to verify if a password entered by the user satisfies the rules described above.

INPUT:

The input consists of an integer n, followed by n words that make up the dictionary of reserved words. All dictionary words are in lowercase. 
Finally, there is the password entered by the user. You can assume that 0 <= n <= 50. The password entered by the user has between 1 and 50 characters. You can assume that there are no accented characters.

OUTPUT:

The output should be 'ok' if the entered password satisfies the rules for a valid password or a subset of the messages below, describing all found errors. If more than one error message is needed, the order of output should follow the sequence below:


    The password must contain at least 8 characters.
    
    The password must contain at least one uppercase letter.
    
    The password must contain at least one lowercase letter.
    
    The password must contain at least one number.
    
    The password must contain at least one symbol.
    
    The password is a palindrome.
    
    The password must not contain reserved words.
