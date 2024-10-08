#pragma once
#include <memory>
#include "../material/Material.h"
#include "BlockSourceListener.h"
class AABB;
class Entity;
class Player;

class Level : public BlockSourceListener {
public:
    unsigned int getSeed();
	virtual ~Level();
	virtual void onSourceCreated(BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void onBlockChanged(BlockSource&, const BlockPos&, FullBlock, FullBlock, int);
	virtual void addEntity(std::unique_ptr<Entity>);
	virtual void addPlayer(std::unique_ptr<Player>);
	virtual void addGlobalEntity(std::unique_ptr<Entity>);
	//virtual void explode(BlockSource&, Entity*, float, float, float, float, bool);

	
	bool checkAndHandleWater(const AABB&, MaterialType, Entity*);
};

