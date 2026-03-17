#pragma once

class CUltrasonicControl
{
public:
  CUltrasonicControl(int trigPIN, int echoPIN);
  void Think();
  double GetCM();

private:
  enum {
    SENDING = false,
    MEASURING = true
  };

  int m_iTrigPIN;    // Trigger
  int m_iEchoPIN;    // Echo
  
  bool m_bTask;
  double m_dLenght;
  double m_dChangeTaskAtTime;
};
