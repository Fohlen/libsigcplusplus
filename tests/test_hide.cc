// -*- c++ -*-
/* Copyright 2002, The libsigc++ Development Team
 *  Assigned to public domain.  Use as you wish without restriction.
 */

#include <sigc++/adaptors/hide.h>
#include <iostream>

struct foo : public sigc::functor_base
{
  // choose a type that can hold all return values
  typedef int result_type;
  int operator()()
    {std::cout << "foo()"<<std::endl; return true;}
  int operator()(int j) 
    {std::cout << "foo(int "<<j<<")"<<std::endl; return 1+j;}
};

struct foo_void : public sigc::functor_base
{
  typedef void result_type;
  void operator()()
    {std::cout << "foo_void()"<<std::endl;}
};

namespace sigc { SIGC_FUNCTOR_TRAIT(foo,bool) }


int main()
{
  std::cout << sigc::hide<1>(foo())(1,2) << std::endl;
  std::cout << sigc::hide<2>(foo())(1,2) << std::endl;
  std::cout << sigc::hide<0>(foo())(1) << std::endl;
  sigc::hide<0>(foo_void())(1); // void test
}
