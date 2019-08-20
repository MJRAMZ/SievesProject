//===================================
// Sieves of Eratosthenes Project
// Created by: MJRAMZ
//===================================

#include <iostream>
#include <cmath>
#include "Sieves.cpp"

using namespace std;

int main()
{
    // Empty queue to store integers
    SievesQueue<int> queueOfNumbers;
    // Empty queue to store primes
    SievesQueue<int> queueOfPrimes;
    // Temporary Queue to store multiples of primes
    SievesQueue<int> tempQueue;

    //-----------------
    // Local variables
    //-----------------
    // Num -- stores user submitted integer value;
    int num = 0;
    // p -- stores the value of the first prime number
    int p;
    // NextP -- stores value of the next prime in queue.
    int nextP;

    // Introduction Message
    cout << "===================================================================" << endl;
    cout << "This program will implement the Sieves of Eratosthenes Algorithm, " << endl;
    cout << "to compute all the prime numbers up to some integer N." << endl;
    cout << "===================================================================" << endl;

    // Get user input
    cout << "Please Enter an Integer Value for N: ";
    cin >> num;

    // Input validation
    while(num < 2)
    {
        // Display message
        cout << "INPUT ERROR: ";
        cout << "Please enter integers greater than 1.";

        // Get user input
        cout << "\nPlease Enter an Integer Value for N: ";
        cin >> num;
    }

    // Fill up the queue
	queueOfNumbers.fillQueue(num);
	cout << "\nFilling up the Integer Queue.....Adding numbers from 2 to " << num << endl;
	// Display
	cout << "\nQueue of Integers: ";
	queueOfNumbers.display();


    // Sieve Algorithm Implementation
    do{
        // Get the next prime by removing the first value in numbers queue
        p = queueOfNumbers.dequeue();
        // Place p into the queue of primes
        queueOfPrimes.enqueue(p);

        // Store size of numbers queue into local variable qSize
        int qSize = queueOfNumbers.getSize();

        // loop through the numbers queue
        for(int j=0; j<qSize; j++)
        {
            // dequeue the next value
            nextP = queueOfNumbers.dequeue();
            // If not divisible by p -- removes all multiples of p
            if((nextP % p) != 0)
            {
                // Enqueue the remaining values back onto numbers queue
                queueOfNumbers.enqueue(nextP);
            }
        }

    }while(p<sqrt(num)); // End of do while -- sieve implementation

    // While the numbers queue is not empty
    while(!queueOfNumbers.isEmpty())
    {
        // Take any remaining values from the numbers queue
        p = queueOfNumbers.dequeue();
        // Add them to the primes queue.
        queueOfPrimes.enqueue(p);
    }
    // Display the primes queue
    cout << "\nRemoving Prime Numbers....Adding them to the Primes Queue" << endl;
    cout << "\nQueue of Primes: ";
    queueOfPrimes.display();

	system("pause");

    return 0;

}
