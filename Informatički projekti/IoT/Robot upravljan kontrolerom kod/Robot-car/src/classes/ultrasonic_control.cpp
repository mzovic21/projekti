#include <Arduino.h>
#include <ultrasonic_control.h>

CUltrasonicControl::CUltrasonicControl( int trigPIN, int echoPIN ) {
    m_iTrigPIN = trigPIN;
    m_iEchoPIN = echoPIN;

    pinMode(trigPIN, OUTPUT);
    pinMode(echoPIN, INPUT);

    m_bTask = SENDING;
    m_dLenght = 0.0f;
    // Change our task in 10 milis, since that's how long we have to send for
    m_dChangeTaskAtTime = millis() + 10;
}

void CUltrasonicControl::Think() {
    if( m_dChangeTaskAtTime <= millis() ) {
        // Swap the current task to the next one
        if( m_bTask == SENDING )
            m_bTask = MEASURING;
        else if( m_bTask == MEASURING )
            m_bTask = SENDING;
        
        // If we are sending, change the task in 10 miliseconds, since we need to measure for that long
        if( m_bTask == SENDING )
            m_dChangeTaskAtTime = millis() + 10;
        // If we are measuring, change the task on the next loop immediately
        else if( m_bTask == MEASURING )
            m_dChangeTaskAtTime = millis();
    }

    // To send with the ultrasonic sensor, we have to set it to high
    if( m_bTask == SENDING ) {
        digitalWrite(m_iTrigPIN, HIGH);
    }
    else if( m_bTask == MEASURING ) {
        // When we want to measure the lenght, we first have to set our sensor to LOW
        digitalWrite(m_iTrigPIN, LOW);

        // Read the signal from the sensor: a HIGH pulse whose
        // duration is the time (in microseconds) from the sending
        // of the ping to the reception of its echo off of an object.
        m_dLenght = pulseIn(m_iEchoPIN, HIGH);
    }
}

double CUltrasonicControl::GetCM() {
    // duration is the time it takes from sending the signal to recieving it
    // Divide by 29.1 or multiply by 0.0343 to convert from ms to cm
    return (m_dLenght/2) / 29.1;
}