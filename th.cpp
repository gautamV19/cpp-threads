#include <iostream>
#include <thread>

using namespace std;

void threadFn(){
    cout<<"Jai Swaminarayan"<<endl;
}

void threadFn2(){
    cout<<"Jai Swaminarayan 2"<<endl;
}

int main(){
    thread t1(threadFn);
    t1.join();

    thread t2(threadFn2);
    t2.join();

    return 0;
}