#include<stdio.h>
#include<stdlib.h>

// structure to contain all inputted values and store future ones
struct Fractions{
    int numerator1;
    int numerator2;
    int denominator1;
    int denominator2;
    int finalNumerator;
    int finalDenominator;
    int wholeNumber;
};

void addition(struct Fractions *X);
void subtraction(struct Fractions *X);
void multiplication(struct Fractions *X);
void division(struct Fractions *X);
void simplify(struct Fractions *X);
void printFraction(struct Fractions *X);

int main(){

    int input; 

    //asks the user on the operation they want to do
    printf("What do you want to do?\n[1]Addition\n[2]Subtraction\n[3]Multiplication\n[4]Division\n[5]Simplify Fractions\n");
    scanf("%i", &input);

    if(input == 1){       //Addition
        
        //contains the initial values for the array that will contain the values of the user's input
        int arr[4] = {1, 1, 1, 1};

        //to loop through each position in the array and store the values there
        for(int i = 0; i < 4; i++){
            if(i%2 == 0){
                printf("Numerator: ");
                scanf("%i", &arr[i]);
            }else if(i%2 != 0){
                printf("Denominator: ");
                scanf("%i", &arr[i]);
            }
        }

        //pointer of the structure points to an address in the heap using memory allocation
        struct Fractions *values = (struct Fractions*)malloc(sizeof(struct Fractions));
        
        //initializaing the values for each struct member
        values->numerator1 = arr[0];
        values->denominator1 = arr[1];
        values->numerator2 = arr[2];
        values->denominator2 = arr[3];
        values->finalNumerator = 0;
        values->finalDenominator = 0;
        values->wholeNumber = 0;

        addition(values);
        simplify(values);
        printFraction(values);

        free(values);

    }else if(input == 2){ //Subtraction

        //the following uses the same logic as for the addition one (choice 1)

        int arr[4] = {1,1,1,1};

        for(int i = 0; i < 4; i++){
            if(i%2 == 0){
                printf("Numerator: ");
                scanf("%i", &arr[i]);
            }else if(i%2 != 0){
                printf("Denominator: ");
                scanf("%i", &arr[i]);
            }
        }

        struct Fractions *values = (struct Fractions*)malloc(sizeof(struct Fractions));

        values->numerator1 = arr[0];
        values->denominator1 = arr[1];
        values->numerator2 = arr[2];
        values->denominator2 = arr[3];
        values->finalNumerator = 0;
        values->finalDenominator = 0;
        values->wholeNumber = 0;

        subtraction(values);
        simplify(values);
        printFraction(values);

        free(values);

    }else if(input == 3){ //Multiplication

        //the following uses the same logic as for the addition one (choice 1)

        int arr[4] = {1,1,1,1};

        for(int i = 0; i < 4; i++){
            if(i%2 == 0){
                printf("Numerator: ");
                scanf("%i", &arr[i]);
            }else if(i%2 != 0){
                printf("Denominator: ");
                scanf("%i", &arr[i]);
            }
        }

        struct Fractions *values = (struct Fractions*)malloc(sizeof(struct Fractions));

        values->numerator1 = arr[0];
        values->denominator1 = arr[1];
        values->numerator2 = arr[2];
        values->denominator2 = arr[3];
        values->finalNumerator = 0;
        values->finalDenominator = 0;
        values->wholeNumber = 0;

        multiplication(values);
        simplify(values);
        printFraction(values);

        free(values);
        
    }else if(input == 4){ //Division

        //the following uses the same logic as for the addition one (choice 1)        

        int arr[4] = {1,1,1,1};

        for(int i = 0; i < 4; i++){
            if(i%2 == 0){
                printf("Numerator: ");
                scanf("%i", &arr[i]);
            }else if(i%2 != 0){
                printf("Denominator: ");
                scanf("%i", &arr[i]);
            }
        }

        struct Fractions *values = (struct Fractions*)malloc(sizeof(struct Fractions));

        values->numerator1 = arr[0];
        values->denominator1 = arr[1];
        values->numerator2 = arr[2];
        values->denominator2 = arr[3];
        values->finalNumerator = 0;
        values->finalDenominator = 0;
        values->wholeNumber = 0;

        division(values);
        simplify(values);
        printFraction(values);

        free(values);

    }else if(input == 5){ //Simplify

        //the following uses the same logic as for the addition one (choice 1)

        int arr[2] = {1, 1};

        for(int i = 0; i < 2; i++){
            if(i%2 == 0){
                printf("Numerator: ");
                scanf("%i", &arr[i]);
            }else if(i%2 != 0){
                printf("Denominator: ");
                scanf("%i", &arr[i]);
            }
        }

        struct Fractions *values = (struct Fractions*)malloc(sizeof(struct Fractions));

        values->finalNumerator = arr[0];
        values->finalDenominator = arr[1];

        simplify(values);
        printFraction(values);

        free(values);
    }

    return 0;
}

//Simplifies fractions
void simplify(struct Fractions *X){

    
    if(X->finalNumerator % X->finalDenominator == 0){       //Checks if the numerator is divisible by the denominator to simply return the quotient of the numerator and denominator
        X->wholeNumber = X->finalDenominator / X->finalDenominator;
    }else if(X->finalNumerator%X->finalDenominator > 0 || X->finalDenominator%X->finalNumerator > 0){       //When the numerator and the denominator do not completely divide

        //Here we will use a gcd finding algorithm
        //As the name implies, we will be looking for the greatest common denominator of the numerator and denominator

        //Initializing values  
        int gcd, tempNume, tempDeno;
        tempNume = X->finalNumerator;
        tempDeno = X->finalDenominator;
        
        //Checks if the number is negative and transforms it to a positive one
        if(X->finalNumerator < 1){
            tempNume = tempNume*-1;
        }

        if(X->finalDenominator < 1){
            tempDeno = tempDeno*-1;
        }

        //repeteadly subtracts the values until we finally have equal values for the numerator and denominator
        //we will use the value that is bigger as the minuend and set the gcd to that number 
        while(tempNume != tempDeno){
            if(tempNume > tempDeno){
                tempNume -= tempDeno;
                gcd = tempNume;
            }else{
                tempDeno -= tempNume;
                gcd = tempDeno;
            }
        }

        //dividing the newfound gcd to divide the original numerator and denominator to simplify them
        X->finalNumerator = X->finalNumerator / gcd;
        X->finalDenominator = X->finalDenominator / gcd;

    }
    
}

//Adds fractions
void addition(struct Fractions *X){

    //same logic as adding numbers manually
    //similar: nume + nume / deno
    //dissimilar: (nume1*deno2) + (nume2*deno1) / (deno1*deno2)

    if(X->denominator1 == X->denominator2){     //similar denominators
        X->finalNumerator = X->numerator1 + X->numerator2;
        X->finalDenominator = X->denominator1; 
    }else if(X->denominator1 != X->denominator2){       //dissimilar denominators
        X->finalNumerator = (X->numerator1 * X->denominator2) + (X->numerator2 * X->denominator1);
        X->finalDenominator = (X->denominator1 * X->denominator2);
    }

}

//Subtracts fractions
void subtraction(struct Fractions *X){

    //same logic as subtracting numbers manually
    //similar: nume - nume / deno
    //dissimilar: (nume1*deno2) - (nume2*deno1) / (deno1*deno2)

    if(X->denominator1 == X->denominator2){     //similar denominators
        X->finalNumerator = X->numerator1 - X->numerator2;
        X->finalDenominator = X->denominator1; 
    }else if(X->denominator1 != X->denominator2){       //dissimilar denominators
        X->finalNumerator = (X->numerator1 * X->denominator2) - (X->numerator2 * X->denominator1);
        X->finalDenominator = (X->denominator1 * X->denominator2);
    }
    
}

//Multiplies fractions
void multiplication(struct Fractions *X){

    //same logic as multiplying numbers manually
    // (nume1*nume2) / (deno1*deno2)

    X->finalNumerator = X->numerator1 * X->numerator2;
    X->finalDenominator = X->denominator1 * X->denominator2;

}

//Divides fractions
void division(struct Fractions *X){

    //same logic as dividing fractions manually
    //(nume1*deno2) / (nume2*deno1)

    X->finalNumerator = X->numerator1 * X->denominator2;
    X->finalDenominator = X->numerator2 * X->denominator1;

}

//Prints final output
void printFraction(struct Fractions *X){

    if(X->finalNumerator%X->finalDenominator == 0){
        printf("Answer: %i", X->wholeNumber);
    }else{
        printf("Answer: %i/%i", X->finalNumerator, X->finalDenominator);
    }

}
