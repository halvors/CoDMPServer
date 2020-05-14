void __fastcall SentientInfo_Clear(sentient_info_t *pInfo) // This is fastcall for some reason.
{
    if (IsBadReadPtr(pInfo))
	{
		return;
    }
    *(undefined4 *)&pInfo->VisCache = 0;
    (pInfo->VisCache).iLastUpdateTime = 0;
    (pInfo->VisCache).iLastVisTime = 0;
    pInfo->iLastAttackMeTime = 0;
    pInfo->lastKnownPosTime = 0;
    pInfo->attackTime = 0;
    pInfo->vLastKnownPos[0] = 0.00000000;
    pInfo->vLastKnownPos[1] = 0.00000000;
    pInfo->vLastKnownPos[2] = 0.00000000;
    pInfo->pLastKnownNode = NULL;
}
