#include <stdio.h>
#include <string.h>
struct op {
char l;
char r[20];
} op[10], pr[10];
void main() {
int a, i, k, j, n, z = 0, m, q;
char *p, *l;
char temp, t;
char *tem;
printf("Enter the Number of Values: ");
scanf("%d", &n);
getchar(); 

for (i = 0; i < n; i++) {
printf("left: ");
op[i].l = getchar(); 
getchar(); 
printf("\tright: ");
fgets(op[i].r, sizeof(op[i].r), stdin);
op[i].r[strcspn(op[i].r, "\n")] = 0; 
}

printf("Intermediate Code\n");
for (i = 0; i < n; i++) {
printf("%c = %s\n", op[i].l, op[i].r);
}

for (i = 0; i < n - 1; i++) {
temp = op[i].l;
for (j = 0; j < n; j++) {
p = strchr(op[j].r, temp); 
if (p) {
pr[z].l = op[i].l;
strcpy(pr[z].r, op[i].r);
z++;
}
}

}
pr[z].l = op[n - 1].l;
strcpy(pr[z].r, op[n - 1].r);
z++;

printf("\nAfter Dead Code Elimination\n");
for (k = 0; k < z; k++) {
printf("%c = %s\n", pr[k].l, pr[k].r);
}

for (m = 0; m < z; m++) {
tem = pr[m].r;
for (j = m + 1; j < z; j++) {
p = strstr(tem, pr[j].r);
if (p) {
t = pr[j].l; pr[j].l
= pr[m].l;
for (i = 0; i < z; i++) {
l = strchr(pr[i].r, t);
if (l) {
a = l - pr[i].r;
pr[i].r[a] = pr[m].l;
}
}
}
}
}

printf("Eliminate Common Expression\n");
for (i = 0; i < z; i++) {
printf("%c = %s\n", pr[i].l, pr[i].r);
}

for (i = 0; i < z; i++) {
for (j = i + 1; j < z; j++) {
q = strcmp(pr[i].r, pr[j].r); 
if ((pr[i].l == pr[j].l) && !q) {
pr[i].l = '\0';
strcpy(pr[i].r, "");
}
}
}

printf("Optimized Code\n");
for (i = 0; i < z; i++) {
if (pr[i].l != '\0') {

printf("%c = %s\n", pr[i].l, pr[i].r);
}
}
}