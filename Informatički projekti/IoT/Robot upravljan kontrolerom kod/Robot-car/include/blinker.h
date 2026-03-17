#pragma once

class CBlinker
{
public:
	void Init( int iLEDPin );
	void StartPlayback( const int *pattern, int length, float playback_speed, bool loop = false );
	void Think();
	void Stop();
	bool IsBlinking();
	
private:
	int m_iLEDPin;

	float m_flPlaybackSpeed;
	int *m_pBlinkPattern;
	int m_iPatternLength;
	int m_iCurrentPos;
	unsigned long m_iNextPatternAt;
	
	bool m_bLoop;
};