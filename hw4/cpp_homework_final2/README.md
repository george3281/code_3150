Pointers: I used pointers char** names and double* gpas point to heap arrays whose sizes are determined by capacity. Each name is stored as a new char[]; updateGPA takes a double* and writes through it (*gpaPtr = newGpa). &gpas[idx] passes the address of one gPA cell when updating. delete[] is used to free the memory of each name on both arrays.

Const: I used const printStudent and const char* name so the name is not modified and const double& gpa to pass the GPA by reference without copying or changing the original. averageGPA takes const double gpas[] so the GPA array is read-only inside the function.

References: The references addStudent takes int&size so adding a student updates the caller's count. printStudent uses const double& gpa so that the gpa values are read-only.

Casting: I casted size to a double using static_cast<double>(size) in order to avoid integer division when calculating the average. When printing, static_cast<int>(avg) converts the average to an integer since the assignment asks for a rounded answer.

Exception: I used an exception in addStudent and averageGPA when the list is full or when size == 0, while updateGPA throws a null pointer. 

Control flow: The menu has a do while loop and a switch to handle control flow.
