#ifndef __CAMERA__
#define __CAMERA__

#include "Define.h"

class Camera
{
private:
	static Camera * instance;
	float _xCam;//toa do cam tren map cho de bat dau ve
	float _yCam;

	int width;//kich thuoc cam, tuong ung voi kich thuoc man hinh
	int height;

	int mapWidth;
	int mapHeight;

	Camera();
	Camera(int w, int h, int mw, int mh);
public:
	void SetPosition(float x, float y);
	float GetXCam();
	float GetYCam();

	void SetMap(int mapWidth, int mapHeight);

	int GetWidth();
	int GetHeight();
	void SetX(float x);
	void SetY(float y);
	void SetXY(float x, float y);
	static Camera* GetInstance();

	void SetCamera(int width, int height, int mapWidth, int mapHeight);
	~Camera();
};
#endif // !__CAMERA__