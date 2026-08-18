# Needleman-Wunsch-Algorithm
1.Implemented a dynamic approach towards sequence matching of DNA nucleotides outputting a matching score. 
2.The program is split across multiple c++ files.

Follow the steps to run the code:
    1. Locate the terminal to this folder by using commands like cd on linux and mac.
    2. Then run the command - g++ matrixCreation.cpp backTracking.cpp -o needlemanWunsch
    3. Then run - ./needlemanWunsch, to run this executable file
    4. Input both of your sequences and parameters which are match bonus, mismatch penalty and gap penalty.
    5. The program outputs the final score based on your sequences and parameters.
    6. (Optional) To get an idea of the inputs, refer to the Input_Examples file.


Note: 
    Need to change backTrack function inside of the file backTracking.cpp. I have not considered cases where if any two or even three of remLeft, remUP and remDiag(I have not created this variable due to it being unused eventually) have the same values. If anybody has knowledge of this biology topic and has good coding skills in c++, contact me.

Contact me:
    email: zaidbaig1111@gmail.com
