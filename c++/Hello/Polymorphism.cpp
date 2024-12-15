#include <iostream>

using namespace std;

class Animal {
public:
  virtual void speak()
  {
    cout << "Animal Speak";
  }
};

class Cat : public Animal {
public:
  void speak()
  {
    cout << "Cat speak";
  }
};

class Dog : public Animal {
public:
  void speak()
  {
    cout << "Dog speak";
  }
};

void DoSpeak(Animal &animal)
{
  animal.speak();
}

int main()
{
  Cat cat;
  DoSpeak(cat);
}
