#include <iostream>
#include <exception>

class A {
public:
  A() {
    std::cout << "A()" << std::endl;
    throw std::exception();
    std::cout << "after exception" << std::endl;
  }
  ~A() {
    std::cout << "~A()" << std::endl;
  }
 
private:
  char bulk_[1024 * 1024];
};

int test_A() {

  A* a_ptr = NULL;
  try {
    a_ptr = new A();
  } catch (const std::exception &e) {
    delete a_ptr;
    std::cout << "catch(..)" << std::endl;
    return -1;
  }
  std::cout << "a_ptr:" << a_ptr << std::endl;
  delete a_ptr;

  return 0;
}

int main() {
  for (size_t i = 0; i < 1000; ++i) {
    test_A();
  }
  return 0;
}

