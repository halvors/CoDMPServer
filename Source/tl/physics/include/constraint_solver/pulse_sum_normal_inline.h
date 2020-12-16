
// public: void __thiscall pulse_sum_normal::set(class rigid_body * const,class phys_vec3 const &,class rigid_body * const,class phys_vec3 const &,class phys_vec3 const &,class pulse_sum_cache * const,class phys_vec3 const &)

void __thiscall pulse_sum_normal::set(pulse_sum_normal *this,rigid_body *param_1,phys_vec3 *param_2,rigid_body *param_3,phys_vec3 *param_4,phys_vec3 *param_5,pulse_sum_cache *param_6,phys_vec3 *param_7)

{
    float fVar1;
    code *pcVar2;
    bool bVar3;
    uint uVar4;
    phys_vec3 *ppVar5;
    phys_vec3 local_20;

    if ((param_6 == NULL) && (bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",0x75,"ps_cache",""), bVar3 != false)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
    }
    if ((param_1 == NULL) && (bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",0x76,"b1",""), bVar3 != false)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
    }
    if ((param_3 == NULL) && (bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",0x77,"b2",""), bVar3 != false)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
    }
    if ((param_1 == param_3) && (bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",0x78,"b1 != b2",""), bVar3 != false)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
    }
    PHYS_ASSERT_UNIT(param_5);
    if (param_1->m_node == NULL) {
        if ((param_3->m_node == NULL) && (bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",0x7a,"rbint::get_pulse_sum_node(b1) || rbint::get_pulse_sum_node(b2)",""), bVar3 != false)) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
        }
        if (param_1->m_node != NULL) goto LAB_00a26768;
        uVar4 = param_1->m_flags & 0x30;
    }
    else {
LAB_00a26768:
        uVar4 = (uint)((*(byte *)&param_1->m_flags & 0x30) == 0);
    }
    if (uVar4 != 0) {
        if (param_3->m_node == NULL) {
            uVar4 = param_3->m_flags & 0x30;
        }
        else {
            uVar4 = (uint)((*(byte *)&param_3->m_flags & 0x30) == 0);
        }
        if (uVar4 != 0) goto LAB_00a267ce;
    }
    bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",0x7b,"rbint::verify_pulse_sum_node(b1) && rbint::verify_pulse_sum_node(b2)","");
    if (bVar3 != false) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
    }
LAB_00a267ce:
    if (param_1->m_node == NULL) {
        this->m_b1 = param_3->m_node;
        (this->m_b1_r).x = param_4->x;
        (this->m_b1_r).y = param_4->y;
        (this->m_b1_r).z = param_4->z;
        this->m_b2 = NULL;
        ppVar5 = rbint::gtv(&local_20,param_1,param_2);
        pulse_sum_normal::set_object_vel(this,ppVar5);
        local_20.x = param_2->x + (param_1->m_mat).w.x;
        local_20.y = (param_1->m_mat).w.y + param_2->y;
        local_20.z = (param_1->m_mat).w.z + param_2->z;
        if ((this->m_b2 != NULL) && (bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal.h",0x48,"m_b2 == NULL",""), bVar3 != false)) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
        }
        (this->m_b2_r).x = local_20.x;
        (this->m_b2_r).y = local_20.y;
        (this->m_b2_r).z = local_20.z;
        local_20.x = -param_5->x;
        local_20.y = -param_5->y;
        fVar1 = -param_5->z;
        (this->m_ud).x = local_20.x;
        (this->m_ud).y = local_20.y;
        local_20.z = fVar1;
    }
    else {
        this->m_b1 = param_1->m_node;
        (this->m_b1_r).x = param_2->x;
        (this->m_b1_r).y = param_2->y;
        (this->m_b1_r).z = param_2->z;
        if (param_3->m_node == NULL) {
            this->m_b2 = NULL;
            ppVar5 = rbint::gtv(&local_20,param_3,param_4);
            pulse_sum_normal::set_object_vel(this,ppVar5);
            local_20.x = param_4->x + (param_3->m_mat).w.x;
            local_20.y = (param_3->m_mat).w.y + param_4->y;
            local_20.z = (param_3->m_mat).w.z + param_4->z;
            pulse_sum_normal::set_object_col_pt(this,&local_20);
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
    pulse_sum_normal::calc_abs(this,param_7);
    return;
}
