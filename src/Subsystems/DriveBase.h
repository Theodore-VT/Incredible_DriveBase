
#ifndef DRIVEBASE_H
#define DRIVEBASE_H


#include <src/Path/Path.h>

class DriveBase
{
public:
	enum State{PATH_FOLOWING, PILOT_DRIVING, VISION_AIMING};

	DriveBase();
	virtual ~DriveBase();

	void Update();


	void SetState(State wantedState);
	State GetState();

	void SetPath(Path wantedPath);


private:
	State m_state;

	Path m_path;
};

#endif
