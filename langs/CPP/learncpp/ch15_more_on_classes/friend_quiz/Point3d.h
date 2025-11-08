#ifndef POINT3D_H
#define POINT3D_H

class Vector3d;

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x, double y, double z);

	void print() const;

    //step 1
	/*void moveByVector(const Vector3d& v)
	{
        m_x += v.m_x;
        m_y += v.m_y;
        m_z += v.m_z;
		// implement this function as a friend of class Vector3d
	}*/

    //step 2
	void moveByVector(const Vector3d& v);
};

#endif
