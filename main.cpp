#include <iostream>
#include <stdexcept>

class smart_array{
   int size{};
   int capacity{};
   int* pnum;
   public:
   smart_array(int num) : capacity(num){
     pnum = new int[num]();
   }
   int& operator[](int ind){
     if(ind<size&&ind>=0){
       return pnum[ind];
     }else{
       throw std::out_of_range("Array index out of bound!");
       //exit(1);
     }
   }
   int get_element(int ind){
     return this->operator[](ind);
     /*auto& self = *this;
     return self[ind];*/
     //return this->[ind] THROWS ERROR!!
     //return (*this)[ind] THROWS ERROR!!
   }
   void add_element(int n){
     if(size == capacity){
       int* pnum_new = new int[capacity*2];
       capacity *= 2;
       int i{};
       for(; i<size; i++){
         pnum_new[i] = pnum[i];
       }
       pnum_new[i+1] = n;
       int* pnum_old = pnum;
       pnum = pnum_new;
       delete[] pnum_old;
     }else{
       pnum[size] = n;
     }
     size++;
   }
   smart_array(const smart_array& smar_first): size(smar_first.size),
       capacity(smar_first.capacity) {
     pnum = new int[capacity];
     for (int i = 0; i < size; ++i) {   // copy smar_first's values
        pnum[i] = smar_first.pnum[i];  // into this array
     }
   }
   smart_array& operator=(const smart_array &smar_first) { // deep copy assignment overloading
     // self-assignment is a special case: don't need to do anything
     if (this == &smar_first) {
       ;
     } else {
       size = smar_first.size;
       capacity = smar_first.capacity;
       delete [] pnum;
       pnum = new int[capacity];
       for (int i = 0; i < size; ++i) {   // copy smar_first's values
           pnum[i] = smar_first.pnum[i];  // into this array
       }
     }
     return *this;
   }
   ~smart_array(){
     delete[] pnum;
   }
};

int main() {
  smart_array arr(5);
  arr.add_element(1);
  arr.add_element(4);
  arr.add_element(155);

  smart_array new_array(2);
  new_array.add_element(44);
  new_array.add_element(34);

  std::cout << arr.get_element(1) << std::endl;

  arr = new_array;

  std::cout << arr.get_element(1) << std::endl;

  //smart_array arr2 = arr;

  //std::cout << arr2.get_element(1) << std::endl;

}
