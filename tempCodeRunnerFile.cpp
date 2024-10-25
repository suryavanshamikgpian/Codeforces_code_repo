#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack {
    
    public:
    int top =-1;
        int a[MAX]; // Maximum size of Stack
        bool push(int x){
            if (top >= (MAX - 1)) {
                cout << "Stack Overflow";
                return false;
            }
            else {
                a[++top] = x;
                cout << x << " pushed into stack\n";
                return true;
            }
        }
        int pop(){
            if (top < 0) {
                cout << "Stack Underflow";
                return 0;
            }
            else {
                int x = a[top--];
                return x;
            }
        }

        int peek(){
            if (top < 0) {
                cout << "Stack is Empty";
                return 0;
            }
            else {
                int x = a[top];
                return x;
            }
        }
        bool isEmpty(){
            return (top < 0);
        }
};

// Driver program to test above functions
int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << " Popped from stack\n";
	
	//print top element of stack after poping
	cout << "Top element is : " << s.peek() << endl;
	
	//print all elements in stack :
	cout <<"Elements present in stack : ";
	while(!s.isEmpty())
	{
		// print top element in stack
		cout << s.peek() <<" ";
		// remove top element in stack
		s.pop();
	}

	return 0;
}
