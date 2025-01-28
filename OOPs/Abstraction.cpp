/*
  Abstraction means displaying only essential information and hiding the details. 
  Data abstraction refers to providing only essential information about the data 
  to the outside world, hiding the background details or implementation. 
  Consider a real-life example of a man driving a car. The man only knows 
  that pressing the accelerator will increase the speed of the car or applying
   brakes will stop the car but he does not know how on pressing the accelerator 
   the speed is actually increasing, he does not know about the inner mechanism of 
   the car or the implementation of an accelerator, brakes, etc. in the car. 
   This is what abstraction is.
   Abstraction using Classes: We can implement Abstraction in C++ using classes. 
   The class helps us to group data members and member functions using available access specifiers.
    A Class can decide which data member will be visible to the outside world and which is not.
Abstraction in Header files: One more type of abstraction in C++ can be header files. 
For example, consider the pow() method present in math.h header file. 
Whenever we need to calculate the power of a number, we simply call the 
function pow() present in the math.h header file and pass the numbers as 
arguments without knowing the underlying algorithm according to which the 
function is actually calculating the power of numbers.
*/