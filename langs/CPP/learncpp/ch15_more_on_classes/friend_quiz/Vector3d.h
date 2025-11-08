#ifndef VEECTOR3D_H
#define VEECTOR3D_H
#include "Point3d.h"
class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x, double y, double z);

	void print() const;

    //friend class Point3d; step 1
    friend void Point3d::moveByVector(const Vector3d& v);
};

#endif
