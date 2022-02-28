#include "puzzle.h"

Puzzle::Puzzle(int size){

  //If-else statement to guard against negative size
  if(size <= 0)
    m_size = 0;
  else
    m_size = size;

  makeMem();
  fill();
}

Puzzle::~Puzzle(){
    clear();
}

void Puzzle::clear(){

  //If elase statement to terminate
  //function if there ie no data to clear
  if(m_size == 0)
    return;
  else {
    //For loop to go through array and delete data
    for( int i = 0;  i < m_size; i++)
      delete [] m_table[i];

    delete [] m_table;
  }
}

void Puzzle::makeMem(){

  //Check to see if there is a neeed to allocate memory first
  if(m_size == 0)
    return;
  else {
    m_table = new char*[m_size];

    //Depending on size, allocate memory
    for(int i = 0; i < m_size; i++)
      m_table[i] = new char[m_size];
    
  }    
}

Puzzle::Puzzle(const Puzzle& rhs){

  //clone size first
  m_size = rhs.m_size;

  if(m_size > 0)
    {
      //allocate memeory, then cop data
  makeMem();

  int c = 0;
  int r = 0;

  while( c < m_size) {
    while (r < m_size) {
      m_table[c][r] = rhs.m_table[c][r];
      r++;
    }
    r = 0;
    c++;
  }
    } else
    return;
  
  
}

const Puzzle& Puzzle::operator=(const Puzzle& rhs){
    
  //If statement to guard against self-assignment
  if(this != &rhs)
    {
      //Deallocate memory first
      for( int i = 0;  i < m_size; i++)
      delete [] m_table[i];

    delete [] m_table;

    //Then procees to clone size and data
    m_size = rhs.m_size;

   if(m_size > 0){
    m_table = new char*[m_size];

    for(int i = 0; i < m_size; i++)
      m_table[i] = new char[m_size];

    int c = 0;
  int r = 0;

  while( c < m_size) {
    while (r < m_size) {
      m_table[c][r] = rhs.m_table[c][r];
      r++;
    }
    r = 0;
    c++;
  }
    }

    }
    return *this;  
}

void Puzzle::dump(){
    if (m_size > 0){
        int i=0;
        int j=0;
        while(i<m_size){
            while(j<m_size){
                cout << m_table[i][j] << " ";
                j++;
            }
            cout << endl;
            j=0;
            i++;
        }
        cout << endl;
    }
}
void Puzzle::fill(){
    srand(time(NULL));//create the seed value using the current time
    int i=0;
    int j=0;
    while(i<m_size){
        while(j<m_size){
            m_table[i][j] = ALPHA[rand() % MAX];//find a random char from the chars list
            j++;
        }
        j=0;
        i++;
    }
}
