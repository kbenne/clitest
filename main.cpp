#include <iostream>
#include <ruby.h>

extern "C" void Init_rubyfoo(void);

int main() { 
  ruby_init();
  Init_rubyfoo();
  rb_eval_string("Rubyfoo::Foo.new.bar");
}

