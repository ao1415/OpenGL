#pragma once

#include "GL/glut.h"
#include <vector>
#include <string>
#include "Property.hpp"
#include "Palette.hpp"
#include "Grid.hpp"

namespace opc {

	/// <summary>
	/// Bitmap�摜�������N���X
	/// </summary>
	class Bitmap {
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Bitmap() = default;
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="path">�摜�t�@�C���̃p�X</param>
		Bitmap(const std::string& path);
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="b">�R�s�[����<see cref="Bitmap"/></param>
		Bitmap(const Bitmap& b) = default;
		/// <summary>�R���X�g���N�^</summary>
		/// <param name="b">�ړ�����<see cref="Bitmap"/></param>
		Bitmap(Bitmap&& b) {
			width = b.width;
			height = b.height;
			data = std::move(b.data);
			b.width = b.height = 0;
		}

		/// <summary>�R�s�[���Z�q</summary>
		/// <param name="other">�R�s�[����<see cref="Bitmap"/></param>
		/// <returns><see cref="Bitmap"/></returns>
		Bitmap& operator=(const Bitmap& other) = default;
		/// <summary>���[�u���Z�q</summary>
		/// <param name="other">�ړ�����<see cref="Bitmap"/></param>
		/// <returns><see cref="Bitmap"/></returns>
		Bitmap& operator=(Bitmap&& other) = default;

		/// <summary>�摜���ǂݍ��܂ꂽ����Ԃ�</summary>
		/// <returns>�ǂݍ��܂ꂽ�ꍇ true, ����ȊO�̏ꍇ�� false</returns>
		operator bool() const;

		/// <summary>�摜��ǂݍ���</summary>
		/// <param name="path">�摜�t�@�C���̃p�X</param>
		void load(const std::string& path);

		/// <summary>OpenGL�̃e�N�X�`���𓾂�</summary>
		/// <returns><see cref="GLuint"/></returns>
		Property_Get(GLuint, Texture) const { return texture; }
		/// <summary>�摜�̕��𓾂�</summary>
		/// <returns>��</returns>
		Property_Get(size_t, Width) const { return width; }
		/// <summary>�摜�̍����𓾂�</summary>
		/// <returns>����</returns>
		Property_Get(size_t, Height) const { return height; }

		/// <summary>�s�N�Z���ɃA�N�Z�X����</summary>
		/// <param name="pos">���W</param>
		/// <returns>�F</returns>
		const Color& operator[](const Point& pos) const { return colorMap[pos]; }

	private:
		/// <summary>
		/// �摜�̕�
		/// </summary>
		size_t width = 0;
		/// <summary>
		/// �摜�̍���
		/// </summary>
		size_t height = 0;

		/// <summary>
		/// �摜���ǂݍ��܂ꂽ���̃t���O
		/// </summary>
		bool flag = false;

		/// <summary>
		///	OpenGL�̃e�N�X�`���A�h���X
		/// </summary>
		GLuint texture;

		/// <summary>
		/// �J���[�f�[�^
		/// </summary>
		std::vector<unsigned char> data;
		/// <summary>
		/// �J���[�s�N�Z��
		/// </summary>
		Grid<Color> colorMap;

		/// <summary>
		/// OpenGL�̃e�N�X�`�����쐬����
		/// </summary>
		void setTexture();

	};

}
