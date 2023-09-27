#include "Matrix3D.hpp"
#include "Vector3D.hpp"
#include <iostream>

/**
 * Following 2 vol. book "Foundations of Game Engine Development".
 **/

int main(int argv, const char *[]) {
  Vector3D v_1, v_2, v_3;
  v_1[0] = 1;
  v_1[1] = 2;
  v_1[2] = 3;

  v_2[0] = 1;
  v_2[1] = 2;
  v_2[2] = 3;

  v_3[0] = 1;
  v_3[1] = 2;
  v_3[2] = 3;

  Matrix3D m_1(1, 2, 3, 1, 2, 3, 1, 2, 3);
  Matrix3D m_2(v_1, v_2, v_3);

  Matrix3D m_3 = m_1 * m_2;

  m_1.disp();
  m_2.disp();
  m_3.disp();
}