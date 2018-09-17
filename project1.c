#include <stdio.h>

/*
Group number:
Team members:
*/

/* PROJECT 1 */

/* In this assignment you will examine a program consisting of a number of functions - labelled ques1.c to ques15.c -- each of which tests your knowledge of bitwise C operations. Your goal is to determine what each function does and if there
is a simpler way to implement the function. There are two parts to the requirements.  */

/* Assume 32 bit integers */

/* PART A: You need to determine what each function is doing .
You have to determine what each function is doing WITHOUT running the code. You must provide an explanation for your answer - you will get no credit if you correctly identify the function but provide  an incorrect or insufficient/incomplete explanation.
 Once you determine the function, you should run the code to check your answer.
To run the code to test your function, you will need to insert appropriate C code to call the function and print out the result.
 Once you are done showing what each function does, you should then answer part b. */

/* PART B: For each function, can you write a simpler equivalent function in C (using any C operators) that produces the same result.
 By simpler, we are interested in fewer operations in C but also more readable code. */


/*
 As an example, consider the answers to function ques0 - which you worked out in class.

 HANDIN Instructions: You must write out your answers to Part A in a report to be submitted (as a tarfile or zipfile, along with your code) - in addition to the report, you can include comments in your code that may provide a secondary explanation (in case
 your report has errors). You MUST provide an explanation for what the function does and justify your answer. Simply providing an example is NOT an explanation - so don't expect any credit if
 your answers are simply a collection of examples or code comments. You are welcome to provide formal proofs where appropriate, but use your judgement on whether to pursue a formal proof or not. It is preferable to write your answers as comments in the code - but do not feel pressured to do so.
 For part B, write out your code in this file with the answer (a simpler code if it exists) after each of the assigned functions in a manner similar to the example shown in ques0.c (i.e., the answer to function ques7.c should be named ans7.c).

 IMPORTANT: The code you submit must compile correctly (using gcc). If the code you submit does not compile without errors, you will get a zero for Part B of this project.

 GRADING: Each question has a specific number of points (i.e., not all questions have the same level of difficulty). Your grade will be based
 on the correctness of your answer, expressing the answer as a logical function where possible, and the efficiency and readability of your rewritten code.

 Collaboration: You can discuss the project with your teammate. You CANNOT refer to online sources to get help; you can refer to the C syntax documentations. Your report must include names of both members of the team -- failure to do so would imply you are claiming you worked on your own, and may constitute a violation of academic integrity policies.*/

/* EXAMPLE
 this function is similar to CallMeLast in the inclass exercises */
/*  function ques0 returns 1 if x=y and returns 0 if x is not equal to y */
/* the function ans0 does the same in two C statements */

int ques0(int x, int y){
    int temp;
    temp = ~y;
    temp = temp +1;
    temp = temp + x;
    return !(temp);
}

/* Answer to PART B: */
int ans0(int x, int y){
    int z=0;
    if (x==y)  z= 0;
    else z= 1;

    return z;
}

/* QUESTIONS */

/* question 1 */
int ques1(int x) {
    int z;
    int y  = ~x+1;
    z= (~(y|x));
    z = (z >> 31);

    return (z & 1);

}
// This function will always return 0. It is adding 1 to the complement of x, then performing an OR function on y and x. Then, it shifts the bits of z to the right by 31. After that, an AND function is performed on z and 1, resulting in 0.

int ans1(int x) {
    return 0;
}

/* question 2 */
int ques2(int x) {
    int mask = x>>31;
    int y= (x ^ mask);
    int z = (~mask + 1);

    return (y+z);
}

// This function will return a copy of the input if it's greater than -1. If the input is less than 0 then the input is negated and returned. The mask is created by performing a right bit shift of 31, then an XNOR function is done on x and the mask. The value z is then the complement of the mask with 1 added to it. The result is added to y, which gives back a copy of the input if it was greater than 0, and an inverted bit representation is it was less than 0.

int ans2(int x) {
    if (x > -1) {
        return x;
    }
    else {
        return -x;
    }
}

/* question 3 */
int ques3(int x){
    int y = !x;
    int z = x >> 31;
    z = z | y;

    return !z;
}

// This function will return a 1 if the input is greater than 0, and 0 is the input is less than 0. It takes the complement of the input, then bit-shifts it to the right by 31 bits. The result is then used for an OR function, which performs it against the complement of x. The result is then a logical NOT value.

int ans3(int x) {
    if (x > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

/* question 4 */
/* Assume 0 <= n <= 32 */
int ques4(int n) {
    int x = (!!n) << 31;
    x = x >> 31;
    printf("%d\n", x);

    int y = (1 << 31);
    y = y >> (n + (~0));

    return x & y;
}

// This function returns an offset of the bits

int ans4(int n) {
    int x;
    int y;

    if (n) {
        x = -1;
    }
    else {
        x = 0;
    }
    y = 1 << 31;
    y = y >> (n - 1);

    return x & y;

}


/* question 5 */
/* if the input is even return 0, otherwise return -1

*/
int ques5(int x) {
    int result = (x<<31); //x bitshift left 31 times 
    result = (result >> 31); //result bitshift right 31 times 

    return result;

}
//answer to question 5
int ans5(int x){
    if (x==0){
        return 0;
    }
    else if (x%2==0){
        return 0;
    }
    else
        return -1;
}


/* question 6 */

int ques6(void) {
    int byte = 0x55;
    /*
    Essential concatinated two 'bytes' by moving 8 digits and adding byte
    into the 0's
     */
    int word = byte | byte<<8;
    /*
    Does the same thing as word, so it makes 'byte' concatinated 4 times
    */
    return word | word<<16;
}

int ans6(void){
  int byte = 0x55;
  return (byte<<24) + (byte<<16) + (byte<<8) + (byte);
}


/* question 7 */

int ques7(int x) {

    return x & (~x+1);
}


/* question 8 */
* x right shift 31, makes y=0;
 z not not x makes z=1;
 returns true because 0 or 1, its always 1
 */

int ques8(int x) {
    int y = x >> 31;
    int z = !!x;

    return y | z;
}

//answer to question 8
int ans8(int x){

    if(x==0) {
        return 0;
    }
    else if (x<0){
        return -1;
    }
    else
        return 1;

}

/* question 9 */

int ques9(int x, int n, int c) {
    int n8 = n << 3;
    int mask = 0xff << n8;
    int cshift = c << n8;
    int z= (x & ~mask);

    return (z  | cshift);
}


/* question 10 */

/* y takes not not x; which always return 1;
 then z first do (x+x) operations, which makes 1 , then not  makes z= 0;
0 and 1, will always give you 0;
 */

int ques10(int x) {
    int y = !!x;
    int z = (!(x+x));

    return y & z;
}

//answer to question 10

int ans10(intx){
    int a=0;
    int b=1;
    return a&b;

}


/* question 11 */


/* x right shift 31 times
 * y right shift 31 times, which will not return 1 for b. it will only return -1,and 0
 * lastly if a=0,b=0, it will return 0;
 * if a=-1, and b=-1, it will return 0;
 * if a=0, and b=0, it will return  0;
 * if a=-1 and b=0, it will return 1

 */

int ques11(int x, int y) {
    int a = x >> 31;
    int b = y >> 31;

    return !((!a & b) | (!(a ^ b) & (y+~x)>>31));
}


//answer to question 11 
int ans11(int x,int y)
{
    if(x==y||x>y){
        return 0;
    }
    else
        return 1;

}

/* question 12 */
int ques12(int x, int m, int n) {
    int a = ~m+1;
    int b = ~x +1;
    a = x + a;
    b = b + n;

    return !((a|b) >> 31);
}

/* question 13 */

int ques13(int x) {

    int mask1, mask2, mask4, mask8, mask16;

    mask2 = 0x33 + (0x33 << 8);
    mask2 += mask2 << 16;
    mask1 = mask2 ^ (mask2 << 1);
    mask4 = 0x0F + (0x0F << 8);
    mask4 += mask4 << 16;
    mask8 = 0xFF + (0xFF << 16);
    mask16 = 0xFF + (0xFF << 8);

    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x & mask8) + ((x >> 8) & mask8);
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
}

/* question 14 */
int ques14(int x) {
    int result = 0;
    int i;

    for (i = 0; i < 32; i++)
        result ^=  (x >> i) & 0x1;

    return result;
}

/* question 15 */

int ques15(int x, int n) {
    /* for ques15 only, assume n is not a negative number  */

    int temp = (1 << n);
    int z = temp + ~0;

    return (z & x);
}


void testFunc () {

    for (int i=0; i<=32; i++) {
        int t = ques4(i);
        int z = ans4(i);
        if (t!=z) {
            printf("Failed");
        }
    }


}



int main(){

    testFunc();

//    int a, b;
//
//    int t1;
//
// 	printf("Enter first number, an integer stored into variable A preferably between 1 and 20:");
// 	scanf ("%d",&a);
//	printf("\n");
// 	printf("Enter second number, an integer stored into variable B preferably between 1 and 20:");
// 	scanf ("%d", &b);
//	printf("\n");
//
//
//	printf("you entered a= %d b= %d  \n", a,b);
//
//
//	t1=ques0(a,b);
//	printf("output of ques0 is t1 = %d  \n", t1);
//    /* To test/run the functions, you will need to input numbers and then call each of the functions, and print the return value */


    return 0;
}
