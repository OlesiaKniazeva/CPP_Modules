#include "Classes.hpp"

int main()
{
  Base *pointer;

  pointer = generate();
  identify(pointer);
  Base &reference = *pointer;
  identify(reference);

  delete pointer;
}
