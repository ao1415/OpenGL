#include "OpenGL.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

//�\���p�̃N���X
class DrawImage {
public:

	//�s�N�Z���R��\��
	void display()
	{
		View::Perspective(30, 1, 1, 15000);

		View::LookAt(RealVector(0, 0, 1000), RealVector(0, 0, 0), RealVector(0, -1, 0));

		View::Translate(RealVector(camera.x, camera.y, 0));
		View::Rotate(angle.x, RealVector(-1, 0, 0));
		View::Rotate(angle.y, RealVector(0, -1, 0));

		for (int y = 0; y < textureSize.height; y++)
		{
			for (int x = 0; x < textureSize.width; x++)
			{
				//Draw3D::Pixel(-textureSize.width / 2.0 + x, -textureSize.height / 2.0 + y, 255.0 - bitmap[y][x].first)
				Draw3D::Pixel(-textureSize.width / 2.0 + x, -textureSize.height / 2.0 + y, (bitmap[y][x].first)*8.0)
					.draw(2, bitmap[y][x].second);
			}
		}

	}

	//���Ԋu�ŕ`��X�V
	void timer(int value) {

		glutPostRedisplay();
	}

	//�}�E�X�̓���
	void mouseMotion()
	{
		Mouse mouse;

		const auto pos = mouse.MotionPos;
		const auto prePos = mouse.PreviousPos;
		int xdir, ydir;

		xdir = pos.x - prePos.x;
		ydir = pos.y - prePos.y;

		if (mouse.mouseL_Click)
		{
			angle.x += (double)ydir * 0.5;
			angle.y += (double)xdir * 0.5;
		}
		if (mouse.mouseR_Click)
		{
			camera.x -= xdir / 40.0;
			camera.y += ydir / 40.0;
		}
	}

	//�摜�t�@�C����ǂݍ���
	void load() {

		int w, h;

		ifstream ifs("256.txt");
		if (!ifs)
		{
			cerr << "�t�@�C�����J���܂���" << endl;
			return;
		}

		ifs >> w >> h;
		textureSize.width = w;
		textureSize.height = h;

		bitmap.resize(w, h, { 0,Color(255,255,255,0) });
		cout << "�摜�ǂݍ��݊J�n" << endl;
		for (int y = 0; y < h; y++)
		{
			for (int x = w - 1; x >= 0; x--)
			{
				int r, g, b, d;
				ifs >> r >> g >> b >> d;

				bitmap[y][x] = { d,Color(r,g,b) };
			}
		}
		cout << "�摜�ǂݍ��ݏI��" << endl;

	}

private:

	RealPoint angle;
	RealPoint camera;

	IntSize textureSize;
	Grid<pair<int, Color>> bitmap;

};

int main(int argc, char *argv[])
{
	//3D�\�����s���N���X�̐錾
	DrawImage drawImage;

	
	//�f�[�^�̓ǂݍ���
	drawImage.load();

	
	//�E�C���h�E�쐬�N���X�̐錾
	System system;


	//�E�C���h�E�̑傫����ݒ肷��
	Window::setSize(960, 960);


	//�\���̐ݒ�(�F:RGBA, �\�����@:�_�u���o�b�t�@)
	system.setDisplayMode(DisplayMode::RGBA, DisplayMode::Double);
	//�o�b�t�@�N���A�̐ݒ�(�F���, �[�������폜����)
	system.setClearMode(ClearMode::Color, ClearMode::Depth);


	//OpenGL�̐ݒ��L���ɂ���(3D�\���@�\��L���ɂ���)
	system.enable(GL_DEPTH_TEST);


	//�\����ʂ�ݒ肷��(DrawImage::display)
	system.setDisplayFunc([&]() {drawImage.display(); });
	//�^�C�}�[��ݒ肷��(DrawImage::timer)
	system.setTimerFunc(10, [&](int v) {drawImage.timer(v); }, 0);
	//�}�E�X�����ݒ肷��(DrawImage::timer)
	system.setMouseMotionFunc([&]() {drawImage.mouseMotion(); });


	//�E�C���h���쐬����
	system.create();
	//���[�v���J�n����
	system.update();

	return 0;
}
