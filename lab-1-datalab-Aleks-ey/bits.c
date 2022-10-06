/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
         
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return (~x & ~y);
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
    int y = x>>15;//bitshifting x to the right by 15
    //If x is within 0 to 32767 then y is equal to 32 0's or just 0 in decimal
    //If x is within (-1) to (-32768) then y is equal to 32 1's or just (-1) in decimal
    return !y | !~y;//!y return 1 if y is 0 or !~y first turns y into 0 if it's 32 1's then back into 1 from 0
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
    int x = 1;//0...001
    x = (x<<3) + x;//(0...00 1000) + (0...001) = 0...00 1001
    x = (x<<6) + x;//(0..0010 0100 0000) + (0...00 1001) = 0...0010 0100 1001
    x = (x<<12) + x;//(0..0010 0100 1001 0...0000) + (0..0010 0100 1001) = 0...0010 0100 1001 0010 0100 1001
    x = (x << 24) + x;//(0100 1001 0...0000) + (0010 0100 1001 0010 0100 1001) = 0100 1001 0010 0100 1001 0010 0100 1001
    return x;
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
    int y = 0x55;//0101 0101
    y = (y<<8) + y;//0101 0101 0101 0101
    y = (y<<16) + y;//0101 0101 0101 0101 0101 0101 0101 0101
    return !!(y & x);//we compare y with x by using & operator.
                    //If any even bit is 1 we will get back a 1 somwhere in the 32 bits after the operation.
                    //If no even bits are 1 we will get 32 0's back after the operation.
                    //By using ! twice we ensure that if there is a 1 somewhere in the 32 bits then we will return a 1
                    //if there isn't a 1, after using ! twice we would instead return a 0
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    int y = (x & 1);//by using & with 1 we make all other 31 bits 0 expect for lsb.
                    //if lsb is 1, y becomes 1 after operation. if lsb is 0, y becomes 0 after operation.
    y = y << 31;//left shift by 31. Now our lsb is the 32nd bit and is followed by all 0's.
    return (y >> 31);//return y after right shifting by 31. After right shift lsb is now back in its original position.
                    //because of arithmetic shifting all 31 bits to the left of lsb are the same as lsb.
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    return ((!x) | y);//De Morgan's law 
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    int lmask = (~0<<highbit) & ~(1<<highbit);//masks every bit to the left of highest bit as 1.
                                              //& operation is necessary because of test case with 31 and 0,
                                              //without & operation we exceed left shit count and get error
    int rmask = ~(~0<<lowbit);//masks every bit to the right of lowest bit as 1.
    return ~(lmask|rmask);//or operation returns binary number with every bit to the right and left of
                          //highest and lowest bits as 1. Negating the returned binary number gives the
                          //binary number with the target mask.
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
    int y = (x+x+x);//multiply x by 3
    int sign = (y>>31);//gets the sign of x after multiplication
                       //if sign is 1 returns -1(32 1's) if sign 0 returns 0(32 0's)
    y = (y + (sign & 3)) >>2;//add the bias to y before dividing.
                             //bias is (2^2)-1 = 3. & operation between the sign and the bias
                             //applies bias if number is negative and does not if number is positive
    return y;
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
    int y = x+x;//multiply by 2
    int z = y+x;//multiply by 3
    int Tmin = 1 << 31;
    
    int hb_x = (x>>31) & 1;//highest bit of x, results in either 0 or 1
    int hb_y = (y>>31) & 1;//highest bit of y, results in either 0 or 1
    int hb_z = (z>>31) & 1;//highest bit of z, results in either 0 or 1
    int xPos;//declared her to avoid errors
    
    int of_check = (hb_x ^ hb_y) | (hb_x ^ hb_z);//check for overflow: if overflow 1, else 0
    of_check = (of_check<<31)>>31;//sets all bits of variable to LSB
    xPos = (x>>31);//sets all bits of xPos to either 0 or 1. If x is positive: 32 0's, else: 32 1's
    
    return (of_check & ((xPos & (Tmin))|(~xPos & ~(Tmin))))|(~of_check & z);
    //Return statement translated into if-else:
        //if(of_check == 1){
            //if(x > 0){
                //return TMax
            //}
            //else{
                //return TMin
            //}
        //}
        //else{
            //return z
        //}
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
    int first_half = x ^ (x >> 16);
    int second_half = first_half ^ (first_half >> 8);
    int third_half = second_half ^ (second_half >> 4);
    int fourth_half = third_half ^ (third_half >> 2);
    int fifth_half = fourth_half ^ (fourth_half >> 1);
    int result = fifth_half & 1;
    return result;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    int every1,every2,every4;
    int y;
    
    every1 = 0x55;
    every1 = (every1<<8) + every1;
    every1 = (every1<<16) + every1;
    
    every2 = 0x33;
    every2 = (every2<<8) + every2;
    every2 = (every2<<16) + every2;
    
    every4 = 0x0f;
    every4 = (every4<<8) + every4;
    every4 = (every4<<16) + every4;
    
    x = (x>>1);
    x = (x>>1) | x;
    x = (x>>2) | x;
    x = (x>>4) | x;
    x = (x>>8) | x;
    x = (x>>16) | x;
    x = (x>>2) | x;
    
    y = (x&every1);
    x = ((x>>1)&every1);
    x = (x + y);
    
    y = (x&every2);
    x = ((x>>2)&every2);
    x = (x + y);
    
    y = (x>>4) + x;
    x = (y&every4);
    
    x = ((x>>8)+x);
    x = ((x>>16)+x);
    x = (x&0x3f);
    
    return x;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
    int sign,bias;
    int lsb2,x3;
    sign = x>>31;
    bias = (sign&3);
    lsb2 = (x&3);
    
    x = x>>2;
    x3 = (x+x+x);
    x = ((lsb2+lsb2+lsb2)+bias)>>2;
    x = (x+x3);
    return x;
}
/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 return 2;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  return 2;
}
