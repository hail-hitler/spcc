#include <stdio.h>
#include <string.h>
#include <ctype.h>

FILE *fp;
char delimiters[] = "(){};,=+-*/";

void analyze_input();

int main()
{
char fname[50];
printf("enter filename:");
scanf("%s", fname);

fp = fopen(fname, "r");
if (fp == NULL)
{
printf("\nThe file does not exist.");
return 1;
}

analyze_input();
fclose(fp);
return 0;
}

int is_delimiter(char c)
{
for (int i = 0; i < strlen(delimiters); i++)
{
if (c == delimiters[i])
return 1;
}
return 0;
}

void analyze_input()
{
char c;
char token[256];
int j = 0;

while ((c = fgetc(fp)) != EOF)
{
if (isspace(c))
{
if (j > 0)
{
token[j] = '\0';
printf("identifier %s\n", token);
j = 0;
}
continue;
}
else if (is_delimiter(c))
{
if (j > 0)
{
token[j] = '\0';
printf("identifier %s\n", token);
j = 0;
}

if (c == '(' || c == ')' || c == ';' || c == ',')
printf("delimiters%c\n", c);
else
printf("operator %c\n", c);
}
else
{
token[j++] = c;
}
}

if (j > 0)
{
token[j] = '\0';
printf("identifier %s\n", token);
}
}
