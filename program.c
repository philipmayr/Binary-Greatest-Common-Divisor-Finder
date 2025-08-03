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

int find_lesser_of_twain(int first_number, int second_number)
{
    return (first_number < second_number) ? first_number : second_number;
}

int get_distance_from_zero(int number)
{
    return (number < 0) ? -number : number;
}

int find_greatest_common_divisor(int first_number, int second_number)
{
    if (first_number == 0) return second_number;
    if (second_number == 0) return first_number;
        
    int trailing_zero_count_of_first_number = count_trailing_zeroes(first_number);
    int trailing_zero_count_of_second_number = count_trailing_zeroes(second_number);
    
    first_number >>= trailing_zero_count_of_first_number;
    second_number >>= trailing_zero_count_of_second_number;
    
    int common_binary_divisor = find_lesser_of_twain(trailing_zero_count_of_first_number, trailing_zero_count_of_second_number);
    
    while (first_number)
    {
        int difference_between_numbers = first_number - second_number;
        
        second_number = find_lesser_of_twain(first_number, second_number);
        first_number = get_distance_from_zero(difference_between_numbers);
        first_number >>= count_trailing_zeroes(first_number);
    }
    
    int greatest_common_divisor = second_number << common_binary_divisor;
    
    return greatest_common_divisor;
}

int main()
{
    int first_number = 16;
    int second_number = 48;

    printf("%d\n", find_greatest_common_divisor(first_number, second_number));
    
    return 0;
}
