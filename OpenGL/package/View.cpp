#include "View.hpp"

namespace opc {

	namespace View {

		void Perspective(const double fovy, const double aspect, const double zNear, const double zFar) {
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(fovy, aspect, zNear, zFar);
		}

		void LookAt(const RealVector& eye, const RealVector& center, const RealVector& up) {
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z);
		}


	}

}
