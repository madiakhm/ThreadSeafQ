# Thread-Safe Queue Implementation

## Introduction  
This C++ program implements a thread-safe queue using mutex locks. It demonstrates how to ensure safe concurrent access to a queue data structure in a multi-threaded environment.

## Files 
- `thread_safe_queue.cpp`: This file contains the implementation of the thread-safe queue class and its usage in a multi-threaded environment.
- `README.md`: This file provides information about the program.

## Implementation Details  
The program defines a `ThreadSafeQ` class that encapsulates a standard queue and provides methods for safe insertion, retrieval, and printing of queue elements in a multi-threaded context. The class uses mutex locks to synchronize access to the queue, ensuring that multiple threads can operate on it safely.

### `main` Function 
The `main` function demonstrates the usage of the `ThreadSafeQ` class. It initializes a queue with some initial values, creates threads to perform queue operations concurrently, and prints the contents of the queue after each operation.

## Usage  
To compile and run the program, follow these steps:
1. Ensure you have a C++ compiler installed on your system.
2. Open a terminal or command prompt.
3. Navigate to the directory containing the `thread_safe_queue.cpp` file.
4. Compile the program using the following command:g++ -o thread_safe_queue thread_safe_queue.cpp -std=c++11 -pthread

Note: The `-std=c++11` flag is used to enable C++11 features, and the `-pthread` flag is used to link the pthread library for multithreading support.
5. Run the compiled executable:./thread_safe_queue


## Example Output  
1 2 3 4


## Notes 
- The program ensures thread safety by using mutex locks to synchronize access to the queue.
- This implementation can be extended to support other queue operations and data types.


