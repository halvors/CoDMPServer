
// WARNING: Variable defined which should be unmapped: b2_r_loc
// public: void __thiscall pulse_sum_contact::set(class rigid_body * const,class rigid_body * const,class contact_point_info *,float)

void __thiscall pulse_sum_contact::set(pulse_sum_contact *this,rigid_body *param_1,rigid_body *param_2,contact_point_info *param_3,float param_4)

{
    rigid_body *prVar1;
    code *pcVar2;
    float fVar3;
    bool bVar4;
    uint uVar5;
    phys_vec3 *ppVar6;
    phys_vec3 *ppVar7;
    pulse_sum_contact_point *this_00;
    phys_vec3 local_70;
    phys_vec3 local_60;
    float local_50;
    float local_4c;
    float local_48;
    float local_40;
    float local_3c;
    float local_38;
    phys_vec3 b2_r;
    int local_20;
    float min_restitution_impact_vel_sq;
    phys_vec3 *local_18;
    int pp_i;
    phys_vec3 *b2_r_loc;
    phys_vec3 *b1_r_loc;

    if (param_1 == NULL) {
        bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",0xec,"b1","");
        if (bVar4 != false) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
        }
    }
    if (param_2 == NULL) {
        bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",0xed,"b2","");
        if (bVar4 != false) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
        }
    }
    if (param_1 == param_2) {
        bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",0xee,"b1 != b2","");
        if (bVar4 != false) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
        }
    }
    if (param_1->m_node == NULL) {
        if (param_2->m_node == NULL) {
            bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",0xef,"rbint::get_pulse_sum_node(b1) || rbint::get_pulse_sum_node(b2)","");
            if (bVar4 != false) {
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
            }
        }
        if (param_1->m_node != NULL) goto LAB_00a279c1;
        uVar5 = param_1->m_flags & 0x30;
    }
    else {
LAB_00a279c1:
        uVar5 = (uint)((*(byte *)&param_1->m_flags & 0x30) == 0);
    }
    if (uVar5 != 0) {
        if (param_2->m_node == NULL) {
            uVar5 = param_2->m_flags & 0x30;
        }
        else {
            uVar5 = (uint)((*(byte *)&param_2->m_flags & 0x30) == 0);
        }
        if (uVar5 != 0) goto LAB_00a27a2a;
    }
    bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",0xf0,"rbint::verify_pulse_sum_node(b1) && rbint::verify_pulse_sum_node(b2)","");
    if (bVar4 != false) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
    }
LAB_00a27a2a:
    if (param_1->m_node == NULL) {
        bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",0xf2,"rbint::get_pulse_sum_node(b1) != NULL","b1 in contact constraint cannot be environment or user rigid body.");
        if (bVar4 != false) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
        }
    }
    this->m_b1 = param_1->m_node;
    this->m_b2 = param_2->m_node;
    ppVar7 = &this->m_ud_n;
    ppVar7->x = (param_3->m_normal).x;
    (this->m_ud_n).y = (param_3->m_normal).y;
    (this->m_ud_n).z = (param_3->m_normal).z;
    ppVar6 = construct_orth_ud(&local_60,ppVar7);
    (this->m_ud_f1).x = ppVar6->x;
    (this->m_ud_f1).y = ppVar6->y;
    (this->m_ud_f1).z = ppVar6->z;
    local_40 = (this->m_ud_n).y * (this->m_ud_f1).z - (this->m_ud_n).z * (this->m_ud_f1).y;
    local_3c = (this->m_ud_f1).x * (this->m_ud_n).z - ppVar7->x * (this->m_ud_f1).z;
    local_38 = ppVar7->x * (this->m_ud_f1).y - (this->m_ud_n).y * (this->m_ud_f1).x;
    (this->m_ud_f2).x = local_40;
    (this->m_ud_f2).y = local_3c;
    (this->m_ud_f2).z = local_38;
    this->m_fric_coef = param_3->m_fric_coef;
    *(pulse_sum_cache_info **)&this->m_pulse_sum_cache_list = param_3->m_list_pulse_sum_cache_info;
    if (this->m_list_pscp_count != param_3->m_point_pair_count) {
        bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",0xfb,"m_list_pscp_count == cpi->m_point_pair_count","");
        if (bVar4 != false) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
        }
    }
    prVar1 = this->m_b1->m_rb;
    local_40 = (prVar1->m_gravity_acc_vec).x;
    local_3c = (prVar1->m_gravity_acc_vec).y;
    local_38 = (prVar1->m_gravity_acc_vec).z;
    b2_r.x = (prVar1->m_gravity_acc_vec).w;
    local_18 = param_3->m_list_b1_r_loc;
    min_restitution_impact_vel_sq = (float)param_3->m_list_b2_r_loc;
    local_20 = 0;
    b2_r.w = (local_38 * local_38 + local_40 * local_40 + local_3c * local_3c) * 0.09000000;
    if (0 < param_3->m_point_pair_count) {
        pp_i = 0;
        do {
            this_00 = (pulse_sum_contact_point *)((int)&(this->m_list_pscp->m_b1_r).x + pp_i);
            phys_multiply33(&local_60,&param_1->m_mat,local_18);
            (this_00->m_b1_r).x = local_60.x;
            (this_00->m_b1_r).y = local_60.y;
            (this_00->m_b1_r).z = local_60.z;
            phys_multiply33((phys_vec3 *)&local_40,&param_2->m_mat,(phys_vec3 *)min_restitution_impact_vel_sq);
            if (this->m_b2 == NULL) {
                ppVar7 = rbint::gtv(&local_70,param_2,(phys_vec3 *)&local_40);
                (this_00->m_b2_ap_n).x = ppVar7->x;
                (this_00->m_b2_ap_n).y = ppVar7->y;
                (this_00->m_b2_ap_n).z = ppVar7->z;
                local_50 = local_40 + (param_2->m_mat).w.x;
                local_4c = (param_2->m_mat).w.y + local_3c;
                local_48 = (param_2->m_mat).w.z + local_38;
                if (this->m_b2 != NULL) {
                    bVar4 = _tlAssert("c:\\projects_pc\\cod\\codsrc\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",0xd1,"psc->m_b2 == NULL","");
                    if (bVar4 != false) {
                        pcVar2 = (code *)swi(3);
                        (*pcVar2)();
                        return;
                    }
                }
                (this_00->m_b2_r).x = local_50;
                (this_00->m_b2_r).y = local_4c;
                fVar3 = local_48;
            }
            else {
                (this_00->m_b2_r).x = local_40;
                (this_00->m_b2_r).y = local_3c;
                fVar3 = local_38;
            }
            (this_00->m_b2_r).z = fVar3;
            pulse_sum_contact_point::calc_abs(this_00,this);
            pulse_sum_contact_point::setup_vel_uni_restitution(this_00,this,param_3->m_bounce_coef,param_3->m_max_restitution_vel,param_4,50.00000000,b2_r.w);
            pp_i += 0xd0;
            local_18 = local_18 + 1;
            min_restitution_impact_vel_sq = (float)((int)min_restitution_impact_vel_sq + 0x10);
            local_20 += 1;
        } while (local_20 < param_3->m_point_pair_count);
    }
    return;
}
