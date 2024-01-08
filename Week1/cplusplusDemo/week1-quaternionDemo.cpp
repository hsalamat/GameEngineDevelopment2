/** @file week1-quaternionDemo.cpp
 *  @brief Quaternions
 *
 *  https://en.wikipedia.org/wiki/William_Rowan_Hamilton
 * 
 *  Quaternion is matrix like structure which provides only one rotation.
 *  https://quaternions.online/
 *  https://eater.net/quaternions
 *  https://adrianb.io/demos/Rotation-Vis/
 * 
 *  1. An ordered 4-tuple of real numbers q = (x, y, z, w) = (q1, q2, q3, q4) is a quaternion.
 *  this is commonly abbreviated as q = (u, w) = (x, y, z, w), and we call u = (x, y, z) the 
 *  imaginary vector part and w the real part. Moreover, equality, addition, subtraction,
 *  multiplication and division are defined as follows:
 *  1. (u, a) = (v, b) if and only if u = v and a = b.
 *  2. (u, a) ± (v, b) = (u ± v, a ± b).
 *  3. (u, a)(v, b) = (av + bu + u × v, ab − u · v)
 *  2. Quaternion multiplication is not commutative, but it is associative. The quaternion e
 *  = (0, 0, 0, 1) serves as a multiplicative identity. Quaternion multiplication distributes
 *  over quaternion addition: p(q + r) = pq + pr and (q + r)p = qp + rp.
 *  3. We can convert a real number s to quaternion space by writing s = (0, 0, 0, s), and we
 *  can convert a vector u to quaternion space by writing u = (u, 0). A quaternion with
 *  zero real part is called a pure quaternion. It is then possible to multiply a scalar and a
 *  quaternion, and the result is s(p1, p2, p3, p4) = (sp1, sp2, sp3, sp4) = (p1, p2, p3, p4)s.
 *  The special case of scalar multiplication is commutative.
 *  4. The conjugate of a quaternion q = (q1, q2, q3, q4) = (u, q4) is denoted by q* and
 *  defined by q* = (-u, q4)
 *  5. The norm (or magnitude) of a quaternion is defined by ||q|| = (qq*)^0.5 = (||u||^2 + q4^2)^0.5
 *  6. Let q = (q1, q2, q3, q4) = (u, q4) be a nonzero quaternion, then the inverse is denoted
 *   by q−1 and given by: q-1= q* / q^2. If q is a unit quaternion, then q−1 = q*.
 *  7. A unit quaternion q = (u, q4) can be written in the polar representation , where n is a
 *  unit vector. If q is a unit quaternion, then q = (sinθn,cosθ) for ||n|| = 1 and θ ∈ [0, π]. The
 *  quaternion rotation operator is defined by Rq(v) = qvq-1 = qvq*
 *  and rotates the point/vector v around the axis n by an angle 2θ. Rq has a matrix
 *  representation, and any rotation matrix can be converted to a quaternion representing
 *  the rotation.
 * 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// Overload the  "<<" operators so that we can use cout to
// output XMVECTOR and XMMATRIX objects.


ostream& XM_CALLCONV operator << (ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
	return os;
}

ostream& XM_CALLCONV operator << (ostream& os, FXMMATRIX m)
{
	for (int i = 0; i < 4; ++i)
	{
		os << XMVectorGetX(m.r[i]) << "\t";
		os << XMVectorGetY(m.r[i]) << "\t";
		os << XMVectorGetZ(m.r[i]) << "\t";
		os << XMVectorGetW(m.r[i]);
		os << endl;
	}
	return os;
}

int main()
{
	// Check support for SSE2 (Pentium4, AMD K8, and above).
	if (!XMVerifyCPUSupport())
	{
		cout << "directx math not supported" << endl;
		return 0;
	}

	//The DirectXMath quaternion functions use an XMVECTOR 4 - vector to represent quaternions, 
	// where the X, Y, and Z components are the vector part and the W component is the scalar part.

	//XMVECTOR quaternionIdentity = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	XMVECTOR quaternionIdentity = XMQuaternionIdentity();
	cout << "Quaternion Identity " << quaternionIdentity << endl;

	//The dot product for quaternions is simply the standard Euclidean dot product in 4D:
	//dot = left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w
   //Then the angle your are looking for is the arccos of the dot product(note that the dot product is not the angle) : acos(dot).
   //However, if you are looking for the relative rotation between two quaternions, say from q1 to q2, 
   //you should compute the relative quaternion q = q1 ^ -1 * q2 and then find the rotation associated with q.
	//q is the minimum angle rotation to take you from one quaternion to the other quaternion 

	// Exercise:
	//  Let p = (1, 2, 3, 4) and q = (2, −1, 1, −2) be quaternions. Perform the indicated
	//	quaternion operations.
	//	1. p + q
	//	2. p − q
	//	3. pq
	//	4. p*
	//	5. q*
	//	6. p*p
	//	7. ||p||
	//	8. ||q||
	//	9. p−1
	//	10. p−1p

	XMVECTOR p = XMVectorSet(1.0f, 2.0f, 3.0f, 4.0f);
	cout << "p " << p << endl;

	XMVECTOR q = XMVectorSet(2.0f, -1.0f, 1.0f, -2.0f);
	cout << "q " << q << endl;

	XMVECTOR p_plus_q = p + q;
	cout << "p + q = " << p_plus_q << endl;

	XMVECTOR p_minus_q = p + q;
	cout << "p - q = " << p_minus_q << endl;

	XMVECTOR p_multiply_q = XMQuaternionMultiply(p, q);
	cout << "p * q = " << p_multiply_q << endl;

	XMVECTOR p_conjugate = XMQuaternionConjugate(p);
	cout << "p* = " << p_conjugate << endl;

	XMVECTOR q_conjugate = XMQuaternionConjugate(q);
	cout << "q* = " << q_conjugate << endl;

	XMVECTOR p_conjuagte_multiply_p = XMQuaternionMultiply(p_conjugate, p);
	cout << "p_conjugate * p = " << p_conjuagte_multiply_p << endl;

	XMVECTOR p_length = XMQuaternionLength(p);
	cout << "||p|| = " << p_length << endl;

	XMVECTOR q_length = XMQuaternionLength(q);
	cout << "||q|| = " << q_length << endl;

	XMVECTOR p_inverse = XMQuaternionInverse(p);
	cout << "p-1 = " << p_inverse << endl;

	XMVECTOR p_inverse_multiply_p = XMQuaternionMultiply(p_inverse, p);
	cout << "p_inverse * p = " << p_inverse_multiply_p << endl;
	cout << "notice that it's not quite a quaternion identity thanks to numerical precision, but close enough!" << endl;


	// While Lerp would give us a vector that is situated on the direct line between Start and Finish, 
	// Slerp will now treat the vector not as a position but as a direction.
	// That means that we’re interpolating between two vector’s angle to the origin point and their radius.
	//https://www.faustofonseca.com/tutorial/unity-vector3-lerp-vs-vector3-slerp

	XMFLOAT3 S0 = XMFLOAT3(0.25f, 0.25f, 0.25f);
	XMFLOAT3 S1 = XMFLOAT3(0.5f, 0.5f, 0.5f);
	XMVECTOR s0 = XMLoadFloat3(&S0);
	XMVECTOR s1 = XMLoadFloat3(&S1);
	float lerpPercent = 0.5f;

	XMVECTOR S = XMVectorLerp(s0, s1, lerpPercent);
	cout << "lerp between s0 & s1 = " << S << endl;

	XMVECTOR Q = XMQuaternionSlerp(p, q, lerpPercent);
	cout << "slerp between p & q = " << Q << endl;

	return 0;
}