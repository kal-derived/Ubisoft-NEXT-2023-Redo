#include "stdafx.h"
#include "Debug.h"

Square* Debug::s1 = new Square({ 300, 100 }, 80, { 1,1,0 });
Square* Debug::s2 = new Square({ 150, 600 }, 50, { 0,1,0 });
Square* Debug::s3 = new Square({ 700, 600 }, 30, { 1,0,1 });

std::vector<BoundingBox*> Debug::testColliders = {
		new BoundingBox(Debug::s1),
		new BoundingBox(Debug::s2),
		new BoundingBox(Debug::s3)
};