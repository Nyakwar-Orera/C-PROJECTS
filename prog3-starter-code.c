#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int numberOfPossiblePuzzles);

int main() {
    // seed the random number generator
    //srand(1);
    srand(time(0));

    char difficultyLevel = 'E';
    int numberOfPossiblePuzzles = 0;
    char fileName[20];
    int numbers[4];
    int num1, num2, num3, num4;
    char op1, op2, op3;


    printf("Welcome to the game of TwentyFour Part Two!\n");
    printf("Use each of the four numbers shown exactly once,\n");
    printf("combining them somehow with the basic mathematical operators (+-)\n");
    printf("to yield the value twenty-four.\n");

    do {
        int choice;
        // ask the user to choose a difficulty level
        printf("Choose your difficulty level: E for easy, M for medium, and H for hard (default is easy).\n");
        printf("Your choice --> ");
        scanf(" %c", &difficultyLevel);

        // set the number of possible puzzles based on the difficulty level
        if (difficultyLevel == 'E') {
            numberOfPossiblePuzzles = 5;
            sprintf(fileName, "easy.txt");
        } else if (difficultyLevel == 'M') {
            numberOfPossiblePuzzles = 10;
            sprintf(fileName, "medium.txt");
        } else if (difficultyLevel == 'H') {
            numberOfPossiblePuzzles = 15;
            sprintf(fileName, "hard.txt");
        } else {
            numberOfPossiblePuzzles = 5;
            sprintf(fileName, "easy.txt");
        }

        // open the file containing the puzzles
        FILE *file = fopen(fileName, "r");

        if (!file) {
            printf("Error opening file %s\n", fileName);
            return 1;
        }

        // choose a random puzzle from the file
        int chosenPuzzleIndex = getRandomNumber(numberOfPossiblePuzzles);
        int puzzleIndex = 0;
        while (puzzleIndex < chosenPuzzleIndex) {
            int numbersRead = fscanf(file, "%d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3]);
            if (numbersRead != 4) {
                printf("Error reading numbers from file %s\n", fileName);
                fclose(file);
                return 1;
            }
            ++puzzleIndex;
        }

        // read the numbers for the chosen puzzle
        int numbersRead = fscanf(file, "%d %d %d %d", &num1, &num2, &num3, &num4);
        if (numbersRead != 4) {
            printf("Error reading numbers from file %s\n", fileName);
            fclose(file);
            return 1;
        }

        // close the file
        fclose(file);

        // print the numbers for the chosen puzzle
        printf("The numbers to use are: %d, %d, %d, %d.\n", num1, num2, num3, num4);
        // Read in the operators
    char op1, op2, op3;
    //printf("Enter 3 operators (+,-,*, or /): ");
    //scanf(" %c %c %c", &op1, &op2, &op3);
    //Enter your solution
    printf("Enter your solution: ");
    scanf(" %d %c %d %c %d %c %d", &num1, &op1, &num2, &op2, &num3, &op3, &num4);

    // Check the number of operators
    if (op3 == '\n') {
        printf("Error! The number of operators is incorrect. Please try again.\n");
        continue;
    }

    // Check if the operators are valid
    if (op1 != '+' && op1 != '-' && op1 != '*' && op1 != '/') {
        printf("Error! Invalid operator entered. Please try again.\n");
        continue;
    }
    if (op2 != '+' && op2 != '-' && op2 != '*' && op2 != '/') {
        printf("Error! Invalid operator entered. Please try again.\n");
        continue;
    }
    if (op3 != '+' && op3 != '-' && op3 != '*' && op3 != '/') {
        printf("Error! Invalid operator entered. Please try again.\n");
        continue;
    }

    // Perform the calculation
    double result = num1;
    double result2 = num2;
    double result3 = num3;
    double result4 = num4;
    if (op1 == '+') {
        result = result + num2;
         printf("%d + %d = %d.\n", num1, num2, (int)result);
    } else if (op1 == '-') {
        result = result - num2;
         printf("%d - %d = %d.\n", num1, num2, (int)result);
    } else if (op1 == '*') {
        result = result * num2;
         printf("%d * %d = %d.\n", num1, num2, (int)result);
    } else if (op1 == '/') {
        result = result / num2;
         printf("%d / %d = %d.\n", num1, num2, (int)result);
    }

    if (op2 == '+') {
        result2 = result + num3;
         printf("%d + %d = %d.\n", (int)result, num3, (int)result2);
    } else if (op2 == '-') {
        result2 = result - num3;
         printf("%d - %d = %d.\n", (int)result, num3, (int)result2);
    } else if (op2 == '*') {
        result2 = result * num3;
         printf("%d * %d = %d.\n", (int)result, num3, (int)result2);
    } else if (op2 == '/') {
        result2 = result / num3;
         printf("%d / %d = %d.\n", (int)result, num3, (int)result2);
    }

    if (op3 == '+') {
         result3 = result2 + num4;
         printf("%d + %d = %d.\n", (int)result2, num4, (int)result3);
    } else if (op3 == '-') {
         result = result - num4;
         printf("%d - %d = %d.\n", (int)result2, num4, (int)result3);
    } else if (op3 == '*') {
         result3 = result2 * num4;
         printf("%d * %d = %d.\n", (int)result2, num4, (int)result3);
    } else if (op3 == '/') {
         result3 = result2 / num4;
         printf("%d / %d = %d.\n", (int)result2, num4, (int)result3);
    }

    // Print the result
    if (result3 == 24) {
        printf("Well done! You are a math genius.\n");
    } else {
        printf("Sorry. Your solution did not evaluate to 24.\n");
    }

        // prompt the user to play again, change difficulty, or exit
        printf("Enter\n 1 to play again\n 2 to change the difficulty level and then play again, or\n 3 to exit the program.\n");
        scanf("%d", &choice);
        // handle user's choice
        switch (choice) {
        case 1:
            // play again with the same difficulty level
            break;
        case 2:
          switch (difficultyLevel) {
            case 'M':
              numberOfPossiblePuzzles = 10;
              sprintf(fileName, "medium.txt");
              break;
            case 'H':
                numberOfPossiblePuzzles = 10;
                sprintf(fileName, "hard.txt");
              break;
            default:
                numberOfPossiblePuzzles = 5;
                sprintf(fileName, "easy.txt");
          }
          break;
      case 3:
        // exit the program
        printf("Thanks for playing!\n");
        return 0;
        }
    }
        while (1); {
        }
    //return result;
    }

    // generates a random number between 1 and numberOfPossiblePuzzles
    int getRandomNumber(int numberOfPossiblePuzzles) {
    return rand() % numberOfPossiblePuzzles + 1;
    }




