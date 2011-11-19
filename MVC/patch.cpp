#include "patch.h"
#include "main.h"

Patch::Patch()
:	img_width(0), img_height(0)
{
	boundary.clear();
}

Patch::Patch(int width, int height)
:	img_width(width), img_height(height)
{
	boundary.clear();
}

bool Patch::addPoint(Point& vertex)
{
	if (boundary.size() > 3 && close(vertex,boundary[0]))
		return true;
	else {
		cerr << "Adding vertex at: " << vertex.x << " " << vertex.y << endl;
		boundary.push_back(vertex);
		return false;
	}
}

void Patch::computeInterior()
{
	interior.reserve(pow(double(boundary.size()),2));
}

void Patch::highLight(Image* img)
{
	for (unsigned int i = 0; i < boundary.size(); ++i)
		for (int chn = RED; chn <= BLUE; ++chn)
			img->setPixel_(boundary[i].x,boundary[i].y,chn,1);
}
