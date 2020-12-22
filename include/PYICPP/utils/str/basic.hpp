#include <stdio.h>

// returns source string length - 1
int char_ln(const char t[])
{
  int len = 0;
  while (t[len] != '\0')
  {
    len++;
  }

  return len;
}

char toupper(char s)
{
  if (s >= 'a' && s <= 'z')
  {
    return s - 32;
  }
  return s;
}

char tolower(char s)
{
  if (s >= 'A' && s <= 'Z')
  {
    return s + 32;
  }
  return s;
}

char reversecase(char s)
{
  if (s >= 'A' && s <= 'Z')
  {
    return s + 32;
  }
  else if (s >= 'a' && s <= 'z')
  {
    return s - 32;
  }
  else
  {
    return s;
  }
}

int csbstr(char src[], const char target[])
{
  int mIdx = 0, idx = 0, count = 0, target_ln = char_ln(target) - 1;
  while (src[idx] != '\0')
  {
    if (target[mIdx] == src[idx])
    {
      mIdx += 1;
    }
    else
    {
      mIdx = 0;
    }

    if (mIdx == target_ln)
    {
      count++;
      mIdx = 0;
    }
    idx++;
  }
  return count;
}

bool p_endswith(char src[], const char target[])
{
  int target_l = char_ln(target) - 1, mIdx = target_l, src_l = char_ln(src) - 1;
  bool matches = true;

  while (matches == true)
  {
    if (src[src_l] == target[target_l])
    {
      src_l -= 1;
      target_l -= 1;
    }
    else
    {
      matches = false;
      break;
    }
  }

  return matches;
}