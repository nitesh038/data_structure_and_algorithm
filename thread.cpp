//odd number 
// even 
#include <iostream>
#include<thread>
#include <mutex>

std::mutex g_mutex;
int count=1;
void even_number()
{
        g_mutex.lock();
        count++;
        std::cout<< count;
        g_mutex.unlock();

}
void odd_number()
{
        g_mutex.lock();
        count++;
        std::cout<< count;
        g_mutex.unlock();
}

int main()
{
    

    std::thread even_thread(even_number);
    
    std::thread odd_thread(odd_number);

    even_thread.join();
    

    return 0;

}
