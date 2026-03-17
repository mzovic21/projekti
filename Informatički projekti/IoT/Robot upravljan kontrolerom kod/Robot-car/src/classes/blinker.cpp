#include <Arduino.h>
#include <blinker.h>

void CBlinker::Init( int iLEDPin ) {
    m_pBlinkPattern = NULL;
    m_iLEDPin = iLEDPin;
    pinMode(m_iLEDPin, OUTPUT);
}

void CBlinker::StartPlayback( const int *pattern, int length, float playback_speed, bool loop ) {
    length /= sizeof(int);
    // No pattern, dont blink
    if( !pattern )
        return;
    
    // Lenght invalid, don't blink
    if( length % 2 != 0 )
        return;

    if( m_pBlinkPattern )
        delete[] m_pBlinkPattern;
    
    m_pBlinkPattern = new int[length];
    memcpy( m_pBlinkPattern, pattern, length * sizeof(int) );
    
    m_iCurrentPos = 0;
    
    m_iPatternLength = length;

    m_flPlaybackSpeed = playback_speed;
    
    m_iNextPatternAt = millis();
    
    m_bLoop = loop;
    
    // Do first think immediately when we start the blinker!
    Think();
}

void CBlinker::Think() {
    if( !m_pBlinkPattern )
        return;
    
    if( m_iNextPatternAt > millis() )
        return;
    
    int pattern_time = m_pBlinkPattern[m_iCurrentPos + 1];
    int blink_time = 0;
    if( m_flPlaybackSpeed > 0 ) {
        blink_time = pattern_time * m_flPlaybackSpeed;
    }
    
    digitalWrite(m_iLEDPin, m_pBlinkPattern[m_iCurrentPos]);

    m_iNextPatternAt = millis() + blink_time;
    
    m_iCurrentPos += 2;
    
    if( m_iCurrentPos >= m_iPatternLength ) {
        if( m_bLoop )
            m_iCurrentPos = 0;
        else {
            Stop();
        }
    }
}

void CBlinker::Stop() {
    digitalWrite(m_iLEDPin, LOW);
    
    if( m_pBlinkPattern ) {
        delete[] m_pBlinkPattern;
        m_pBlinkPattern = NULL;
    }
    m_iCurrentPos = 0;
}

bool CBlinker::IsBlinking() {
    return m_pBlinkPattern != NULL;
}