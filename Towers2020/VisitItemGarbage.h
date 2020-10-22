#pragma once
#include "ItemVisitor.h"
#include <set>

class CVisitItemGarbage : public CItemVisitor
{
public:

	/**Constructor*/
	virtual void VisitGarbage() override;

	CVisitItemGarbage(CProjectile* projectile);

	std::set<CItem* > GetInactiveProjectiles() { return mInactiveProjectiles; }

private: 
	std::set<CItem* > mInactiveProjectiles;
};

