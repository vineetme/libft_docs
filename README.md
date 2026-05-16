_This project has been created as part of the 42 curriculum by vmeharia._

## **DESCRIPTION**

Create a C functions library from scratch, containing 43 functions for manipulating strings, memory and lists as follows:

  - libc fubctions: reimplement 23 functions from libc (with their prototypes and behaviour exactly as defined in man page).
  
  - Additional functions: develop 11 functions that are either not in libc or behave a little differently from the standard function.
  
  - Linked list: Set of 9 functions for list manipulation.

## **INSTRUCTIONS**

  ### **Standards and Rules**
  
    - The Norm: Code must strictly comply with the Norm; any norm error (even in bonus files) will result in a grade of 0.  

    - No Global Variables: Declaring global variables is strictly forbidden.  

    - Function Scope: Helper functions must be defined as static to restrict their scope to the appropriate file.  

    - Naming Convention: All recreated standard functions must be prefixed with ft_ (e.g., strlen becomes ft_strlen).  

    - Forbidden Keywords: Cannot use "restrict" keyword in prototypes or compile with the -std=c99 flag.

  ### **Memory Management & Stability**
    
    - No Crashes: Functions must not quit unexpectedly due to segmentation faults, bus errors, or double frees (except for undefined behavior). If this occurs, the project receives a 0. 
  
    - No Leaks: All heap-allocated memory must be properly freed; memory leaks will not be tolerated.

  ### **Compilation & Library Creation**
  
    - Compiler and Flags: Every .c file must be compiled using cc with the strict flags -Wall, -Wextra, and -Werror.
  
    - Makefile Rules: Makefile must at least contain the rules $(NAME), all, clean, fclean, and re.  

    - No Relinking: Makefile must not perform any relinking.  

    - Archive Creation: Must use the ar command to create the library (libft.a); using libtool is forbidden.  

  ### **Submission Structure**
  
    - File Location: All project files, including libft.a, must be placed at the root of your Git repository.  
    
    - Unused Files: Submitting unused files is not allowed.  
  
    - README Requirements: You must provide a README.md at the root of your repository containing specific italicized introductory text, a description, setup instructions, a resources section (detailing AI usage), and a detailed description of the library.

  ### **Special Note**

   For the character classification functions (isalpha, isdigit, isalnum, isascii, isprint)the return value must be:
   - 1 if the character matches the tested class
   - 0 if the character does not match
   - For ’calloc’ function: If nmemb or size is 0, then calloc() returns a unique pointer value that can be successfully passed to free().

## **RESOURCES**
    - External tester I made use of for cross checking https://github.com/Sfabi28/libft_tester
    - AI was used to learn concepts, go deeper into some topics, ask questions and test my knowledge, not to write code
    - Made use of many many resources, too many to write. Will update later.
