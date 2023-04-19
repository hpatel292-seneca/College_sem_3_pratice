// The time to complete a communication is referred to as its latency. The latency of a communication between a processor and a resource is at least one order of magnitude greater than that between the processor and main memory. Accessing a resource can leave the processor idle for a considerable period of time. A processor waiting for a communication to complete is available to execute another task or another program.

//Operating systems are designed to switch from one task or program to another. The system of switching from one task to another is called multi-tasking.

// A thread is a sequence of program instructions that represents an independent flow of control within a process

// A thread may be a software thread or a hardware thread. A software thread is a virtual thread associated with a task within a process. The task may be the same or different from the task associated with another thread. A hardware thread is a mini-process that executes a software thread (that is, the task associated with the software thread). The operating system's scheduler maps software threads to hardware threads.

//a thread is the lighter unit of system scheduling, while a process is the heavier.

// A process starts executing on a single thread. When it encounters an instruction that divides the execution path into concurrent tasks, we say that the process launches a concurrent task or spawns a child thread. When the child thread reunites with its parent, we say that the two join or the child and parent threads synchronize. The join point in the execution path is the synchronization point. If either task is still executing when the one thread reaches this point, that thread waits until the other has completed its task.

// A race condition occurs whenever two threads can update the same memory location at the same time. If a race condition is present, one run may produce different results from a subsequent run as different threads access shared memory in different orders in each run. Techniques for avoiding race conditions include shared states, mutexes, locks, and atomics.

// Mutex stands for mutual exclusion. It is a technique that excludes access by other threads to a memory location while a particular thread updates the value at that location. Mutexes are implemented using locks. The thread that is changing the value owns a lock on the memory locations and must release it before any other thread can acquire that lock.

// A deadlock occurs when two or more threads are waiting for one another to complete execution and therefore are blocked forever.

// Vectorization is the register-based technique that implements a single instruction multiple data execution (must be supported by the hardware)

// Threaded_class
//  These libraries implement the Resource Allocation Is Initialization (RAII) idiom.
 //A thread object is either joinable or not-joinable. A joinable object represents an actual thread of execution with a unique id. A non-joinable object represents a potential thread of execution (the object is not associated yet with a hardware thread, or the thread has been already joined). Operations on a thread object can change its joinable/non-joinable state.

// #include<iostream>
// #include<vector>
// #include<thread>
// //using namespace std;

// void task(){
//     std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
// }

// int main(){
//     std::vector<std::thread> threads;

//     for (size_t i = 0; i < 10; i++)
//     {
//         threads.push_back(std::thread(task));
//     }

//     for (size_t i = 0; i < 10; i++)
//     {
//         threads[i].join();
//     }
//     return 0;
    
// }

// Thread Class - Thread Identifiers
// thread_id.cpp

// Thread Class - Function with Arguments
// thread_id_arg.cpp

// Thread Class - Function Object
// thread_id_fo.cpp

#include <iostream>
#include <thread>
#include <vector>

// constexpr int NT = 10;

// class Task
// {
//   public:
//     Task() = default;
//     void operator()(int i)
//     {
//         std::cout << i << " Thread id = "
//                   << std::this_thread::get_id() << std::endl;
//     }
// };

// int main()
// {
//     // create a vector of not-joinable threads
//     std::vector<std::thread> threads;

//     // launch execution of each thread
//     for (int i = 0; i < NT; i++)
//         threads.push_back(std::thread(Task(), i));

//     // synchronize their execution here
//     for (auto& thread : threads)
//         thread.join();
// }

// The future library of the thread support category facilitates efficient transfer of values between tasks through shared states. The class and function templates that support communications across a shared state are defined in the header file <future>.

// Instantiation of the templated std::future class creates a future object. A future object is either valid or not-valid. A valid object is associated with a shared state and can retrieve the value of that shared state once it is ready. Until it is ready, any retrieval request necessarily waits.

// The templated promise class defines a simple set_value() counterpart to the get() member function of the templated future class.

// Promise - Future
// promise_future.cpp

#include <iostream>
#include <thread>
#include <future>

void task(std::promise<double>& p)
{
    p.set_value(12.34);
}

int main()
{
    std::promise<double> p;
    std::future<double> f = p.get_future();
    std::thread t(task, std::ref(p));
    std::cout << "Value = " << f.get()<< std::endl;
    t.join();
}