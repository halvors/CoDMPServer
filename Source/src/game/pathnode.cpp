
// void __cdecl Path_DrawDebugNode(float const * const,struct pathnode_t const *)

void __cdecl Path_DrawDebugNode(float *cameraPos,pathnode_t *node)

{
    char *pcVar1;
    code *pcVar2;
    undefined4 *puVar3;
    uint uVar4;
    int iVar5;
    float10 fVar6;
    undefined4 *local_17c;
    undefined4 *local_174;
    undefined4 *local_16c;
    undefined4 *local_164;
    undefined4 *local_15c;
    undefined4 *local_154;
    undefined4 *local_14c;
    undefined4 *local_144;
    undefined4 *local_13c;
    float boxsizeMax[3];
    float boxsizeMin[3];
    char temp[256];
    float org[3];
    float scale;

    boxsizeMin[0] = -16.00000000;
    boxsizeMin[1] = -16.00000000;
    boxsizeMin[2] = 0.00000000;

    _Assert_MyHandler(cameraPos == NULL);
    _Assert_MyHandler(node == NULL);

    Path_DrawDebugNodeBox(node);
    org[0] = (node->constant).vOrigin[0];
    org[1] = (node->constant).vOrigin[1];
    org[2] = (16.00000000 - boxsizeMin[2]) * 0.50000000 + (node->constant).vOrigin[2];
    fVar6 = (float10)Path_GetDebugStringScale(cameraPos,org);
    scale = (float)fVar6;
    _sprintf(temp,"%s",(&nodeStringTable)[(node->constant).type]);

    iVar5 = IsNodeEnabled(node);

	if (iVar5 == 0) {
        puVar3 = (undefined4 *)((int)boxsizeMin + 0xb);

	    do {
            local_13c = puVar3;
            puVar3 = (undefined4 *)((int)local_13c + 1);
        } while (*(char *)((int)local_13c + 1) != '\0');

	    *(undefined4 *)((int)local_13c + 1) = 0x4c44203a;
        *(undefined *)((int)local_13c + 5) = 0;
    }

	if (((node->constant).spawnflags & 4) != 0) {
        local_144 = (undefined4 *)((int)boxsizeMin + 0xb);

		do {
            pcVar1 = (char *)((int)local_144 + 1);
            local_144 = (undefined4 *)((int)local_144 + 1);
        } while (*pcVar1 != '\0');

	    *local_144 = 0x53443a;
    }

    if (((node->constant).spawnflags & 8) != 0) {
        local_14c = (undefined4 *)((int)boxsizeMin + 0xb);

	    do {
            pcVar1 = (char *)((int)local_14c + 1);
            local_14c = (undefined4 *)((int)local_14c + 1);
        } while (*pcVar1 != '\0');

	    *local_14c = 0x43443a;
    }

    if (((node->constant).spawnflags & 0x10) != 0) {
        local_154 = (undefined4 *)((int)boxsizeMin + 0xb);

	    do {
            pcVar1 = (char *)((int)local_154 + 1);
            local_154 = (undefined4 *)((int)local_154 + 1);
        } while (*pcVar1 != '\0');

	    *local_154 = 0x50443a;
    }

    if (((node->constant).spawnflags & 0x800) != 0) {
	    if ((node->constant).type == NODE_COVER_PILLAR) {
            local_15c = (undefined4 *)((int)boxsizeMin + 0xb);

			do {
                pcVar1 = (char *)((int)local_15c + 1);
                local_15c = (undefined4 *)((int)local_15c + 1);
            } while (*pcVar1 != '\0');

		    *local_15c = 0x52443a;
        } else {
            if (((node->constant).type == NODE_NEGOTIATION_BEGIN) || ((node->constant).type == NODE_NEGOTIATION_END)) {
                puVar3 = (undefined4 *)((int)boxsizeMin + 0xb);

			    do {
                    local_164 = puVar3;
                    puVar3 = (undefined4 *)((int)local_164 + 1);
                } while (*(char *)((int)local_164 + 1) != '\0');

			    *(undefined4 *)((int)local_164 + 1) = 0x5254533a;
                *(undefined4 *)((int)local_164 + 5) = 0x544349;
            } else {
                puVar3 = (undefined4 *)((int)boxsizeMin + 0xb);

			    do {
                    local_16c = puVar3;
                    puVar3 = (undefined4 *)((int)local_16c + 1);
                } while (*(char *)((int)local_16c + 1) != '\0');

			    *(undefined4 *)((int)local_16c + 1) = 0x4e59423a;
                *(undefined2 *)((int)local_16c + 5) = 0x52;
            }
        }
    }

    if (((node->constant).spawnflags & 0x400) != 0) {
        if ((node->constant).type == NODE_COVER_PILLAR) {
            local_174 = (undefined4 *)((int)boxsizeMin + 0xb);

		    do {
		        pcVar1 = (char *)((int)local_174 + 1);
                local_174 = (undefined4 *)((int)local_174 + 1);
		    } while (*pcVar1 != '\0');

		    *local_174 = 0x4c443a;
        } else {
            local_17c = (undefined4 *)((int)boxsizeMin + 0xb);

		    do {
                pcVar1 = (char *)((int)local_17c + 1);
                local_17c = (undefined4 *)((int)local_17c + 1);
            } while (*pcVar1 != '\0');

		    *local_17c = 0x59423a;
        }
    }

	G_AddDebugStringWithDuration(org,(float *)&colorYellow,scale,temp,0);
    @__security_check_cookie@4();
    return;
}
