#include <stdlib.h>
#include <string>
#include "utils/str/basic.hpp"
#include <iostream>

namespace PYICPP
{
  class str
  {
  private:
    char *data;
    int length;

  public:
    // Constructors
    // From char
    str(const char src[])
    {
      // Get length to allocate memory
      int src_length = char_ln(src);

      // Allocate memory and assign this->data's value to this
      this->data = (char *)malloc(sizeof(char) * src_length);

      // Copy all the charecters from src to this->data
      for (int idx = 0; idx < src_length; idx++)
      {
        this->data[idx] = src[idx];
      }
      length = src_length;
    }

    // incomplete type
    str()
    {
      // do nothing
    }

    // From std::string
    str(std::string src)
    {
      // Get length to allocate memory
      int src_length = src.length();

      // Allocate memory and assign this->data's value to this
      this->data = (char *)malloc(sizeof(char) * src_length);

      // Copy all the charecters from src to this->data
      for (int idx = 0; idx < src_length; idx++)
      {
        this->data[idx] = src[idx];
      }
      length = src_length;
    }

    // Destructor
    ~str()
    {
      if (length == 0)
        return;
      free(this->data);
    }

    // Functions
    str capitalize()
    {
      char result[length];
      for (int idx = 0; idx <= length; idx++)
      {
        if (idx == 0)
        {
          result[idx] = toupper(this->data[idx]);
          continue;
        }
        result[idx] = tolower(this->data[idx]);
      }
      return str(result);
    }

    bool endswith(char suffix[])
    {
      return p_endswith(this->data, suffix);
    }

    bool endswith(std::string suffix)
    {
      return p_endswith(this->data, suffix.c_str());
    }

    int count(str t)
    {
      return csbstr(this->data, t);
    }

    int count(char t[])
    {
      return csbstr(this->data, t);
    }
    int count(std::string t)
    {
      return csbstr(this->data, t.c_str());
    }

    bool isascii()
    {
      if (length == 0)
        return false;

      for (int idx = 0; idx < length; idx++)
      {
        if (this->data[idx] > 127)
        {
          return false;
        }
      }

      return true;
    }

    bool isalpha()
    {
      if (length == 0)
        return false;

      for (int idx = 0; idx < length; idx++)
      {
        if (this->data[idx] < 'A' || this->data[idx] > 'z')
        {
          return false;
        }
      }
      return true;
    }
    bool isdecimal()
    {
      if (length == 0)
        return false;

      int idx = 0;
      while (this->data[idx] != '\0')
      {
        if (this->data[idx] < 48 && this->data[idx] > 57)
        {
          return false;
        }
      }

      return true;
    }
    bool isalnum()
    {
      if (length == 0)
        return false;

      if (isalpha() || isdecimal())
      {
        return true;
      }
      return false;
    }
    bool islower()
    {
      int idx = 0;
      while (this->data[idx] != '\0')
      {
        if (!tolower(this->data[idx]) != this->data[idx])
        {
          return false;
        }
        if (this->data[idx] == ' ')
        {
          return false;
        }
      }
      return true;
    }
    bool isupper()
    {
      int idx = 0;
      while (this->data[idx] != '\0')
      {
        if (!toupper(this->data[idx]) != this->data[idx])
        {
          return false;
        }
        else if (!isalpha())
        {
          return false;
        }
      }
      return true;
    }
    bool isspace()
    {
      int idx = 0;
      while (this->data[idx] != '\0')
      {
        if (this->data[idx] != '\n' && this->data[idx] != ' ' && this->data[idx] != '\r' && this->data[idx] != '\t' && this->data[idx] != '\v' && this->data[idx] != '\f')
        {
          return false;
        }
      }
      return true;
    }
    int len()
    {
      return length;
    }

    // to char*
    operator char *()
    {
      return this->data;
    }
    // add
    str &operator+(const char target[])
    {
      int target_l = char_ln(target);
      int src_l = char_ln(this->data);
      int idx = 0;
      length = target_l + src_l;

      char *res;

      res = (char *)malloc(sizeof(char) * (target_l + src_l));

      while (idx < src_l)
      {
        res[idx] = this->data[idx];
        idx++;
      }

      int t_idx = 0;
      while (t_idx < target_l)
      {
        res[idx] = target[t_idx];
        idx++;
        t_idx++;
      }
      free(this->data);
      this->data = res;
      this->length = target_l + src_l;

      return *this;
    }

    str &operator+=(const char target[])
    {
      int target_l = char_ln(target) - 1;
      int src_l = char_ln(this->data) - 1;
      int idx = 0;

      char *res;

      res = (char *)malloc(sizeof(char) * (target_l + src_l));

      while (idx < src_l)
      {
        res[idx] = this->data[idx];
        idx++;
      }

      int t_idx = 0;
      while (t_idx < target_l)
      {
        res[idx] = target[t_idx];
        idx++;
        t_idx++;
      }
      free(this->data);
      this->data = res;
      this->length = target_l + src_l;

      return *this;
    }
  };
}; // namespace PYICPP