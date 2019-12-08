#ifndef __GRID__
#define __GRID__
#include "Game.h" 
#include "Cell.h"
#include "Brick.h"
using namespace std;

class Grid
{
private:
	static Grid * instance;

	int rows; // Số hàng của grid
	int columns; // Số cột của grid
	int cellWidth; // Kích thước bề rộng
	int cellHeight; // Kích thước bề cao

	unordered_map<int, Cell *> grid;
	
	Grid();
	
public:
	vector<int> cellShowing; // những cell đang hiển thị lên màn hình

	static Grid * GetInstance();
	Cell * GetCell(int id);
	void LoadGrid(int idMap);
	void Update(DWORD dt);
	int GetIdCellContainPoint(Point p);
	void GetObjects(vector<LPGAMEOBJECT> &obj);
	~Grid();
};
#endif // !__GRID__