#include "Bitmap.hpp"

#include <iostream>
#include <fstream>

namespace opc {

	Bitmap::Bitmap(const std::string& path) {
		load(path);
	}

	Bitmap::operator bool() const { return flag; }

	void Bitmap::load(const std::string& path) {

		flag = false;

		std::ifstream ifs(path, std::ios::in | std::ios::binary);

		if (!ifs)
		{
			std::cerr << "ファイルを開けません" << std::endl;
			return;
		}

		unsigned short bfType;
		unsigned int bfSize;
		unsigned short bfReserved1;
		unsigned short bfReserved2;
		unsigned int bfOffBits;

		unsigned int biSize;
		int biWidth;
		int biHeight;
		unsigned short biPlanes;
		unsigned short biBitCount;
		unsigned int biCompression;
		unsigned int biSizeImage;
		int biXPelsPerMeter;
		int biYPelsPerMeter;
		unsigned int biClrUsed;
		unsigned int biClrImportant;

		//ヘッダー読み込み
		const auto fileHeader = [&]() {

			ifs.read((char*)&bfType, sizeof(unsigned short));

			if (((char*)&bfType)[0] != 'B' || ((char*)&bfType)[1] != 'M')
				return false;

			ifs.read((char*)&bfSize, sizeof(unsigned int));

			ifs.read((char*)&bfReserved1, sizeof(unsigned short));
			ifs.read((char*)&bfReserved2, sizeof(unsigned short));

			ifs.read((char*)&bfOffBits, sizeof(unsigned int));

			return true;
		};

		//インフォ読み込み
		const auto infoHeader = [&]() {

			ifs.read((char*)&biSize, sizeof(unsigned int));
			if (biSize != 40)
				return false;

			ifs.read((char*)&biWidth, sizeof(int));
			ifs.read((char*)&biHeight, sizeof(int));
			if (biHeight <= 0)
				return false;

			ifs.read((char*)&biPlanes, sizeof(unsigned short));
			ifs.read((char*)&biBitCount, sizeof(unsigned short));

			ifs.read((char*)&biCompression, sizeof(unsigned int));

			ifs.read((char*)&biSizeImage, sizeof(unsigned int));

			ifs.read((char*)&biXPelsPerMeter, sizeof(int));
			ifs.read((char*)&biYPelsPerMeter, sizeof(int));

			ifs.read((char*)&biClrUsed, sizeof(unsigned int));

			ifs.read((char*)&biClrImportant, sizeof(unsigned int));

			return true;
		};

		if (!fileHeader())
		{
			std::cerr << "対応していないファイル形式です(ファイルヘッダ)" << std::endl;
			return;
		}
		if (!infoHeader())
		{
			std::cerr << "対応していないファイル形式です(情報ヘッダ)" << std::endl;
			return;
		}

		colorMap = Grid<Color>(biWidth, biHeight, Palette::Black);

		if (bfOffBits == 54)
		{
			if (biBitCount == 24)
			{
				width = biWidth;
				height = biHeight;

				const int size = (biWidth * 3 + 3) / 4 * 4;
				data.reserve(size*biHeight);

				std::vector<unsigned char> buf(size, 0);
				for (int y = biHeight - 1; y >= 0; y--)
				{
					for (auto& b : buf)
					{
						ifs.read((char*)&b, sizeof(unsigned char));
					}
					int index = 0;
					for (int x = 0; x < biWidth; x++)
					{
						colorMap[y][x].b = buf[index]; index++;
						colorMap[y][x].g = buf[index]; index++;
						colorMap[y][x].r = buf[index]; index++;
						colorMap[y][x].a = 0xff;
						data.push_back(colorMap[y][x].r);
						data.push_back(colorMap[y][x].g);
						data.push_back(colorMap[y][x].b);
						data.push_back(colorMap[y][x].a);
					}
				}
			}
			else if (biBitCount == 32)
			{
				width = biWidth;
				height = biHeight;

				const int size = (biWidth * 4 + 3) / 4 * 4;
				std::vector<unsigned char> buf(size, 0);
				for (int y = biHeight - 1; y >= 0; y--)
				{
					for (auto& b : buf)
					{
						ifs.read((char*)&b, sizeof(unsigned char));
					}
					int index = 0;
					for (int x = 0; x < biWidth; x++)
					{
						colorMap[y][x].b = buf[index]; index++;
						colorMap[y][x].g = buf[index]; index++;
						colorMap[y][x].r = buf[index]; index++;
						colorMap[y][x].a = buf[index]; index++;
						data.push_back(colorMap[y][x].r);
						data.push_back(colorMap[y][x].g);
						data.push_back(colorMap[y][x].b);
						data.push_back(colorMap[y][x].a);
					}
				}
			}
			else
			{
				std::cerr << "対応していないファイル形式です(ヘッダ情報)" << std::endl;
				return;
			}
		}
		else
		{
			std::cerr << "対応していないファイル形式です(保存形式)" << std::endl;
			return;
		}

		setTexture();
		flag = true;
	}

	void Bitmap::setTexture() {
		glEnable(GL_TEXTURE_2D);
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)width, (GLsizei)height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.data());
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
	}

}
