#include "Emeny.h"

int UEmeny::GetScoreValue() const {
	if(IsDestroyed())
		return 0;
	
	return OnElminatedScoreValue;
}