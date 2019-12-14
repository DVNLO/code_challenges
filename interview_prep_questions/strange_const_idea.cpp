#include <iostream>
using namespace std;
class Point
{
    int x, y;
  public:
   Point(int i = 0, int j =0)
   { x = i; y = j;  }
   int getX() const { return x; }
   int getY() {return y;}
};
 
int main()
{
    const Point t;
    cout << t.getX() << " ";	// a const Point object t cannot make 
    				// calls to non-const member functions.
				// Very intriguing. I have run into this before,
				// but I forgot it here.
    cout << t.getY();
    return 0;
}
