#pragma once

class CMotorControl{
  public:
    CMotorControl(int in1, int in2, int in3, int in4);
    void MotorSetup();
    void DriveForward();
    void DriveBackward();
    void TurnLeft();
    void TurnRight();
    void Stop();

  // defining motor control pins
  private:
    int m_iRightWheelsForward;
    int m_iRightWheelsBack;
    int m_iLeftWheelsForward;
    int m_iLeftWheelsBack;
};