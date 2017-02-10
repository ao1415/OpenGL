#include "OpenGL.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <chrono>

using namespace std;

//�\���p�̃N���X
class DrawImage {
public:

	//�s�N�Z���Q��\���R
	void display()
	{
		View::Perspective(30, 1, 1, 15000);

		View::LookAt(Vec3(0, 0, 1000), Vec3(0, 0, 0), Vec3(0, -1, 0));

		View::Translate(Vec3(camera.x, camera.y, distance));
		View::Rotate(angle.x, Vec3(-1, 0, 0));
		View::Rotate(angle.y, Vec3(0, -1, 0));

		const auto start = std::chrono::system_clock::now();

		for (int y = 0; y < textureSize.height; y++)
		{
			for (int x = 0; x < textureSize.width; x++)
			{
				const int D = 32;
				const int depth = bitmap[y][x].first;
				const Color color = bitmap[y][x].second;

				HSV hsv1(color);
				HSV hsv2(color);
				
				//*�ǂ̐F���Â�����
				hsv1.v *= 0.85;
				hsv2.v *= 0.70;
				//*/

				const Color darkColor1 = hsv1.toRGB();
				const Color darkColor2 = hsv2.toRGB();

				const Vec3 pos(-textureSize.width / 2.0 + x, -textureSize.height / 2.0 + y, depth * D);

				//*���s�̋��E�ɕǂ�\������
				if (0 <= x - 1 && bitmap[y][x - 1].first < depth)
				{
					int d = -(depth - bitmap[y][x - 1].first) * D;
					Draw3D::Quad(pos + Vec3(0, 0, 0), pos + Vec3(0, 1, 0), pos + Vec3(0, 1, d), pos + Vec3(0, 0, d)).draw(darkColor2);
				}
				if (0 <= y - 1 && bitmap[y - 1][x].first < depth)
				{
					int d = -(depth - bitmap[y - 1][x].first) * D;
					Draw3D::Quad(pos + Vec3(0, 0, 0), pos + Vec3(1, 0, 0), pos + Vec3(1, 0, d), pos + Vec3(0, 0, d)).draw(darkColor1);
				}
				if (x + 1 < textureSize.width && bitmap[y][x + 1].first < depth)
				{
					int d = -(depth - bitmap[y][x + 1].first) * D;
					Draw3D::Quad(pos + Vec3(1, 0, 0), pos + Vec3(1, 1, 0), pos + Vec3(1, 1, d), pos + Vec3(1, 0, d)).draw(darkColor2);
				}
				if (y + 1 < textureSize.height && bitmap[y + 1][x].first < depth)
				{
					int d = -(depth - bitmap[y + 1][x].first) * D;
					Draw3D::Quad(pos + Vec3(0, 1, 0), pos + Vec3(1, 1, 0), pos + Vec3(1, 1, d), pos + Vec3(0, 1, d)).draw(darkColor1);
				}
				//*/
				//*���s�̋��E�ɍ���������
				if (0 <= x - 1 && bitmap[y][x - 1].first < depth)
					Draw3D::Line(pos + Vec3(0, 0, 0), pos + Vec3(0, 1, 0)).draw(2, Color(0x000000));
				if (0 <= y - 1 && bitmap[y - 1][x].first < depth)
					Draw3D::Line(pos + Vec3(0, 0, 0), pos + Vec3(1, 0, 0)).draw(2, Color(0x000000));
				if (x + 1 < textureSize.width && bitmap[y][x + 1].first < depth)
					Draw3D::Line(pos + Vec3(1, 0, 0), pos + Vec3(1, 1, 0)).draw(2, Color(0x000000));
				if (y + 1 < textureSize.height && bitmap[y + 1][x].first < depth)
					Draw3D::Line(pos + Vec3(0, 1, 0), pos + Vec3(1, 1, 0)).draw(2, Color(0x000000));
				//*/
				Draw3D::Quad(pos + Vec3(0, 0, 0), pos + Vec3(1, 0, 0), pos + Vec3(1, 1, 0), pos + Vec3(0, 1, 0)).draw(color);
			}
		}
		const auto end = std::chrono::system_clock::now();
		const auto dif = end - start;
		//cout << chrono::duration_cast<chrono::microseconds>(dif).count() << "us" << endl;
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
		if (mouse.mouseM_Click)
		{
			distance -= ydir / 1.0;
		}
		if (mouse.mouseR_Click)
		{
			camera.x -= xdir / 1.0;
			camera.y += ydir / 1.0;
		}
	}

	//�摜�t�@�C����ǂݍ���
	void load() {

		int w, h;

		//ifstream ifs("�g���ƃW�F���[.txt");
		//ifstream ifs("�g�����v.txt");
		//ifstream ifs("�h��������.txt");
		//ifstream ifs("�A�i�Ɛ�̏���.txt");
		//ifstream ifs("�ǂݎ��摜002.txt");
		ifstream ifs("�e�X�g�P�[�X01.txt");
		//ifstream ifs("256.txt");

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

	//���_�p�x
	Vec2 angle;
	//�J�����ʒu
	Vec2 camera;
	//����
	double distance = 0;

	//�e�N�X�`���̑傫��
	IntSize textureSize;
	//�s�N�Z���Ɖ��s�f�[�^
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
