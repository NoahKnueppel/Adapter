#include <iostream>

class Square
{
  public:
    virtual void draw() = 0;
};

class LegacySquare
{
  public:
    LegacySquare(int x1, int y1, int x2, int y2) {
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
        std::cout << "LegacySquare(x, y, w, h)\n";
    }

    void oldDraw() {   

     }
  private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;
};

class SquareAdapter: public Square, private LegacySquare 
{
  public:
    SquareAdapter(int x, int y, int w, int h):
      LegacySquare(x, y, x + w, y + h) {
         std::cout << "SquareAdapter(x + y + w + h)\n";
      }
    
    void draw() { 
        oldDraw();
    }
};

int main()
{
  int x = 30, y = 60, w = 500, h = 400;
  Square *r = new SquareAdapter(x,y,w,h);
  r->draw();
}