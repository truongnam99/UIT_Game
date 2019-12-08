#ifndef __CELL__
#define __CELL__
#include "GameObject.h"
#include <unordered_set>
using namespace std;
class Cell
{
private:
	int id;
	int x;
	int y;
	int width;
	int height;
public:
	vector<GameObject*> object;
	Cell(int id, int x, int y, int w= 283, int h = 227);
	bool isCheckContainPoint(Point a); // kiểm tra xem cell có chứa 1 điểm không
	~Cell();
	void Move(float x, float y);
};


#endif // !__CELL__