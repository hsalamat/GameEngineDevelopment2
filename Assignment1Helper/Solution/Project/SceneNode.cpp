#include "SceneNode.hpp"
#include "Game.hpp"

SceneNode::SceneNode(Game* game)
	: mChildren()
	, mParent(nullptr)
	, game(game)
{
	mWorldPosition = XMFLOAT3(0, 0, 0);
	mWorldScaling = XMFLOAT3(1, 1, 1);
	mWorldRotation = XMFLOAT3(0, 0, 0);
}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) { return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::update(const GameTimer& gt)
{
	updateCurrent(gt);
	updateChildren(gt);
}

void SceneNode::updateCurrent(const GameTimer& gt)
{
	// Do nothing by default
}

void SceneNode::updateChildren(const GameTimer& gt)
{
	for (Ptr& child : mChildren)
	{
		child->update(gt);
	}
}

void SceneNode::draw() const
{
	drawCurrent();
	drawChildren();
}

void SceneNode::drawCurrent() const
{
	//Empty for now
}

void SceneNode::drawChildren() const
{
	for (const Ptr& child : mChildren)
	{
		child->draw();
	}
}

void SceneNode::build()
{
	buildCurrent();
	buildChildren();
}

void SceneNode::buildCurrent()
{
	//Empty for now
}

void SceneNode::buildChildren()
{
	for (const Ptr& child : mChildren)
	{
		child->build();
	}
}

XMFLOAT3 SceneNode::getWorldPosition() const
{
	return mWorldPosition;
}

void SceneNode::setPosition(float x, float y, float z)
{
	mWorldPosition = XMFLOAT3(x, y, z);
}

XMFLOAT3 SceneNode::getWorldRotation() const
{
	return mWorldRotation;
}

void SceneNode::setWorldRotation(float x, float y, float z)
{
	mWorldRotation = XMFLOAT3(x, y, z);
}

XMFLOAT3 SceneNode::getWorldScale() const
{
	return mWorldScaling;
}

void SceneNode::setScale(float x, float y, float z)
{
	mWorldScaling = XMFLOAT3(x, y, z);
}

XMFLOAT4X4 SceneNode::getWorldTransform() const
{
	XMFLOAT4X4 transform = MathHelper::Identity4x4();
	XMMATRIX T = XMLoadFloat4x4(&transform);

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
	{
		auto nodeTransform = node->getTransform();
		XMMATRIX Tp = XMLoadFloat4x4(&nodeTransform);
		T = Tp * T;
	}
	XMStoreFloat4x4(&transform, T);

	return transform;
}

XMFLOAT4X4 SceneNode::getTransform() const
{
	XMFLOAT4X4 transform;
	XMStoreFloat4x4(&transform, XMMatrixScaling(mWorldScaling.x, mWorldScaling.y, mWorldScaling.z) *
		XMMatrixRotationX(mWorldRotation.x) *
		XMMatrixRotationY(mWorldRotation.y) *
		XMMatrixRotationZ(mWorldRotation.z) *
		XMMatrixTranslation(mWorldPosition.x, mWorldPosition.y, mWorldPosition.z));
	return transform;
}

void SceneNode::move(float x, float y, float z)
{
	mWorldPosition.x += x;
	mWorldPosition.y += y;
	mWorldPosition.z += z;
}
