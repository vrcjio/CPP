#include<iostream>
#include<chrono>
#include<thread>

int main(){
    std::cerr << "Mein Cerr hu kya mei screen per aaya?";
    std::cout << "Hello World! Kya mei screen per aaya?";
    
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cerr << "Mei second error hu. after time wala.";
    
    std::cout << std::endl; // flush here
    return 0;
}

// run using `./a > test.txt` 

/*
    cout/stdout channle 1 per hota hai or channel 2 per cerr/stderr
    isliye cerr pahale screen per aayega ye test.txt me naa jaa kr bypass
    kr jayega... os ise screen per dikhayega..
    agar cerr/stderr ko jo channel 2 me hai use files me dalana hai to .
    ./a 2> text.txt likh kr kr skte hai yaha 2 channel 2 hai 
    channle 0 bhi hota hai stdin /cin ke liye  
*/