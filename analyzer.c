#include <stdio.h>
#include <string.h>


int hasLowercase(char password[]) {
    int i;

    //Iterating through password and returning 1 point if lowercase letter is contained
    for(i=0; password[i] != '\0'; i++) {
        if(password[i] >= 97 && password[i] <= 122) {
            return 1;
        }
    }

    return 0;
}

int hasUppercase(char password[]) {
    int i;

    //Iterating through password and returning 1 point if uppercase letter is contained
    for(i=0; password[i] != '\0'; i++) {
        if(password[i] >= 65 && password[i] <= 90) {
            return 1;
        }
    }

    return 0;
}

int hasDigit(char password[]) {
    int i;

    //Iterating through password and returning 1 point if digit is contained
    for(i=0; password[i] != '\0'; i++) {
        if(password[i] >= 48 && password[i] <= 57) {
            return 1;
        }
    }

    return 0;
}

int hasSpecialChar(char password[]) {
    int i;

    //Iterating through password and returning 1 point if special char is contained
    for(i=0; password[i] != '\0'; i++) {
        if((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) 
        || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126)) {
            return 1;
        }
    }

    return 0;
}

int evaluateStrength(char password[]) {
    int strength = 0;

    //Calling each evalutation function and summing their outputs
    strength += hasLowercase(password) + hasUppercase(password) + hasDigit(password) + hasSpecialChar(password);

    //Extra point if password is 12+ letters
    if(strlen(password) >= 12) {
        strength += 1;
    }

    return strength;

}

int main() {

    //Var for previous password strength
    char last_tested[500] = "Previous password has not been tested";

    //Current password
    char password[500];
    while(1) {
        printf("\nPassword Resilience Analyzer \n1. Test a New Password \n2. View Strength of the last tested password \n3. Exit");
        printf("\nEnter your choice: ");

        char buf[500];
        scanf("%s", buf);

        //Prompting enter password if first option is clicked
        if(strcmp(buf, "1") == 0) {
            printf("Enter the password: ");
            scanf("%s", password);

            //Prompt for password less than 8 letters
            if(strlen(password) < 8) {
                printf("Error: Password should be atleast 8 characters long.\n");
                continue;
            }

            //Calling method to evaluate strength and then displaying strength of password. Storing strength for 2nd option.
            int strength = evaluateStrength(password);
            if(strength >= 0 && strength <= 2) {
                strcpy(last_tested, "Weak" );
            } else if(strength >= 3 && strength <= 4) {
                strcpy(last_tested, "Moderate");
            } else {
                strcpy(last_tested, "Strong");    
            }
            printf("Password Strength: %s \n", last_tested);         
        } else if(strcmp(buf, "2") == 0) {
            //Displaying stored strength of last tested password
            printf("Last Tested Password Strength: %s \n", last_tested);
        } else if(strcmp(buf, "3") == 0) {
            //Exiting program
            printf("Exiting...");
            return 0;
        } else {
            //Message for invalid input
            printf("Enter a valid number (1-3)\n");
        }
    }
}
