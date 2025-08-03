#include <stdio.h>

int count_trailing_zeroes(int number)
{
    int trailing_zero_count = 1;
  
    // 0b1111111111111111, or 2^16 - 1
    if ((number & 0x0000FFFF) == 0)
    {
        trailing_zero_count += 16;
        number >>= 16;
    }
  
    // 0b11111111, or 2^8 - 1
    if ((number & 0x000000FF) == 0)
    {
      trailing_zero_count += 8;
      number >>= 8;
    }
    
    // 0b1111, or 2^4 - 1
    if ((number & 0x0000000F) == 0)
    {
      trailing_zero_count += 4;
      number >>= 4;
    }
    
    // 0b11, or 2^2 - 1
    if ((number & 0x00000003) == 0)
    {
      trailing_zero_count += 2;
      number >>= 2;
    }
  
    return trailing_zero_count - (number & 1);
}

int find_lesser_of_twain(int a, int b)
{
    return (a < b) ? a : b;
}

int find_greatest_common_divisor(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    
    int common_divisor = 1;
    
    int trailing_zero_count_of_a = count_trailing_zeroes(a);
    int trailing_zero_count_of_b = count_trailing_zeroes(b);
    
    a >>= trailing_zero_count_of_a;
    b >>= trailing_zero_count_of_b;
    
    common_divisor <<= find_lesser_of_twain(trailing_zero_count_of_a, trailing_zero_count_of_b);
    
    while (a)
    {
        if (a >= b) a = (a - b) >> 1;
        else b = (b - a) >> 1;
    }
    
    int greatest_common_divisor = common_divisor * b;
    
    return greatest_common_divisor;
}

int main()
{
    int a = 37;
    int b = 73;

    printf("%d\n", find_greatest_common_divisor(a, b));
    
    return 0;
}
