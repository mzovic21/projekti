//=================================================================
// Credit to https://github.com/robsoncouto/arduino-songs 
// For divider and tempo calculations
//=================================================================

#pragma once

#include "note_volumes.h"

class CMusicPlayer
{
public:
	void Init( int iTonePin );
	void StartPlayback( const int *melody, int length, int tempo, bool loop = false );
	void Think();
	void Stop();
	bool IsPlaying();

private:
	int m_iBuzzerPin;

	int m_iTempo;
	int *m_pMelody;
	int m_iMelodyLength;
	int m_iCurrentNote;
	unsigned long m_iNextBeatAt;
	
	bool m_bLoop;
};