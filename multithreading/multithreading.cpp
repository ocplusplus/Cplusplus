#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>

//a program using multi-threads to create a global integer vectorand storing the outcome


std::vector<int> fibSeries;
std::mutex mtx;

void FibonacciNumber(std::promise<int>&& prom, int n1, int n2) {
    try {
        while (true) {
            int next = n1 + n2;
            prom.set_value(next); // Set the value in the promise
            n1 = n2;
            n2 = next;
        }
    }
    catch (...) {
        prom.set_exception(std::current_exception());
    }
}

void printFibSeries() {
    while (true) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Current Fibonacci Series: ";
        for (int num : fibSeries) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int first = 0, second = 1; // Initial values for Fibonacci series

    try {
        // Create promise and future for retrieving Fibonacci number
        std::promise<int> prom;
        std::future<int> fut = prom.get_future();

        // Start Fibonacci calculation thread
        std::thread t1(FibonacciNumber, std::move(prom), first, second);
        t1.detach();

        // Retrieve Fibonacci numbers from the future and insert them into the vector
        while (true) {
            int next = fut.get(); // Get the value from the future
            {
                std::lock_guard<std::mutex> lock(mtx);
                fibSeries.push_back(next);
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Start printing thread
    std::thread t2(printFibSeries);
    t2.join();

    return 0;
}
//NB: The output is an infinite loop and eventual runtime error due to misuse of the std::promise and std::future mechanism
//along with thread management issues. In the Fibonacci calculation thread (t1), the FibonacciNumber function continuously processes 
//without a termination condition, pushing new values into promise. At the same time, the main thread indefinitely waits for values from future 
// and the printFibSeries function is running which causes for congestion in competing memory allocation, leading to a runtime error.
