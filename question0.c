#include <stdio.h>

int ques0(int x, int y){
    int temp;
    temp = ~y;
    temp = temp +1;
    temp = temp + x;
    return !(temp);
}

int
main(){
    int a, b;

    int t1;

 	printf("Enter first number, an integer stored into variable A preferably between 1 and 20:");
 	scanf ("%d",&a);
	printf("\n");
 	printf("Enter second number, an integer stored into variable B preferably between 1 and 20:");
 	scanf ("%d", &b);
	printf("\n");


	printf("you entered a= %d b= %d  \n", a,b);


	t1=ques0(a,b);
	printf("output of ques0 is t1 = %d  \n", t1);
    /*
    To test/run the functions, you will need to input numbers and then call
    each of the functions, and print the return value
    */


	return 0;
}
