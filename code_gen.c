#include <stdio.h>
#include <string.h>

char op[5], arg1[10], arg2[10], result[10]; // Increased buffer sizes

int main() // Changed from void main() to int main() for better standard compliance
{
    FILE *fp1, *fp2;
    int count = 0;
    
    // Open files with explicit paths to make sure we're looking in the right place
    fp1 = fopen("coded_gen_input.txt", "r");
    fp2 = fopen("output.txt", "w");
    
    if (fp1 == NULL) {
        printf("Error: Could not open input.txt for reading\n");
        return 1;
    }
    
    if (fp2 == NULL) {
        printf("Error: Could not open output.txt for writing\n");
        fclose(fp1);
        return 1;
    }
    
    printf("Files opened successfully. Processing input...\n");
    
    // Read each line of the input file
    while(fscanf(fp1, "%s %s %s %s", op, arg1, arg2, result) == 4)
    {
        count++;
        printf("Processing line %d: %s %s %s %s\n", count, op, arg1, arg2, result);
        
        if(strcmp(op, "+") == 0)
        {
            fprintf(fp2, "MOV R0,%s\n", arg1);
            fprintf(fp2, "ADD R0,%s\n", arg2);
            fprintf(fp2, "MOV %s,R0\n", result);
        }
        else if(strcmp(op, "*") == 0)
        {
            fprintf(fp2, "MOV R0,%s\n", arg1);
            fprintf(fp2, "MUL R0,%s\n", arg2);
            fprintf(fp2, "MOV %s,R0\n", result);
        }
        else if(strcmp(op, "-") == 0)
        {
            fprintf(fp2, "MOV R0,%s\n", arg1);
            fprintf(fp2, "SUB R0,%s\n", arg2);
            fprintf(fp2, "MOV %s,R0\n", result);
        }
        else if(strcmp(op, "/") == 0)
        {
            fprintf(fp2, "MOV R0,%s\n", arg1);
            fprintf(fp2, "DIV R0,%s\n", arg2);
            fprintf(fp2, "MOV %s,R0\n", result);
        }
        else if(strcmp(op, "=") == 0)
        {
            fprintf(fp2, "MOV R0,%s\n", arg1);
            fprintf(fp2, "MOV %s,R0\n", result);
        }
        else {
            printf("Warning: Unknown operator '%s' on line %d\n", op, count);
        }
    }
    
    // Force the buffer to be written to the file
    fflush(fp2);
    
    // Close the files
    fclose(fp1);
    fclose(fp2);
    
    printf("Processing complete. Read %d lines.\n", count);
    
    if (count == 0) {
        printf("Warning: No lines were read from input.txt. Check your file format.\n");
        printf("Expected format: operator operand1 operand2 result\n");
        printf("Example: + a b t1\n");
    }
    
    return 0;
}