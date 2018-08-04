#pragma once

class Entity
{
public:
	virtual void update() {};
protected:
	float x, y, rot, xScale, yScale;
};