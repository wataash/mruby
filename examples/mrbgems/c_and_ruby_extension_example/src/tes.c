#include <mruby.h>
#include <mruby/string.h>

// mruby.h
static void
mruby(mrb_state *mrb)
{
  // 1222 mrb_p
  {
    // step-in and learn many...
    mrb_p(mrb, mrb_nil_value());
  }
}

// mruby/string.h
static void
string(mrb_state *mrb)
{
  // 178 mrb_str_concat
  {
    mrb_value str1;
    mrb_value str2;
    str1 = mrb_str_new_lit(mrb, "abc");
    str2 = mrb_str_new_lit(mrb, "def");
    mrb_str_concat(mrb, str1, str2); // destruct str1
    mrb_p(mrb, str1); // "abcdef"
    mrb_p(mrb, str2); // "def"
  }

  // 288 mrb_str_resize
  {
    // Creates a new string.
    mrb_value str = mrb_str_new_lit(mrb, "Hello, world!");
    // Returns 5 characters of
    mrb_str_resize(mrb, str, 5);
    mrb_p(mrb, str); // "Hello"
  }

  // 330 mrb_str_substr
  {
    mrb_value str1;
    mrb_value str2;
    str1 = mrb_str_new_lit(mrb, "Hello, world!");
    // Returns a sub-string within the range of 0..2
    str2 = mrb_str_substr(mrb, str1, 0, 2);
    mrb_p(mrb, str2);
  }

  // 386 mrb_str_to_str
  {
    // return mrb_convert_type(mrb, str, MRB_TT_STRING, "String", "to_s");
  }
}

void
tes(mrb_state *mrb)
{
  mruby(mrb);
  string(mrb);
}
