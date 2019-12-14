// https://www.sanfoundry.com/cplusplus-programming-questions-answers-oops-concept-4/
// The above link, number 4, states that the below code will result in a 
// segmentation fault when run. This did not occur on my computer. I was 
// initially skeptical of this because their resoning suggests that this is 
// an improper use of delete, but it is correct. It simply only calls the 
// destructor of one of the 5 objects created and then the program exits. 
// Their conclusion was not correct in my experience.

#include <bits/stdc++.h>
using namespace std;
class A{
public:
	A(){
		cout<<"Constructor called\n";
	   }
	~A(){
		cout<<"Destructor called\n";
	    }
};
int main(int argc, char const *argv[])
{
	A *a = new A[5];
	delete a;	// delete the one object of class A a points too. The remaining
				// objects remain in memory, but it doesn't matter because
				// the program exits and it's the OS's responsibility to manage
				// destruction of this processes heap. 
	return 0;
}
