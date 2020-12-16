class actor_s {
private:
	/* data */

public:
	actor_s();
	~actor_s();

	gentity_s *Actor_GetTargetEntity() {
		if (!self) {
			return NULL;
		}

		if (!self->sentient) {
			return NULL;
		}

		return EntHandle::isDefined(&self->sentient->targetEnt) ? EntHandle::ent(&self->sentient->targetEnt) : NULL;
	}

	bool Actor_IsNearClaimedNode() {
		// TODO: Redo this
		if (!self) {
			return false;
		}

		if (!self->ent) {
			return false;
		}

		if (!self->sentient) {
			return false;
		}

		if (!self->sentient->pClaimedNode) {
			return false;
		}

		if (!Actor_KeepClaimedNode(self)) {
			return Actor_PointNearNode((self->ent->r).currentOrigin, self->sentient->pClaimedNode);
		} else {
			return true;
		}

		return false;
	}

	bool Actor_IsMoving() {
		if ((self->eAnimMode == AI_ANIM_MOVE_CODE) && (self->moveMode != '\0')) {
			return true;
		}

		return false;
	}
};

void __fastcall SentientInfo_Clear(sentient_info_t *this) {
	// class function
	if (!this) {
		return;
	}
	
	// *(undefined4 *)&this->VisCache = 0;
	(this->VisCache).iLastUpdateTime = 0;
	(this->VisCache).iLastVisTime = 0;
	this->iLastAttackMeTime = 0;
	this->lastKnownPosTime = 0;
	this->attackTime = 0;
	this->vLastKnownPos[0] = 0.00000000;
	this->vLastKnownPos[1] = 0.00000000;
	this->vLastKnownPos[2] = 0.00000000;
	this->pLastKnownNode = NULL;
}
