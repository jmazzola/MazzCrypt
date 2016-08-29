// BSP.h - File for all the BSP enums/structs to parse through BSP trees for an external/reliable visibility check
#pragma once

#include "stdafx.h"
#include "Vector.h"

#include "Decrypt.h"



enum Header
{
	LUMP_ENTITIES = 0,
	LUMP_PLANES = 1,
	LUMP_TEXTURES = 2,
	LUMP_VERTICES = 3,
	LUMP_VISIBILITY = 4,
	LUMP_NODES = 5,
	LUMP_TEXINFO = 6,
	LUMP_FACES = 7,
	LUMP_LIGHTING = 8,
	LUMP_CLIPNODES = 9,
	LUMP_LEAVES = 10,
	LUMP_MARKSURFACES = 11,
	LUMP_EDGES = 12,
	LUMP_SURFEDGES = 13,
	LUMP_MODELS = 14,
	HEADER_LUMPS = 15
};


enum Contents
{
	CONTENTS_EMPTY = 0,				//  No contents
	CONTENTS_SOLID = 0x1,				//	an eye is never valid in a solid
	CONTENTS_WINDOW = 0x2,				//	translucent, but not watery( glass )
	CONTENTS_AUX = 0x4,				//
	CONTENTS_GRATE = 0x8,				//	alpha - tested "grate" textures.Bullets / sight pass through, but solids don't
	CONTENTS_SLIME = 0x10,				//
	CONTENTS_WATER = 0x20,				//
	CONTENTS_MIST = 0x40,				//
	CONTENTS_OPAQUE = 0x80,				//	block AI line of sight
	CONTENTS_TESTFOGVOLUME = 0x100,			//	things that cannot be seen through( may be non - solid though )
	CONTENTS_UNUSED = 0x200,			//	unused
	CONTENTS_UNUSED6 = 0x400,			//  unused
	CONTENTS_TEAM1 = 0x800,			//  per team contents used to differentiate collisions between players and objects on different teams
	CONTENTS_TEAM2 = 0x1000,			//
	CONTENTS_IGNORE_NODRAW_OPAQUE = 0x2000,			//	ignore CONTENTS_OPAQUE on surfaces that have SURF_NODRAW
	CONTENTS_MOVEABLE = 0x4000,			//	hits entities which are MOVETYPE_PUSH( doors, plats, etc. )
	CONTENTS_AREAPORTAL = 0x8000,			//	remaining contents are non - visible, and don't eat brushes
	CONTENTS_PLAYERCLIP = 0x10000,			//
	CONTENTS_MONSTERCLIP = 0x20000,			//
	CONTENTS_CURRENT_0 = 0x40000,			//	currents can be added to any other contents, and may be mixed
	CONTENTS_CURRENT_90 = 0x80000,			//
	CONTENTS_CURRENT_180 = 0x100000,			//
	CONTENTS_CURRENT_270 = 0x200000,			//
	CONTENTS_CURRENT_UP = 0x400000,			//
	CONTENTS_CURRENT_DOWN = 0x800000,			//
	CONTENTS_ORIGIN = 0x1000000,		//	removed before bsping an entity
	CONTENTS_MONSTER = 0x2000000,		//	should never be on a brush, only in game
	CONTENTS_DEBRIS = 0x4000000,		//
	CONTENTS_DETAIL = 0x8000000,		//	brushes to be added after vis leafs
	CONTENTS_TRANSLUCENT = 0x10000000,		//	auto set if any surface has trans
	CONTENTS_LADDER = 0x20000000,		//
	CONTENTS_HITBOX = 0x40000000		//	use accurate hitboxes on trace
};


struct dleaf_t
{
	int					contents;			// OR of all brushes (not needed?)

	short				cluster;			// cluster this leaf is in

	short				area : 9;			// area this leaf is in

	short				flags : 7;			// flags

	short				mins[3];			// for frustum culling

	short				maxs[3];

	unsigned short		firstleafface;		// index into leaffaces

	unsigned short		numleaffaces;

	unsigned short		firstleafbrush;		// index into leafbrushes

	unsigned short		numleafbrushes;

	short				leafWaterDataID;	// -1 for not in water


											//!!! NOTE: for maps of version 19 or lower uncomment this block
											/*
											CompressedLightCube	ambientLighting;	// Precaculated light info for entities.

											short			padding;		// padding to 4-byte boundary

											*/
};


struct lump_t
{
	int	 fileofs;	// offset into file (bytes)

	int	 filelen;	// length of lump (bytes)

	int	 version;	// lump format version

	char fourCC[4];	// lump ident code

};


struct dheader_t
{
	int		ident;                // BSP file identifier

	int		version;              // BSP file version

	lump_t	lumps[HEADER_LUMPS];// lump directory array

	int		mapRevision;          // the map's revision (iteration, version) number

};


struct dnode_t
{
	int				planenum;	// index into plane array

	int		children[2];		// negative numbers are -(leafs + 1), not nodes

	short		mins[3];		// for frustum culling

	short		maxs[3];

	unsigned short	firstface;	// index into face array

	unsigned short	numfaces;	// counting both sides

	short			area;		// If all leaves below this node are in the same area, then

								// this is the area index. If not, this is -1.
	short			padding;	// pad to 32 bytes length

};


struct dplane_t
{
	Vector	normal;	// normal vector

	float	dist;	// distance from origin

	int		type;	// plane axis identifier

};


class BSP
{
public:

	BSP() = default;

	~BSP();


	
	void Unload();

	bool IsNull();

	bool IsVisible(Vector& vStart, Vector& vEnd);
	dleaf_t* GetLeafFromPoint(Vector point);




	void DisplayInfo();

	bool Load(std::string& szPath, std::string& szMapName);
	std::string GetMapName() const;


private:



	
	std::string m_szPathName;

	dleaf_t* m_pLeaf;


	dplane_t* m_pPlane;
	BYTE* m_pbData;

	std::string m_szMapName = Decrypt(15,11,41,103,5,40,58,107,8,40,58,42,51,37,55,55);

	dheader_t* m_pHeader;

	dnode_t* m_pNode;



	char GGDCQRWLAO = 'J';
bool MUEHPNTAPJ = true;
char* FUNCXHRIDK = "KYNPMBAGVX";
int XGZPCZOGVM = 0x788442B5;


};


extern BSP* pBSP;



