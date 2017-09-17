/*
 *	Declaration of the robot class wich is the nexus of all functions
 */

#ifndef ROBOT_H
#define ROBOT_H



class Robot: public frc::IterativeRobot
{

public:

	Robot();

	void RobotInit();

	void DisabledInit();

	void DisabledPeriodic();

	void AutonomousInit();

	void AutonomousPeriodic();

	void TeleopInit();

	void TeleopPeriodic();

	void TestPeriodic();

private:

};


#endif
