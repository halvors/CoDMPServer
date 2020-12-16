int Turret_PlaceTurret_Client(int id, entityState_s *es, float *outOrigin, float *outAngles) {
	// playerState_s *ps; // this isn't used
	int canPlace;
	float viewOrg[3];
	float moverOrigin[3];
	float viewAngles[3];

	if (!es) {
		return 0;
	}

	if (!outOrigin) {
		return 0;
	}

	if (!outAngles) {
		return 0;
	}

	if ((*(unsigned int *)((es->lerp).u + 0x1C) & 8) == 0) {
		canPlace = 0;
	} else {
		cg_s *cgameGlob = CG_GetLocalClientGlobals(id);

		if (!cgameGlob) {
			return 0;
		}

		if ((unsigned short)es->otherEntityNum > MAX_CLIENTS) {
			return 0;
		}

		if (((int)es->otherEntityNum == (unsigned int)(cgameGlob->predictedPlayerState).clientNum) && ((cgameGlob->renderingThirdPerson == TP_OFF || Demo_IsPlaying()))) {
			BG_GetPlayerViewOrigin(&cgameGlob->predictedPlayerState, viewOrg, cgameGlob->time);
			viewOrg[2] = (60.00000000 - (cgameGlob->predictedPlayerState).viewHeightCurrent) + viewOrg[2];
			viewAngles[0] = (cgameGlob->predictedPlayerState).viewangles[0];
			viewAngles[1] = (cgameGlob->predictedPlayerState).viewangles[1];
			viewAngles[2] = (cgameGlob->predictedPlayerState).viewangles[2];
			moverOrigin[0] = (cgameGlob->predictedPlayerState).origin[0];
			moverOrigin[1] = (cgameGlob->predictedPlayerState).origin[1];
			moverOrigin[2] = (cgameGlob->predictedPlayerState).origin[2];
		} else {
			centity_s *carrierEnt = (int)es->otherEntityNum == (unsigned int)(cgameGlob->predictedPlayerState).clientNum ? &cgameGlob->predictedPlayerEntity : CG_GetEntity(id, (int)es->otherEntityNum);

			if (!carrierEnt) {
				return 0;
			}

			clientInfo_t *ci = (clientInfo_t *)((int)(cgameGlob->bgs).clientinfo + (unsigned int)es->clientNum * 0x5C8);

			if ((ci == NULL) || (ci->infoValid == 0)) {
				Com_PrintWarning(0x11, "Sentry [%d] isBeingCarried but the client info [%d] is invalid! Script should ensure that this doesn\'t happen.\n", es->number, (int)es->otherEntityNum);
				return 0;
			}

			viewAngles[0] = ci->playerAngles[0];
			viewAngles[1] = ci->playerAngles[1];
			viewAngles[2] = ci->playerAngles[2];

			moverOrigin[0] = (carrierEnt->pose).origin[0];
			moverOrigin[1] = (carrierEnt->pose).origin[1];
			moverOrigin[2] = (carrierEnt->pose).origin[2];

			viewOrg[0] = (carrierEnt->pose).origin[0];
			viewOrg[1] = (carrierEnt->pose).origin[1];
			viewOrg[2] = (carrierEnt->pose).origin[2] + 60.00000000;

			AddLeanToPosition(viewOrg, viewAngles[1], ci->lerpLean, 16.00000000, 20.00000000);
		}

		canPlace = Turret_PlaceTurret_Internal(TURRET_HANDLER_CLIENT, id, (int)es->otherEntityNum, moverOrigin, viewOrg, viewAngles, outOrigin, outAngles);

		if ((cgameGlob->predictedPlayerState).pm_flags & 4U) {
			canPlace = 0;
		}
	}

	return canPlace;
}
