#include <Arduino.h>
#include <music_player.h>

void CMusicPlayer::Init( int iTonePin ) {
    m_pMelody = NULL;
    m_iBuzzerPin = iTonePin;
}

void CMusicPlayer::StartPlayback( const int *melody, int length, int tempo, bool loop ) {
    length /= sizeof(int);
    // No melody, dont play
    if( !melody )
        return;
    
    // Lenght invalid, don't play
    if( length % 2 != 0 )
        return;

    if( m_pMelody )
        delete[] m_pMelody;
    
    m_pMelody = new int[length];
    memcpy( m_pMelody, melody, length * sizeof(int) );
    
    m_iCurrentNote = 0;
    
    m_iMelodyLength = length;

    m_iTempo = (60000 * 4) / tempo;
    
    m_iNextBeatAt = millis();
    
    m_bLoop = loop;
    
    // Do first think immediately when we start the song!
    Think();
}

void CMusicPlayer::Think() {
    if( !m_pMelody )
        return;
    
    if( m_iNextBeatAt > millis() )
        return;
    
    // calculates the duration of each note
    int divider = m_pMelody[m_iCurrentNote + 1];
    int noteDuration = 0;
    if( divider > 0 ) {
        // regular note, just proceed
        noteDuration = (m_iTempo) / divider;
    }
    else if( divider < 0 ) {
        // dotted notes are represented with negative durations!!
        noteDuration = (m_iTempo) / abs(divider);
        noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    
    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(m_iBuzzerPin, m_pMelody[m_iCurrentNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    m_iNextBeatAt = millis() + noteDuration;
    
    m_iCurrentNote += 2;
    
    if( m_iCurrentNote >= m_iMelodyLength ) {
        if( m_bLoop )
            m_iCurrentNote = 0;
        else {
            Stop();
        }
    }
}

void CMusicPlayer::Stop() {
    tone(m_iBuzzerPin, REST, 0);
    
    if( m_pMelody ) {
        delete[] m_pMelody;
        m_pMelody = NULL;
    }
    m_iCurrentNote = 0;
}

bool CMusicPlayer::IsPlaying() {
    return m_pMelody != NULL;
}