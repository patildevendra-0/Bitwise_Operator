To run this application, you need:

            A C compiler (e.g., GCC) installed on your system.
            A text file (in this case, a .txt file) containing the input data.

Overview

            This program reads a text file and counts the number of small letters (lowercase), capital letters (uppercase), and digits present in the file using three separate threads. The main goal is to demonstrate the use of multithreading to efficiently count different character types in a file

Code Structure

        Functions
                    ThreadProc1(void *ptr): This function is executed by the first thread. It counts the small letters (lowercase) in the file.

                    ThreadProc2(void *ptr): This function is executed by the second thread. It counts the capital letters (uppercase) in the file.

                    ThreadProc3(void *ptr): This function is executed by the third thread. It counts the digits in the file.

                    Mutex locks (lock1, lock2, and lock3) for thread safety.

        Main Function
                    main(int argc, char *argv[]): The main function is responsible for handling program arguments, opening the file, creating three threads, and managing their execution. It also retrieves and prints the results after thread execution.
Usage

                    Compile the code using a C compiler (e.g., gcc Application_1.c -o myexe).
                    Run the compiled program with a text file as an argument (e.g., ./myexe Demo.txt).

                    The program will count small letters, capital letters, and digits in the specified file and print the results.

Sample Output
                    The program will produce output in the following format:

                    SMALL LETTER COUNT FROM FILE - demo.txt IS : X
                    CAPITAL LETTER COUNT FROM FILE - demo.txt IS : Y
                    DIGITS COUNT FROM FILE - demo.txt IS : Z
                                            X is the count of small letters (lowercase) in the file.
                                            Y is the count of capital letters (uppercase) in the file.
                                            Z is the count of digits in the file.

Error Handling
                    The program includes error handling for various scenarios, such as insufficient arguments, the inability to open a file, thread creation failures, and thread join errors. It prints error messages when such situations occur.for that perror lib. function is use

Closing Files
                    The program closes the file descriptors after thread execution to release system resources.
                    And destroy the mutex lock at the end to release system resources.

