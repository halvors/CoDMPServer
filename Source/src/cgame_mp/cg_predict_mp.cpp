#include "cg_local_mp.h"

void __cdecl CG_ClearSavedPlayerState(int index) {
    cg_s *cgameGlob = CG_GetLocalClientGlobals(index);
    if (!cgameGlob) {
		return;
    }
    cgameGlob->impactEffects[11] = 0;
    cgameGlob->impactEffects[12] = 0;
    cgameGlob->impactEffects[13] = 0;
    cgameGlob->impactEffects[14] = 0;
    cgameGlob->impactEffects[15] = 0;
    cgameGlob->impactEffects[16] = 0;
    cgameGlob->impactEffects[17] = 0;
    CG_ClearTransPlayerState((transPlayerState_t *)(cgameGlob->impactEffects + 0x12));
}
