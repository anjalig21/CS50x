#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
  // prompt user for the card number and count the digits
  long long card_number;
  int counter = 0;
  card_number = get_long_long("Number: ");
  long long n = card_number;
  while (n>0)
  {
      n = n/10;
      counter++;
  }

  // Credit Card must be between 13 and 16 digits
  if (counter<13 || counter>16)
  {
      printf("INVALID\n");
      return 0;
  }
  int cs_seclast = floor((card_number/10)%10) * 2;
  if (cs_seclast > 9)
  {
      int sec1 = floor(cs_seclast/10);
      int sec2 = cs_seclast % 10;
  }
  else
  {
      int sec1 = cs_seclast;
      int sec2 = 0;
  }
  int cs_fourlast = floor((card_number/1000)%10) * 2;
  if (cs_fourlast > 9)
  {
      int four1 = floor(cs_fourlast/10);
      int four2 = cs_fourlast % 10;
  }
  else
  {
      int four1 = cs_fourlast;
      int four2 = 0;
  }
  int cs_sixlast = floor((card_number/100000)%10) * 2;
  if (cs_sixlast > 9)
  {
      int six1 = floor(cs_sixlast/10);
      int six2 = cs_sixlast % 10;
  }
  else
  {
      int six1 = cs_sixlast;
      int six2 = 0;
  }
  int cs_eightlast = floor((card_number/10000000)%10) * 2;
  if (cs_eightlast > 9)
  {
      int eight1 = floor(cs_eightlast/10);
      int eight2 = cs_eightlast % 10;
  }
  else
  {
      int eight1 = cs_eightlast;
      int eight2 = 0;
  }
  int cs_tenlast = floor((card_number/1000000000)%10) * 2;
  if (cs_tenlast > 9)
  {
      int ten1 = floor(cs_tenlast/10);
      int ten2 = cs_tenlast % 10;
  }
  else
  {
      int ten1 = cs_tenlast;
      int ten2 = 0;
  }
  int cs_twelvelast = floor((card_number/100000000000)%10) * 2;
  if (cs_twelvelast > 9)
  {
      int twelve1 = floor(cs_twelvelast/10);
      int twelve2 = cs_twelvelast % 10;
  }
  else
  {
      int twelve1 = cs_twelvelast;
      int twelve2 = 0;
  }
  long long sum = sec1 + 0;
  printf("%lli", sum);
}
