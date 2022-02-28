#ifndef _PUZZLE_H
#define _PUZZLE_H
#include <cstdlib>//used to generate random numbers
#include <ctime>//used to get the current time
#include <iostream>
using namespace std;
class Grader;//this class is for grading purposes, no need to do anything
class Tester;//this is your tester class, you add your test functions in this class
const int MAX = 27;
const char ALPHA[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z', '#'};
class Puzzle{
    public:
    friend class Grader;
    friend class Tester;
  Puzzle(int size=0);
    Puzzle(const Puzzle& rhs);
    const Puzzle& operator=(const Puzzle& rhs);
    void dump();
    ~Puzzle();
    private:
    void makeMem();
    void fill();
    void clear();
    char ** m_table;//2d table to store chars
    int m_size;//used for both number of columns and number of rows

    // ***************************************************
    // Any private helper functions must be delared here!
    // ***************************************************
};
#endif
