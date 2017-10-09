
#ifndef A_STAR_H
#define A_STAR_H

#include "Point.h"
#include "Map.h"

#include <vector>
#include <math.h>
#include <iostream>

#define POSITIVE_INFINITY 99999999999999

class A_star
{
public:
	A_star();
	virtual ~A_star();

	std::vector<Point> Get_Path();

private:

	class Node;

	std::vector<Point> Path_;
};

class Node
{

public:

	Node(int X, int Y, bool IsWall, bool AllowDiag, bool IsStart);

	void NewPath(std::vector<Point> Path, Node PrevNode);

	void GetNeighbours(Map map);
	inline std::vector<Node> Neighbours(){return Neighbours_;};


	inline int X(){return X_;};
	inline int Y(){return Y_;};


	inline void CalcF_Score(){F_Score_ = G_Score_ + H_Score_;};
	inline int F_Score(){return F_Score_;};

	float CalcHeuristic(Node EndNode);				//may also return value to simplifie main code
	inline float H_Score(){return H_Score_;};

	inline void SetG_Score(int G_Score){G_Score_ = G_Score;};
	inline float G_Score(){return G_Score_;};

	inline void SetIsWall(bool IsWall){IsWall_ = IsWall;};
	inline bool IsWall(){return IsWall_;};

	inline std::vector<Point> OptimumPath(){return OptimumPath_;};

private:
	int X_, Y_;
	float F_Score_, H_Score_, G_Score_;

	bool AllowDiags_, IsWall_;

	std::vector<Node> Neighbours_;

	std::vector<Point> OptimumPath_;
};

#endif
