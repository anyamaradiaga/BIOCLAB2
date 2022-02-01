/*
Name: Anya Maradiaga 
Date: 01/25/22
Description: The following program reads contents of file random.txt, sums the contents and outputs summation. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int sum=0, val;
    int randomArray[20];

    FILE *fp = fopen("random.txt", "r");

    for (int i = 1; i <= 20; i++){
        fscanf(fp, "%d", &val);
        randomArray[i] = val;
        //("val: %d",val);
        sum += randomArray[i];
        }
    
    FILE *fo = fopen("sum_output.txt","w");
    fprintf(fo, "%d", sum);

    fclose(fp);
    fclose(fo);
    printf("Sum: %d\n\n", sum);
    return 0;
}
