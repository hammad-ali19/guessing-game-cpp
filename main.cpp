#include <iostream>
#include <chrono>
#include <random>

class randomDevice {
    private:
        unsigned long seed;
        std::default_random_engine engine;
    public:
        randomDevice();
        // randomDevice(unsigned long);
        int randInt(int,int);
};

// randomDevice::randomDevice(unsigned long n) : seed(n), engine(n) {};

randomDevice::randomDevice()
{
    unsigned long _seed  = std::chrono::system_clock::now().time_since_epoch().count();
    seed = _seed;
    engine.seed(_seed);
}

int randomDevice::randInt(int min, int max){
    std::uniform_int_distribution<int> distribution(min,max);
    int rand_num = distribution(engine);
    return rand_num;
}

int main()
{
    randomDevice random;
    int rand_int = random.randInt(1,100);
    int guess {};
    int tries {1};
    std::cout << "Welcome to this Guessing Game! \n";
    std::cout << "Guess the Number (1-100): ";
    std::cin >> guess;

    do 
    {
        if(guess < rand_int)
        {
            std::cout << "Higer Number Please: ";
            std::cin >> guess;
            tries++;
        }
        else if(guess > rand_int)
        {
            std::cout << "Lower Number Please: ";
            std::cin >> guess;
            tries++;
        }
    }
    while(guess != rand_int);

    std::cout << "Congratulations! You got it in " << tries << " attempts.\n";
    return 0;
}