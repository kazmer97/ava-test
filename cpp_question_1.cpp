// implement a class with a member function int nobjs() which returns the number of object of the class currently in existence.

#include <iostream>
using namespace std;
template <class T>
class Counter
{
  private:
      static int count;
  public:
    Counter()
    {
       count++;
    }  
    Counter(const Counter &c)
    {
       count++;
    }   
    ~Counter()
    {
       count--;
    }
        
    static int nobjs() {

         return count;
    }
};

template<class T> 
int Counter<T>::count = 0; 



class MyClass : private Counter<MyClass>
{
   public:
    ;  using Counter<MyClass>::nobjs;
};


int main()
{
   MyClass a, b, c;
   cout << "Number of objects: " << MyClass::nobjs() << endl;

   return 0;
}