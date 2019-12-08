#include "Camera.h"

Camera* Camera::instance = NULL;

void Camera::SetPosition(float x, float y)
{
	this->_xCam = x;
	this->_yCam = y;
	if (_xCam < 0)
		_xCam = 0;
	if (_xCam > mapWidth - CAM_WIDTH)
		_xCam = mapWidth - CAM_WIDTH;
	if (_yCam < 0)
		_yCam = 0;
	if (_yCam > mapHeight)
		_yCam = mapHeight;
}

float Camera::GetXCam()
{
	return _xCam;
}

float Camera::GetYCam()
{
	return _yCam;
}

void Camera::SetMap(int mapWidth, int mapHeight)
{
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;
}

int Camera::GetWidth()
{
	return width;
}

int Camera::GetHeight()
{
	return height;
}

void Camera::SetX(float x)
{
	this->_xCam = x;
}

void Camera::SetY(float y)
{
	this->_yCam = y;
}

void Camera::SetXY(float x, float y)
{
	_xCam = x;
	_yCam = y;
}

Camera * Camera::GetInstance()
{
	if (instance == NULL)
		instance = new Camera();
	return instance;
}

Camera::Camera()
{
	width = CAM_WIDTH;
	height = CAM_HEIGHT;
	this->_xCam = 0;
	this->_yCam = 2000;
	mapHeight = MAP1_SIZE_OF_HEIGHT;
}

Camera::Camera(int w, int h, int mw, int mh)
{
	this->width = w;
	this->height = h;
	this->mapWidth = mw;
	this->mapHeight = mh;
	this->_xCam = 0;
	this->_yCam = mh - h;
}


void Camera::SetCamera(int width, int height, int mapWidth, int mapHeight)
{
	this->width = width;
	this->height = height;
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;
}

Camera::~Camera()
{
	delete instance;
}
