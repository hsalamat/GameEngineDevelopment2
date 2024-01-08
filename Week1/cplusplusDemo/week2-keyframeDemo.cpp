/** @file week2-keyframeDemo.cpp
 *  @brief Key Frame
 *
 *  A common form of animation is called key frame animation. A key frame specifies
 *  the position, orientation, and scale of an object at an instance in time.
 *  In this demo , we define the key frame structure
 *
 *  GetStartTime just returns the time of the first key frame. For example, maybe the
 *  object does not start animating until after ten seconds relative to some timeline. Similarly,
 *  the method GetEndTime returns the time of the last key frame. This is useful to know
 *  when the animation ends, and we can stop animating it.
 *  We now have a list of key frames, which define the rough overall look of the
 *  animation. So how will the animation look at time between the key frames? This is where
 *  interpolation comes in. For times t between two key frames, say Ki and Ki+1, we
 *  interpolate between the two key frames Ki and Ki+1.
 * 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <vector>
#include <iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

///<summary>
/// A Keyframe defines the bone transformation at an instant in time.
///</summary>
struct Keyframe
{
	float TimePos;
	DirectX::XMFLOAT3 Translation;
	DirectX::XMFLOAT3 Scale;
	DirectX::XMFLOAT4 RotationQuat;

	Keyframe() :
		TimePos(0.0f),
		Translation(0.0f, 0.0f, 0.0f),
		Scale(1.0f, 1.0f, 1.0f),
		RotationQuat(0.0f, 0.0f, 0.0f, 1.0f)
	{
	}

	~Keyframe()
	{
	}

};

///<summary>
/// A BoneAnimation is defined by a list of keyframes.  For time
/// values in between two keyframes, we interpolate between the
/// two nearest keyframes that bound the time.  
///
/// We assume an animation always has two keyframes.
///</summary>
struct BoneAnimation
{
	std::vector<Keyframe> Keyframes;

	float GetStartTime()const
	{
		// Keyframes are sorted by time, so first keyframe gives start time.
		return Keyframes.front().TimePos;
	}
	float GetEndTime()const
	{
		// Keyframes are sorted by time, so last keyframe gives end time.
		float f = Keyframes.back().TimePos;

		return f;
	}

	void Interpolate(float t, DirectX::XMFLOAT4X4& M)const
	{
		if (t <= Keyframes.front().TimePos)
		{
			XMVECTOR S = XMLoadFloat3(&Keyframes.front().Scale);
			XMVECTOR P = XMLoadFloat3(&Keyframes.front().Translation);
			XMVECTOR Q = XMLoadFloat4(&Keyframes.front().RotationQuat);

			XMVECTOR zero = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
			XMStoreFloat4x4(&M, XMMatrixAffineTransformation(S, zero, Q, P));
		}
		else if (t >= Keyframes.back().TimePos)
		{
			XMVECTOR S = XMLoadFloat3(&Keyframes.back().Scale);
			XMVECTOR P = XMLoadFloat3(&Keyframes.back().Translation);
			XMVECTOR Q = XMLoadFloat4(&Keyframes.back().RotationQuat);

			XMVECTOR zero = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
			XMStoreFloat4x4(&M, XMMatrixAffineTransformation(S, zero, Q, P));
		}
		else
		{
			for (UINT i = 0; i < Keyframes.size() - 1; ++i)
			{
				if (t >= Keyframes[i].TimePos && t <= Keyframes[i + 1].TimePos)
				{
					float lerpPercent = (t - Keyframes[i].TimePos) / (Keyframes[i + 1].TimePos - Keyframes[i].TimePos);

					XMVECTOR s0 = XMLoadFloat3(&Keyframes[i].Scale);
					XMVECTOR s1 = XMLoadFloat3(&Keyframes[i + 1].Scale);

					XMVECTOR p0 = XMLoadFloat3(&Keyframes[i].Translation);
					XMVECTOR p1 = XMLoadFloat3(&Keyframes[i + 1].Translation);

					XMVECTOR q0 = XMLoadFloat4(&Keyframes[i].RotationQuat);
					XMVECTOR q1 = XMLoadFloat4(&Keyframes[i + 1].RotationQuat);

					XMVECTOR S = XMVectorLerp(s0, s1, lerpPercent);
					XMVECTOR P = XMVectorLerp(p0, p1, lerpPercent);
					XMVECTOR Q = XMQuaternionSlerp(q0, q1, lerpPercent);

					XMVECTOR zero = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
					XMStoreFloat4x4(&M, XMMatrixAffineTransformation(S, zero, Q, P));

					break;
				}
			}
		}

	}
};


int main()
{
	BoneAnimation mSkullAnimation;

	XMVECTOR q0 = XMQuaternionRotationAxis(XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f), XMConvertToRadians(30.0f));
	XMVECTOR q1 = XMQuaternionRotationAxis(XMVectorSet(1.0f, 1.0f, 2.0f, 0.0f), XMConvertToRadians(45.0f));
	XMVECTOR q2 = XMQuaternionRotationAxis(XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f), XMConvertToRadians(-30.0f));
	XMVECTOR q3 = XMQuaternionRotationAxis(XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f), XMConvertToRadians(70.0f));

	mSkullAnimation.Keyframes.resize(5);
	mSkullAnimation.Keyframes[0].TimePos = 0.0f;
	mSkullAnimation.Keyframes[0].Translation = XMFLOAT3(-7.0f, 0.0f, 0.0f);
	mSkullAnimation.Keyframes[0].Scale = XMFLOAT3(0.25f, 0.25f, 0.25f);
	XMStoreFloat4(&mSkullAnimation.Keyframes[0].RotationQuat, q0);

	mSkullAnimation.Keyframes[1].TimePos = 2.0f;
	mSkullAnimation.Keyframes[1].Translation = XMFLOAT3(0.0f, 2.0f, 10.0f);
	mSkullAnimation.Keyframes[1].Scale = XMFLOAT3(0.5f, 0.5f, 0.5f);
	XMStoreFloat4(&mSkullAnimation.Keyframes[1].RotationQuat, q1);

	mSkullAnimation.Keyframes[2].TimePos = 4.0f;
	mSkullAnimation.Keyframes[2].Translation = XMFLOAT3(7.0f, 0.0f, 0.0f);
	mSkullAnimation.Keyframes[2].Scale = XMFLOAT3(0.25f, 0.25f, 0.25f);
	XMStoreFloat4(&mSkullAnimation.Keyframes[2].RotationQuat, q2);

	mSkullAnimation.Keyframes[3].TimePos = 6.0f;
	mSkullAnimation.Keyframes[3].Translation = XMFLOAT3(0.0f, 1.0f, -10.0f);
	mSkullAnimation.Keyframes[3].Scale = XMFLOAT3(0.5f, 0.5f, 0.5f);
	XMStoreFloat4(&mSkullAnimation.Keyframes[3].RotationQuat, q3);

	mSkullAnimation.Keyframes[4].TimePos = 8.0f;
	mSkullAnimation.Keyframes[4].Translation = XMFLOAT3(-7.0f, 0.0f, 0.0f);
	mSkullAnimation.Keyframes[4].Scale = XMFLOAT3(0.25f, 0.25f, 0.25f);
	XMStoreFloat4(&mSkullAnimation.Keyframes[4].RotationQuat, q0);
}