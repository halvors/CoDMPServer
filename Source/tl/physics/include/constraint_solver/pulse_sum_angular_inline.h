
// public: void __thiscall pulse_sum_angular::set(class rigid_body * const,class phys_vec3 const &,class rigid_body * const,class phys_vec3 const &,class phys_vec3 const &,class pulse_sum_cache * const)

void __thiscall pulse_sum_angular::set(pulse_sum_angular *this,rigid_body *param_1,phys_vec3 *param_2,rigid_body *param_3,phys_vec3 *param_4,phys_vec3 *param_5,pulse_sum_cache *param_6)

{
    float fVar1;
    float fVar2;
    code *pcVar3;
    bool bVar4;
    uint uVar5;

    if ((param_6 == NULL) && (bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",0x56,"ps_cache",""), bVar4 != false)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
    }
    if ((param_1 == NULL) && (bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",0x57,"b1",""), bVar4 != false)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
    }
    if ((param_3 == NULL) && (bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",0x58,"b2",""), bVar4 != false)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
    }
    if ((param_1 == param_3) && (bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",0x59,"b1 != b2",""), bVar4 != false)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
    }
    PHYS_ASSERT_UNIT(param_5);
    if (param_1->m_node == NULL) {
        if ((param_3->m_node == NULL) && (bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",0x5b,"rbint::get_pulse_sum_node(b1) || rbint::get_pulse_sum_node(b2)",""), bVar4 != false)) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
        }
        if (param_1->m_node != NULL) goto LAB_00a27028;
        uVar5 = param_1->m_flags & 0x30;
    }
    else {
LAB_00a27028:
        uVar5 = (uint)((*(byte *)&param_1->m_flags & 0x30) == 0);
    }
    if (uVar5 != 0) {
        if (param_3->m_node == NULL) {
            uVar5 = param_3->m_flags & 0x30;
        }
        else {
            uVar5 = (uint)((*(byte *)&param_3->m_flags & 0x30) == 0);
        }
        if (uVar5 != 0) goto LAB_00a2708e;
    }
    bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",0x5c,"rbint::verify_pulse_sum_node(b1) && rbint::verify_pulse_sum_node(b2)","");
    if (bVar4 != false) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
    }
LAB_00a2708e:
    if (param_1->m_node == NULL) {
        this->m_b1 = param_3->m_node;
        (this->m_b1_r).x = param_4->x;
        (this->m_b1_r).y = param_4->y;
        (this->m_b1_r).z = param_4->z;
        this->m_b2 = NULL;
        pulse_sum_angular::set_object_vel(this,&param_1->m_a_vel);
        pulse_sum_angular::set_object_col_pt(this,param_2);
        fVar2 = param_5->y;
        fVar1 = -param_5->z;
        (this->m_ud).x = -param_5->x;
        (this->m_ud).y = -fVar2;
    }
    else {
        this->m_b1 = param_1->m_node;
        (this->m_b1_r).x = param_2->x;
        (this->m_b1_r).y = param_2->y;
        (this->m_b1_r).z = param_2->z;
        if (param_3->m_node == NULL) {
            this->m_b2 = NULL;
            pulse_sum_angular::set_object_vel(this,&param_3->m_a_vel);
            pulse_sum_angular::set_object_col_pt(this,param_4);
        }
        else {
            this->m_b2 = param_3->m_node;
            (this->m_b2_r).x = param_4->x;
            (this->m_b2_r).y = param_4->y;
            (this->m_b2_r).z = param_4->z;
        }
        (this->m_ud).x = param_5->x;
        (this->m_ud).y = param_5->y;
        fVar1 = param_5->z;
    }
    (this->m_ud).z = fVar1;
    this->m_pulse_sum_cache = param_6;
    this->m_flags = 0;
    pulse_sum_angular::calc_abs(this);
    return;
}
