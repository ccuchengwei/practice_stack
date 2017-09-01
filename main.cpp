#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
class array
{
    public:
        //constructor
        array(int len);
        ~array()
        {
            delete[] a;
        }
        
        

        

        //operator []
        T& operator[](int i) {
            assert(i >= 0 && i < length);
            return a[i];
        }
        
        //operator =
        array<T>& operator=(array<T> &b) {
            if (a != NULL) delete[] a;
            a = b.a;
            b.a = NULL;
            length = b.length;
            
            return *this;

        }
        int length;
    private:
        T *a;
       
};

template <class T>
array<T>::array (int len) : 
    length(len)
{
   
    a = new T[length];
    
}

class arrayStack
{
    public:
        arrayStack();
        int size(){return n;}
        void resize();
        void add(int i,int x);
        void add(int x);
        int remove();
        void print()
        {
            for(int i=0; i < n-1;i++) cout<< a[i]<< " ";
            cout << a[n-1] << "\n";
        }
    private:
        array<int> a;
        int n;

};

arrayStack::arrayStack():n(0),a(1)
{
}

void arrayStack::add(int i,int x)
{
    assert(i <= n);
    if(n+1 > a.length) resize();
    for(int j = n;j > i;j--)
       a[j] = a[j-1];
    a[i] = x;
    n++;

}
int arrayStack::remove()
{
    a[n-1] = 0;
    n--;
    if(a.length >= 3*n) resize();
}
void arrayStack::add(int x)
{
    if(n + 1 > a.length ) resize();
    a[n] = x;
    n++;

}    

void arrayStack::resize()
{
    array<int> b(max(n*2,1));
    for(int i=0;i < n; i++)
        b[i] = a[i];
    a = b; 
}
int main()
{
    arrayStack stack;
    stack.add(0,1);
    stack.print();
    stack.add(2);
    stack.print();
    stack.remove();
    stack.print();
}




