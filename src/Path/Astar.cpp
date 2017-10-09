
#include "Astar.h"

Node::Node(int X = 0, int Y = 0, bool IsWall = false, bool AllowDiags = true, bool IsStart = false):
X_(X),
Y_(Y),

IsWall_(IsWall),
AllowDiags_(AllowDiags),

F_Score_(POSITIVE_INFINITY * !IsStart),
H_Score_(POSITIVE_INFINITY * !IsStart),
G_Score_(POSITIVE_INFINITY * !IsStart)

{
	if(IsStart)
		OptimumPath_.push_back(Point(X_, Y_));
}


//Make a guess about the distance from a node to the end
//we can under estimate it without a problem, but we can't under estimate it

float Node::CalcHeuristic(Node EndNode)
{
	if(AllowDiags_)
		H_Score_ = std::sqrt(float(std::pow(X_ - EndNode.X(), 2.0) + (std::pow(Y_ - EndNode.Y(), 2.0))));
	else
		H_Score_ = std::abs(X_ - EndNode.X()) + std::abs(Y_ - EndNode.Y());

	return H_Score_;
}

void Node::GetNeighbours(Map map)
{
	if(map[X_ + 1][Y_] != 1)
		Neighbours_.push_back(Node(X_ + 1, Y_));
	if(map[X_ - 1][Y_] != 1)
		Neighbours_.push_back(Node(X_ - 1, Y_));
	if(map[X_][Y_ + 1] != 1)
		Neighbours_.push_back(Node(X_, Y_ + 1));
	if(map[X_][Y_ - 1] != 1)
		Neighbours_.push_back(Node(X_, Y_ - 1));

	if(AllowDiags_)
	{
		if(map[X_ + 1][Y_ + 1] != 1)
			Neighbours_.push_back(Node(X_ + 1, Y_ + 1));
		if(map[X_ - 1][Y_ + 1] != 1)
			Neighbours_.push_back(Node(X_ - 1, Y_ + 1));
		if(map[X_ + 1][Y_ - 1] != 1)
			Neighbours_.push_back(Node(X_ + 1, Y_ - 1));
		if(map[X_ - 1][Y_ - 1] != 1)
			Neighbours_.push_back(Node(X_ - 1, Y_ - 1));
	}
}

void Node::NewPath(std::vector<Point> Path, Node PrevNode)
{
	OptimumPath_ = Path;
	OptimumPath_.push_back(Point(PrevNode.X(), PrevNode.Y()));
}

bool operator == (Node &a, Node &b)
{
	return (a.X() == b.X()) && (a.Y() == b.Y());
}

std::ostream &operator<<(std::ostream &os, Node &a)
{
	return os<<"[ "<<a.X()<<", "<<a.Y()<<" ]\tF : "<<a.F_Score()<<",  G : "<<a.G_Score()<<",  H : "<<a.H_Score();
}
