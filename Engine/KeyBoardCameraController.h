#pragma once
#include "Keyboard.h"
#include "Camera.h"
class KeyBoardCameraController {
public:
	KeyBoardCameraController(Keyboard& kbd, Camera& cam)
		:
		kbd(kbd),
		cam(cam)
	{ }

	void Update() {
		if (kbd.KeyIsPressed('Q')) {
			cam.SetAngle(cam.GetAngle() + 0.05f);
		}
		if (kbd.KeyIsPressed('E')) {
			cam.SetAngle(cam.GetAngle() - 0.05f);
		}
	}
private:
	Keyboard& kbd;
	Camera& cam;
};