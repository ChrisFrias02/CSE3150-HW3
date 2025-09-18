 #HW 3

 Implementation

- Parallel arrays sized by command-line capacity**  
  I set up two arrays based on the number the user gives when running the program. One array holds the student names (char** names = new char*[capacity];) and the other holds their GPAs (double* gpas = new double[capacity];). The arrays grow as I add students until they reach that max capacity.  

- addStudent**  
  This function takes in a C-style string for the student name and their GPA, then copies the name into a new chunk of memory using std::strcpy. It also checks that there’s still room left in the arrays. If the list is already full, it throws an error string.  

- updateGPA**  
  Here I pass a pointer to a GPA. By dereferencing the pointer (*gpaPtr), I can directly update that student’s GPA in the array. If the pointer is `nullptr or the GPA is out of range, I handle that gracefully.  

- printStudent**  
  This prints a student’s info nicely. It uses const on the name and GPA so nothing gets changed inside the function. I also used a reference (`const double& gpa) to avoid copying the GPA unnecessarily.  

- averageGPA**  
  This loops through the GPA array, adds them all up, and divides by the number of students. If there are no students, it throws an exception string. The average is printed both as a double and as a rounded integer using static_cast<int>.  

- *Menu and control flow**  
  In main, I made a loop with a menu so the user can pick options: add, update, print, average, or quit. The menu uses a switch statement, and I made sure to always use braces for if/`else so it’s clear and easy to follow.  

- Exceptions**  
  I throw and catch string exceptions (like `"Error: list is full") whenever something goes wrong, and then display the message to the user.  

- Pointers, const, and references**  
  - Pointers: used to directly modify GPA values in memory.  
  - Const: used in function parameters to protect values from being changed.  
  - References: used to pass variables around without copying.  

- *string library**  
  I used std::strlen to measure the name length and std::strcpy to copy names into new memory. This keeps everything in C-style strings instead of std::string`, which is the whole point of this exercise.  # CSE3150-HW3
