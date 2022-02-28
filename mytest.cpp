#include "puzzle.h"

class Tester{                                                                              
    public:
 
  bool testAssignmentOperator(const Puzzle& puzzle, const Puzzle& copy);
  void measureInsertionTime(int numTrials, int N);
};

int main() {
    Tester tester;
    {
      Puzzle p1(1000);
      Puzzle copy1 = p1;
      //Regular assignament operator test
      cout << "Test case, Assignment Operator: members and sise should be the same, but different pointers:" << endl;
      if(tester.testAssignmentOperator(p1, copy1)) cout << "Assignment Operator passed!\n" << endl;
      else cout << "Assignment Operator failed!\n" << endl;

      p1 = p1;
      //Slef-assignament test - Remember to check valgrind
       cout << "Test case, Assignment Operator: Self assignament" << endl;
      if(tester.testAssignmentOperator(p1, p1)) cout << "Assignment Operator passed!\n" << endl;
      else cout << "Assignment Operator failed!\n" << endl;
    }
    {
      Puzzle p2(1);
      Puzzle copy2 = p2;
      //Test Case for only 1 member
      cout << "Test case, Assignment Operator: 1 member:" <<	endl;
      if(tester.testAssignmentOperator(p2, copy2)) cout << "Assignment Operator passed!\n" << endl;
      else cout	<< "Assignment Operator failed!\n" << endl;
    }
    {
      Puzzle p3(0);
      Puzzle copy3 = p3;
      //Test Case for zero members
      cout << "Test case, Assignment Operator: zero members:" <<	endl;
      if(tester.testAssignmentOperator(p3, copy3)) cout << "Assignment Operator passed!\n" << endl;
      else cout	<< "Assignment Operator failed!\n" << endl;
    }
    {
      Puzzle p4(-2);
      Puzzle copy4 = p4;
      //Test Case for negatize amount of members
      cout << "Test case, Assignment Operator: negative size of members:" <<	endl;
      if(tester.testAssignmentOperator(p4, copy4)) cout << "Assignment Operator passed!\n" << endl;
      else cout	<< "Assignment Operator failed!\n" << endl;
    }
     {
        //Measuring the efficiency of insertion functionality                                                                                                    
        cout << "\nMeasuring the efficiency of insertion functionality:" << endl;
        int M = 5;//number of trials                                                                                                                             
        int N = 1000;//original input size                                                                                                                       
        tester.measureInsertionTime(M, N);
    }


}


bool Tester::testAssignmentOperator(const Puzzle& puzzle, const Puzzle& copy){
  bool result = false;

  //If-else to avoid treating self-assignament as a regular test
  if(&puzzle == &copy){
    result = true;
    cout << "This is a self assignament. This test is not needed. Check Valgrind" << endl;
  }
  else{
  if(puzzle.m_size == 0 && copy.m_size == 0)
    result = true;
  else {
    if(puzzle.m_size == copy.m_size && puzzle.m_table != copy.m_table){
      for(int r = 0; r < copy.m_size; r++){
	for(int c = 0; c < copy.m_size; c++){
	  if(puzzle.m_table[r][c] == copy.m_table[r][c] &&
	     puzzle.m_table[r] != copy.m_table[r])
	    result = true;
	}
      }
    }
  }
  }  
    return result;

}


//IMPORTANT-NOTE: This function has been copied from the driver class
//that was provided to me. Minor changes have been made to
//satisfy project requirements
void Tester::measureInsertionTime(int numTrials, int N)
{

  const int a = 2;//scaling factor for input size                                                                                                              
  double T = 0.0;//to store running times                                                                                                                      
  clock_t start, stop;//stores the clock ticks while running the program                                                                                       
    for (int k=0;k<numTrials-1;k++)
    {
      Puzzle p1(N);
        start = clock();
        Puzzle copy(p1);//the algorithm to be analyzed for efficiency                                                                                               
        stop = clock();
        T = stop - start;//number of clock ticks the algorithm took                                                                                              
        cout << "Inserting " << N * N << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
        N = N * a;//increase the input size by the scaling factor                                                                                                
    }
  

}
