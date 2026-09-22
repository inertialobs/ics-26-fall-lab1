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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return 1<<31;
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
  int a = ~(x&y);
  int b = ~(a&x);
  int c = ~(a&y);
  int d = ~(b&c);
	return d;
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  return x>>31 & (~x+1);
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  int src8= (src << 3);
  int dst8= (dst << 3);
  return (((x >> src8 )& 0xFF) << dst8) | (x & ~(0xFF << dst8));
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  return x>>n & ~(0x1 << 31 >> n <<1);
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
  int mask1=(0xF0)+(0xF0<<8)+(0xF0<<16)+(0xF0<<24);
  int mask2=~mask1;
  int ans = (((x&mask1)>>4)&(~(0xF0<<24))) | ((x&mask2)<<4);
  return ans;
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
  int l1 = ~x &(x+1);
  int x1 = x + l1;
  int l2 = ~x1 &(x1+1);
  return l2;
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
  int l1=x, h1=x>>16;
  int x1=l1^h1;
  int l2=x1, h2=x1>>8;
  int x2=l2^h2;
  int l3=x2, h3=x2>>4;
  int x3=l3^h3;
  int l4=x3, h4=x3>>2;
  int x4=l4^h4;
  int l5=x4, h5=x4>>1;
  return (~(h5^l5)) & 0x1;
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
  return ((x>>n)&(~(0x1<<31>>n<<1))) | (x<<(33+~n));
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
  int q=x>>n;
  int half = 1<<(n+~0);
  return (x+half+~0+(q&1))>>n<<n ;
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
  return (x&y)+((x^y)>>1) + ((x^y)&1&((((x^y)>>31)&~(x>>31))|(((~(x^y))>>31)&~((x+~y+1)>>31))));
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
  int signx=x>>31, signxa=(x^a)>>31, signxb=(x^b)>>31;
  int xa=(signxa&signx)|((~signxa)&((x+~a+1)>>31));
  int xb=(signxb&signx)|((~signxb)&((x+~b+1)>>31));
  int ax=(signxa&(a>>31))|((~signxa)&((a+~x+1)>>31));
  int bx=(signxb&(b>>31))|((~signxb)&((b+~x+1)>>31));
  return ~((xa&xb)|(ax&bx))&1;
}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
  int x4=x<<2;
  int a=((x4)>>2)^x;
  int b=(a|(~a+1))>>31;//1: x4 ovf
  int p=(x^(x+x4))>>31;//1: pls ovf
  return ((x4+x)&(~b)&(~p))+((b|p)&((x>>31)^~(1<<31)));
}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
  int sx=x>>31, sy=y>>31, sz=z>>31;
  int ss=sx+sy+sz;
  int xy=x+y, xyz=xy+z;
  int c1=(((x&y)|((x^y)&~xy))>>31)&1;
  int c2=(((xy&z)|((xy^z)&~xyz))>>31)&1;
  int h=ss+c1+c2+((xyz>>31)&1);
  return (h>>31)| !!h;
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
  unsigned s = uf & 0x80000000, e = (uf>>23)&0xFF , m = uf & 0x7FFFFF;
  if (e==0xFF) return uf;
  if (e==0 && m==0) return uf;
  if (e) m = m | 0x800000;
  unsigned last = m&1;
  unsigned sm = (m>>1) + m;
  if ((sm&1) && last) sm+=1;
  if (!e && (sm>>23)){
    return s|sm;
  }
  unsigned smovf=sm>>24;
  if (smovf) {
    if ((sm&1) && sm&2) sm+=2;
    e += 1;
    sm = sm >> 1;
    if (e==0xFF) return s|0x7F800000;
  }

  return s|(e<<23)|(sm&0x7FFFFF);
}

// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
  unsigned s=uf&0x80000000, e = (uf >> 23)&0xFF, m = uf & 0x7FFFFF;
  if (e == 0xFF || e>=150) return uf;
  if (e==0) return s;
  if (e<127) return (e==126 && m)? s|(0x7F<<23):s;
  m = m | 0x800000;
  unsigned sh = 150 - e;
  if ((m>>(sh-1))&1&(m>>sh)) m=(m>>sh)+1;
  else if((m>>(sh-1)&1)&&(sh!=1)&&(m<<(33-sh))) m=(m>>sh)+1;
  else m=m>>sh;
  if(m<<sh>>24) return s|((e+1)<<23)|((m<<(sh-1))&0x7FFFFF);
  return s|(e<<23)|((m<<sh)&0x7FFFFF);
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
  if (x){
    unsigned s = x & 0x80000000, m= x>0? x: (~x+1);
    unsigned e=127+23;
    if (m>>24){
      unsigned last = 0x0;
      while (m>>24){
        last = (m&1)+(last<<1);
        m=m>>1;
        e+=1;
      }
      if ((last&1)&&((last>>1)||(m&1))) m+=1;
      if (m>>24){
        m = m>>1;
        e+=1;
      }
    } else {
      while (!(m & 0x800000)){
        e-=1;
        m=m<<1;
      }
    }
    return s|(e<<23)|(m&0x7FFFFF);
  }
  return 0x0;
}



// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
  int n5=0xFF|(0xFF<<8);
  int n4=0xFF|(0xFF<<16);
  int n3=n4^(n4<<4);
  int n2=n3^(n3<<2);
  int n1=n2^(n2<<1);
  int x1=(x&n1)+((x>>1)&n1);
  int x2=(x1&n2)+((x1>>2)&n2);
  int x3=(x2&n3)+((x2>>4)&n3);
  int x4=(x3&n4)+((x3>>8)&n4);
  int x5=(x4&n5)+((x4>>16)&n5);
  return x5;
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x)
{
  int n5=0xFF|(0xFF<<8);
  int n4=0xFF|(0xFF<<16);
  int n3=n4^(n4<<4);
  int n2=n3^(n3<<2);
  int n1=n2^(n2<<1);
  int x1=((x&n1)<<1)+((x>>1)&n1);
  int x2=((x1&n2)<<2)+((x1>>2)&n2);
  int x3=((x2&n3)<<4)+((x2>>4)&n3);
  int x4=((x3&n4)<<8)+((x3>>8)&n4);
  int x5=((x4)<<16)+((x4>>16)&n5);
  return x5;
}
