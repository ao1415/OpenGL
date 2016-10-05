#pragma once

#include "GL/glut.h"
#include <vector>
#include <string>
#include "Property.hpp"
#include "Palette.hpp"
#include "Grid.hpp"

namespace opc {

	class Bitmap {
	public:

		Bitmap() = default;
		Bitmap(const std::string& path);

		Bitmap(const Bitmap& b) = default;
		Bitmap(Bitmap&& b) {
			width = b.width;
			height = b.height;
			data = std::move(b.data);
			b.width = b.height = 0;
		}

		Bitmap& operator=(const Bitmap& other) = default;
		Bitmap& operator=(Bitmap&& other) = default;

		operator bool() const;

		void load(const std::string& path);

		Property_Get(GLuint, Texture) const { return texture; }
		Property_Get(size_t, Width) const { return width; }
		Property_Get(size_t, Height) const { return height; }

		const Color& operator[](const IntPoint& pos) const { return colorMap[pos]; }

	private:

		size_t width = 0;
		size_t height = 0;

		bool flag = false;

		GLuint texture;

		std::vector<unsigned char> data;
		Grid<Color> colorMap;

		void setTexture();

	};

}
