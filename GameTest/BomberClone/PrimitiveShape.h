#pragma once

#include "app/app.h"
#include "BomberClone\DrawUtils.h"
//#include "RenderableItems.h"
class PrimitiveShape
{
public:
	PrimitiveShape();
	PrimitiveShape(float x, float y);
	~PrimitiveShape();

	bool renderMode = true;

	void Render();
	void SetCenter(Position newPosition);
	Position GetCenter();
	std::vector<Vertex*> GetVerts();
	void SetColor(float r, float g, float b);

protected:
	virtual void CreateShape();
	//void Register(PrimitiveShape* self);
	Position center;
	std::vector<Vertex*> vertices;
	Color color;


private:
	void PrimitiveShape::CreateDebugShape();
	void UpdateVertPositions(Position newPosition);

};

