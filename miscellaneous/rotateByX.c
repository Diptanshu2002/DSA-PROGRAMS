#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void rotateLeft(char *s , int d , int len){
    for (int i=0 ; i<d ; i++){
        char first = s[0];
        for(int j=0;j<len;j++){
            s[j] = s[j+1];
        }
        s[len-1] = first;    
    }
}

void rotateRight(char *s , int d , int len){
    for (int i=0 ; i<d ; i++){
        char last = s[len-1];
        for(int j=len-1;j>=0;j--){
            s[j] = s[j-1];
        }
        s[0] = last;    
    }
}

void optionChoosing(char *s , int d ,int len){
    int choose;
    printf("\nENTER THE NUMBER BESIDE THE OPTION YOU WANT TO SELECT :-");
    printf("\n\t1. Rotate Left");
    printf("\n\t2. Rotate Right");
    printf("\nEnter you choice : ");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:
        rotateLeft(s,d,len);
        printf("After Rotating Left by %d : ",d);
        break;
    case 2:
        rotateRight(s,d,len);
        printf("After Rotating Right by %d : ",d);
        break;
    default:
        printf("\nWrong Input");
        optionChoosing(s,d,len);
        break;
    }
}

int main(){
    int n , rot;
    printf("Enter the length of the string  : ");
    scanf("%d",&n);
    printf("Enter the number of characters to be rotated : ");
    scanf("%d",&rot);
    char str[20];
    printf("Enter the string : ");
    scanf("%s",str);
    optionChoosing(str,rot,n);
    puts(str);
}