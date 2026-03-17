#include <Arduino.h>
#include <motor_control.h>

CMotorControl::CMotorControl(int in1, int in2, int in3, int in4){
    m_iRightWheelsForward = in1;
    m_iRightWheelsBack = in2;
    m_iLeftWheelsForward = in3;
    m_iLeftWheelsBack = in4;
}

void CMotorControl::MotorSetup() {
    // setting up motor control pins
    pinMode(m_iRightWheelsForward, OUTPUT);
    pinMode(m_iRightWheelsBack, OUTPUT);
    pinMode(m_iLeftWheelsForward, OUTPUT);
    pinMode(m_iLeftWheelsBack, OUTPUT);

    // setting motor control pin outputs
    digitalWrite(m_iRightWheelsForward, LOW);
    digitalWrite(m_iRightWheelsBack, LOW);
    digitalWrite(m_iLeftWheelsForward, LOW);
    digitalWrite(m_iLeftWheelsBack, LOW);
}

void CMotorControl::DriveForward(){
    digitalWrite(m_iRightWheelsForward, HIGH);
    digitalWrite(m_iRightWheelsBack, LOW);
    digitalWrite(m_iLeftWheelsForward, HIGH);
    digitalWrite(m_iLeftWheelsBack, LOW);
}

void CMotorControl::DriveBackward(){
    digitalWrite(m_iRightWheelsForward, LOW);
    digitalWrite(m_iRightWheelsBack, HIGH);
    digitalWrite(m_iLeftWheelsForward, LOW);
    digitalWrite(m_iLeftWheelsBack, HIGH);
}

void CMotorControl::TurnLeft(){
    digitalWrite(m_iRightWheelsForward, HIGH);
    digitalWrite(m_iRightWheelsBack, LOW);
    digitalWrite(m_iLeftWheelsForward, LOW);
    digitalWrite(m_iLeftWheelsBack, HIGH);
}

void CMotorControl::TurnRight(){
    digitalWrite(m_iRightWheelsForward, LOW);
    digitalWrite(m_iRightWheelsBack, HIGH);
    digitalWrite(m_iLeftWheelsForward, HIGH);
    digitalWrite(m_iLeftWheelsBack, LOW);
}

void CMotorControl::Stop(){
    digitalWrite(m_iRightWheelsForward, LOW);
    digitalWrite(m_iRightWheelsBack, LOW);
    digitalWrite(m_iLeftWheelsForward, LOW);
    digitalWrite(m_iLeftWheelsBack, LOW);
}