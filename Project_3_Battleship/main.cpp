#include <cstdlib>
#include "Input.h"

int main(int argc, char** argv) {
  Input input;
  input.RunTest();
  input.Destroy();
  return 0;
}