#include "Grid.h"

Grid * Grid::instance = NULL;

Grid::Grid()
{

}

Grid * Grid::GetInstance()
{
	if (instance == NULL)
		instance = new Grid();
	return instance;
}

Cell * Grid::GetCell(int id)
{
	return grid[id];
}

void Grid::LoadGrid(int idMap)
{
	string path;
	switch (idMap) {
	case MAP1: 
		path = "Resources/grid/grid1.txt";
		break;
	case MAP2:
		path = "Resources/grid/grid2.txt";
		break;
	}

	ifstream input = ifstream(path, ios::in);
	// Lấy dữ liệu hàng đầu tiên
	input >> columns;
	input >> rows;
	input >> cellWidth;
	input >> cellHeight;

	int totalCells = columns * rows;

	// Khởi tạo cell, đọc dữ liệu của từng cell lên
	int id;
	int x;
	int y;
	for (int i = 0; i < totalCells; i++)
	{
		input >> id >> x >> y;
		Cell * cell = new Cell(id, x, y);
		grid[id] = cell;
	}
	
	int type;
	int width;
	int height;
	oType obj;
	while (!input.eof())
	{
		input >> id;
		if (id == -1)
			break;
		input >> type >> x >> y >> width >> height;
		
		switch (type)
		{
		case BRICK:
			Brick * br = new Brick(x, y, width, height, BRICK);
			grid[id]->object.push_back(br);
			break;
		

		}
	}
}

void Grid::Update(DWORD dt)
{
	Camera * cam = Camera::GetInstance();

	Point a;
	a.x = (int)cam->GetXCam();
	a.y = (int)cam->GetYCam();

	Point b;
	b.x = (int)cam->GetXCam() + cam->GetWidth();
	b.y = (int)cam->GetYCam() + cam->GetHeight();

	int c1 = GetIdCellContainPoint(a);
	int c2 = GetIdCellContainPoint(b);

	if (c1 == -1||c2 == -1) {
		//OutputDebugString(L"Grid:Camera nam ngoai grid\n");
		return;
	}
	cellShowing.clear();

	// Thêm cell hiển thị vào cellShowing
	// Kết thúc đoạn code dưới sẽ có danh sách id những cell đang nằm trong camera
	int cs = c1 % columns; // column start
	int ce = c2 % columns; // column end
	int rs = c1 / columns; // row start
	int re = c2 / columns; // row end

	for (int i = rs; i <= re; i++)
	{
		for (int j = cs; j <= ce; j++) 
		{
			cellShowing.push_back(i*columns + j);
		}
	}
	// Update các đối tượng trong Grid
}

int Grid::GetIdCellContainPoint(Point p)
{
	int total = rows * columns;
	for (int id = 0; id < total; id++)
	{
		if (grid[id]->isCheckContainPoint(p))
			return id;
	}
	return -1;
}

void Grid::GetObjects(vector<LPGAMEOBJECT>& obj)
{
	obj.clear();
	int s = cellShowing.size();
	for (int i = 0; i < s; i++)
	{
		Cell * c = GetCell(cellShowing[i]);
		int sCell = c->object.size();
		for (int j = 0; j < sCell; j++)
		{
			obj.push_back(c->object[j]);
			float x=0.0f;
			float y=0.0f; 
			c->object[j]->GetPosition(x, y);
		}
	}
}

Grid::~Grid()
{
	for (int i = 0; i < columns * rows; i++) 
	{
		delete grid[i];
	}
	grid.clear();
	if (instance != NULL)
		delete instance;
}