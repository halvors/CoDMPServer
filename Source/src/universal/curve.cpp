class cCurve {
private:
	/* data */

public:
	void Smooth() {
		float *pfVar1;
		float fVar2;
		float local_38;
		float local_34;
		float local_30;
		float local_2c;
		float local_28;
		float local_24;
		int local_20;
		float newVel[3];
		float oldVel[3];

		cCurve::GetStartVelocity(this, 0, oldVel);

		for (int i = 1; i < this->mNumNodes - 1; i++) {
			cCurve::GetEndVelocity(this, i, &local_38);
			fVar2 = this->mNodes[i].dist;
			local_38 = fVar2 * local_38;
			local_34 = fVar2 * local_34;
			local_30 = fVar2 * local_30;
			cCurve::GetStartVelocity(this, i, &local_2c);

			fVar2 = this->mNodes[i - 1].dist;

			local_2c = fVar2 * local_2c;
			local_28 = fVar2 * local_28;
			local_24 = fVar2 * local_24;

			newVel[2] = 1.00000000 / (this->mNodes[i - 1].dist + this->mNodes[i].dist);
			newVel[0] = newVel[2] * (local_2c + local_38);
			newVel[1] = newVel[2] * (local_28 + local_34);
			newVel[2] = newVel[2] * (local_24 + local_30);

			pfVar1 = this->mNodes[i - 1].vel;

			*pfVar1 = oldVel[0];
			pfVar1[1] = oldVel[1];
			pfVar1[2] = oldVel[2];

			oldVel[0] = newVel[0];
			oldVel[1] = newVel[1];
			oldVel[2] = newVel[2];
		}

		cCurve::GetEndVelocity(this, this->mNumNodes - 1, this->mNodes[this->mNumNodes - 1].vel);

		pfVar1 = this->mNodes[this->mNumNodes - 2].vel;
		*pfVar1 = oldVel[0];

		pfVar1[1] = oldVel[1];
		pfVar1[2] = oldVel[2];
	}

	float GetLength() {
		float fVar4;
		float local_48;
		float local_44;
		float local_40;
		float local_38;
		float local_34;
		float local_30;
		float length;
		undefined4 local_24;
		float local_20;
		float local_1c;
		float local_18;
		float local_14;
		float local_10;
		float local_c;
		float local_8;

		_Assert_MyHandler(this->mActive == true);

		if (this->mCurveType == CURVE_TNS) {
			length = 0.00000000;
			local_14 = 0.00000000;
			local_24 = 0x20;

			for (int i = 0; i < this->mNumNodes; i++) {
				local_34 = local_14 + this->mNodes[i].dist;
				local_30 = (local_34 - local_14) / 32.00000000;
				local_38 = local_14;
				fVar4 = local_14 / this->mDistance;
				local_14 = local_14 + this->mNodes[i].dist;
				cCurve::GetPosition(this, fVar4, &local_10);

				for (int j = 0; j < 32; j++) {
					local_38 = local_38 + local_30;
					cCurve::GetPosition(this, local_38 / this->mDistance, &local_20);

					local_48 = local_20 - local_10;
					local_44 = local_1c - local_c;
					local_40 = local_18 - local_8;

					fVar4 = Vec3Length(&local_48);
					length = fVar4 + length;

					local_10 = local_20;
					local_c = local_1c;
					local_8 = local_18;
				}
			}
		} else {
			length = this->mDistance;
		}

		return length;
	}

	void Reinit() {
		this->mActive = true;
		this->mDraw = false;
		this->mUseColor = false;
		this->mPaused = true;
		this->mNotifyEntNum = 1023;
		this->mNotifyLevel = false;
		this->mCameraEntNum = 1023;
		this->mLastNode = -1;
		this->mNumNodes = 0;
		this->mCurveType = CURVE_RNS;
		this->mDistance = 0.00000000;
		this->mCurPos = 0.00000000;
		this->mCurServerPos = 0.00000000;
	}

	void SetDraw(float *color) {
		this->mDraw = true;

		if (color == NULL) {
			this->mUseColor = false;
		} else {
			this->mDrawColor[0] = *color;
			this->mDrawColor[1] = color[1];
			this->mDrawColor[2] = color[2];
			this->mDrawColor[3] = color[3];
			this->mUseColor = true;
		}
	}

	void Reset() {
		this->mActive = false;
		this->mDraw = false;
		this->mUseColor = false;
		this->mPaused = true;
		this->mNotifyEntNum = 1023;
		this->mNotifyLevel = false;
		this->mCameraEntNum = 1023;
		this->mLastNode = -1;
		this->mNumNodes = 0;
		this->mCurveType = CURVE_RNS;
		this->mDistance = 0.00000000;
		this->mCurPos = 0.00000000;
		this->mCurServerPos = 0.00000000;
		this->mSpeed = 12.00000000;

		for (int i = 0; i < 100; i++) {
			this->mNodes[i].pos[2] = 0.00000000;
			this->mNodes[i].pos[1] = 0.00000000;
			this->mNodes[i].pos[0] = 0.00000000;
			this->mNodes[i].vel[2] = 0.00000000;
			this->mNodes[i].vel[1] = 0.00000000;
			this->mNodes[i].vel[0] = 0.00000000;
			this->mNodes[i].dist = 0.00000000;
			this->mNodes[i].totalDist = 0.00000000;
			this->mNodes[i].bReached = false;
		}
	}

	void Sort(float *param_1, bool increasingOrder) {
		nodeData *node1;
		nodeData *node2;
		float vecLength;
		vec3_t vecDist;

		gCurveSortArgs.increasing_sort_order = increasingOrder;
		gCurveSortArgs.p[0] = *param_1;
		gCurveSortArgs.p[1] = param_1[1];
		gCurveSortArgs.p[2] = param_1[2];
		_qsort(this, this->mNumNodes, 0x24, cCurve::CurveSortCompare);

		for (int i = 0; i < this->mNumNodes; i++) {
			if (i == 0) {
				this->mDistance = 0.00000000;
				this->mNodes[0].totalDist = 0.00000000;
			} else {
				node1 = this->mNodes + i;
				node2 = this->mNodes + i - 1;
				vecDist = node2->pos - node1->pos;
				vecLength = Vec3Length(&vecDist);
				this->mNodes[i - 1].dist = vecLength;
				this->mDistance = this->mDistance + this->mNodes[i - 1].dist;
				this->mNodes[i].totalDist = this->mDistance;
			}
		}
	}
};


void Constrain() {
	// float *pfVar1;
	// nodeData *node1;
	// nodeData *node2;
	// float fVar2;
	// float fVar3;
	// float *local_40;
	// vec3_t vecDist;
	//
	// for (int i = 0; i < this->mNumNodes; i++) {
	// 	node1 = this->mNodes + i - 1;
	// 	node2 = this->mNodes + i;
	// 	vecDist = node2->pos - node1->pos;
	// 	fVar2 = Vec3Length((vec3_t)CONCAT48(local_40, CONCAT44(this, vecDist)));
	// 	fVar2 = fVar2 / this->mNodes[i - 1].dist;
	//
	// 	node2 = this->mNodes + i;
	// 	node1 = this->mNodes + i + 1;
	// 	vecDist = node1->pos - node2->pos;
	// 	fVar3 = Vec3Length((vec3_t)CONCAT48(local_40, CONCAT44(this, vecDist)));
	// 	fVar3 = fVar3 / this->mNodes[i].dist;
	//
	// 	local_40 = this->mNodes[i].vel;
	// 	fVar2 = (fVar2 * 4.00000000 * fVar3) / ((fVar2 + fVar3) * (fVar2 + fVar3));
	// 	pfVar1 = this->mNodes[i].vel;
	//
	// 	*local_40 = fVar2 * *pfVar1;
	// 	local_40[1] = fVar2 * pfVar1[1];
	// 	local_40[2] = fVar2 * pfVar1[2];
	// }
}

void __thiscall cCurve::AddNode(cCurve *this, vec3_t pos, float dist) {
	_Assert_MyHandler(mActive == true);
	_Assert_MyHandler(mNumNodes < MAX_NODES);

	this->mNodes[this->mNumNodes].pos = *pos;

	if (this->mNumNodes == 0) {
		this->mDistance = 0.00000000;
	} else {
		this->mNodes[this->mNumNodes + -1].dist = dist;
		this->mDistance = this->mDistance + this->mNodes[this->mNumNodes + -1].dist;
		this->mNodes[this->mNumNodes].totalDist = this->mDistance;
	}

	this->mCurveType = CURVE_TNS;
	this->mNumNodes = this->mNumNodes + 1;

	return;
}
