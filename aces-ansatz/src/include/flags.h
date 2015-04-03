
#ifndef _FLAGS_H_
#define _FLAGS_H_

#define h_IOPPAR_print		1 

#define h_IOPPAR_calclevel	2
#define h_IOPPAR_calc		2 /* an alias */

#define h_IOPPAR_deriv_lev	3

#define h_IOPPAR_cc_conv	4

#define h_IOPPAR_scf_conv	5

#define h_IOPPAR_xform_tol	6

#define h_IOPPAR_cc_maxcyc	7

#define h_IOPPAR_lindep_tol	8

#define h_IOPPAR_rdo		9

#define h_IOPPAR_scf_extrapo	10
#define h_IOPPAR_scf_extrap	10 /* an alias */

#define h_IOPPAR_reference	11
#define h_IOPPAR_ref		11 /* an alias */

#define h_IOPPAR_cc_exporder	12

#define h_IOPPAR_tamp_sum	13

#define h_IOPPAR_ntop_tamp	14

#define h_IOPPAR_dampscf	15

#define h_IOPPAR_scf_maxcyc	16

#define h_IOPPAR_occupation	17
#define h_IOPPAR_occ		17 /* an alias */

#define h_IOPPAR_props		18

#define h_IOPPAR_density	19

#define h_IOPPAR_scf_exporde	20

#define h_IOPPAR_cc_extrapol	21
#define h_IOPPAR_cc_extrap	21 /* an alias */

#define h_IOPPAR_brueckner	22

#define h_IOPPAR_xfield		23

#define h_IOPPAR_yfield		24

#define h_IOPPAR_zfield		25

#define h_IOPPAR_save_ints	26

#define h_IOPPAR_dropmo		27

#define h_IOPPAR_charge		28

#define h_IOPPAR_multiplicty	29
#define h_IOPPAR_mult		29 /* an alias */

#define h_IOPPAR_cphf_conver	30

#define h_IOPPAR_cphf_maxcyc	31

#define h_IOPPAR_qrhf_orbita	34
#define h_IOPPAR_qrhf_orb	34 /* an alias */

#define h_IOPPAR_incore		35

#define h_IOPPAR_memory_size	36
#define h_IOPPAR_mem		36 /* an alias */

#define h_IOPPAR_file_recsiz	37

#define h_IOPPAR_nonhf		38 /* missing hyphen (non-hf) on purpose */

#define h_IOPPAR_orbitals	39

#define h_IOPPAR_scf_expstar	40

#define h_IOPPAR_lock_orbocc	41

#define h_IOPPAR_file_stripe	42

#define h_IOPPAR_hbar		43

#define h_IOPPAR_cache_recs	44

#define h_IOPPAR_guess		45

#define h_IOPPAR_joda_print	46

#define h_IOPPAR_opt_method	47

#define h_IOPPAR_convergence	48

#define h_IOPPAR_eigenvector	49

#define h_IOPPAR_negeval	50

#define h_IOPPAR_curvilinear	51

#define h_IOPPAR_stp_siz_ctl	52

#define h_IOPPAR_max_step	53

#define h_IOPPAR_vibration	54
#define h_IOPPAR_vib		54 /* an alias */

#define h_IOPPAR_eval_hess	55

#define h_IOPPAR_integrals	56

#define h_IOPPAR_fd_stepsize	57

#define h_IOPPAR_points		58

#define h_IOPPAR_contraction	59

#define h_IOPPAR_symmetry	60
#define h_IOPPAR_sym		60 /* an alias */

#define h_IOPPAR_basis		61

#define h_IOPPAR_spherical	62

#define h_IOPPAR_reset_flags	63

#define h_IOPPAR_pert_orb	64

#define h_IOPPAR_genbas_1	65

#define h_IOPPAR_genbas_2	66

#define h_IOPPAR_genbas_3	67

#define h_IOPPAR_coordinates	68
#define h_IOPPAR_coord		68 /* an alias */

#define h_IOPPAR_check_sym	69

#define h_IOPPAR_scf_print	70

#define h_IOPPAR_ecp		71

#define h_IOPPAR_restart	72

#define h_IOPPAR_trans_inv	73

#define h_IOPPAR_hfstability	74
#define h_IOPPAR_hfstab		74 /* an alias */

#define h_IOPPAR_rot_evec	75

#define h_IOPPAR_bruck_conv	76

#define h_IOPPAR_qrhf_genera	77
#define h_IOPPAR_qrhf_gen	77 /* an alias */

#define h_IOPPAR_units		78

#define h_IOPPAR_fd_usegroup	79

#define h_IOPPAR_fd_project	80

#define h_IOPPAR_fd_irreps	82

#define h_IOPPAR_vtran		83

#define h_IOPPAR_hf2_file	84

#define h_IOPPAR_subgroup	85

#define h_IOPPAR_subgrpaxis	86

#define h_IOPPAR_excite		87

#define h_IOPPAR_zeta_conv	88

#define h_IOPPAR_estate_sym	89

#define h_IOPPAR_treat_pert	90

#define h_IOPPAR_estate_prop	91

#define h_IOPPAR_opt_maxcyc	92

#define h_IOPPAR_abcdtype	93

#define h_IOPPAR_qrhf_spin	94

#define h_IOPPAR_ao_ladders	95

#define h_IOPPAR_fock		96

#define h_IOPPAR_estate_maxc	97

#define h_IOPPAR_estate_tol	98

#define h_IOPPAR_turbomole	99

#define h_IOPPAR_gamma_abcd	100

#define h_IOPPAR_zeta_type	101

#define h_IOPPAR_zeta_maxcyc	102

#define h_IOPPAR_resraman	103

#define h_IOPPAR_psi		104

#define h_IOPPAR_geom_opt	105

#define h_IOPPAR_external	106

#define h_IOPPAR_hess_update	107

#define h_IOPPAR_init_hessian	108

#define h_IOPPAR_extrap		109

#define h_IOPPAR_frag       121

#define h_IOPPAR_ea_calc	201

#define h_IOPPAR_ea_sym		202

#define h_IOPPAR_tdhf		203

#define h_IOPPAR_functional	204

#define h_IOPPAR_eom_maxcyc	205

#define h_IOPPAR_eomprop	206

#define h_IOPPAR_abcdfull	207

#define h_IOPPAR_intgrl_tol	208

#define h_IOPPAR_damp_typ	209

#define h_IOPPAR_damp_tol	210

#define h_IOPPAR_lshf_a1	211

#define h_IOPPAR_lshf_b1	212

#define h_IOPPAR_polyrate	213

#define h_IOPPAR_ip_calc	214

#define h_IOPPAR_ip_sym		215

#define h_IOPPAR_ip_search	216

#define h_IOPPAR_eomref		217

#define h_IOPPAR_solvent	218

#define h_IOPPAR_ee_search	219

#define h_IOPPAR_eom_prjct	220

#define h_IOPPAR_newvrt		221

#define h_IOPPAR_hbarabcd	222

#define h_IOPPAR_hbarabci	223

#define h_IOPPAR_nt3eomee	224

#define h_IOPPAR_noreori	225

#define h_IOPPAR_ee_sym		226

#define h_IOPPAR_ks_pot		227

#define h_IOPPAR_dip_calc	228

#define h_IOPPAR_dip_sym	229

#define h_IOPPAR_dea_calc	230

#define h_IOPPAR_dea_sym	231

#define h_IOPPAR_program	232

#define h_IOPPAR_ccr12		233

#define h_IOPPAR_eomxfield	234

#define h_IOPPAR_eomyfield	235

#define h_IOPPAR_eomzfield	236

#define h_IOPPAR_insertf	237

#define h_IOPPAR_grad_calc	238

#define h_IOPPAR_imem_size	239
#define h_IOPPAR_imem		239 /* an alias */

#define h_IOPPAR_makerhf	240

#define h_IOPPAR_global_mem	241

#define h_IOPPAR_prp_ints	242

#define h_IOPPAR_trunc_orbs	243 /* previously fno_keep */

#define h_IOPPAR_fno_keep	244 /* previously fno_post */

#define h_IOPPAR_fno_bsse	245 /* previously fno_active */

#define h_IOPPAR_natural	246

#define h_IOPPAR_acc_sym	247

#define h_IOPPAR_uno_ref	248

#define h_IOPPAR_uno_charge	249

#define h_IOPPAR_uno_mult	250

#define h_IOPPAR_raman		251

#define h_IOPPAR_kucharski	252

#define h_IOPPAR_scf_type	253

#define h_IOPPAR_direct		254

#define h_IOPPAR_single_store	255

#endif /* _FLAGS_H_ */

