
// public: void __thiscall pulse_sum_point::set(class rigid_body * const,class phys_vec3 const &,class rigid_body * const,class phys_vec3 const &,class pulse_sum_cache * const,float,bool,float,float)

void __thiscall pulse_sum_point::set(pulse_sum_point *this,rigid_body *param_1,phys_vec3 *param_2,rigid_body *param_3,phys_vec3 *param_4,pulse_sum_cache *param_5,float param_6,bool param_7,float param_8,float param_9)

{
    code *pcVar1;
    float fVar2;
    bool bVar3;
    uint uVar4;
    phys_vec3 *ppVar5;
    phys_vec3 local_20;

    if (param_5 == NULL) {
        bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",0xa7,"ps_cache","");
        if (bVar3 != false) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    if (param_1 == NULL) {
        bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",0xa8,"b1","");
        if (bVar3 != false) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    if (param_3 == NULL) {
        bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",0xa9,"b2","");
        if (bVar3 != false) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    if (param_1 == param_3) {
        bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",0xaa,"b1 != b2","");
        if (bVar3 != false) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    if ((param_1->m_node == NULL) && (param_3->m_node == NULL)) {
        bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",0xab,"rbint::get_pulse_sum_node(b1) || rbint::get_pulse_sum_node(b2)","");
        if (bVar3 != false) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    if (param_1->m_node == NULL) {
        uVar4 = param_1->m_flags & 0x30;
    }
    else {
        uVar4 = (uint)((*(byte *)&param_1->m_flags & 0x30) == 0);
    }
    if (uVar4 != 0) {
        if (param_3->m_node == NULL) {
            uVar4 = param_3->m_flags & 0x30;
        }
        else {
            uVar4 = (uint)((*(byte *)&param_3->m_flags & 0x30) == 0);
        }
        if (uVar4 != 0) goto LAB_00a27531;
    }
    bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",0xac,"rbint::verify_pulse_sum_node(b1) && rbint::verify_pulse_sum_node(b2)","");
    if (bVar3 != false) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
    }
LAB_00a27531:
    if (param_1->m_node == NULL) {
        bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",0xae,"rbint::get_pulse_sum_node(b1) != NULL","");
        if (bVar3 != false) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    this->m_b1 = param_1->m_node;
    (this->m_b1_r).x = param_2->x;
    (this->m_b1_r).y = param_2->y;
    (this->m_b1_r).z = param_2->z;
    if (param_3->m_node == NULL) {
        this->m_b2 = NULL;
        ppVar5 = rbint::gtv(&local_20,param_3,param_4);
        pulse_sum_point::set_object_vel(this,ppVar5);
        local_20.x = param_4->x + (param_3->m_mat).w.x;
        local_20.y = (param_3->m_mat).w.y + param_4->y;
        local_20.z = (param_3->m_mat).w.z + param_4->z;
        if (this->m_b2 != NULL) {
            bVar3 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_point.h",0x2f,"m_b2 == NULL","");
            if (bVar3 != false) {
                pcVar1 = (code *)swi(3);
                (*pcVar1)();
                return;
            }
        }
        (this->m_b2_r).x = local_20.x;
        (this->m_b2_r).y = local_20.y;
        fVar2 = local_20.z;
    }
    else {
        this->m_b2 = param_3->m_node;
        (this->m_b2_r).x = param_4->x;
        (this->m_b2_r).y = param_4->y;
        fVar2 = param_4->z;
    }
    (this->m_b2_r).z = fVar2;
    this->m_pulse_sum_cache = param_5;
    pulse_sum_point::calc_abs_and_setup(this,param_6,param_7,param_8,param_9);
    return;
}
